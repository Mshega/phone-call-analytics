#include <vcl.h>
#include <set>
#pragma hdrstop

#include "DisplayExtensions.h"

#pragma package(smart_init)

void __fastcall TForm1::DisplayExtensions(TObject *Sender)
{
    std::set<AnsiString> extensions;
    for (int i = 0; i < ListBox1->Items->Count; i++)
    {
        AnsiString line = ListBox1->Items->Strings[i];
        std::vector<AnsiString> fields = SplitString(line, "\t");
        extensions.insert(fields[3]);
    }

    RadioGroup2->Items->Clear();
    RadioGroup2->Items->Add("ALL");
    for (const auto& ext : extensions)
        RadioGroup2->Items->Add(ext);
}
