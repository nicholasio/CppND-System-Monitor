#include "system.h"

#include <unistd.h>

#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

System::~System() {
    for(auto it = processesMap.begin(); it != processesMap.end(); it++) {
        delete processesMap[it->first];
    }
}
Processor& System::Cpu() { return cpu_; }

vector<Process>& System::Processes() {
    std::vector<int> pids = LinuxParser::Pids();
    processes_.clear();

    for(int pid : pids) {
        if(processesMap.find(pid) == processesMap.end()) {
            processesMap[pid] = new Process(pid);
        }

        auto p = processesMap[pid];
        p->Update();
    }
    
    // remove old processes
    for(const auto& [key, _] : processesMap) {
        if (std::find(pids.begin(), pids.end(), key) == pids.end()) {
            delete processesMap[key];
            processesMap.erase(key);
        }
    }
    

    processes_.reserve(processesMap.size());

    std::for_each(
        processesMap.begin(),
        processesMap.end(),
        [this] (const auto it) {
            processes_.emplace_back(*it.second);
        }
    );
    
    std::sort(processes_.begin(), processes_.end());

    return processes_;
}

std::string System::Kernel() { return LinuxParser::Kernel(); }

float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

long int System::UpTime() { return LinuxParser::UpTime(); }