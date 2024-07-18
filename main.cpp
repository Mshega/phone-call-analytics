#include <vcl.h>
#include <tchar.h>
#include "FormActivate.h"

#pragma hdrstop
#pragma argsused

int _tmain(int argc, _TCHAR* argv[])
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TForm1), &Form1);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
