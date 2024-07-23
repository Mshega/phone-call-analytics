#include <vcl.h>
#pragma hdrstop

#include "FilterRecords.h"

#pragma package(smart_init)

// Function to filter records based on selected extension from a radio group
void __fastcall TForm1::FilterRecords(TObject *Sender)
{
    AnsiString selectedExt = RadioGroup2->Items->Strings[RadioGroup2->ItemIndex]; // Get the selected extension from the radio group
    ListBox2->Clear(); // Clear the second list box before adding filtered items
    
    // If "ALL" is selected, add all items from ListBox1 to ListBox2
    if (selectedExt == "ALL")
    {
        for (int i = 0; i < ListBox1->Items->Count; i++)
        {
            ListBox2->Items->Add(ListBox1->Items->Strings[i]);
        }
    }
    else // Otherwise, filter items based on the selected extension
    {
        for (int i = 0; i < ListBox1->Items->Count; i++)
        {
            AnsiString line = ListBox1->Items->Strings[i]; // Split the line into fields using a custom SplitString function
            std::vector<AnsiString> fields = SplitString(line, "\t"); // If the extension field matches the selected extension, add the line to ListBox2
            
            if (fields[3] == selectedExt)
            {
                ListBox2->Items->Add(line);
            }
        }
    }
    
    lblExt->Caption = "Extension: " + selectedExt; // Update the label with the selected extension
    StatusBar1->Panels->Items[1]->Text = "Filtered records: " + IntToStr(ListBox2->Items->Count); // Update the status bar with the number of filtered records
}

