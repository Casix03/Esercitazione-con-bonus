/// \file Shapes.cpp
///	\brief Functions to manage shapes: implementation of the functions
/// @author Elisa Castellari / Francesco Casazza
/// 
///	Details;
///

#include "Shapes.h"

/// @brief funzione per vedere tutte le forme create
/// @param int Sh per stampare le forme
/// @param int lenght è la lunghezza dell'array
void ShowShapes(Quadrilateral* Shapes[SHAPESNUMBER], int lenght) {


	cout << "__________________________________________________________" << endl;
	cout << "Ecco tutte le tue forme\n" << endl;
	for (int Sh = 0; Sh < lenght; Sh++) {
		cout << "Forma " << Sh + 1 << ":";
		Shapes[Sh]->Drawing();
	}
	cout << "__________________________________________________________" << endl;
}

/// @brief funzione per aggiungere forme
void AddShapes(vector<Quadrilateral> Shapes) {

}

