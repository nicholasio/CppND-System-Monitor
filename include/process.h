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
        int Pid();
        std::string User();
        std::string Command();
        double CpuUtilization();
        std::string Ram();
        long int UpTime();
        bool operator<(Process const& a) const;
        void Update();
    private:
        int pid = 0;
        double cpu_utilization = 0;
        LinuxParser::CpuProcessInfo cpuProcessInfo;
        LinuxParser::CpuProcessInfo prevCpuProcessInfo = {};
        void CalculateCpuUtilization();
        long prev_elapsed_seconds = 0;
};

#endif