#pragma once
#include<iostream>
#include<string>
using namespace std;
class Titre
{ 
private:
	int idsong;
	string nom;
	string artist;
	int duree;
	static int compteur;

public:
	Titre();
	Titre(string nom, string artist, int duree);
	string getNom() const;
	string getArtiste() const;
	int getduree() const;
	int getidsong() const;
    void afficher() const;
	
};

