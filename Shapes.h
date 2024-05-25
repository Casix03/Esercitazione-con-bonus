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
	void ShowShapes(vector<Quadrilateral*> Shapes);
/// @}

/// @name AGGIUNGI-SHAPE
/// @{
	void AddShapes(vector<Quadrilateral*> Shapes[SHAPESNUMBER], Quadrilateral* NewShape);
/// @}

/// @name RIMUOVI-SHAPE
/// @{
	void RemoveOneShape(vector<Quadrilateral*> Shapes[SHAPESNUMBER], int ShapeToRemoveNumber);
	void RemoveAllShapes(vector<Quadrilateral*> Shapes[SHAPESNUMBER]);
/// @}

#endif; //SHAPES_H
