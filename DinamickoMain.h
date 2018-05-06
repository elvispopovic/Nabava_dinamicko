/***************************************************************
 * Name:      DinamickoMain.h
 * Purpose:   Defines Application Frame
 * Author:    Elvis Popović (elvpopovi@foi.hr)
 * Created:   2018-05-05
 * Copyright: Elvis Popović ()
 * License:
 **************************************************************/

#ifndef DINAMICKOMAIN_H
#define DINAMICKOMAIN_H



#include "DinamickoApp.h"


#include "GUIFrame.h"

class DinamickoFrame: public GUIFrame
{
    public:
        DinamickoFrame(wxFrame *frame);
        ~DinamickoFrame();
    protected:
        virtual void Init();
        virtual void ParamPromijenjen( wxCommandEvent& event );
        virtual void GridPotraznjaPromijenjena( wxGridEvent& event );
        virtual void Izracunaj( wxCommandEvent& event );
        virtual void OtvoriDijalogIspisa( wxCommandEvent& event );
    private:
        long broj_razd;
        double rata, maxKol, troskovi_skl, maxZal, troskovi_nab;
        std::vector<double> potraznja;
        wxString ispisPostupka;
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void PromijeniBrojRazdoblja(bool init=false);
        virtual void AzurirajParametre();
        virtual void GridRjesenjaPrilagodi();
};

class DijalogIspisa : public dlgIspisRacunanja
{
	public:
	    DijalogIspisa( wxWindow* parent, wxString& ispis);
		~DijalogIspisa(){};
	private:

	protected:
		void Zatvori( wxCommandEvent& event );

};

#endif // DINAMICKOMAIN_H
