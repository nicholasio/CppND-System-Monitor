#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "linux_parser.h"

class Processor {
 public:
  Processor();
  double Utilization();

 private:
    int n_cores = 0;
    LinuxParser::CpuProcessesInfo prevCpuInfo;
};

#endif