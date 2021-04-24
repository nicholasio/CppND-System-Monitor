#include "linux_parser.h"

#include <dirent.h>
#include <unistd.h>
#include <cmath>

#include <sstream>
#include <string>
#include <vector>

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, kernel, version;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

float LinuxParser::MemoryUtilization() {
  string line;
  string key, unit;
  float value;

  std::ifstream stream(kProcDirectory + kMeminfoFilename);
  float mem_total, mem_free;
  mem_total = mem_free = 0;

  if(stream.is_open()) {
    while(std::getline(stream, line)) {
      std::istringstream linestream(line);

      linestream >> key >> value >> unit;
      if (key == "MemTotal:") {
        mem_total = value;
      } else if (key == "MemFree:") {
        mem_free = value;
      }
    }
  }

  return ((mem_total - mem_free) / mem_total);
}

long LinuxParser::UpTime() {
  long uptime = 0;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  string line;
  if(stream.is_open()) {
    std::getline(stream, line);
  
    std::istringstream linestram(line);
    linestram >> uptime;
  }

  return uptime;
  
}

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { return 0; }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid [[maybe_unused]]) { return 0; }

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { return 0; }

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { return 0; }

LinuxParser::CpuProcessesInfo LinuxParser::CpuUtilization() {
  std::ifstream stream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
  std::string line;
  std::string key;
  CpuProcessesInfo cpuPInfo;

  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> key >> cpuPInfo.user >> cpuPInfo.nice >> 
      cpuPInfo.system >> cpuPInfo.idle >> cpuPInfo.iowait >>
      cpuPInfo.irq >> cpuPInfo.softirq >> cpuPInfo.steal >>
      cpuPInfo.guest >> cpuPInfo.guestnice;
  }

  return cpuPInfo;

}

int LinuxParser::TotalProcesses() { 
  std::ifstream stream(kProcDirectory + kStatFilename);
  std::string line;
  std::string key;
  int value = 0;

  if(stream.is_open()) {
    while(std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> key;
      if(key == "processes") {
        linestream >> value;
      }
    }
  }

  return value;
}

int LinuxParser::RunningProcesses() {
  std::ifstream stream(kProcDirectory + kStatFilename);
  std::string line;
  std::string key;
  int value = 0;

  if(stream.is_open()) {
    while(std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> key;
      if(key == "procs_running") {
        linestream >> value;
      }
    }
  }

  return value;
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid [[maybe_unused]]) { return 0; }
