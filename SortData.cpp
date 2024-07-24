#include <vcl.h>
#include <algorithm>
#include <vector>
#pragma hdrstop

#include "SortData.h"

#pragma package(smart_init)

// Function to handle sorting the data in ListBox1 based on user selection in RadioGroup1
void __fastcall TForm1::SortData(TObject *Sender)
{
    std::vector<AnsiString> items; // Vector to hold the items from ListBox1

    // Copy items from ListBox1 to the vector
    for (int i = 0; i < ListBox1->Items->Count; i++)
        items.push_back(ListBox1->Items->Strings[i]);

    // Determine the sorting criteria based on RadioGroup1 selection
    if (RadioGroup1->ItemIndex == 0) // If the first radio button is selected (Service Provider)
    {
        // Sort items by the 6th field (Service Provider) after splitting the string by tab
        std::sort(items.begin(), items.end(), [](AnsiString a, AnsiString b) {
            return SplitString(a, "\t")[5] < SplitString(b, "\t")[5];
        });
    }
    else // If the second radio button is selected (Starting Time)
    {
        // Sort items by the 2nd field (Starting Time) after splitting the string by tab
        std::sort(items.begin(), items.end(), [](AnsiString a, AnsiString b)
            {
            return SplitString(a, "\t")[1] < SplitString(b, "\t")[1];
        });
    }
    ListBox1->Clear(); // Clear the current items in ListBox1

    // Add the sorted items back to ListBox1
    for (const auto& item : items)
        ListBox1->Items->Add(item);
}
