#include <vcl.h>
#include <algorithm>
#include <vector>
#pragma hdrstop

#include "SortData.h"

#pragma package(smart_init)

void __fastcall TForm1::SortData(TObject *Sender)
{
    std::vector<AnsiString> items;
    for (int i = 0; i < ListBox1->Items->Count; i++)
        items.push_back(ListBox1->Items->Strings[i]);

    if (RadioGroup1->ItemIndex == 0) // Sort by Service Provider
    {
        std::sort(items.begin(), items.end(), [](AnsiString a, AnsiString b) {
            return SplitString(a, "\t")[5] < SplitString(b, "\t")[5];
        });
    }
    else // Sort by Starting Time
    {
        std::sort(items.begin(), items.end(), [](AnsiString a, AnsiString b) {
            return SplitString(a, "\t")[1] < SplitString(b, "\t")[1];
        });
    }

    ListBox1->Clear();
    for (const auto& item : items)
        ListBox1->Items->Add(item);
}
