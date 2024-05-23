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
	cout << "__________________________________________________________\n" << endl;

}

/// @brief funzione per aggiungere forme
bool AddShapes(Quadrilateral* NewShape, static int lenght, Quadrilateral* Shapes[SHAPESNUMBER]) {
	if (lenght > (SHAPESNUMBER)) {
		cout << endl << "Hai raggiunto il numero massimo di forme. cancellane una per aggiungerne altre";
		return false;
	}
	else {
		Shapes[++lenght] = NewShape;
		cout << endl << "Aggiunto alla lista";
		return true;
	}
	lenght++;
}

/// @brief funzione per rimuovere tutte le forme
/// @param Sh per far passare una ad una tutte le forme nel ciclo for e cancellarle
void RemoveAllShapes(Quadrilateral* Shapes[SHAPESNUMBER], int lenght) {
	cout << "__________________________________________________________" << endl;
	cout << "Cancellazione in corso...." << endl;
	//for (int Sh = 0; Sh < lenght; Sh++) {
		//Shapes[Sh]->Init();
	//	delete[] Shapes;
		//lenght--;
	//}
	cout << "Cancellazione eseguita con successo" << endl;
	cout << "__________________________________________________________\n" << endl;
}

