#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <cstring>

#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "Shapes.h"

using namespace std;

/// @brief variabili globali
const int LISTL = 6;
Quadrilateral* quadList[LISTL];
vector<Quadrilateral*> MyShapes;


/// @brief menu per fare operazioni con le forme
/// @param Quadrilateral* ShapePointer è puntatore a quadrilatero che poi potra' diventare o rettangolo o rombo
/// @param int choice indica la scelta nel menu
/// @param char DestroyChoice e' per decidere se voglio davvero cancellare tutto o no
/// @param int MyQuadrilateral per decidere se voglio rombo o rettangolo
/// @param float dim1 e dim2 per settare le dimenzioni della forma
/// @param unsigned int fontDim per settare dimensione carattere
/// @param int ShapeToDelete per decidere il numero della forma da eliminare
/// @param char NewText[SLEN] ospita il testo da scrivere nella forma
void Menu(Quadrilateral* ShapePointer) {

	int choice = 99;
	char DestroyChoice = 'c';
	int MyQuadrilateral = 99;
	float dim1 = 99, dim2 = 99;
	unsigned int fontDim = 99;
	int ShapeToDelete = 99;
	char NewText[SLEN] = "default";

	cout << "_______|| DISEGNATORE DI FORME ||_______" << endl;

	while (1) { //fa sempre andare il menu fino a che non seleziono 0

		cout << endl << "Cosa vuoi fare?" << endl;
		cout << "0: esci dal programma" << endl;
		cout << "1: aggiungi forma " << endl;
		cout << "2: elimina forma " << endl;
		cout << "3: elimina tutto " << endl;
		cout << "4: mostra forme " << endl;

		choice = 99;
		scanf("%d", &choice);

		switch (choice) {
		case 0: //USCITA
			cout << "_______|| USCITA IN CORSO... ||________" << endl;
			return; // torna nel main
		case 1: // AGGIUNTA FORMA
			cout << "Che forma vuoi? " << endl;
			cout << "1: rettangolo " << endl;
			cout << "2: rombo " << endl;
			scanf("%d", &MyQuadrilateral);

			if (MyQuadrilateral == 1) {
				cout << "Hai selezionato rettanglo!" << endl;
				ShapePointer = new Rectangle;
				cout << "Scegli dimensione base: ";
				scanf("%f", &dim1);
				cout << "Scegli dimensione altezza: ";
				scanf("%f", &dim2);
				ShapePointer->SetDim(dim1, dim2);
			}
			else if (MyQuadrilateral == 2) {
				cout << "Hai selezionato rombo!" << endl;
				ShapePointer = new Rhombus;
				cout << "Scegli dimensione diagonale maggiore: ";
				scanf("%f", &dim1);
				cout << "Scegli dimensione diagonale minore: ";
				scanf("%f", &dim2);
				ShapePointer->SetDim(dim1, dim2);
			}
			else {
				cout << "Scelta non valida " << endl;
				break;
			}
			cout << "Scegli dimensione del carattere: ";
			scanf("%u", &fontDim);
			ShapePointer->SetFontSize(fontDim);
			cout << "Scegli testo dentro la forma: " << endl;
			scanf("\n");					// per prendere l'invio
			fgets(NewText, SLEN, stdin);	// cosi' anche se metto lo spazio funziona
			strtok(NewText, "\n");			// rimuove il \n finale letto da fgets
			ShapePointer->SetText(NewText);

			AddShapes(&MyShapes, ShapePointer); // aggiungo la forma appena creata dall'utente
			break;
		case 2: //RIMUOVI UNA FORMA		
			ShowShapes(MyShapes); //fa una lista per decidere quale forma eliminare
			if (MyShapes.size() != 0) {
				cout << "Scegli la forma da eliminare: ";
				scanf("%d", &ShapeToDelete);
				RemoveOneShape(&MyShapes, ShapeToDelete);
			}
			else
				cout << "Non hai nessuna forma da eliminare. Aggiungine una per usare questa funzione." << endl;
			break;
		case 3: //rimuovi tutte forme
			cout << "ATTENZIONE: questa operazione cancellera' TUTTO. Procedere? (Y/N) ";
			scanf("\n");
			scanf("%c", &DestroyChoice);
			if (DestroyChoice == 'Y' || DestroyChoice == 'y') { // nel caso la scelta fosse di cancellare tutto cancello tutto
				RemoveAllShapes(&MyShapes);
			}
			else
				cout << "Operazione annullata" << endl; //annulla operazione cancellazione
			break;
		case 4: //MOSTRA LE FORME
			ShowShapes(MyShapes);
			break;
		case 99: //PUNIZIONE PER CHI METTE UN CARATTERE
			cout << endl << "________________________________________________________________" << endl;
			cout << endl << "SEI STATO CATTIVO, HAI INSERITO UN QUALCOSA CHE NON E' UN NUMERO" << endl;
			cout << "SEI ESPULSO A TEMPO INDEFINITO DAL PROGRAMMA" << endl;
			cout << "________________________________________________________________\n" << endl;
			return;
		default: // QUALSIASI ALTRO CASO NON TRATTATO
			cout << choice << " non e' una scelta valida. Riprova!" << endl;
			break;
		}
	} 
} 

//@brief funzione data dal professore
void Show() {

	int i;

	for (i = 0; i < LISTL; i++)
		quadList[i]->Drawing();

}

int main() {
	// per punto extra
	Quadrilateral* p = NULL;
	Menu(p);
	// inizio main di prova fornito da professore
	TextArea a1, a2;
	char t1[SLEN] = "testo 1";
	char t2[SLEN] = "testo 2";
	char t3[SLEN] = "testo 3";

	memcpy(a1.string, t1, strlen(t1) + 1);
	a1.size = 8;
	memcpy(a2.string, t2, strlen(t2) + 1);
	a2.size = 14;

	Rectangle rectA(10, 5);
	Rectangle rectB(3, 7, a1);
	Rectangle rectC = rectA;

	Rhombus rhoA(6, 2, a2);
	Rhombus rhoB = rhoA;
	Rhombus rhoC(4, 3);

	quadList[0] = &rectA;
	quadList[1] = &rectB;
	quadList[2] = &rectC;
	quadList[3] = &rhoA;
	quadList[4] = &rhoB;
	quadList[5] = &rhoC;

	Show();

	rectA.SetFontSize(20);
	rectC = rectA;
	rectB.SetTextArea(a2);
	rhoB.SetText(t3);

	Show();
	// per vedere se tiene le forme in memoria
	Menu(p);
	// per deallocare la memoria allocata dalle forme che ho creato
	for (auto ShapeToDelete : MyShapes) {
		if (ShapeToDelete != NULL)
		delete[] ShapeToDelete;
	}
	return 0;
}