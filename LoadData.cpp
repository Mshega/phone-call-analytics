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
    std::ifstream infile("AppData/OneMonthData.csv"); // Open the input file stream for the CSV file
    std::string line; // Variable to store each line from the file
    
    ListBox1->Clear(); // Clear the ListBox before adding new items
    Heading1(); // Call Heading1 function to set up any necessary headings

    // Read the file line by line
    while (std::getline(infile, line))
    {
        String s(line.c_str()); // Convert the std::string to a VCL String
        s = StringReplace(s, "#", "\t", TReplaceFlags() << rfReplaceAll); // Replace all '#' characters with tab characters
        ListBox1->Items->Add(s); v
    }

    lblCalls->Caption = "Total Calls: " + IntToStr(ListBox1->Items->Count); // Update the label with the total number of calls
    // Enable the radio group and button
    RadioGroup1->Enabled = true;
    Button2->Enabled = true;
}
