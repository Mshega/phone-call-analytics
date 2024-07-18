//---------------------------------------------------------------------------

#ifndef Phone_H
#define Phone_H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
class TfrmST1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pgctrlPage;
	TStatusBar *stsInfo;
	TTabSheet *tbsOne;
	TListBox *lstOutput;
	TButton *btnDuration;
	TButton *btnLoad;
	TLabel *Label7;
	TLabel *lblCalls;
	TRadioGroup *rdgSort;
	TLabel *lblBusy;
	TPanel *pnlTop;
	TLabel *Label5;
	TLabel *Label15;
	TImage *img1;
	TImage *img2;
	TTabSheet *tbsTWO;
	TListBox *lstSelected;
	TRadioGroup *rdgExtension;
	TLabel *lblExt;
	TLabel *Label1;
	void __fastcall SortData(TObject *Sender);
	void __fastcall LoadData(TObject *Sender);
	void __fastcall CalcCallDuration(TObject *Sender);
	void __fastcall DisplayExtensions(TObject *Sender);
	void __fastcall FilterRecords(TObject *Sender));
	void __fastcall FormActivate(TObject *Sender);

private:	// User declarations
public:		// User declarations
   //AnsiString TempDesc;
   //	AnsiString TempCode;
	__fastcall TfrmST1(TComponent* Owner);                  // provided
	void Heading1();
    void Heading2();
	AnsiString getFieldNrFrom(AnsiString aLine, int fieldNr, char delim);
															  // delete?
	AnsiString CallDuration(AnsiString startT, AnsiString endT);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmST1 *frmST1;
//---------------------------------------------------------------------------
#endif
