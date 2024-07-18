#include <vcl.h>
#pragma hdrstop

#include "FormActivate.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

void __fastcall TForm1::FormActivate(TObject *Sender)
{
    TLabel *label = new TLabel(this);
    label->Parent = this;
    label->Caption = "Cell-phone Joy";
    label->Font->Name = "Segoe Script";
    label->Font->Size = 18;
    label->Font->Color = clMaroon;
    label->Font->Style = TFontStyles() << fsBold;
    label->Top = 10;
    label->Left = 10;
}
