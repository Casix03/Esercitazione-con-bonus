/*! \file StructTextArea.h
	\brief Declaration of the struct TextArea
     @author Elisa Castellari / Francesco Casazza

	Details.
*/

#ifndef STRUCTAREA_H
#define STRUCTAREA_H

# define SLEN 50

/// @struct TextArea
/// @brief includes the text to be showed and the font size 
struct TextArea {
	char string[SLEN]; // the text 
	unsigned int size; // font size
	
};

#endif // STRUCTAREA_H