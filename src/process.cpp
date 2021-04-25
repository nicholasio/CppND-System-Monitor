#include "process.h"
#include "linux_parser.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid(pid) {
  cpuProcessInfo = LinuxParser::CpuUtilization(this->Pid());
  prevCpuProcessInfo = LinuxParser::CpuUtilization(this->Pid());
  prev_elapsed_seconds = this->UpTime();
}
void Process::Update() {
  this->CalculateCpuUtilization();
}

int Process::Pid() { return pid; }

void Process::CalculateCpuUtilization() {
  auto clock_tick = sysconf(_SC_CLK_TCK);
  
  long total_time = cpuProcessInfo.utime + cpuProcessInfo.stime + cpuProcessInfo.cutime + cpuProcessInfo.cstime;
  double total_time_seconds = 1.0 * total_time / clock_tick;
  double elapsed_seconds = this->UpTime();

  /* long prev_total_time = prevCpuProcessInfo.utime + prevCpuProcessInfo.stime + prevCpuProcessInfo.cutime + prevCpuProcessInfo.cstime;
  double prev_total_time_seconds = 1.0 * prev_total_time / clock_tick;

  double seconds = elapsed_seconds - prev_elapsed_seconds;
  double total_delta = total_time_seconds - prev_total_time_seconds;  */

  prevCpuProcessInfo = cpuProcessInfo;
  prev_elapsed_seconds = elapsed_seconds;

  if (elapsed_seconds == 0) {
    cpu_utilization = 0.;
  } else {
    cpu_utilization = total_time_seconds / elapsed_seconds;
  }
}
double Process::CpuUtilization() { 
  return cpu_utilization;
}

string Process::Command() { return LinuxParser::Command(this->Pid()); }

string Process::Ram() { return LinuxParser::Ram(this->Pid()); }

string Process::User() {
  int uid = LinuxParser::Uid(this->Pid());

  return LinuxParser::User(uid);
}

long int Process::UpTime() { 
  long uptime = LinuxParser::UpTime();
  return double(uptime) - ( 1.0 * cpuProcessInfo.starttime / sysconf(_SC_CLK_TCK) );
}

bool Process::operator<(Process const& a) const {
  return cpu_utilization > a.cpu_utilization;
}