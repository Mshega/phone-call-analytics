#include <vcl.h>
#include <string>
#include <sstream>
#pragma hdrstop

#include "CallDuration.h"

#pragma package(smart_init)

AnsiString CallDuration(AnsiString start, AnsiString end)
{
    int start_h, start_m, start_s;
    int end_h, end_m, end_s;

    sscanf(start.c_str(), "%d:%d:%d", &start_h, &start_m, &start_s);
    sscanf(end.c_str(), "%d:%d:%d", &end_h, &end_m, &end_s);

    int start_total_seconds = start_h * 3600 + start_m * 60 + start_s;
    int end_total_seconds = end_h * 3600 + end_m * 60 + end_s;
    int duration_seconds = end_total_seconds - start_total_seconds;

    int duration_mins = duration_seconds / 60;
    int duration_secs = duration_seconds % 60;

    std::ostringstream oss;
    oss << duration_mins << ":" << (duration_secs < 10 ? "0" : "") << duration_secs;
    return AnsiString(oss.str().c_str());
}
