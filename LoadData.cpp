#include <vcl.h>        // VCL header for using visual components
#include <fstream>      // Header for file handling
#include <string>       // Header for string handling
#pragma hdrstop        // Stops precompiled header

#include "LoadData.h"   // Custom header file for LoadData
#include "Heading1.h"   // Custom header file for Heading1

#pragma package(smart_init) // Initialize VCL package

// Function to load data from a CSV file into ListBox1
void __fastcall TForm1::LoadData(TObject *Sender)
{
    // Open the input file stream for the CSV file
    std::ifstream infile("AppData/OneMonthData.csv");
    std::string line; // Variable to store each line from the file
    ListBox1->Clear(); // Clear the ListBox before adding new items
    Heading1(); // Call Heading1 function to set up any necessary headings

    // Read the file line by line
    while (std::getline(infile, line))
    {
        // Convert the std::string to a VCL String
        String s(line.c_str());
        // Replace all '#' characters with tab characters
        s = StringReplace(s, "#", "\t", TReplaceFlags() << rfReplaceAll);
        // Add the modified line to the ListBox
        ListBox1->Items->Add(s);
    }

    // Update the label with the total number of calls
    lblCalls->Caption = "Total Calls: " + IntToStr(ListBox1->Items->Count);
    // Enable the radio group and button
    RadioGroup1->Enabled = true;
    Button2->Enabled = true;
}
