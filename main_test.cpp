#include<iostream>
#include <cstring>

#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "Shapes.h"

int ShapeLenght = 0; //inizializzo lunghezza a 0
Quadrilateral* ShapeList[SHAPESNUMBER]; //prova per shape grande
const int LISTL = 6; 
//int LISTL = 6;
Quadrilateral* quadList[LISTL];

void Show() {

	int i;

	for (i = 0; i < LISTL; i++)
		quadList[i]->Drawing();

}

void Show(int q) {

	int i;

	for (i = 0; i < LISTL; i++)
		quadList[i]->Dump();

}


int main() {
	 
	TextArea a1, a2;
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
	RemoveAllShapes(&path, 1);
	//Show();
	//Show(1);
	for (auto i : path) {
		cout << "\n\ndisegno da vector\n\n";
		i->Drawing();
		std::cout << i->GetFontSize() << ' '; // will print the various sizes
	}

	Rhombus rhoBELLO;
	rhoBELLO.Drawing();
	
	rectA.SetFontSize(20);
	//rectC=rectA;
	rectB.SetTextArea(a2);
//	rhoB.SetText(t3);
	rhoC.SetText(t4);
	
	ShowShapes(quadList, LISTL);
	RemoveAllShapes(quadList, LISTL);
//	ShowShapes(quadList, LISTL);
	
	//memcpy(b.string, b1, strlen(b1) + 1);
	//Quadrilateral* a = new Rectangle;
	//Rectangle prova(3, 4, b);
	//ShapeList[0] = &prova;
	//AddShapes(ShapeList[0], ShapeLenght, ShapeList);
	//ShowShapes(ShapeList, ShapeLenght + 1);


	return 0;
}