#include <vcl.h> // VCL library for AnsiString and GUI components
#include <set> // Standard library for set operations
#pragma hdrstop // Stops the precompiled header

#include "DisplayExtensions.h" // Include the header file for DisplayExtensions

#pragma package(smart_init) // Initializes the package

// Function to display unique file extensions in a radio group
void __fastcall TForm1::DisplayExtensions(TObject *Sender) 
{
    std::set<AnsiString> extensions; // Set to store unique extensions

    // Iterate through each item in the ListBox
    for (int i = 0; i < ListBox1->Items->Count; i++) 
    {
        AnsiString line = ListBox1->Items->Strings[i]; // Get the current line
        std::vector<AnsiString> fields = SplitString(line, "\t"); // Split the line by tab character
        if (fields.size() > 3) { // Ensure there are enough fields
            extensions.insert(fields[3]); // Insert the extension into the set
        }
    }
    
    RadioGroup2->Items->Clear(); // Clear existing items in the RadioGroup
    RadioGroup2->Items->Add("ALL"); // Add "ALL" option to the RadioGroup

    // Add each unique extension to the RadioGroup
    for (const auto& ext : extensions) 
    {
        RadioGroup2->Items->Add(ext);
    }
}

