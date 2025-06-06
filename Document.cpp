/*****************************************
** File: Document.cpp
** Project: Text Editor
** Author: Vidal Bickersteth
** Date: 4/1/25
** 
**
** This program is the Document.cpp file of Text Editor.
** This file creates a document object, which is linked list.
** The linked list are made up of lines.
** You can also know how many lines are in your document.
** This file creates the functions to insert, delete, edit, display,
** save, and load your document. 
** The file also allows you to search for lines that contains
** the word that you want to search.
** 
**
**
***********************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "Line.h"
#include "Document.h"
using namespace std;

// Document
// Given: None, Creates an empty Document (linked list)
Document::Document(){
    // Initalizes the member variables with default values
    m_head = nullptr;
    m_lineCount = 0;
}

// ~Document
// Given: None, Removes all lines from Document (removes all nodes from linked list)
Document::~Document(){
    Line* temp = m_head; // Creates the first node of the linked list
    while(temp != nullptr){
        // Deletes each lines of the document
        m_head = m_head -> GetNext();
        delete temp;
        temp = m_head;
    }
}

// InsertLine
// Given: The text and the position,
// inserts a new line (node) into the Document (linked list)
void Document::InsertLine(string text, int position){
    Line *temp = new Line(text); // Creates a new line
    Line *curr = m_head; // Sets current line to the first line
    if(position == 1){
        // If the user wants to insert a line as the first line
        // the first node is set to the text that the users wants to 
        // then, the number of lines gets increased
        temp -> SetNext(m_head);
        m_head = temp;
        m_lineCount++;
    }
    else{
        // Traverses until the position that the user
        // wants to insert their text, then all other lines
        // after it gets pushed to the right by one
        for(int i = 1; i < position - 1; i++){
            curr = curr -> GetNext();
        }
        temp ->SetNext(curr->GetNext());
        curr ->SetNext(temp);
        m_lineCount++;
    }
    
    
}

// DeleteLine
// Given: the position, deletes a line from the Document at a provided position
void Document::DeleteLine(int position){
    Line *temp = m_head; // The current line of the document
    Line *prev = m_head; // The previous line of the document
    if(position == 1){
        // If the user wants to delete the first lines
        // then the first line is set to the next line of the document
        // deletes the current first line of the document
        m_head = m_head ->GetNext();
        delete temp;
        temp = nullptr;
        --m_lineCount;
    }else{
        for(int i = 1; i <= position-1; i++){
            // Traverses until you reach the line before
            // the line you want to delete
            prev = temp;
            temp = temp -> GetNext();
        }
        // Deletes the line the user wants to delete
        prev->SetNext(temp -> GetNext());
        delete temp;
        temp = nullptr;
        --m_lineCount;
    }
}

// EditLine
// Given: The position and newText, edits the text 
// in a specific Line at a provided position (line number)
void Document::EditLine(int position, string newText){
    Line *temp = m_head; // The current line of the document
    if(position == 1){
        // if the user wants to change the first line, 
        // only changes the first line to the text that the user wants 
        // to change
        temp ->SetText(newText);
    }else{
        for(int i = 1; i < position; i++){
            // Traverses the document until you reach the line 
            // you want to edit
            temp = temp -> GetNext();
        }
        // Edits the line that the user wants to change
        temp->SetText(newText);
    }
}

// DisplayDocument
// Given: None, displays the entire document
void Document::DisplayDocument(){
    Line *temp = m_head; //The current line of the document
    if(GetLineCount() == 0){
        // Stops the program if there's no document to display
        cout << "There is no document to display" << endl;
        return;
    }else{
        // Traverses the entire document and displays each line.
        for(int i = 1; i <= GetLineCount(); i++){
            cout << i << ": " << temp -> GetText() << endl;
            temp = temp -> GetNext();
        }
    }
}

// SearchWord
// Given: the text, searches for all lines that contains the 
// word that the user wants to edit.
void Document::SearchWord(string text){
    Line *temp = m_head; // The current line of the document
    string line = text; // The word that the user wants to search for in all lines
    size_t index; // The position of the lines that contains the word.
    int j = 0; // Number of the found lines
    if(GetLineCount() == 0){
        // Stops the program if there's no line to search
        cout << "There is no document to search" << endl;
        return;
    }
    for(int i = 1; i <= GetLineCount(); i++){
        // Traverses through the document to find any line
        // that contains the word that the user wants to search for
        index = temp->GetText().find(line);
        if(index != std::string::npos){
            std::cout << "Word found in line "
            << i << ": " 
            << temp -> GetText() << std::endl;
            j++; // Increments per found line
        }
        temp = temp->GetNext();
    }
    // If no lines are found, then there are no lines that contains
    // the word that the user wants to search for
    if(j == 0){
        cout << "No found lines" << endl;
    }
}

// SaveToFile
// Given: The filename, saves current document to the .txt file
void Document::SaveToFile(string filename){
    Line *temp = m_head; // The current line of the document    
    ofstream outputstream; // The output stream variable that will save the 
                           // current document to a text file     
    // Creates the text file
    // the text file gets opened
    outputstream.open(filename);
    if((outputstream.is_open())){
        // If the file is open, then 
        // the current document and all of it's lines
        // gets saved into the file
        for(int i = 1; i <= GetLineCount(); i++){
            outputstream << temp -> GetText() << " ";
            outputstream << endl;
            temp = temp -> GetNext();
        }
        // The file gets closed after the save
        cout << "File saved successfully!" << endl;
        outputstream.close();
    }
}

// LoadFromFile
// Given: The filename, loads the contents of the .txt file into 
// the document
void Document::LoadFromFile(string filename){
    ifstream inputStream; // The input stream variable that will load the 
                          // text file into the document
    string text; // Contains the current line from the .txt file
    int i = 1; // Contains the current line position from the .txt file
               // Will increment per line inserted into the document
    // the text file gets opened
    inputStream.open(filename);
    if(inputStream.is_open()){
        // If the file is open, then 
        // the text file and all of it's lines
        // gets loaded into the document
        while(getline(inputStream, text))
        {
            InsertLine(text, i);
            i++;
        }
        // The file gets closed after the load
        inputStream.close();
        cout << "File loaded successfully!" << endl;
    }else{
        // Print this if the file does not get opened
        cout << "File does not exist." << endl;
    }
}

// GetLineCount
// Given: None, returns the number of lines of document
int Document::GetLineCount(){
    //Amount of lines in document gets returned
    return m_lineCount;
}