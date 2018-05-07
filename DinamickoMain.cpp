/***************************************************************
 * Name:      DinamickoMain.cpp
 * Purpose:   Code for Application Frame
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

#include "DinamickoMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


DinamickoFrame::DinamickoFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(wxT("Operacijska istraživanja 2"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f)+" + TDM GCC 5.1.0 MinGW64 C++", 1);
#endif
    Init();
}

DinamickoFrame::~DinamickoFrame()
{
}

void DinamickoFrame::Init()
{
    long int redaka, i;
    wxGridEvent emptyGridEvent;
    gridPotraznja->SetColLabelValue(0,wxT("Potražnja"));
    gridPotraznja->SetColSize(0,90);
    gridPotraznja->SetRowLabelAlignment(wxALIGN_LEFT,wxALIGN_CENTRE);
    PromijeniBrojRazdoblja(true);
    GridPotraznjaPromijenjena(emptyGridEvent);
    AzurirajParametre();
    std::cout << "broj razdoblja: " << broj_razd << std::endl;
    std::cout << "rata: " << rata << std::endl;
    std::cout << "max. kolicina: " << maxKol << std::endl;
    std::cout << "troskovi skladistenja: " << troskovi_skl << std::endl;
    std::cout << "max. zalihe: " << maxZal << std::endl;
    std::cout << "troskovi nabave: " << troskovi_nab << std::endl;
    std::cout << "Potraznja: ";
    for(std::vector<double>::iterator it=potraznja.begin(); it!=potraznja.end();++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    gridRjesenje->HideRowLabels();

    gridOdluka->SetColSize(0,90);
    gridOdluka->SetColLabelValue(0,"Razdoblje\n(i)");
    gridOdluka->SetColSize(1,90);
    gridOdluka->SetColLabelValue(1,"Zalihe\nI(i-1)");
    gridOdluka->SetColSize(2,90);
    gridOdluka->SetColLabelValue(2,"Nabava\nQ(i)");
    gridOdluka->SetColSize(3,90);
    gridOdluka->SetColLabelValue(3,wxT("Potražnja\nD(i)"));
    gridOdluka->SetColSize(4,90);
    gridOdluka->SetColLabelValue(4,"Zalihe\nI(i)");
    gridOdluka->SetColSize(5,120);
    gridOdluka->SetColLabelValue(5,wxT("Troškovi nabave\nCp(i)"));
    gridOdluka->SetColSize(6,120);
    gridOdluka->SetColLabelValue(6,wxT("Troškovi zaliha\nCh(i)"));
    gridOdluka->HideRowLabels();
}
void DinamickoFrame::ParamPromijenjen( wxCommandEvent& event )
{
    wxWindowID ID;
    ID = wxDynamicCast(event.GetEventObject(),wxTextCtrl)->GetId();
    switch(ID)
    {
    case ID_BROJ_RAZDOBLJA:
        PromijeniBrojRazdoblja();
        break;
    case ID_RATA:
        if(!txtRata->GetValue().ToDouble(&rata)||rata<=0.0)
        {
            rata=10.0;
            txtRata->SetValue("10");
        }
        break;
    case ID_MAX_KOL:
        if(!txtMaxKol->GetValue().ToDouble(&maxKol)||maxKol<=0.0)
        {
            maxKol=70.0;
            txtMaxKol->SetValue("70");
        }
        break;
    case ID_TROSKOVI_SKL:
        if(!txtTrosSkl->GetValue().ToDouble(&troskovi_skl)||troskovi_skl<=0.0)
        {
            troskovi_skl=5.0;
            txtTrosSkl->SetValue("5");
        }
        break;
    case ID_MAX_ZAL:
        if(!txtMaxZal->GetValue().ToDouble(&maxZal)||maxZal<=0.0)
        {
            maxZal=30.0;
            txtMaxZal->SetValue("30");
        }
        break;
    case ID_TROSKOVI_NAB:
        if(!txtTrosNab->GetValue().ToDouble(&troskovi_nab)||troskovi_nab<=0.0)
        {
            troskovi_nab=800.0;
            txtTrosNab->SetValue("800");
        }
        break;
    }
}
void DinamickoFrame::GridPotraznjaPromijenjena( wxGridEvent& event )
{
    int i;
    double val;
    potraznja.clear();
    for(i=0; i<gridPotraznja->GetNumberRows(); i++)
    {
        if(!gridPotraznja->GetCellValue(i,0).ToDouble(&val)||val<=0.0)
        {
            val=10.0;
            gridPotraznja->SetCellValue(i,0,"10");
        }
        potraznja.push_back(val);
    }
}
void DinamickoFrame::GridRjesenjaPrilagodi()
{
    int i;
    int nr,nc;
    int calcR, calcC;
    nr = gridRjesenje->GetNumberRows();
    nc = gridRjesenje->GetNumberCols();
    calcC=broj_razd*2+1;
    if(calcC>nc)
        gridRjesenje->InsertCols(0,calcC-nc);
    if(nc>calcC)
        gridRjesenje->DeleteCols(calcC,nc-calcC);
    calcR=(int)(maxZal/rata+0.1)+1;
    if(calcR>nr)
        gridRjesenje->InsertRows(0,calcR-nr);
    if(nr>calcR)
        gridRjesenje->DeleteRows(calcR,nr-calcR);
    if(gridRjesenje->GetNumberCols()<1)
        return;
    gridRjesenje->SetColLabelValue(0,"I");
    for(i=0; i<broj_razd; i++)
    {
        gridRjesenje->SetColLabelValue(2*i+1,wxString::Format("Q(%d)",i+1));
        gridRjesenje->SetColLabelValue(2*i+2,wxString::Format("f(%d)",i+1));
    }
    nr = gridOdluka->GetNumberRows();
    calcR=(int)broj_razd+2;
    if(calcR>nr)
        gridOdluka->InsertRows(0,calcR-nr);
    if(nr>calcR)
        gridOdluka->DeleteRows(calcR,nr-calcR);
    //gridOdluka->SetSize(750,25*broj_razd+60);
}

void DinamickoFrame::Izracunaj( wxCommandEvent& event )
{
    int razdoblje, i;
    double zalihe, potraznja;
    double nabavaMin, nabavaMax, nabava;
    double troskovi_nab_sum, troskovi_skl_sum;
    std::vector<double> f, f2;
    double Q,fc, proslo;
    GridRjesenjaPrilagodi();
    ispisPostupka.clear();
    std::cout << "Izracunavanje..." << std::endl;
    ispisPostupka.Printf(wxT("Postupak rješavanja za problem nabave sa parametrima:\n"));
    ispisPostupka.Append(wxString::Format(wxT("broj razdoblja: %d\n"),broj_razd));
    ispisPostupka.Append(wxString::Format(wxT("rata: %.1lf\n"),rata));
    ispisPostupka.Append(wxString::Format(wxT("max. nabava: %.1lf\n"),maxKol));
    ispisPostupka.Append(wxString::Format(wxT("max. zalihe: %.1lf\n"),maxZal));
    ispisPostupka.Append(wxString::Format(wxT("troškovi skladištenja: %.1lf\n"),troskovi_skl));
    ispisPostupka.Append(wxString::Format(wxT("troškovi nabave: %.1lf\n"),troskovi_nab));
    ispisPostupka.Append(wxT("potražnja po razdobljima:\n"));
    i=0;
    for(std::vector<double>::iterator it=this->potraznja.begin(); it!=this->potraznja.end();++it)
        ispisPostupka.Append(wxString::Format(wxT("\trazdoblje %d: %.1lf\n"),i++,*it));
    ispisPostupka.Append("====================================================\n\n");
    ispisPostupka.Append(wxT("Računanje tablice rješenja problema nabave:\n"));
    ispisPostupka.Append("----------------------------------------------------\n\n");
    for(zalihe = 0.0, i=0; zalihe <= maxZal; zalihe += rata, i++)
    {
        gridRjesenje->SetCellAlignment(wxALIGN_CENTRE,i,0);
        gridRjesenje->SetCellBackgroundColour(wxColor(250,234,207),i,0);
        gridRjesenje->SetCellValue(i,0,wxString::Format("%.1lf",zalihe));
    }
    for(razdoblje=0; razdoblje<broj_razd; razdoblje++)
    {
        std::cout << razdoblje+1 << ". razdoblje" << std::endl;
        ispisPostupka.Append(wxString::Format(wxT("%d. razdoblje\n"),razdoblje+1));
        ispisPostupka.Append("----------------------------------------------------\n");
        f2.clear();
        gridOdluka->SetCellAlignment(wxALIGN_CENTRE,razdoblje,0);
        gridOdluka->SetCellBackgroundColour(wxColor(227,234,254),razdoblje,0);
        gridOdluka->SetCellValue(razdoblje,0,wxString::Format("%d",razdoblje+1));
        gridOdluka->SetCellAlignment(wxALIGN_CENTRE,razdoblje,3);
        gridOdluka->SetCellBackgroundColour(wxColor(187,218,247),razdoblje,3);
        gridOdluka->SetCellValue(razdoblje,3,wxString::Format("%.1lf",this->potraznja[razdoblje]));

        for(zalihe = 0.0,i=0; zalihe <= maxZal; zalihe += rata,i++)
        {
            potraznja = this->potraznja[razdoblje];
            nabavaMin = (zalihe+potraznja-maxZal<0.0?0.0:zalihe+potraznja-maxZal);
            nabavaMax = zalihe+potraznja>maxKol?maxKol:zalihe+potraznja;
            if(razdoblje>0)
            {
                f2.push_back(1.0e100);
                ispisPostupka.Append(wxString::Format("f(%d)[%.1lf] = min{\n",razdoblje+1,zalihe));
                for(nabava=nabavaMin; nabava<=nabavaMax; nabava+=rata)
                {
                    proslo = f[(int)((zalihe+potraznja-nabava) / rata+0.1)];
                    fc=(nabava>0.0?troskovi_nab:0.0)+zalihe*troskovi_skl + proslo;
                    std::cout << "f[" << zalihe << "] = [" << nabava << "," << zalihe << "] = " << fc << std::endl;
                    ispisPostupka.Append(wxString::Format("\tg(%d)[%.1lf,%.1lf] + f(%d)[%.1lf+%.1lf-%.1lf] = %.1lf + %.1lf*%.1lf + %.1lf = %.1lf\n",
                                                          razdoblje+1,nabava,zalihe,razdoblje,zalihe,potraznja,nabava,
                                                          (nabava>0.0?troskovi_nab:0.0),zalihe,troskovi_skl,proslo,
                                                          fc));
                    if(fc<=f2.back())
                    {
                        f2.pop_back();
                        f2.push_back(fc);
                        Q=nabava;
                    }
                }
                ispisPostupka.Append("\t}\n");
                ispisPostupka.Append(wxString::Format("f(%d)[%.1lf] = %.1lf, za Q(%d)=%.1lf\n",razdoblje+1,zalihe,f2.back(),razdoblje+1,Q));
                std::cout << "Minimum nabave: Q=" << Q << ", f=" << f2.back() << std::endl;
            }
            else
            {
                nabava=nabavaMax;
                fc=(nabava>0.0?troskovi_nab:0.0)+zalihe*troskovi_skl;
                std::cout << "f[" << zalihe << "] = [" << nabava << "," << zalihe << "] = " << fc << std::endl;
                ispisPostupka.Append(wxString::Format("f(%d)[%.1lf] = g(%d)[%.1lf,%.1lf] = %.1lf + %.1lf*%.1lf = %.1lf\n",
                                                      razdoblje+1,zalihe,razdoblje+1,nabava,zalihe,
                                                      (nabava>0.0?troskovi_nab:0.0),zalihe,troskovi_skl,
                                                      fc));
                f2.push_back(fc);
                Q=nabava;
            }
            gridRjesenje->SetCellAlignment(wxALIGN_CENTRE,i,razdoblje*2+1);
            gridRjesenje->SetCellBackgroundColour(wxColor(253,227,243),i,razdoblje*2+1);
            gridRjesenje->SetCellValue(i,razdoblje*2+1,wxString::Format("%.2lf",Q));
            gridRjesenje->SetCellAlignment(wxALIGN_CENTRE,i,razdoblje*2+2);
            gridRjesenje->SetCellBackgroundColour(wxColor(224,242,254),i,razdoblje*2+2);
            gridRjesenje->SetCellValue(i,razdoblje*2+2,wxString::Format("%.2lf",f2.back()));
            ispisPostupka.Append("\n");
        }
        f.clear();
        for(std::vector<double>::iterator it=f2.begin(); it!=f2.end(); ++it)
        {
            f.push_back(*it);
            std::cout << *it << " ";
        }
        ispisPostupka.Append("\n");
        std::cout << std::endl;
    }
    ispisPostupka.Append("====================================================\n\n");
    ispisPostupka.Append(wxT("Računanje tablice odluke:\n"));
    ispisPostupka.Append("----------------------------------------------------\n\n");
    troskovi_nab_sum=troskovi_skl_sum=0.0;
    for(razdoblje=broj_razd-1,zalihe=0.0; razdoblje >=0; razdoblje--)
    {
        gridOdluka->SetCellAlignment(wxALIGN_CENTRE,razdoblje,4);
        gridOdluka->SetCellBackgroundColour(wxColor(194,206,245),razdoblje,4);
        gridOdluka->SetCellValue(razdoblje,4,wxString::Format("%.1lf",zalihe));
        gridOdluka->SetCellAlignment(wxALIGN_CENTRE,razdoblje,6);
        gridOdluka->SetCellBackgroundColour(wxColor(207,199,235),razdoblje,6);
        gridOdluka->SetCellValue(razdoblje,6,wxString::Format("%.1lf",zalihe*troskovi_skl));
        troskovi_skl_sum+=zalihe*troskovi_skl;
        gridRjesenje->GetCellValue( (int)(zalihe/rata+0.1),razdoblje*2+1  ).ToDouble(&nabava);
        gridOdluka->SetCellAlignment(wxALIGN_CENTRE,razdoblje,2);
        gridOdluka->SetCellBackgroundColour(wxColor(199,241,252),razdoblje,2);
        gridOdluka->SetCellValue(razdoblje,2,gridRjesenje->GetCellValue( (int)(zalihe/rata+0.1),razdoblje*2+1  ));
        gridOdluka->SetCellAlignment(wxALIGN_CENTRE,razdoblje,5);
        gridOdluka->SetCellBackgroundColour(wxColor(199,252,228),razdoblje,5);
        if(nabava < 0.001)
            gridOdluka->SetCellValue(razdoblje,5,wxString::Format("%.1lf",0.0));
        else
        {
            gridOdluka->SetCellValue(razdoblje,5,wxString::Format("%.1lf",troskovi_nab));
            troskovi_nab_sum+=troskovi_nab;
        }
        ispisPostupka.Append(wxString::Format("I(%d)=%.1lf, Q(%d)[za I=%.1lf] = %s, I(%d) = %.1lf + %.1lf - %.1lf = %.1lf\n\tCp(%d) = %s, Ch(%d) = %.1lf * %.1lf = %.1lf\n",
                            razdoblje+1,zalihe,razdoblje+1,zalihe,gridRjesenje->GetCellValue( (int)(zalihe/rata+0.1),razdoblje*2+1  ),
                            razdoblje,zalihe,this->potraznja[razdoblje],nabava,zalihe+this->potraznja[razdoblje]-nabava,
                            razdoblje+1, gridOdluka->GetCellValue(razdoblje,5),razdoblje+1, zalihe, troskovi_skl, zalihe*troskovi_skl   ));
        zalihe=zalihe+this->potraznja[razdoblje]-nabava;
        gridOdluka->SetCellAlignment(wxALIGN_CENTRE,razdoblje,1);
        gridOdluka->SetCellBackgroundColour(wxColor(248,252,199),razdoblje,1);
        gridOdluka->SetCellValue(razdoblje,1,wxString::Format("%.1lf",zalihe));

    }
    gridOdluka->SetCellAlignment(wxALIGN_RIGHT,broj_razd,4);
    gridOdluka->SetCellFont(broj_razd,4,wxFont(9, wxFONTFAMILY_SWISS,
        wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    gridOdluka->SetCellValue(broj_razd,4,"Ukupno:");
    gridOdluka->SetCellAlignment(wxALIGN_CENTRE,broj_razd,5);
    gridOdluka->SetCellFont(broj_razd,5,wxFont(9, wxFONTFAMILY_SWISS,
        wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    gridOdluka->SetCellBackgroundColour(wxColor(199,252,228),broj_razd,5);
    gridOdluka->SetCellValue(broj_razd,5,wxString::Format("%.1lf",troskovi_nab_sum));

    gridOdluka->SetCellAlignment(wxALIGN_CENTRE,broj_razd,6);
    gridOdluka->SetCellFont(broj_razd,6,wxFont(9, wxFONTFAMILY_SWISS,
        wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    gridOdluka->SetCellBackgroundColour(wxColor(207,199,235),broj_razd,6);
    gridOdluka->SetCellValue(broj_razd,6,wxString::Format("%.1lf",troskovi_skl_sum));

    ispisPostupka.Append(wxString::Format("Cp = %.1lf, Cf = %.1lf\n",troskovi_nab_sum, troskovi_skl_sum));

    gridOdluka->SetCellAlignment(wxALIGN_RIGHT,broj_razd+1,4);
    gridOdluka->SetCellFont(broj_razd+1,4,wxFont(9, wxFONTFAMILY_SWISS,
        wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    gridOdluka->SetCellTextColour(wxColor(240,0,0),broj_razd+1,4);
    gridOdluka->SetCellValue(broj_razd+1,4,"Sveukupno:");
    gridOdluka->SetCellAlignment(wxALIGN_CENTRE,broj_razd+1,5);
    gridOdluka->SetCellBackgroundColour(wxColor(240,0,0),broj_razd+1,5);
    gridOdluka->SetCellTextColour(wxColor(240,240,0),broj_razd+1,5);
    gridOdluka->SetCellValue(broj_razd+1,5,wxString::Format("%.1lf",troskovi_nab_sum+troskovi_skl_sum));

    ispisPostupka.Append(wxString::Format("Cp + Cf = %.1lf\n",troskovi_nab_sum + troskovi_skl_sum));
}

void DinamickoFrame::OtvoriDijalogIspisa( wxCommandEvent& event )
{
    DijalogIspisa dlg(this, ispisPostupka);
    dlg.ShowModal();
}

void DinamickoFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void DinamickoFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void DinamickoFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void DinamickoFrame::PromijeniBrojRazdoblja(bool init)
{
    long int i, nr;
    if(!txtBrojRazd->GetValue().ToLong(&broj_razd)||broj_razd<1||init)
    {
        broj_razd = 3;
        txtBrojRazd->SetValue("3");
    }
    if(init)
    {
        gridPotraznja->SetCellValue(0,0,"40");
        gridPotraznja->SetCellValue(1,0,"20");
        gridPotraznja->SetCellValue(2,0,"30");
    }
    nr = gridPotraznja->GetNumberRows();
    if(broj_razd>nr)
    {
        gridPotraznja->InsertRows(nr,broj_razd-nr);
        gridPotraznja->SetCellValue(broj_razd-1,0,gridPotraznja->GetCellValue(broj_razd-2,0));
    }

    if(nr>broj_razd)
        gridPotraznja->DeleteRows(broj_razd,nr-broj_razd);
    if(broj_razd<6)
        gridPotraznja->SetSize(200,20*broj_razd+20);
    else
        gridPotraznja->SetSize(200,120);
    for(i=0; i < broj_razd; i++)
    {
        gridPotraznja->SetCellBackgroundColour(wxColor(187,218,247),i,0);
        gridPotraznja->SetRowLabelValue(i,wxString::Format(wxT("Razdoblje %d"),i+1));
        gridPotraznja->SetCellAlignment(i,0,wxALIGN_RIGHT,wxALIGN_CENTRE);
    }
}

void DinamickoFrame::AzurirajParametre()
{
    if(!txtBrojRazd->GetValue().ToLong(&broj_razd)||broj_razd<1)
    {
        broj_razd = 3;
        txtBrojRazd->SetValue("3");
    }
    if(!txtRata->GetValue().ToDouble(&rata)||rata<=0.0)
    {
        rata=10.0;
        txtRata->SetValue("10");
    }
    if(!txtMaxKol->GetValue().ToDouble(&maxKol)||maxKol<=0.0)
    {
        maxKol=70.0;
        txtMaxKol->SetValue("70");
    }
    if(!txtTrosSkl->GetValue().ToDouble(&troskovi_skl)||troskovi_skl<=0.0)
    {
        troskovi_skl=5.0;
        txtTrosSkl->SetValue("5");
    }
    if(!txtMaxZal->GetValue().ToDouble(&maxZal)||maxZal<=0.0)
    {
        maxZal=30.0;
        txtMaxZal->SetValue("30");
    }
    if(!txtTrosNab->GetValue().ToDouble(&troskovi_nab)||troskovi_nab<=0.0)
    {
        troskovi_nab=800.0;
        txtTrosNab->SetValue("800");
    }
}

/* DIJALOG */
DijalogIspisa::DijalogIspisa( wxWindow* parent, wxString& ispis) : dlgIspisRacunanja(parent)
{
    if(ispis.empty())
        txtIspis->SetValue(wxT("Nema zabilježenog postupka rješavanja."));
    else
        txtIspis->SetValue(ispis);
}
void DijalogIspisa::Zatvori( wxCommandEvent& event )
{
    Destroy();
}
