/* This header file contains major display and input requests as well as displaying the list to the user */

#ifndef DISPLAYMANAGEMENT_H_INCLUDED
#define DISPLAYMANAGEMENT_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

/*============================*/

void menu(int &a) // function which displays the menu to the user and gets menu select input
{
    cout << endl; // display the menu of what options the user can select and get input at the very end
    cout << "==========MENU==========" << endl;
    cout << "What do you want to do with the list?"<< endl;
    cout << "(1) add an item to the inventory" << endl;
    cout << "(2) update an item in the inventory" << endl;
    cout << "(3) delete an item from the inventory" << endl;
    cout << "(4) display an item from the inventory" << endl;
    cout << "(5) display the entire inventory" << endl;
    cout << "(6) end program and save to file" << endl;
    cin >> a; // get input
}

/*============================*/

void displayLogo() // function to display the logo of the program
{
    cout << "FRED'S JUNK TRUCK INVENTORY PROGRAM v0.1.1";
    cout << endl << endl;
}

/*============================*/

void displayList(link* head) // function to display every item in the linked list
{
    link* temp = head; // set the temp to point to the head
    cout << endl << "Name, Id, Number of Units, and Description" << endl; // header
    while(temp != NULL) // while the list has not ended, display each link's contents
    {
        cout << endl; // display name, id, units and the description
        cout << "Name: " << temp->name << " ";
        cout << endl;
        cout << "ID Number: " << temp->idNumber << " ";
        cout << endl;
        cout << "Units in stock: " << temp->units;
        cout << endl;
        cout << "Description: " << temp->description;
        cout << endl;
        temp = temp->next; // move along the list
    }
}

/*============================*/

void printSpecific(link* head, int elements) // function to print a specific element
{
    link* temp = head; // set the temp variable to point to the head of the list and input variables
    int position = 0;
    int input;

    cout << endl << "Items: " << endl; // display header for the possible items to display
    while(temp != NULL) // while the list did not end
    {
        cout << position + 1 << "." << temp->name << " "; // display the name of the element
        temp = temp->next; // move along the list
        position++; // increase count variable
    }

    temp = head; // reset the temp variable to point to the head of the list
    cout << endl << "Give the position of what name to be displayed: "; // ask for which element will be displayed
    cin >> input; // get that position

    while(input <= 0 || input > elements) // while users input is not 1-the total links
    {
        cout << endl << "Invalid input, please give valid input: "; // get new input
        cin >> input;
    }

    for(int tick = 0; tick < input - 1; tick++) // for loop to move along the list until selected element is found
    {
        temp = temp->next;
    }

        cout << endl << "Name, Id, Number of Units, and Description" << endl; // display the gotten link to the user

        cout << endl;
        cout << "Name: " << temp->name << " ";
        cout << endl;
        cout << "ID Number: " << temp->idNumber << " ";
        cout << endl;
        cout << "Units in stock: " << temp->units;
        cout << endl;
        cout << "Description: " << temp->description;
        cout << endl;
}
/*============================*/
#endif // DISPLAYMANAGEMENT_H_INCLUDED
