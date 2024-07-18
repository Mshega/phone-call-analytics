#include <vcl.h>
#pragma hdrstop

#include "FilterRecords.h"

#pragma package(smart_init)

void __fastcall TForm1::FilterRecords(TObject *Sender)
{
    AnsiString selectedExt = RadioGroup2->Items->Strings[RadioGroup2->ItemIndex];
    ListBox2->Clear();
    if (selectedExt == "ALL")
    {
        for (int i = 0; i < ListBox1->Items->Count; i++)
            ListBox2->Items->Add(ListBox1->Items->Strings[i]);
    }
    else
    {
        for (int i = 0; i < ListBox1->Items->Count; i++)
        {
            AnsiString line = ListBox1->Items->Strings[i];
            std::vector<AnsiString> fields = SplitString(line, "\t");
            if (fields[3] == selectedExt)
                ListBox2->Items->Add(line);
        }
    }
    lblExt->Caption = "Extension: " + selectedExt;
    StatusBar1->Panels->Items[1]->Text = "Filtered records: " + IntToStr(ListBox2->Items->Count);
}
