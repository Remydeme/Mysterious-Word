// main.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <ctime>
#define espaces() std::cout<<"\n"<<std::endl
#define affiche(x) std::cout<<x<<std::endl
//int multiplier(int);
#include "Header.h"
//int num = 30;
//int *recup = &num;


int main()
{
	std:: string recomencer;
	do 
	{

		mainGame();
		espaces();
		std::cout << "Voulez vous rejouez? repondre par 'oui'  ou 'non' " << std::endl;
		std::cin >> recomencer;

	} while (recomencer != "non");







	return 0;
}

