//
// Created by vanba on 01/10/2025.
//

#include "Grille.hpp"
#include <ostream>
#include <vector>

// constructeurs
// par defaut
Grille::Grille()
{
    // 15x15, vide, non torique
    this->width = 15;
    this->height = 15;
    this->isToreidal = false;

    this->grille = new int *[width];

    for (int i = 0; i < width; i++)
    {
        grille[i] = new int[height];
        for (int j = 0; j < height; j++)
        {
            grille[i][j] = 0;
        }
    }
}

Grille::Grille(const int width, const int height, const int choix, const bool isToreidal)
{
    srand(time(0));
    this->width = width;
    this->height = height;
    this->isToreidal = isToreidal;
    this->grille = new int *[width];

    if (choix == 1)
    {
        // Tableau vide
        for (int i = 0; i < width; i++)
        {
            grille[i] = new int[height];
            for (int j = 0; j < height; j++)
            {
                grille[i][j] = 0;
            }
        }
    }
    else if (choix == 2)
    {
        // tableau plein
        for (int i = 0; i < width; i++)
        {
            grille[i] = new int[height];
            for (int j = 0; j < height; j++)
            {
                grille[i][j] = 1;
            }
        }
    }
    else if (choix == 3)
    {
        // damier
        for (int i = 0; i < width; i++)
        {
            grille[i] = new int[height];
            for (int j = 0; j < width; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    grille[i][j] = 1;
                }
                else
                {
                    grille[i][j] = 0;
                }
            }
        }
    }
    else if (choix == 4)
    {
        // random
        for (int i = 0; i < width; i++)
        {
            grille[i] = new int[height];
            for (int j = 0; j < height; j++)
            {
                grille[i][j] = rand() % 2;
            }
        }
    }
}

// avec paramètre
Grille::Grille(const int width, const int height, const bool isToreidal)
{
    this->width = width;
    this->height = height;
    this->isToreidal = isToreidal;

    this->grille = new int *[width];

    for (int i = 0; i < width; i++)
    {
        grille[i] = new int[height];
        for (int j = 0; j < height; j++)
        {
            grille[i][j] = 0;
        }
    }
}

// par recopie
Grille::Grille(const Grille &autre)
{
    this->width = autre.width;
    this->height = autre.height;
    this->isToreidal = autre.isToreidal;

    this->grille = new int *[width];
    for (int i = 0; i < width; i++)
    {
        grille[i] = new int[height];
        for (int j = 0; j < height; j++)
        {
            grille[i][j] = autre.grille[i][j];
        }
    }
}

Grille Grille::iteration(const Grille &grilleInitiale)
{
    Grille grilleVoisins;
    const int initialwidth = grilleInitiale.width;
    const int initialheight = grilleInitiale.height;
    grilleVoisins.width = initialwidth;
    grilleVoisins.height = initialheight;
    grilleVoisins.isToreidal = grilleInitiale.isToreidal;

    int count;
    if (grilleInitiale.isToreidal)
    {
        for (int i = 0; i < initialwidth; i++)
        {
            grilleVoisins.grille[i] = new int[initialheight];
            for (int j = 0; j < initialheight; j++)
            {
                count = 0;

                for (int k = -1; k < 2; ++k)
                {
                    for (int l = -1; l < 2; ++l)
                    {
                        int w = i;
                        int h = j;
                        if (j + k < 0)
                        {
                            h = initialheight;
                        }
                        if (j + k == initialheight)
                        {
                            h = -1;
                        }
                        if (i + l < 0)
                        {
                            w = initialwidth;
                        }
                        if (i + l == initialwidth)
                        {
                            w = -1;
                        }
                        if (l == 0 && k == 0)
                        {
                            continue;
                        }
                        count += grilleInitiale.grille[w + l][h + k];
                    }
                }
                grilleVoisins.grille[i][j] = count;
            }
        }
    }
    else
    {
        for (int i = 0; i < initialwidth; i++)
        {
            grilleVoisins.grille[i] = new int[initialheight];
            for (int j = 0; j < initialheight; j++)
            {
                count = 0;
                if (i - 1 >= 0)
                {
                    count += grilleInitiale.grille[i - 1][j];
                    if (j - 1 >= 0)
                    {
                        count += grilleInitiale.grille[i - 1][j - 1];
                    }
                    if (j + 1 < initialheight)
                    {
                        count += grilleInitiale.grille[i - 1][j + 1];
                    }
                }
                if (j - 1 >= 0)
                {
                    count += grilleInitiale.grille[i][j - 1];
                    if (i + 1 < initialwidth)
                    {
                        count += grilleInitiale.grille[i + 1][j - 1];
                    }
                }
                if (i + 1 < initialwidth)
                {
                    count += grilleInitiale.grille[i + 1][j];
                    if (j + 1 < initialheight)
                    {
                        count += grilleInitiale.grille[i + 1][j + 1];
                    }
                }
                if (j + 1 < initialheight)
                {
                    count += grilleInitiale.grille[i][j + 1];
                }

                grilleVoisins.grille[i][j] = count;
            }
        }
    }

    Grille nouvelleGrille;
    nouvelleGrille.width = initialwidth;
    nouvelleGrille.height = initialheight;
    nouvelleGrille.isToreidal = grilleInitiale.isToreidal;
    for (int i = 0; i < initialwidth; i++)
    {
        nouvelleGrille.grille[i] = new int[initialheight];
        for (int j = 0; j < initialheight; j++)
        {
            // si cellule vivante et 2 ou 3 voisins
            if (grilleInitiale.grille[i][j] == 1 && grilleVoisins.grille[i][j] == 2)
            {
                nouvelleGrille.grille[i][j] = 1;
            }
            else if (grilleInitiale.grille[i][j] == 1 && grilleVoisins.grille[i][j] == 3)
            {
                nouvelleGrille.grille[i][j] = 1;
            }
            // si cellule morte et 3 voisins
            else if (grilleInitiale.grille[i][j] == 0 && grilleVoisins.grille[i][j] == 3)
            {
                nouvelleGrille.grille[i][j] = 1;
            }
            else
            {
                nouvelleGrille.grille[i][j] = 0;
            }
        }
    }
    // return nouvelleGrille;
    return nouvelleGrille;
}

// réaliser un nombre n d'itérations
Grille Grille::iterations(Grille &grilleInitiale, const int nbrOfIteration)
{
    Grille grilleUtilisable = grilleInitiale;
    Grille nouvelleGrille = grilleInitiale;
    for (int x = 0; x < nbrOfIteration; ++x)
    {
        nouvelleGrille = iteration(grilleUtilisable);
        grilleUtilisable = nouvelleGrille;
    }

    return nouvelleGrille;
}

// destructeur
Grille::~Grille()
{
    for (int i = 0; i < this->width; i++)
        delete[] grille[i];
    delete[] grille;
}

// opérateurs
// de flot
std::ostream &operator<<(std::ostream &sortie, Grille &g)
{
    sortie << "dimension : " << g.width << " x " << g.height << "\n";

    for (int i = 0; i < g.width; ++i)
    {
        for (int j = 0; j < g.height; ++j)
        {
            sortie << g.grille[i][j] << " ";
        }
        sortie << "\n";
    }
    return sortie;
}
