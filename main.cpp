//
// Created by vanba on 01/10/2025.
//

#include "Grille.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout <<"########## Le Jeu de la Vie ##########\n\n";


    std::cout <<"Veuillez saisir les dimensions de votre tableau !\n";
    std::cout <<"\tlargeur -> ";
    int width;
    std::cin >> width;
    std::cout <<"\tlongeur -> ";
    int height;
    std::cin >> height;
    std::cout <<"Le jeu se deroulera-t-il sur un tore ?\n";
    std::cout <<"\t1. oui\n"
                "\t2. non\n"
                "\n-->";
    bool isToreidal;
    int Toreidal;
    std::cin >>Toreidal;
    (Toreidal == 1) ? isToreidal = true : isToreidal = false;
    std::cout <<"Comment souhaitez vous initialiser votre tableau ?\n";
    std::cout <<"\t1. vide\n"
                "\t2. plein\n"
                "\t3. a damier\n"
                "\t4. aleatoirement\n"
                "\t5. ----(importer un fichier)----\n"
                "\n-->";
    int choix;
    std::cin >>choix;
    Grille grille(width, height, choix, isToreidal);
    std::cout <<"\n" << grille <<"\n";
    std::cout <<"Combien d'iterations voulez vous appliquez ?\n"
                "\n-->";
    int nbrOfIteration;
    std::cin >>nbrOfIteration;
    Grille grilleApresIterations = Grille::iterations(grille, nbrOfIteration);
    std::cout <<"Grille apres " << nbrOfIteration << " iterations :";
    std::cout <<"\n" << grilleApresIterations;
}