/// \file Shapes.cpp
///	\brief Functions to manage shapes: implementation of the functions
/// @author Elisa Castellari / Francesco Casazza
/// 
///	Abbiamo provato a usare vector come preannunciato in classe
///

#include "Shapes.h"
#include <vector>
using namespace std;

/// @brief funzione per vedere tutte le forme create
/// @param vector<Quadrilateral*> Shapes per stampare le forme
/// @param counter tiene il conto del numero delle forme 
void ShowShapes(vector<Quadrilateral*> Shapes) {

	int counter = 0;

	cout << "_________________________CON_VECTOR________________________" << endl;
	cout << "Ecco tutte le tue forme:" << endl;
	if (Shapes.size() != 0) {
		for (auto i : Shapes) {  //passa in rassegna tutte le shapes per disegnarle
			cout << endl << "Forma " << counter;
			i->Drawing();
			counter++;
		}
	}
	else {
		cout << endl << "Non hai nessuna forma" << endl;
	}
	cout << "__________________________________________________________\n" << endl;

}

/// @brief funzione per rimuovere tutte le forme
/// @param vector<Quadrilateral*> Shapes[SHAPESNUMBER] per indicare quale lista cancellare
void RemoveAllShapes(vector<Quadrilateral*> Shapes[SHAPESNUMBER]) {
	cout << "__________________________________________________________" << endl;
	cout << "Cancellazione in corso...." << endl;
	Shapes->clear();
	//////////////////////////////////////
	for (auto ShapeToDelete : Shapes[SHAPESNUMBER]) { 	// per deallocare la memoria allocata dalle forme che ho creato
		if (ShapeToDelete != NULL)
			delete[] ShapeToDelete;
	}
	/////////////////////////////////////////
	cout << "Cancellazione eseguita con successo" << endl;
	cout << "__________________________________________________________\n" << endl;
	return;

}

/// @brief funzione per rimuovere una sola shape
/// @param vector<Quadrilateral*> ShapeToRemove[SHAPESNUMBER] per indicare dove cancellare
/// @param int ShapeToRemoveNumber è il numero della shape da eliminare
void RemoveOneShape(vector<Quadrilateral*> ShapeToRemove[SHAPESNUMBER], int ShapeToRemoveNumber) {
	try {
		if (ShapeToRemoveNumber < SHAPESNUMBER && ShapeToRemoveNumber < ShapeToRemove->size() && ShapeToRemove->size() != 0) {
			ShapeToRemove->erase((ShapeToRemove->begin() + ShapeToRemoveNumber)); // controllo per verificare che la shape da rimuovere effettivamente esista
			cout<< endl << "Forma rimossa con successo!" << endl;
		}
		else {
			throw(1);
		}
	}
	catch (...) {
		cout << endl << "----------------------------ERRORE------------------------------\n";
		cout << endl << "Questa shape non esiste, riprova con una shape valida" << endl;
	}
}

/// @brief funzione per aggiungere forme
/// @param vector<Quadrilateral*> Shapes[SHAPESNUMBER] per indicare dove inserire la shape
/// @param Quadrilateral* NewShape indica la shape da aggiungere
void AddShapes(vector<Quadrilateral*> Shapes[SHAPESNUMBER], Quadrilateral* NewShape) {

	if (Shapes->size() < SHAPESNUMBER) {
		Shapes->push_back(NewShape);
		cout << endl << "Forma aggiunta con successo!" << endl;
	}
	else {
		cout << endl << "Limite forme raggiunto! Cancella qualcosa per aggiungere una nuova forma" << endl;
	}
}