
#pragma once
#include <iostream>
#include <string>
#include "Titre.h"

using namespace std;

class Playlist
{
private:
    const int id;
    string playlist;
    Titre* Titres;  // Pointeur vers un tableau de Titre
    int capacite;
    int dureeTotal;
    int nbrSong;

    static int compteur;
    static int nbrplaylist;
    static int nbrTotalSong;

public:
    Playlist(string t, int c);
    void ajouterTitre(string nom, string artist, int duree);
    void supprimerTitre(int numero);
    void agrandir(int supplement);
    void trierParDuree();

    int compterParArtiste(string artist) const;
    int trouverIndexPlusLong() const;
    int calculerDureeTotale() const;
    void afficher() const;

    static int getNbrPlaylist();
    static int getNbrTotalSong();
    string getNomPlaylist() const {
        return playlist;
    }

    ~Playlist();
};
