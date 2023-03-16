#include <iostream>
#include <fstream>
#include "linkManagement.h"
#include "displayManagement.h"
#include "fileManagement.h"

using namespace std;

int main()
{               // variables used across the program
    int trigger; // trigger is used to check which menu option was selected
    int tick = 0; // tick is used to see if the menu has been displayed outside of the menu select switch statement
    int elements = 0; // total number of links in the list
    int validFiles = 0; // total file check variable
    string input;

    link* head = NULL; // define the head of the linked list and a temp link holder
    link* newLink;

    checkForFiles(validFiles); // call function to check if all required files are present

    if(validFiles == 3) // if all files are present
    {
        loadFile(&head, elements); // load what is saved in the files
    }
    else
    {
        cout << endl << "Missing a required file/files, defaulting to creating new list" << endl; // otherwise default to making a new save
    }

    displayLogo(); // display the logo of the program and display the menu
    menu(trigger); // also get user input for menu selection

    while(trigger != 6) // while 6 was not selected
    {
        if(tick == 1) // check to see if menu should be displayed
        {
           menu(trigger);
        }

    switch(trigger) // menu selection
    {
    case 1: // case 1 is for the user to create a new element and put it into the list in order
        newLink = newlink();
        sortedInsert(&head, newLink);
        elements++; // add 1 to the total elements
        break;
    case 2: // case 2 is to update an entry
        updateEntry(head, elements); // updates a existing link then sorts the list so links are in order
        head = selectionSort(head);
        break;
    case 3: // case 3 is to delete an entry
        if(elements <= 0) // if no elements exist display a error message
        {
            cout << endl << "No items in the list so none can be deleted" << endl;
        }
        else // otherwise delete an entry while decreasing the total elements by 1
        {
            deleteName(&head);
            --elements;
        }
        break;
    case 4: // case 4 is to display a specific element
        printSpecific(head, elements); // call function to handle specific display
        break;
    case 5: // case 5 is to display the whole list
        if(elements <= 0) // if no elements exist display an error
        {
            cout << "Error, no items to display" << endl;
        }
        else // otherwise display the list
        {
            displayList(head);
        }
        break;
    case 6: break; // case 6 will trigger the program to close
    default: cout << endl << "Option not found, give a valid option" << endl; // default for errors
        break;
    }
        tick = 1; // set the trigger variable to 1, this lets the menu be displayed once more
    }

    writeFile(head); // call function to write the list to a file

    if(elements >= 1) // if elements exist delete the list
    {
       deleteList(head,elements);
    }
    return 0;
}
