#include "Jeu.h"
#include <iostream>
#include <thread>
#include <chrono>

Jeu::Jeu(int m, int n, int attente) : _m(m), _n(n), _grille(m, n), _tempsAttente(attente) {}

void Jeu::AjouteCellule(int i, int j) {
    _grille.AjouteCellule(i, j);
}

void Jeu::SupprimeCellule(int i, int j) {
    _grille.SupprimeCellule(i, j);
}

void Jeu::Affiche() const {
    std::cout << "\033[2J\033[1;1H"; 
    _grille.Affiche();
    std::cout << "----------------------" << std::endl;
}

void Jeu::Avance() {
    Grille nouvelleGrille(_m, _n);
    
    for (int i = 0; i < _m; i++) {
        for (int j = 0; j < _n; j++) {
            int voisins = _grille.NbVoisins(i, j);
            bool occupee = _grille.EstOccupee(i, j);
            
            if (occupee && (voisins == 2 || voisins == 3)) {
                nouvelleGrille.AjouteCellule(i, j);
            } else if (!occupee && voisins == 3) {
                nouvelleGrille.AjouteCellule(i, j);
            }
        }
    }
    _grille = nouvelleGrille;
}

void Jeu::Lance() {
    while (true) {
        Affiche();
        Avance();
        std::this_thread::sleep_for(std::chrono::milliseconds(_tempsAttente));
    }
}
bool Jeu::EstOccupee(int i, int j) const { 
    return _grille.EstOccupee(i, j); 
}
int Jeu::getM() const { return _m; }
int Jeu::getN() const { return _n; }