/*! \file Shapes.h
	\brief Dichiarazione funzioni per generare e gestire le forme
	@author Elisa Castellari / Francesco Casazza

	abbiamo usato vector e le sue funzioni
*/

#include<iostream>
#include <cstring>
#include <vector>
#include <iterator>

#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"

#define SHAPESNUMBER 50
//int ShapeLenght = 0;
//Quadrilateral* ShapeList[SHAPESNUMBER];

using namespace std;

#ifndef SHAPES_H
#define SHAPES_H

/// @name VISUALIZZATORE
/// @{
	void ShowShapes(Quadrilateral* Shapes[SHAPESNUMBER], int lenght);
/// @}

/// @name AGGIUNGI-SHAPE
/// @{
	bool AddShapes(Quadrilateral* NewShape, int lenght, Quadrilateral* Shapes[SHAPESNUMBER]);
/// @}

/// @name RIMUOVI-SHAPE
/// @{
	void RemoveOneShape(Quadrilateral* ShapeToRemove);
	void RemoveAllShapes(Quadrilateral* Shapes[SHAPESNUMBER], int lenght);
	void RemoveAllShapes(vector<Quadrilateral*> Shapes[SHAPESNUMBER], int lenght);
	/// @}

#endif; //SHAPES_H
