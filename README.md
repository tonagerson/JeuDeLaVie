# Jeu de la Vie de Conway (Automate Cellulaire en C++)

Implémentation en **C++** de l'automate cellulaire de John Conway avec une interface graphique interactive développée sous **wxWidgets**.

Projet réalisé dans le cadre de la Licence Mathématiques-Informatique (Université Grenoble Alpes).

---

## Fonctionnalités

- **Moteur de simulation :** Gestion dynamique de l'état des cellules (vivante/morte) selon les règles classiques de transition de Conway :
  - Survie : une cellule vivante avec 2 ou 3 voisines vivantes reste en vie.
  - Naissance : une cellule morte avec exactement 3 voisines vivantes devient vivante.
  - Mort : par sous-population (< 2) ou surpopulation (> 3).
- **Interface graphique (GUI) :** Rendu de la grille et commandes interactives via **wxWidgets** (`gui.cpp` / `gui.h`).
- **Architecture modulaire :** Découplage strict entre la grille (`Grille.cpp`), les règles d'évolution (`Jeu.cpp`) et la couche graphique.

---

## Technologies

- **Langage :** C++
- **Bibliothèque graphique :** wxWidgets
- **Build :** Makefile

---

## Compilation et exécution

```bash
# Compilation
make

# Lancement de l'application
./test
