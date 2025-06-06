/*****************************************
** File: Line.cpp
** Project: Text Editor
** Author: Vidal Bickersteth
** Date: 4/1/25
**
** This program is the Line.cpp file of Text Editor.
** This file creates a new line.
** This file contains the getters and setters of 
** the m_text and m_next member variables.
** This program also have the class constructors
** to set default values for the member variables 
** or to initialize them with values from the 
** constructor's parameters.
**
**
**
**
***********************************************/

// Access input and output, characters as well as
// the namespace standard and the Line.h file
#include <iostream>
#include <string>
using namespace std;

#include "Line.h" 

// Line
// Given: None, Creates an empty line (acts as linked list node) 
// and sets the member variables to default values
Line::Line(){

    m_text = "";
    m_next = nullptr;
}

// Line
// Given: The text, Creates a line with the passed value and a nullptr (acts as linked list node)
Line::Line(string text){
    m_text = text;
    m_next = nullptr;
}

// GetText
// Given: None, returns the member variable m_text
string Line::GetText(){
    // returns the text of line
    return m_text;
}

// GetNext
// Given: None, returns the member variable m_next
Line* Line::GetNext(){
    // returns the next line
    return m_next;
}

// SetText
// Given: None, updates current text
void Line::SetText(string text){
    // sets current text to new text
    m_text = text;
}

// SetNext
// Given: None, sets the m_next to next
void Line::SetNext(Line* next){
    // changes the next line to the line 
    // that the user wants to set
    m_next = next;
}

