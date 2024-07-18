#include <vcl.h>
#include <fstream>
#include <string>
#pragma hdrstop

#include "LoadData.h"
#include "Heading1.h"

#pragma package(smart_init)

void __fastcall TForm1::LoadData(TObject *Sender)
{
    std::ifstream infile("AppData/OneMonthData.csv");
    std::string line;
    ListBox1->Clear();
    Heading1();

    while (std::getline(infile, line))
    {
        String s(line.c_str());
        s = StringReplace(s, "#", "\t", TReplaceFlags() << rfReplaceAll);
        ListBox1->Items->Add(s);
    }

    lblCalls->Caption = "Total Calls: " + IntToStr(ListBox1->Items->Count);
    RadioGroup1->Enabled = true;
    Button2->Enabled = true;
}
