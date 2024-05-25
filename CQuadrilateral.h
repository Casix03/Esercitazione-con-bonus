/*! \file CQuadrilateral.h
	\brief Declaration of the general class Quadrilateral
	@author Elisa Castellari / Francesco Casazza

	Details.
*/


#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include<iostream> 
#include "StructTextArea.h"

using namespace std;

/// @class Quadrilateral
/// @brief an abstract base class for quadrilateral
class Quadrilateral {
protected:

	float sides[4];
	
	TextArea* tarea;
	
	void SetSides(float s1, float s2, float s3, float s4); 
	
	/// @name PURE VIRTUAL FUNCTIONS
	/// @{
	virtual float Area()=0;
	/// @}

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Quadrilateral();
	Quadrilateral(TextArea ta);
	Quadrilateral(const Quadrilateral &o);
	virtual ~Quadrilateral();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Quadrilateral& operator=(const Quadrilateral &o); 
	bool operator==(const Quadrilateral &o);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	virtual void Init();												
	void Init(const Quadrilateral &o);							
	void Reset();												
	/// @}

			
	/// @name GETTERS
	/// @{
	float GetArea();
	float GetPerimeter();
	void GetSides(float &s0, float &s1, float &s2, float &s3);
	void GetTextArea(TextArea &ta); 
	void GetText(char* text);
	unsigned int GetFontSize();
	/// @}
	
	/// @name SETTERS
	/// @{
	void SetTextArea(TextArea ta);
	void SetText(char* text);
	void SetFontSize(unsigned int size);
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	virtual	void Dump();				 //per sfruttare polimorfismo
	/// @}
	
	/// @name PURE VIRTUAL FUNCTIONS 
	/// @{
	virtual void Drawing()=0;
	virtual void SetDim(float, float) = 0; //abbiamo deciso di metterla virtuale pura per sfruttare il polimorfismo nella funzione menu del main
	/// @}

};

#endif