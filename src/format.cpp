#include "format.h"

#include <string>
#include <sstream>
#include <iomanip>

using std::string;

constexpr int HOUR_IN_SECONDS = 60 * 60;
constexpr int MINUTE_IN_SECONDS = 60;

string Format::ElapsedTime(long seconds) {
    int hh = seconds / HOUR_IN_SECONDS;
    int mm = (seconds % HOUR_IN_SECONDS) / MINUTE_IN_SECONDS;
    int ss = seconds % MINUTE_IN_SECONDS;

    std::stringstream  time;

    time << std::setw(2) << std::setfill('0') << hh << ':';
    time << std::setw(2) << std::setfill('0') << mm << ':';
    time << std::setw(2) << std::setfill('0') << ss;
    return time.str();
}