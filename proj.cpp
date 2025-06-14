/*****************************************
** File: proj.cpp
** Project: Text Editor
** Author: Vidal Bickersteth
** Date: 4/1/25
** E-mail: vidalb1@umbc.edu
**
** This program is the proj.cpp file of the Text Editor Project.
** This file creates a textEditor object.
** The program implements the Text Editor.
***********************************************/
#include "TextEditor.h"
#include <iostream>
using namespace std;

int main() {
  TextEditor T = TextEditor(); //Creates a new TextEditor object
  T.Start(); //Calls the Start function
  return 0;
}
