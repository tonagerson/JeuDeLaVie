#ifndef GRILLE_H
#define GRILLE_H

#include <vector>

class Grille {
private:
    int m;
    int n;
    std::vector<std::vector<bool>> grille;

public:
    Grille(int lignes, int colonnes);
    void AjouteCellule(int i, int j);
    void SupprimeCellule(int i, int j);
    void Affiche() const;
    bool EstOccupee(int i, int j) const;
    int NbVoisins(int i, int j) const;
};

#endif