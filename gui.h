#ifndef GUI_H
#define GUI_H

#include <wx/wx.h>
#include "Jeu.h"

// La fenêtre principale
class Fenetre : public wxFrame {
private:
    Jeu monJeu;           // Notre moteur de jeu
    wxTimer* timer;       // L'horloge qui remplace le sleep_for
    int tailleCellule;    // Taille d'une case en pixels

    // Nos 3 boutons demandés par l'énoncé
    wxButton* btnStart;
    wxButton* btnStop;
    wxButton* btnClear;
    wxButton* btnGlisseur; 

public:
    Fenetre(const wxString& title);

    // Les méthodes Callbacks (qui réagissent aux événements)
    void OnPaint(wxPaintEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnStart(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);
    void OnMouseClick(wxMouseEvent& event);
    void OnGlisseur(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE(); // Déclaration de la table des événements
};

// Le moteur de l'application wxWidgets
class MyApp : public wxApp {
public:
    bool OnInit() override;
};

#endif