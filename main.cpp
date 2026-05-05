#include "gui.h"


bool MyApp::OnInit() {
    Fenetre* fenetre = new Fenetre(wxT("Jeu de la Vie - Automate de Conway"));
    fenetre->Show(true);
    return true;
}

// C'est cette ligne qui génère automatiquement le main
wxIMPLEMENT_APP(MyApp);

 