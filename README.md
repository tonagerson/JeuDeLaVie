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
## Apercu
<img width="960" height="540" alt="Démo1" src="https://github.com/user-attachments/assets/37a20ddb-b1d3-49f2-95c3-6b912355cb3d" />

<img width="960" height="540" alt="choix Aléatoire1" src="https://github.com/user-attachments/assets/86de2736-9388-4316-911b-fe264eacf877" />

<img width="960" height="540" alt="Evolution" src="https://github.com/user-attachments/assets/c6dcc152-3cb4-47e2-9250-283d5aebe566" />

<img width="960" height="540" alt="Fin d&#39;évolution" src="https://github.com/user-attachments/assets/78f89fe6-5780-49e8-bcb2-9d17becfd256" />

<img width="960" height="540" alt="Choix cliqué" src="https://github.com/user-attachments/assets/a50f0a50-6e87-448e-a4d2-a874acd54838" />

<img width="960" height="540" alt="Fin d&#39;évolution (2)" src="https://github.com/user-attachments/assets/c7d6c7b4-78c6-45ae-85fb-71c4d44005b5" />





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
