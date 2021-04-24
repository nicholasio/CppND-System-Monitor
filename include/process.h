#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include "linux_parser.h"

/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
    public:
        Process(int pid);
        int Pid();                               // TODO: See src/process.cpp
        std::string User();                      // TODO: See src/process.cpp
        std::string Command();                   // TODO: See src/process.cpp
        double CpuUtilization();                  // TODO: See src/process.cpp
        std::string Ram();                       // TODO: See src/process.cpp
        long int UpTime();                       // TODO: See src/process.cpp
        bool operator<(Process const& a) const;
    private:
        int pid = 0;
        double cpu_utilization = 0;
        LinuxParser::CpuProcessInfo cpuProcessInfo;
};

#endif