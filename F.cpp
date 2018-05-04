#include "stdafx.h"
#include<iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>
#include <time.h>
#include <algorithm>
#include <vector>
#include <sstream>
#define MAX_WORD 323577
#define affiche(x) std::cout<<x<<std::endl
#define espaces() std::cout<<"\n"<<std::endl


// La fonction qui nous sert a melanger les lettre d'un mot au hasard
std::string melangerLettre(std::string mot)
{
	std::string melanger; // on definit une variable melanger 
	int positions(0);    // defini la position de la premiere lettre du mot qui est a 0

	while (mot.size() != 0) // on cree une boucle afin que le programme extrait toutes les lettre de la variable et la met aleatoirement dasn une autre variable
	{
		srand(time_t(nullptr)); // fonction aleatoire
		positions = rand() % mot.size(); // position bring one letter 
		melanger += mot.at(positions); // += use to put the letter into their new variable
		mot.erase(positions, 1); // erased the letter which was bring of the old variable
	}

	return melanger; // return the new variable with the letter which was put randomly
}



//Affin de jouer seul on tire un mot d'un texte au hasard
void joueurSolo(void)
{
	affiche("Vous allez donc jouer avec l'ordinateur bon jeu et que le meilleur gagne :)");
	affiche("Vous aurez 5 essaie afin de gagner la partie !");
	int chiffre;
	int counter = 0;
	int Try = 5;;
	std::string mots, Wordguess, Guess;
	std::string motHasard;
	std::vector <std::string> tableau;
	std::ifstream monFlux("D:/Telechargement/dico.txt");
	do
	{
		if (monFlux)
		{

			while (getline(monFlux, mots))
			{
				tableau.push_back(mots); // place les mots a chaque ligne dans le tableau dynamique
				counter++;
			}
		}
		else // if we got an error
		{
			affiche("ERREUR !");
		}
	} while (counter != MAX_WORD);
		int srand(unsigned int(time_t(nullptr)));
		chiffre = rand() % MAX_WORD; // chiffre au hasard qui va tirer un mot du tablrau aleatoirement
		motHasard = tableau[chiffre]; // la variable qui va contenir la ligne du tableau tirer au hasard
		Wordguess = melangerLettre(motHasard); // mot melanger
		espaces();
		affiche("Retrouvez le mot : " << Wordguess);
		do
		{
			std::cin >> Guess;
			if (Guess == motHasard)
			{
				affiche("Bravo vous avez retrouver le mots !");
			}
			else
			{
				Try--;
				affiche("Mauvaise reponse :(");
				affiche("Il vous reste "<<Try <<"essaies");
			}

			if (Try == 0)
			{
				affiche("Vous avez perdu !");
				break;
			}

		} while (Guess != motHasard);

		espaces();
		affiche("La reponse est: " << motHasard);
}
	


//Just pour espacé lorsque le joueur1 fait deviner un mot au joueur2
void espaceJeu(void)
{
	for (int i = 0; i < 10; i++){
		espaces();
	}
}

// le coeur du jeu
void mainGame(void)
{
	std::string motMystere, motDeviner, motMelanger;
	std::string rep1, rep2;
	char reponse;
	rep1 = "UN JOUEUR";
	rep2 = "DEUX JOEUR";
	int score = 0, count = 0;
	affiche("Bienvenue, ce programme est le jeu mystere");
	espaces();
	affiche(" choissez votre mode de jeu, taper A ou B :");
	espaces();
	affiche("A : " << rep1);
	affiche("B : " << rep2);
	std::cin >> reponse;
	std::string *choix = nullptr; // crée un pointeur afin de stocker la reponse du joueur

	switch (reponse)
	{
		case 'A':
			choix = &rep1;
			break;
		case 'B':
			choix = &rep2;
			break;
	}
	affiche("Vous avez choisie le mode : " << *choix);

	if (reponse == 'A')
	{
		joueurSolo();

	}

	if(reponse == 'B')
	{
		affiche("Veuillez rentrez un mot a faire devinez au joueur 2");
		std::cin >> motMystere;
		espaceJeu();

		motMelanger = melangerLettre(motMystere);
		std::cout << "voici le mot lettre melanger: " << motMelanger;
		espaces();
		affiche("A vous de jouer le joueur 2, Quel est le mot ? :");
		int essayer = 5;


		do
		{

			std::cin >> motDeviner;

			if (motMystere == motDeviner)
			{
				affiche("Félicitation vous avez trouver le bon mot !");
			}
			else
			{
				essayer--;
				affiche("Ce n'est pas le bon mot, il vous reste " << essayer << " essaie");
			}

			if (essayer == 0)
			{
				affiche(" Vous avez perdu ! :(");
				break;
			}

			

		} while (motMystere != motDeviner);

		espaces();
		std::cout << "La solution etais : " << motMystere << std::endl;
	}
}



int multiplier(int val)
{
	int resultat;
	resultat = val + 4;
	return resultat;
}

int nombreDeSecondes(int heures, int minutes, int secondes)
{
	int total = 0;

	total = heures * 60 * 60;
	total += minutes * 60;
	total += secondes;

	return total;
}
