//
// Created by vanba on 01/10/2025.
//

#ifndef TP1_GRILLE_HPP
#define TP1_GRILLE_HPP

#include <iostream>


class Grille {
private:
    //attributs


public:
    int width, height;
    bool isToreidal;
    int **grille;
    //Méthods
    //constructeurs
    Grille();
    Grille(int width, int height, int choix, bool isToreidal);
    Grille(int width, int height, bool isToreidal);
    Grille(const Grille &autre);

    //destructeur
    ~Grille();

    //methodes
    static Grille iteration(const Grille &grilleInitiale);
    static Grille iterations(Grille &grilleInitiale, int nbrOfIteration);

    //friend
    friend std::ostream &operator<<(std::ostream &sortie, Grille &g);
};

#endif //TP1_GRILLE_HPP
