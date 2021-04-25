#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>
#include <map>

#include "process.h"
#include "processor.h"

class System {
 public:
  ~System();
  Processor& Cpu();
  std::vector<Process>& Processes();
  float MemoryUtilization(); 
  long UpTime();
  int TotalProcesses();
  int RunningProcesses();
  std::string Kernel();
  std::string OperatingSystem();

 private:
  Processor cpu_ = {};
  std::vector<Process> processes_ = {};
  std::unordered_map<int, Process*> processesMap;
};

#endif