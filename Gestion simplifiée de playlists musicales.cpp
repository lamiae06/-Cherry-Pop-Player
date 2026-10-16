
#define NOMINMAX
#include <iostream>
#include <string>
#include <limits>
#include <windows.h>
#include "Titre.h"
#include "Playlist.h"

using namespace std;

// Couleurs de la console Windows
void couleur(int code)
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE), code
    );
}

// Choisir une playlist existante
Playlist* choisirPlaylist(Playlist* playlists[], int nbrPlaylists)
{
    if (nbrPlaylists == 0) {
        cout << "Aucune playlist. Creez d'abord une playlist."
            << endl;
        return nullptr;
    }

    couleur(13);
    cout << "\n===== CHOISIR UNE PLAYLIST =====" << endl;
    couleur(7);

    for (int i = 0; i < nbrPlaylists; i++) {
        cout << i + 1 << ". "
            << playlists[i]->getNomPlaylist() << endl;
    }

    int choix;
    cout << "Votre choix : ";

    if (!(cin >> choix)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Saisie invalide." << endl;
        return nullptr;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choix < 1 || choix > nbrPlaylists) {
        cout << "Choix invalide." << endl;
        return nullptr;
    }

    return playlists[choix - 1];
}

int main()
{
    // Configuration UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int MAX_PLAYLISTS = 10;

    Playlist* playlists[MAX_PLAYLISTS] = { nullptr };
    int nbrPlaylists = 0;

    string nomPlaylist, nom, artiste;
    int capacite, choix = -1, numero, duree, supplement;

    // Creation de la premiere playlist
    couleur(13);
    cout << "\n===== CREATION DE LA PREMIERE PLAYLIST ====="
        << endl;
    couleur(7);

    cout << "Nom de votre playlist (ex: My Pink Mixtape) : ";
    getline(cin, nomPlaylist);

    while (nomPlaylist.empty()) {
        cout << "Le nom ne peut pas etre vide. Reessayez : ";
        getline(cin, nomPlaylist);
    }

    cout << "Capacite initiale (ex: 5) : ";

    while (!(cin >> capacite) || capacite <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrez une capacite positive : ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    playlists[nbrPlaylists] = new Playlist(nomPlaylist, capacite);
    nbrPlaylists++;

    couleur(10);
    cout << "Premiere playlist creee avec succes !" << endl;
    couleur(7);

    // Menu principal
    do {
        couleur(13);
        cout << "\n";
        cout << "╔══════════════════════════════════════╗" << endl;
        cout << "║       ♡ CHERRY POP PLAYER ♡          ║" << endl;
        cout << "║        votre mixtape 90s 🎧          ║" << endl;
        cout << "╠══════════════════════════════════════╣" << endl;
        couleur(11);
        cout << "║  1. ♡ Ajouter un titre               ║" << endl;
        cout << "║  2. ♡ Supprimer un titre             ║" << endl;
        cout << "║  3. ♡ Afficher une playlist          ║" << endl;
        cout << "║  4. ♡ Agrandir une playlist          ║" << endl;
        cout << "║  5. ♡ Trier par duree                ║" << endl;
        cout << "║  6. ♡ Consulter les statistiques     ║" << endl;
        cout << "║  7. ♡ Compteurs globaux              ║" << endl;
        cout << "║  8. ♡ Creer une playlist             ║" << endl;
        cout << "║  0. ♡ Quitter                        ║" << endl;
        couleur(13);
        cout << "╚══════════════════════════════════════╝" << endl;
        cout << "♡ Votre choix : ";
        couleur(7);

        if (!(cin >> choix)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            couleur(12);
            cout << "Erreur : entrez un nombre entre 0 et 8."
                << endl;
            couleur(7);
            choix = -1;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choix) {

        case 1: {
            Playlist* p = choisirPlaylist(playlists, nbrPlaylists);

            if (p != nullptr) {
                cout << "Nom du titre : ";
                getline(cin, nom);

                cout << "Nom de l'artiste : ";
                getline(cin, artiste);

                cout << "Duree en secondes : ";

                if (!(cin >> duree)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Duree invalide." << endl;
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                p->ajouterTitre(nom, artiste, duree);
            }
            break;
        }

        case 2: {
            Playlist* p = choisirPlaylist(playlists, nbrPlaylists);

            if (p != nullptr) {
                cout << "Numero du titre a supprimer : ";

                if (!(cin >> numero)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Numero invalide." << endl;
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                p->supprimerTitre(numero);
            }
            break;
        }

        case 3: {
            Playlist* p = choisirPlaylist(playlists, nbrPlaylists);

            if (p != nullptr) {
                p->afficher();
            }
            break;
        }

        case 4: {
            Playlist* p = choisirPlaylist(playlists, nbrPlaylists);

            if (p != nullptr) {
                cout << "Supplement de capacite : ";

                if (!(cin >> supplement)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valeur invalide." << endl;
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                p->agrandir(supplement);
            }
            break;
        }

        case 5: {
            Playlist* p = choisirPlaylist(playlists, nbrPlaylists);

            if (p != nullptr) {
                p->trierParDuree();
                cout << "Playlist triee par duree croissante."
                    << endl;
                p->afficher();
            }
            break;
        }

        case 6: {
            Playlist* p = choisirPlaylist(playlists, nbrPlaylists);

            if (p != nullptr) {
                cout << "\n===== STATISTIQUES =====" << endl;

                cout << "Duree totale : "
                    << p->calculerDureeTotale()
                    << " secondes" << endl;

                int index = p->trouverIndexPlusLong();

                if (index == -1) {
                    cout << "La playlist est vide." << endl;
                }
                else {
                    cout << "Numero du titre le plus long : "
                        << index + 1 << endl;
                }

                cout << "Nom de l'artiste a rechercher : ";
                getline(cin, artiste);

                cout << "Nombre de titres de cet artiste : "
                    << p->compterParArtiste(artiste) << endl;
            }
            break;
        }

        case 7: {
            cout << "\n===== COMPTEURS GLOBAUX =====" << endl;

            cout << "Playlists existantes : "
                << Playlist::getNbrPlaylist() << endl;

            cout << "Titres stockes globalement : "
                << Playlist::getNbrTotalSong() << endl;
            break;
        }

        case 8: {
            if (nbrPlaylists >= MAX_PLAYLISTS) {
                cout << "Nombre maximal de playlists atteint."
                    << endl;
                break;
            }

            cout << "Nom de la nouvelle playlist : ";
            getline(cin, nomPlaylist);

            if (nomPlaylist.empty()) {
                cout << "Le nom ne peut pas etre vide." << endl;
                break;
            }

            cout << "Capacite initiale : ";

            if (!(cin >> capacite)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Capacite invalide." << endl;
                break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (capacite <= 0) {
                cout << "La capacite doit etre positive." << endl;
                break;
            }

            playlists[nbrPlaylists] =
                new Playlist(nomPlaylist, capacite);
            nbrPlaylists++;

            couleur(10);
            cout << "Playlist creee avec succes !" << endl;
            couleur(7);
            break;
        }

        case 0:
            couleur(13);
            cout << "Fermeture de Cherry Pop Player..." << endl;
            couleur(7);
            break;

        default:
            cout << "Choix invalide. Choisissez entre 0 et 8."
                << endl;
            break;
        }

    } while (choix != 0);

    // Liberation de toutes les playlists
    for (int i = 0; i < nbrPlaylists; i++) {
        delete playlists[i];
    }

    cout << "Toutes les playlists ont ete liberees." << endl;

    return 0;
}
