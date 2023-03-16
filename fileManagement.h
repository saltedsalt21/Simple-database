/* This header file contains major functions for dealing with saving and reading inputs and outputs to a file */

#ifndef FILEMANAGEMENT_H_INCLUDED
#define FILEMANAGEMENT_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

/*============================*/

void checkForFiles(int &valid) // function which checks if the files relating to being saved and loaded are present
{
    fstream elementFile; // variables to hold the files which are to be loaded
    fstream saveFile;
    fstream descriptionFile;

    elementFile.open("NumberOfElements.txt"); // load the files which are need to restore previous session
    saveFile.open("save.txt");
    descriptionFile.open("descriptions.txt");

    if(elementFile.is_open()) // check to see if element file is present
    {
        valid++; // if so add 1 to valid check variable
    }
    if(saveFile.is_open()) // check to see if save file is present
    {
        valid++; // if so add 1 to valid check variable
    }
    if(descriptionFile.is_open()) // check to see if description file is present
    {
        valid++; // if so add 1 to valid check variable
    }
}

/*============================*/

void loadFile(link** head, int &totalElements) // function to load the file contents into the linked list
{
    link* current; // variables for the files, a temp for holding a linked list and a current position of the list
    link* newLink;
    fstream file;
    fstream file2;
    fstream numberFile;

    string name; // variables to hold the name number units and description of file input
    int number;
    int units;
    string description;

    file.open("save.txt", ios::in); // open files
    file2.open("descriptions.txt", ios::in);
    numberFile.open("NumberOfElements.txt", ios::in);

    numberFile >> totalElements; // get the total number of expected elements

    for(int i = 0; i < totalElements; i++) // for the total number of elements
    {
        newLink = new link(); // create a new link

        file >> name; // get input for the link
        file >> number;
        file >> units;
        getline(file2,description);

        newLink->name = name; // set the link equal to the input
        newLink->idNumber = number;
        newLink->units = units;
        newLink->description = description;
        newLink->next = NULL; // set next to null

    if (*head == NULL || (*head)->name >= newLink->name) // if the head of the list is null
    {
        newLink->next = *head; // set the newlink to point to the head (which is null)
        *head = newLink; // set the head to point to the new link
    }
    else // otherwise
    {
        current = *head; // set the current target to the head
        while(current->next != NULL && current->next->name < newLink->name) // while the list as not ended and the input gotten is less than the gotten name
        {
            current = current->next; // move along the list
        }
        newLink->next = current->next; // then after, put the new link into the list (where it will be in order)
        current->next = newLink;
    }
    }
    file.close(); // close the files
    file2.close();
    numberFile.close();

    cout << endl << "INVENTORY STATE LOADED" << endl; // display the save was loaded
}

/*============================*/

void writeFile(link* head) // function which will write the generated linked list to files
{
    fstream file; // variables for files to save list to
    fstream file2;
    fstream numberFile;

    int elements = 0; // set elements to zero

    file.open("save.txt", ios::out); // open files
    file2.open("descriptions.txt", ios::out);
    numberFile.open("NumberOfElements.txt", ios::out);

    link* temp = head; // set the temp variable to the head of the linked list

    while(temp != NULL) // while the list has not ended write the linked list to the files
    {
        file << temp->name;
        file << endl;
        file << temp->idNumber;
        file << endl;
        file << temp->units;
        file << endl;
        file2 << temp->description;
        file2 << endl;
        temp = temp->next;

        elements++;
    }

    numberFile << elements; // write the total number of elements found to the number file

    file.close(); // close the files
    file2.close();
    numberFile.close();
    cout << endl << "INVENTORY SAVED TO FILE" << endl; // display that list was saved
}

/*============================*/

#endif // FILEMANAGEMENT_H_INCLUDED
