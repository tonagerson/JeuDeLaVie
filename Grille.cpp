#include "Grille.h"
#include <iostream>

Grille::Grille(int lignes, int colonnes) : m(lignes), n(colonnes) {
    grille.resize(m, std::vector<bool>(n, false));
}

void Grille::AjouteCellule(int i, int j) {
    if (i >= 0 && i < m && j >= 0 && j < n) {
        grille[i][j] = true;
    }
}

void Grille::SupprimeCellule(int i, int j) {
    if (i >= 0 && i < m && j >= 0 && j < n) {
        grille[i][j] = false;
    }
}

void Grille::Affiche() const {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grille[i][j]) {
                std::cout << "O ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

bool Grille::EstOccupee(int i, int j) const {
    if (i >= 0 && i < m && j >= 0 && j < n) {
        return grille[i][j];
    }
    return false;
}

int Grille::NbVoisins(int i, int j) const {
    int voisins = 0;
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            if (x == 0 && y == 0) continue;
            int ni = i + x;
            int nj = j + y;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                if (grille[ni][nj]) {
                    voisins++;
                }
            }
        }
    }
    return voisins;
}