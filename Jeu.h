#ifndef JEU_H
#define JEU_H

#include "Grille.h"

class Jeu {
private:
    int _m;
    int _n;
    Grille _grille;
    int _tempsAttente;

public:
    Jeu(int m, int n, int attente);
    void AjouteCellule(int i, int j);
    void SupprimeCellule(int i, int j);
    void Affiche() const;
    void Avance();
    void Lance();
    bool EstOccupee(int i, int j) const;
    int getM() const;
    int getN() const;
};

#endif