#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>

#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "Shapes.h"

int ShapeLenght = 0; //inizializzo lunghezza a 0
Quadrilateral* ShapeList[SHAPESNUMBER]; //prova per shape grande
const int LISTL = 6;
Quadrilateral* quadList[LISTL];
vector<Quadrilateral*> MyShapes;

void Menu(Quadrilateral* ShapePointer) {
	int choice = 999;
	int MyQuadrilateral = 99;
	int dim1 = 99;
	int dim2 = 99;
	int fontDim = 99;
	int ShapeToDelete = 99;
	char NewText[SLEN] = "default";
	
	while (1) {

		cout << endl << "Cosa vuoi fare?" << endl;
		cout << "1: aggiungi forma " << endl;
		cout << "2: elimina forma " << endl;
		cout << "3: elimina tutto " << endl;
		cout << "4: mostra forme " << endl;
		cout << "0: esci dal programma" << endl;

		scanf("%d", &choice);

		switch (choice) {
		case 1:
			cout << "che forma vuoi? " << endl;
			cout << "1: rettangolo " << endl;
			cout << "2: rombo " << endl;
			scanf("%d", &MyQuadrilateral);

			if (MyQuadrilateral == 1) {
				cout << "Hai selezionato rettanglo!" << endl;
				ShapePointer = new Rectangle;
				cout << "scegli dimensione base: ";
				scanf("%d", &dim1);
				cout << "scegli dimensione altezza: ";
				scanf("%d", &dim2);
				//ShapePointer->SetDim(dim1, dim2);
			}
			else if (MyQuadrilateral == 2) {
				cout << "Hai selezionato rombo!" << endl;
				ShapePointer = new Rhombus;
				cout << "scegli dimensione diagonale maggiore: ";
				scanf("%d", &dim1);
				cout << "scegli dimensione diagonale minore: ";
				scanf("%d", &dim2);
				//ShapePointer->SetDim(dim1, dim2);
			}
			else {
				cout << "Scelta non valida " << endl;
			}
			cout << "Scegli dimensione del carattere: ";
			scanf("%d", &fontDim);
			ShapePointer->SetFontSize(fontDim);
			cout << "Scegli testo dentro la forma: " << endl;
			scanf("%s", &NewText);
			ShapePointer->SetText(NewText);
			

			//ShapePointer->SetDim(5, 7);
			AddShapes(&MyShapes, ShapePointer);
			break;
		case 2:
			cout << "Scegli la forma da eliminare: " << endl;
			ShowShapes(MyShapes);
			scanf("%d", &ShapeToDelete);
			RemoveOneShape(&MyShapes, ShapeToDelete);
			break;
		case 3:
			//cout << "ATTENZIONE: questa operazione cancellerà TUTTO. Procedere? (Y/N) ";
			RemoveAllShapes(&MyShapes);
			break;
		case 4:
			ShowShapes(MyShapes);
			break;
		case 0:
			return;
		default:
			cout << "Scelta non valida. Riprova!" << endl;
			break;
		}
	}
}




void Show() {

	int i;

	for (i = 0; i < LISTL; i++)
		quadList[i]->Drawing();

}

int main() {
	
	Quadrilateral* p = NULL;
	Menu(p);
	Rectangle a;

	p = &a;
	//AddShapes(p, &MyShapes);
	//AddShapes(p, &MyShapes);
	//AddShapes(p, &MyShapes);
	//AddShapes(p, &MyShapes);
	ShowShapes(MyShapes);
	RemoveOneShape(&MyShapes, 1);
	RemoveOneShape(&MyShapes, 5);
	ShowShapes(MyShapes);


	ShowShapes(MyShapes);

	/*TextArea a1, a2;
	char t1[SLEN]= "testo 1"; 
	char t2[SLEN]= "testo 2"; 
	char t3[SLEN]= "testo 3";
	char t4[600] = "dbnlkabfsbsbfsbjggbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggsvlkb kbfsjkvgsbjgbhgdbkbbhlgssbgjkdgsbjkddajsgbjkds<  sv nsv n";
	char b1[SLEN] = "SE MI LEGGI SEI FORTE";

	memcpy(a1.string,t1,strlen(t1)+1);
	a1.size = 8; 
	memcpy(a2.string,t2,strlen(t2)+1);
	a2.size = 14;
	
	Rectangle rectA(10,5);
	Rectangle rectB(3,7,a1);
	Rectangle rectC = rectA;
	//Rectangle rectC(5, 5, a2);

	Rhombus rhoA(6,2,a2);
	Rhombus rhoB = rhoA;
	//Rhombus rhoB(34,54,a1);
	Rhombus rhoC(4,3);
		
	quadList[0]= &rectA;
	quadList[1]= &rectB;
	quadList[2]= &rectC;
	quadList[3]= &rhoA;
	quadList[4]= &rhoB;
	quadList[5]= &rhoC;
	std::vector<Quadrilateral*> path(std::begin(quadList), std::end(quadList)); //FORSE VA LUI
	//RemoveAllShapes(&path, 1);
	RemoveOneShape(&path, 2);
	RemoveOneShape(&path, 3);
	RemoveOneShape(&path, 1);
	RemoveOneShape(&path, 9);
	AddShapes(quadList[5], &path);
	//Show();
	//Show(1);
	ShowShapes(path);
	/*
	for (auto i : path) {
		cout << "\n\ndisegno da vector\n\n";
		i->Drawing();
		std::cout << i->GetFontSize() << ' '; // will print the various sizes
	}
	*/

	/*Rhombus rhoBELLO;
	rhoBELLO.Drawing();
	
	AddShapes(quadList[1], &path);
	AddShapes(quadList[2], &path);
	AddShapes(quadList[3], &path);
	AddShapes(quadList[5], &MyShapes);

	ShowShapes(path);

	rectA.SetFontSize(20);
	rectC=rectA;
	rectB.SetTextArea(a2);
	rhoB.SetText(t3);
	rhoC.SetText(t4);
	
	ShowShapes(MyShapes);
//	ShowShapes(quadList, LISTL);
	RemoveAllShapes(&path);
	ShowShapes(path);
	//RemoveOneShape(&path, 2);

//	ShowShapes(quadList, LISTL);
	
	//memcpy(b.string, b1, strlen(b1) + 1);
	//Quadrilateral* a = new Rectangle;
	//Rectangle prova(3, 4, b);
	//ShapeList[0] = &prova;
	//AddShapes(ShapeList[0], ShapeLenght, ShapeList);
	//ShowShapes(ShapeList, ShapeLenght + 1);

	*/
	//delete p;
	return 0;
}