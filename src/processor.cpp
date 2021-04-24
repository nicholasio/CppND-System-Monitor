#include "processor.h"
#include "linux_parser.h"

#include <sstream>
#include <string>
#include <vector>

Processor::Processor() {
    std::ifstream stream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
    std::string line;
    std::string key;

    if (stream.is_open()) {
        while(std::getline(stream, line)) {
            std::istringstream linestream(line);
            linestream >> key;

            if (key == "cpu"){
                continue;
            }

            if(key != "intr") {
                n_cores += 1;
            } else {
                break;
            }
        }
    }
}

double Processor::Utilization() { 
    LinuxParser::CpuProcessesInfo cpuInfo = LinuxParser::CpuUtilization();
    unsigned long long idlealltime = cpuInfo.idle + cpuInfo.iowait;
    unsigned long long systemalltime = cpuInfo.system + cpuInfo.irq + cpuInfo.softirq;
    unsigned long long totaltime = cpuInfo.user + cpuInfo.nice + systemalltime + cpuInfo.steal + idlealltime;

    unsigned long long prevIdlealltime = prevCpuInfo.idle + prevCpuInfo.iowait;
    unsigned long long prevSystemalltime = prevCpuInfo.system + prevCpuInfo.irq + prevCpuInfo.softirq;
    unsigned long long prevTotaltime = prevCpuInfo.user + prevCpuInfo.nice + prevSystemalltime + prevCpuInfo.steal + prevIdlealltime;

    prevCpuInfo = cpuInfo;

    double totalDelta = totaltime - prevTotaltime;
    double idleDelta = idlealltime - prevIdlealltime;

    double diff = totalDelta - idleDelta;
    double percentage = diff / totalDelta;

    return percentage;
}