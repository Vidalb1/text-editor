/*****************************************
** File: TextEditor.cpp
** Project: Text Editor
** Author: Vidal Bickersteth
** Date: 4/1/25
**
** This program is the TextEditor.cpp of Text Editor.
** This file creates a text editor object, which is a document
** A document consists of lines that the user can manipulate with
** The user can choose what option they want to choose from the menu
** There are 8 options. 
** The user can insert, delete, edit, display, search, save, and load their document
** The user can also quit from doing anything with their document.
** Each mode have validation to ensure that the user can effectively modify their document
**
***********************************************/

#include "Document.h"
#include "TextEditor.h"
#include <iostream>
#include <string>

// TextEditor
// Given: None, creates document (m_editor)
TextEditor::TextEditor(){
    // Initalizes the member variables with default values
    m_fileName = "";
    m_editor = Document();
}

// MainMenu
// Given: None, Returns valid choice (1-8) only
int TextEditor::MainMenu(){
    int option; // The option from 1-8 that the user chooses

    // The main menu of Text Editor
    // The user can choose to participate or exit
    cout << "--- Simple Text Editor ---" << endl;
    cout << "1. Insert Line" << endl;
    cout << "2. Delete Line" << endl;
    cout << "3. Edit Line" << endl;
    cout << "4. Display Document" << endl;
    cout << "5. Search Word" << endl;
    cout << "6. Save to File" << endl;
    cout << "7. Load from File" << endl;
    cout << "8. Exit" << endl;
    
    // If the user chooses to partipates, then the game starts
    // If the user chooses to exit, the game ends
    cout << "Enter your choice: " << endl;
    cin >> option; 
    while(true){
        // If the input is invaild, the user is prompt to try again.
        if(cin.fail() || option < 1 || option > 8){
        cin.clear();
        cin.ignore(256, '\n');
        cout << endl;
        cout << "--- Simple Text Editor ---" << endl;
        cout << "1. Insert Line" << endl;
        cout << "2. Delete Line" << endl;
        cout << "3. Edit Line" << endl;
        cout << "4. Display Document" << endl;
        cout << "5. Search Word" << endl;
        cout << "6. Save to File" << endl;
        cout << "7. Load from File" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> option;
        }else{
            break;
        }
    }
    // Returns the user's choice
    return option;

}

// GetLineNumber 
// Given: A boolean value, returns the line number chosen by user
int TextEditor::GetLineNumber(bool isExact){
    int line_num; // The line number that the user selects
    cout << "Enter line number: " << endl;
    cin >> line_num;
    // If the line number is not exact and between 1
    // and the number of lines + 1, then the user wants to 
    // insert their line.
    if(!isExact){
        if(line_num >= 1 && line_num <= m_editor.GetLineCount() + 1){
            return line_num;
        }
     // If the line number is exact and between 1
    // and the number of lines, then the user wants to 
    // delete or edit their line.
    }else if(isExact){
        if(line_num >= 1 && line_num <= m_editor.GetLineCount()){
            return line_num;
        }
    }
    // Otherwise, the line number doesn't exist in document.
    return -1;
}

// GetFileName
// Given: None, returns a valid file name
string TextEditor::GetFileName(){
    string file; // The file name that the user wants to open or load
    cout << "Enter the file name:" << endl;
    getline(cin, file);
    while(true){
        // If the input is invaild, the user is prompt to try again.
        if(cin.fail()){
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter the file name:" << endl;
            getline(cin, file);
        }else{
            break;
        }
    }
    // The user's file name gets stored into the m_fileName member variable
    m_fileName = file;
    return m_fileName;    
}

// Start
// Given: None, starts the entire Text Editor
void TextEditor::Start(){
    int menu = 0; // stores the user's choice
    while(menu != 8){
        // The game will contiune to play until
        // the user wants to exit, which is 8.
        cout << endl;
        menu = MainMenu();
        switch(menu){
            case 1:
                // If the user choose 1, their line gets inserted
                cout << "**Insert Line**" << endl;
                if(cin.peek() == '\n'){
                    cin.ignore();
                }
                InsertLine();
                break;
            case 2:
                // If the user choose 2, their line gets deleted
                cout << "**Delete Line**" << endl;
                if(cin.peek() == '\n'){
                    cin.ignore();
                }
                DeleteLine();
                break;
            case 3:
                // If the user choose 3, they can edit their line
                cout << "**Edit Line**" << endl;
                if(cin.peek() == '\n'){
                    cin.ignore();
                }
                EditLine();
                break;
            case 4:
                // If the user choose 4, their document gets displayed
                cout << "**Display Document**" << endl;
                if(cin.peek() == '\n'){
                    cin.ignore();
                }
                m_editor.DisplayDocument();
                break;
            case 5:
                // If the user choose 5, they can search for lines that contains
                // their chosen word
                cout << "**Search Document**" << endl;
                if(cin.peek() == '\n'){
                    cin.ignore();
                }
                SearchDocument();
                break;
            case 6:
                // If the user choose 6, they can save their document into 
                // their file
                cout << "**Save File**" << endl;
                if(cin.peek() == '\n'){
                    cin.ignore();
                }
                SaveFile();
                break;
            case 7:
                // If the user choose 7, they can load their file to 
                // their document
                cout << "**Load File**" << endl;
                if(cin.peek() == '\n'){
                    cin.ignore();
                }
                LoadFile();
                break;
            case 8:
                // If the user choose 8, the Text Editor will exit
                cout << "Thank you for using the Text Editor" << endl;
                break;
        }
    }
}

// InsertLine
// Given: None, inserts a line if valid
void TextEditor::InsertLine(){
    int num; // The line that the user wants to insert
    string text; // The text that the user wants at their specfic
                 // line number
    if(m_editor.GetLineCount() == 0){
        // If the document is empty, then the user's text will be
        // the first line of their document
        cout << "Enter text: " << endl;
        getline(cin, text);
        while(true){
            // If the input is invaild, the user is prompt to try again.
            if(cin.fail()){
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Enter new text: " << endl;
                getline(cin, text);
            }else{
                break;
            }
        }
        m_editor.InsertLine(text, 1);
    }else{
        // If their document is not empty, then their document gets displayed
        // If the user's line number is invalid
        // then they will be prompted to try again
        cout << "Inserts line before chosen line number" << endl;
        m_editor.DisplayDocument();
        num = GetLineNumber(false);
        while(true){
            if(cin.fail() || num == -1){
                // If the input is invaild, the user is prompt to try again.
                cout << "Must be between 1 and " << m_editor.GetLineCount() + 1
                << endl;
                cin.clear();
                cin.ignore(256, '\n');
                m_editor.DisplayDocument();
                num = GetLineNumber(false);
            }else{
                break;
            }
        }
        // If the document is not empty, the user can insert their text
        // and line number at any valid position they desire.
        if(cin.peek() == '\n'){
            cin.ignore();
        }
        cout << "Enter text: " << endl;
        getline(cin, text);
        while(true){
            // If the input is invaild, the user is prompt to try again.
            if(cin.fail()){
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Enter new text: " << endl;
                getline(cin, text);
            }else{
                break;
            }
        }
        // inserts user's line
        m_editor.InsertLine(text, num);
    }
}

// DeleteLine
// Given: None, deletes a line if valid
void TextEditor::DeleteLine(){
    int num; // The line that the user wants to delete
    if(m_editor.GetLineCount() == 0){
        // If the document is empty, then the user can't delete any line
        cout << "There is no line to delete" << endl;
        return;
    }
    // If their document is not empty, then their document gets displayed
    // If the user's line number is invalid
    // then they will be prompted to try again
    m_editor.DisplayDocument();
    num = GetLineNumber(true);
    while(true){
        if(cin.fail() || num == -1){
            cout << "Must be between 1 and " << m_editor.GetLineCount()
            << endl;
            cin.clear();
            cin.ignore(256, '\n');
            m_editor.DisplayDocument();
            num = GetLineNumber(true);
        }else{
            break;
        }
    }
    // The user gets to delete their chosen line
    m_editor.DeleteLine(num);
}

// EditLine
// Given: None, edits the user's chosen line
void TextEditor::EditLine(){
    int num; // The line that the user wants to edit
    string text; // The new text that the user wants replace their old text
    if(m_editor.GetLineCount() == 0){
        // If the document is empty, then the user can't edit any line
        cout << "There is no line to edit" << endl;
        return;
    }
    // If their document is not empty, then their document gets displayed
    // If the user's line number is invalid
    // then they will be prompted to try again
    m_editor.DisplayDocument();
    num = GetLineNumber(true);
    while(true){
        if(cin.fail() || num == -1){
            cout << "Must be between 1 and " << m_editor.GetLineCount()
            << endl;
            cin.clear();
            cin.ignore(256, '\n');
            m_editor.DisplayDocument();
            num = GetLineNumber(true);
        }else{
            break;
        }
    }
    // The user can now edit their line
    // User's new text must be valid in order to edit their line
    // Otherwise, they will get prompted to try again
    if(cin.peek() == '\n'){
        cin.ignore();
    }
    cout << "Enter new text: " << endl;
    getline(cin, text);
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter new text: " << endl;
            getline(cin, text);
        }else{
            break;
        }
    }
    // Edits the user's current line to their new text
    m_editor.EditLine(num, text);

}

// SearchDocument
// Given: None, searches and displays all lines that have the matching text. 
void TextEditor::SearchDocument(){
    string text; // The text that the user wants to search for
    if(m_editor.GetLineCount() == 0){
        // If the document is empty, then the user can't search for any line
        cout << "There is no line to search." << endl;
        return;
    }
    // User searches for any line that contains the text 
    // they want to search for
    // If input is invalid, they will be prompted to try again
    cout << "Enter the word to search: " << endl;
    getline(cin, text);
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter the word to search: " << endl;
            getline(cin, text);
        }else{
            break;
        }
    }
    // Displays the lines that contains the text
    m_editor.SearchWord(text);
}

// SaveFile
// Given: None, saves current document to the file
void TextEditor::SaveFile(){
    // Asks for user's file name, and inserts all lines from
    // their document into the file
    m_editor.SaveToFile(GetFileName());
}

// LoadFile
// Given: None, loads all lines from file to the document
void TextEditor::LoadFile(){
    // Asks for user's file name, and inserts all lines from
    // their file into the document
    m_editor.LoadFromFile(GetFileName());   
}