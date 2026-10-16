#include "Titre.h"
int Titre::compteur = 1;
Titre::Titre()
	: idsong(0), nom(""), artist(""), duree(0)
{
}
Titre::Titre(string nom, string artist, int duree):
	idsong(compteur++)
{
	this->nom = nom;
	this->artist = artist;
	this->duree = duree;
}

string Titre::getNom() const { return nom; }
string Titre::getArtiste() const { return artist; }
int Titre::getduree() const { return duree; }

int Titre::getidsong() const
{
	return idsong;
}
void Titre::afficher() const
{
	cout << "ID : " << idsong << endl;
	cout << "Nom : " << nom << endl;
	cout << "Artiste : " << artist << endl;
	cout << "Duree : " << duree << " secondes" << endl;
}

