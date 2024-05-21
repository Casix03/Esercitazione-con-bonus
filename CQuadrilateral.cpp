#include <cstring>
#include "CQuadrilateral.h"

/// @brief default constructor 
Quadrilateral::Quadrilateral() {

	cout << "Quadrilateral - constructor - default" << endl;

	Init();

} 

/// @brief constructor 
/// ta a struct of type TextArea with infos on text and font size
Quadrilateral::Quadrilateral(TextArea ta) {
	
	Init();

	SetFontSize(ta.size);  /// metto la size di ta in tarea con la funzione apposita
	SetText(ta.string);    /// scrivo la stringa di ta in tarea con la funzione apposita
	
} 

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Quadrilateral::Quadrilateral(const Quadrilateral &o) {
	
	cout << "Quadrilateral - copy constructor" << endl;

	Init(o);
}

/// @brief destructor
Quadrilateral::~Quadrilateral() {

	cout << "Quadrilateral - destructor" << endl;
	Reset();

}  


/// @brief sets the value of the four sides 
/// @param s1 side 1 
/// @param s2 side 2 
/// @param s3 side 3
/// @param s4 side 4 
void Quadrilateral::SetSides(float s1, float s2, float s3, float s4) {
	
	sides[0] = s1;
	sides[1] = s2;
	sides[2] = s3;
	sides[3] = s4; 
	
	return;

} 

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Quadrilateral& Quadrilateral::operator=(const Quadrilateral &o) { 
	
	Init(o);
	return *this;
	
}

/// @brief overload of operator == 
/// @param o reference to the object on the right side of the operator 
/// @return always false 
bool Quadrilateral::operator==(const Quadrilateral &o) {

	return false;

}


/// @brief default initialization of the object
/// @param temp inizializza una stringa vuota per usare la funzione dedicata SetText 
void Quadrilateral::Init() {
	
	char temp[SLEN] = " ";
	
	SetSides(0.,0.,0.,0.); /// inizializzo lati a 0
	SetFontSize(0);        /// inizializzo size a 0
	SetText(temp);		   /// inizializzo text come vuoto
		
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Quadrilateral::Init(const Quadrilateral &o) {
	Reset();
	Init();
	sides[0] = o.sides[0]; 
	sides[1] = o.sides[1]; 
	sides[2] = o.sides[2]; 
	sides[3] = o.sides[3];
	SetFontSize(o.tarea->size); /// inizializza il quadrilateral con la size di o
	SetText(o.tarea->string);   /// inizializza la string di quadrilateral con quella di o
	
}

/// @brief total reset of the object  
void Quadrilateral::Reset() {
	
	if (tarea != NULL) {
		delete tarea;
		tarea = NULL;
	}
	sides[0]= sides[1]= sides[2]= sides[3] = 0.;
	
}

/// @brief get the area of the object
/// @return area 
float Quadrilateral::GetArea() {
	
	return Area();

}

/// @brief get the perimeter of the object
/// @return perimeter 
float Quadrilateral::GetPerimeter() {

	return (sides[0]+sides[1]+sides[2]+sides[3]);

} 

/// @brief get the sides of the object 
/// @param s0 side 0 
/// @param s1 side 1
/// @param s2 side 2
/// @param s3 side 3 
void Quadrilateral::GetSides(float &s0, float &s1, float &s2, float &s3) {

	s0 = sides[0]; 
	s1 = sides[1];
	s2 = sides[2];
	s3 = sides[3];

}

/// @brief get the info about the text area
/// @param ta a struct of type TextArea to be filled
void Quadrilateral::GetTextArea(TextArea &ta) {
	
	ta.size = tarea->size;  /// metto in ta la size di textarea
	memcpy(ta.string, tarea->string, SLEN); /// copio con memcpy la stringa di ta

} 

/// @brief get the text of the text area 
/// @param text the string used in the text area 
void Quadrilateral::GetText(char* text) {
	
	memcpy(text, tarea->string, SLEN); /// copia in text la stringa di textarea

}

/// @brief get the font size of the text area 
/// @return the font size
unsigned int Quadrilateral::GetFontSize() {
	
	return tarea->size;
}


/// @brief set the text area of the object 
/// @param ta a struct of type TextArea filled with a text and a font size
void Quadrilateral::SetTextArea(TextArea ta) {

	SetFontSize(ta.size);  /// metto la size di ta in tarea con la funzione apposita
	SetText(ta.string); /// scrivo la stringa di ta in tarea con la funzione apposita

}

/// @brief set the text of the text area 
/// @param text the text 
void Quadrilateral::SetText(char* text) {

	if (sizeof(text) <= SLEN) { /// controllo che le 2 stringhe siano compatibili
		memcpy(tarea->string, text, SLEN);
	}
	else {
		WarningMessage("Stringa troppo lunga");
		memcpy(tarea->string, " ", SLEN);
	}

}

/// @brief set the font size of the text area 
/// @param size the font size 
void Quadrilateral::SetFontSize(unsigned int size) {
	
	tarea->size = size; /// metto la size di size in tarea

}



/// @brief write an error message 
/// @param string message to be printed
void Quadrilateral::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Quadrilateral --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Quadrilateral::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Quadrilateral --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
/// @param temp stringa vuota che accoglierà il testo di GetText 
void Quadrilateral::Dump() {

	char temp[SLEN] = " "; /// variabile temporanea per scrivere text message nel cout
	GetText(temp);

	cout << endl;
	cout << "---Quadrilateral---" << endl; 
	cout << endl;
	
	cout << "Sides = " << sides[0] << "; " << sides[1] << "; " << sides[2] << "; " << sides[3] << "; " << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << "Font Size = " << GetFontSize() << endl;
	cout << "Text message = " << temp << endl;
	cout << "------------------" << endl; 
	cout << endl;

}

