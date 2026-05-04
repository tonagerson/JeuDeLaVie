#include "gui.h"

// Les identifiants uniques pour nos éléments
enum {
    ID_START = 101,
    ID_STOP = 102,
    ID_CLEAR = 103,
    ID_TIMER = 104,
     ID_GLISSEUR = 105,
};

// La fameuse table des événements pour relier les clics aux fonctions
wxBEGIN_EVENT_TABLE(Fenetre, wxFrame)
    EVT_PAINT(Fenetre::OnPaint)
    EVT_TIMER(ID_TIMER, Fenetre::OnTimer)
    EVT_BUTTON(ID_START, Fenetre::OnStart)
    EVT_BUTTON(ID_STOP, Fenetre::OnStop)
    EVT_BUTTON(ID_CLEAR, Fenetre::OnClear)
      EVT_BUTTON(ID_GLISSEUR, Fenetre::OnGlisseur)
    EVT_LEFT_DOWN(Fenetre::OnMouseClick) // Clic gauche de la souris
wxEND_EVENT_TABLE()

// Constructeur de la fenêtre
Fenetre::Fenetre(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(550, 650)),
      monJeu(20, 20, 200), // On garde une grille de 20x20
      tailleCellule(25)    // Chaque cellule fera 25x25 pixels
{
    // Placement manuel des boutons en bas de la fenêtre
    btnStart = new wxButton(this, ID_START, wxT("Start"), wxPoint(20, 550));
    btnStop  = new wxButton(this, ID_STOP, wxT("Stop"), wxPoint(150, 550));
    btnClear = new wxButton(this, ID_CLEAR, wxT("Clear"), wxPoint(280, 550));
        btnGlisseur = new wxButton(this, ID_GLISSEUR, wxT("Glisseur"), wxPoint(410, 550));

    timer = new wxTimer(this, ID_TIMER);

    // On met un petit planeur par défaut pour tester
    
}

// Méthode de dessin (appelée automatiquement)
void Fenetre::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);

    for (int i = 0; i < monJeu.getM(); i++) {
        for (int j = 0; j < monJeu.getN(); j++) {
            int x = j * tailleCellule + 20; // Décalage pour la marge
            int y = i * tailleCellule + 20;

            // 1. Dessiner le contour de la case
            dc.SetBrush(*wxWHITE_BRUSH);
            dc.SetPen(*wxLIGHT_GREY_PEN);
            dc.DrawRectangle(x, y, tailleCellule, tailleCellule);

            // 2. Si la case est occupée, on dessine un disque !
            if (monJeu.EstOccupee(i, j)) {
                dc.SetBrush(*wxBLUE_BRUSH);
                dc.DrawCircle(x + tailleCellule/2, y + tailleCellule/2, tailleCellule/2 - 2);
            }
        }
    }
}

// Action du Timer (à chaque tic)
void Fenetre::OnTimer(wxTimerEvent& event) {
    monJeu.Avance();
    Refresh(); // Force la fenêtre à se redessiner
}

void Fenetre::OnStart(wxCommandEvent& event) { timer->Start(200); /* 200 ms */ }
void Fenetre::OnStop(wxCommandEvent& event) { timer->Stop(); }
void Fenetre::OnClear(wxCommandEvent& event) {
    for (int i = 0; i < monJeu.getM(); i++) {
        for (int j = 0; j < monJeu.getN(); j++) {
            monJeu.SupprimeCellule(i, j);
        }
    }
    Refresh(); // On met à jour l'écran
}

// Interaction au clic de souris (Ajout/Suppression à la volée)
void Fenetre::OnMouseClick(wxMouseEvent& event) {
    int x = event.GetX();
    int y = event.GetY();

    // On convertit les pixels (x,y) en indices de matrice (i,j)
    int j = (x - 20) / tailleCellule;
    int i = (y - 20) / tailleCellule;

    // Si on a bien cliqué dans la grille
    if (i >= 0 && i < monJeu.getM() && j >= 0 && j < monJeu.getN()) {
        if (monJeu.EstOccupee(i, j)) monJeu.SupprimeCellule(i, j);
        else monJeu.AjouteCellule(i, j);
        Refresh();
    }
}
void Fenetre::OnGlisseur(wxCommandEvent& event) {
    // 1. On arrête le temps si le jeu tournait
    timer->Stop();
    
    // 2. On vide toute la grille
    for (int i = 0; i < monJeu.getM(); i++) {
        for (int j = 0; j < monJeu.getN(); j++) {
            monJeu.SupprimeCellule(i, j);
        }
    }
    
    // 3. On dessine la structure du Glisseur demandée dans le TP
    monJeu.AjouteCellule(0, 1);
    monJeu.AjouteCellule(1, 2);
    monJeu.AjouteCellule(2, 0);
    monJeu.AjouteCellule(2, 1);
    monJeu.AjouteCellule(2, 2);

    // 4. On rafraîchit l'écran pour afficher notre dessin
    Refresh(); 
}

