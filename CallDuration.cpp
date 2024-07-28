#include <vcl.h> 
#include <string> 
#include <sstream>
#pragma hdrstop // Stops the precompiled header

#include "CallDuration.h" 

#pragma package(smart_init) // Initializes the package

AnsiString CallDuration(AnsiString start, AnsiString end) 
{
    int start_h, start_m, start_s; // Variables for start time hours, minutes, and seconds
    int end_h, end_m, end_s; // Variables for end time hours, minutes, and seconds

    sscanf(start.c_str(), "%d:%d:%d", &start_h, &start_m, &start_s); // Parse the start time string into hours, minutes, and seconds
    sscanf(end.c_str(), "%d:%d:%d", &end_h, &end_m, &end_s); // Parse the end time string into hours, minutes, and seconds

    int start_total_seconds = start_h * 3600 + start_m * 60 + start_s; // Convert start time to total seconds
    int end_total_seconds = end_h * 3600 + end_m * 60 + end_s; // Convert end time to total seconds
    int duration_seconds = end_total_seconds - start_total_seconds; // Calculate the duration in seconds

    // Calculate duration in minutes and seconds
    int duration_mins = duration_seconds / 60;
    int duration_secs = duration_seconds % 60;

    // Create a string stream to format the output as "MM:SS"
    std::ostringstream oss;
    oss << duration_mins << ":" << (duration_secs < 10 ? "0" : "") << duration_secs;
    
    return AnsiString(oss.str().c_str()); // Return the formatted duration as AnsiString
} 
