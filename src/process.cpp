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
  this->CpuUtilization();
}

int Process::Pid() { return pid; }

double Process::CpuUtilization() { 
  long uptime = LinuxParser::UpTime();
  
  double total_time = cpuProcessInfo.utime + cpuProcessInfo.stime + cpuProcessInfo.cutime + cpuProcessInfo.cstime;
  double seconds = uptime - (double(cpuProcessInfo.starttime) / double(sysconf(_SC_CLK_TCK)));
  
  if (seconds == 0) {
    cpu_utilization = 0;
    return 0;
  } 

  cpu_utilization = ( (total_time / sysconf(_SC_CLK_TCK)) / seconds) * 100;

  return cpu_utilization;
}

string Process::Command() { return LinuxParser::Command(this->Pid()); }

string Process::Ram() { return LinuxParser::Ram(this->Pid()); }

string Process::User() {
  int uid = LinuxParser::Uid(this->Pid());
  
  return LinuxParser::User(uid);
}

long int Process::UpTime() { return double(cpuProcessInfo.starttime) / sysconf(_SC_CLK_TCK); }

bool Process::operator<(Process const& a) const {
  return cpu_utilization < a.cpu_utilization;
}