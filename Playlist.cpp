#include "Playlist.h"
#include "Titre.h"

int Playlist::compteur=0;
int Playlist::nbrplaylist=0;
int Playlist::nbrTotalSong=0;

Playlist::Playlist(string t, int c)
	:id(++compteur) , dureeTotal(0), nbrSong(0)
{
	this->playlist = t;
	this->capacite = c;
	this->Titres = new Titre[this->capacite];
	nbrplaylist++;
}

void Playlist::ajouterTitre(string nom, string artist, int duree)
{
	if (nom.empty() || artist.empty() || duree <= 0) {
		cout << "Titre invalide." << endl;
		return;
	}

	if (nbrSong >= capacite) {
		cout << "Playlist pleine." << endl;
		return;
	}

	Titres[nbrSong] = Titre(nom, artist, duree);
	nbrSong++;
	nbrTotalSong++;
	dureeTotal += duree;
}

void Playlist::supprimerTitre(int numero)
{
	if (numero < 1 || numero > nbrSong) {
		cout << "Numero de titre invalide." << endl;
		return;
	}

	int index = numero - 1;
	dureeTotal -= Titres[index].getduree();

	for (int j = index; j < nbrSong - 1; j++) {
		Titres[j] = Titres[j + 1];
	}

	nbrSong--;
	nbrTotalSong--;
}

void Playlist::agrandir(int supplement)
{
	if (supplement <= 0) {
		cout << "impossible";
		return;
	}
	Titre *nouveau = new Titre[capacite + supplement];//creer une nouveau tableau 
	for (int i = 0; i <nbrSong; ++i)
		nouveau[i] = Titres[i];
	delete[] Titres;                      // libérer l'ancien tableau
	Titres = nouveau;
	capacite += supplement;
	cout << "Nouvelle capacite : " << capacite << endl;
}

void Playlist::trierParDuree()
{
	int min;
	for (int i = 0;i < nbrSong;i++) {
		min = i;
		for (int j = i+1;j < nbrSong ;j++) {
			if (Titres[j].getduree() < Titres[min].getduree()) {
				min = j;
            }

		}  if (min != i) {
			Titre temp = Titres[i];
			Titres[i] = Titres[min];
			Titres[min] = temp;
		}
	}
}

int Playlist::trouverIndexPlusLong() const
{
	if (nbrSong == 0) {
		return -1;
	}
	int max = 0;

	for (int i = 1; i < nbrSong; i++) {
		if (Titres[i].getduree() > Titres[max].getduree()) {
			max = i;
		}
	}

	return max;
}

int Playlist::calculerDureeTotale() const
{
	int total = 0;
	for (int i = 0;i < nbrSong;i++) {
		total += Titres[i].getduree();
	}
	return total;
}


void Playlist::afficher() const
{
	cout << "\n========================================" << endl;
	cout << "           PLAYLIST : " << playlist << endl;
	cout << "========================================" << endl;

	cout << "ID playlist       : " << id << endl;
	cout << "Capacite          : " << capacite << endl;
	cout << "Nombre de titres  : " << nbrSong << endl;
	cout << "----------------------------------------" << endl;

	if (nbrSong == 0) {
		cout << "La playlist est vide." << endl;
	}
	else {
		for (int i = 0; i < nbrSong; i++) {
			cout << "\nTitre numero " << i + 1 << endl;
			cout << "ID      : " << Titres[i].getidsong() << endl;
			cout << "Nom     : " << Titres[i].getNom() << endl;
			cout << "Artiste : " << Titres[i].getArtiste() << endl;
			cout << "Duree   : " << Titres[i].getduree()
				<< " secondes" << endl;
		}
	}

	cout << "\n----------------------------------------" << endl;
	cout << "Duree totale : " << calculerDureeTotale()
		<< " secondes" << endl;
	cout << "========================================" << endl;
}


int Playlist::compterParArtiste(string artist) const 
{
	int nbr = 0;
	for (int i = 0;i < nbrSong;i++) {
		if (Titres[i].getArtiste() == artist) {
			nbr++;
		}
	}
	return nbr;
}

int Playlist::getNbrPlaylist()
{
	return nbrplaylist;
}

int Playlist::getNbrTotalSong()
{
	return nbrTotalSong;
}

Playlist::~Playlist()
{
	delete[] Titres;

	nbrplaylist--;
	nbrTotalSong -= nbrSong;
}

		










