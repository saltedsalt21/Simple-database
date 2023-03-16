/* This header file contains major display and input requests as well as displaying the list to the user */

#ifndef LINKMANAGEMENT_H_INCLUDED
#define LINKMANAGEMENT_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

/*============================*/

class link // link class that will be used to hold the information given by the user and files
{
public:
    string name; // the name, id, units and description are used in addition to a pointer to the next link
    int idNumber;
    int units;
    string description;
    link* next;
};

/*============================*/

void sortedInsert(link** head, link* newLink) // function
{
    link* current; // define a current link variable

    if(*head == NULL || (*head)->name >= newLink->name) // if the head of the link is null or the the name of the head is greater than the new name
    {
        newLink->next = *head; // set the the pointer of the new link to null
        *head = newLink; // and set the head to the newlink
    }
    else // otherwise
    {
        current = *head; // set a position variable to point to the head
        while(current->next != NULL && current->next->name < newLink->name) // while the current link is not the last and the next link is less than the new links name
        {
            current = current->next; // move along the list
        }
        newLink->next = current->next; // when done set the newlink to point to the next variable
        current->next = newLink; // and set the current link to point to the new link
    }
}

/*============================*/

link* selectionSort(link* head) // function to sort the list right after a modification of a link
{
    link *a;
    link *b;
    link *c;
    link *d;
    link *e;

    a = head;
    b = head;

    while(b->next) // while b is not the last link
        {
        c = b->next;
        d = b->next;

        while(d) // when d is pointing to a link
            {
            if(b->name > d->name)
                {
                if (b->next == d) // if d is after b
                    {
                    if (b == head) // if b is the head of the list
                        {
                            b->next = d->next; // move d before b appears
                            d->next = b;

                            e = b; // Swap b and d
                            b = d;
                            d = e;

                            c = d;

                            head = b; // Update the head

                            d = d->next; // move to the next element
                        }
                    else // otherwise
                    {
                        b->next = d->next; // Move d before b
                        d->next = b;
                        a->next = d;

                        e = b; // Swap b and d
                        b = d;
                        d = e;

                        c = d;

                        d = d->next; // move to the next element
                    }
                }
                    else
                    {
                    if (b == head) // if b is the head of the list
                    {
                        e = b->next; // swap b and d pointers
                        b->next = d->next;
                        d->next = e;
                        c->next = b;

                        e = b; // swap b and d pointers
                        b = d;
                        d = e;

                        c = d;

                        d = d->next; // move to the next element
                        head = b; // Update the head
                    }
                    else // if b is not the head
                    {
                        e = b->next; // Swap b and d pointers as well as as setting c and a to b and d
                        b->next = d->next;
                        d->next = e;
                        c->next = b;
                        a->next = d;

                        e = b; // Swap b and d pointers
                        b = d;
                        d = e;

                        c = d; // set c to d

                        d = d->next; // move to the next element
                    }
                }
            }
            else
            {
                c = d; // update c and move to the next element
                d = d->next;
            }
        }

        a = b; // move along the list
        b = b->next;
    }

    return head; // return the head of list
}

/*============================*/

link* newlink() // function to create a new link to be put in the list
{
    link* newLink = new link(); // dynamically allocate a new link

    string newName; // define temp variables to hold user input
    int number;
    int units;
    string description;

    cout << endl << "Give the Name of the item: "; // get the name
    cin.ignore();
    getline(cin,newName);
    cout << endl << "Give the Id number of the item: "; // get the id number
    cin >> number;
    cout << endl << "Give the number of units in stock for the item: "; // get the amount of units
    cin >> units;
    cout << endl << "Give the description of the item: "; // get the description of the item
    cin.ignore();
    getline(cin,description);

    newLink->name = newName; // set the new link equal to the given values
    newLink->idNumber = number;
    newLink->units = units;
    newLink->description = description;
    newLink->next = NULL; // set it's pointer to none

    return newLink; // return the link
}

/*============================*/

void deleteName(link** head) // function to remove a specified item from the list
{
    link* deleteTarget = *head; // declare variables such as the delete target
    link* before = *head; // before the target
    link* after = deleteTarget->next; // after the target
    link* pointer = *head; // a pointer to the head
    string target; // the target link
    int targetPosition = 0; // target position
    int position = 0; // position variable
    int temp = 0; // a temp

    if(*head == NULL) // if the head is null
    {
        cout << endl << "No items made, please make items first"; // display a error and end the function
        return;
    }

    cout << endl << "Items: " << endl; // display a header
    while(pointer != NULL) // while the list has not ended
    {
        cout << position + 1 << "." << pointer->name << " "; // display the name of the pointer
        pointer = pointer->next; // move along the list
        position++; // increase the position
    }

    cout << endl << "Which item will be deleted: "; // get input for which item will be deleted
    cin >> targetPosition;

    while(targetPosition < 1 || targetPosition > position) // check to see if the user select is valid
    {
        cout << endl << "Invalid input, give valid input: "; // if not display error and get new input
        cin >> targetPosition;
    }


    pointer = *head; // reset the pointer variable
    position = 0; // set position variable to zero
    while(pointer != NULL) // while the pointer is not null
    {
        position++; // increase the position variable
        if(position == targetPosition) // if the position is the target position
        {
            target = pointer->name; // set the target name to be that name
        }
        pointer = pointer->next; // move along the list
    }

    while(deleteTarget->next != NULL && deleteTarget->name != target) // while the end of the list is not found and the delete target link is not the target
        {
            deleteTarget = deleteTarget->next; // move along the array
            if(temp > 0) // if the temp is greater than 1
            {
                before = before->next; // move the pointer to before that delete target up
            }
            after = after->next; // move the after link up
            temp++;
        }
        if(temp == 0) // if the temp  is zero
        {
            *head = after; // set the head of the link to after the delete target
        }
        else
        {
            before->next = after; // otherwise set the before link to the link after the delete target
        }

        delete deleteTarget; // delete the target link
}

/*============================*/

void updateEntry(link* head, int &elements) // function to update a specific entry
{
    link* current = head; // set a current variable to point to the head and a temp
    link* temp = head;
    int position = 0; // also a position variable and input
    int input;


    cout << endl << "Items: " << endl; // display the elements in the list by name only
    while(temp != NULL)
    {
        cout << position + 1 << "." << temp->name << " "; // display the name
        temp = temp->next; // move along the list
        position++; // increase position
    }

    cout << endl << "Which item would you like to modify?: "; // get input from the user
    cin >> input;

    while((input - 1) < 0 || (input - 1) > (position - 1)) // check to see if the input is within the elements of the list
    {
        cout << endl << "Input invalid please give valid input: "; // if not display error and get new input
        cin >> input;
    }

    for(int i = 0; i < input - 1; i++) // move along the list until the selected element has been reached
    {
        current = current->next;
    }

    cout << endl << "Updating " << current->name; // display which link is being updated
    cout << endl << "Give the updated name of the item: "; // get the new name, id, units, and the description of the item
    cin.ignore();
    getline(cin,current->name);
    cout << endl << "Give the updated Id number of the item: ";
    cin >> current->idNumber;
    cout << endl << "Give the number of units in stock for the updated item: ";
    cin >> current->units;
    cout << endl << "Give the description of the item: ";
    cin.ignore();
    getline(cin,current->description);
}

/*============================*/

void deleteList(link* head, int elements) // function to delete the list
{
    link* temp = head; // set variables to point to the first and second element
    link* temp2 = temp->next;

      for(int tick = 0; tick < elements; tick++) // for the whole list
        {
            delete temp; // delete what temp is pointing to

            if(tick == elements - 1) // if no elements after temp 2 are left do nothing
            {

            }
            else if(tick == elements - 2) // otherwise check to see if two elements are left
            {
                temp = temp2; // if so set temp equal to temp 2
            }
            else // otherwise overall
            {
                temp = temp2; // set temp equal to temp 2
                temp2 = temp->next; // move temp 2 along the list
            }

        }
}

/*============================*/

#endif // LINKMANAGEMENT_H_INCLUDED
