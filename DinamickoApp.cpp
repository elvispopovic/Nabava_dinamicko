/***************************************************************
 * Name:      DinamickoApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Elvis Popović (elvpopovi@foi.hr)
 * Created:   2018-05-05
 * Copyright: Elvis Popović ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "DinamickoApp.h"
#include "DinamickoMain.h"

IMPLEMENT_APP(DinamickoApp);

bool DinamickoApp::OnInit()
{
    DinamickoFrame* frame = new DinamickoFrame(0L);
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
