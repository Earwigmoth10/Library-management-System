#include <iostream>
#include<windows.h>
using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
const int MAX_BOOKS = 100;  // Maximum number of books that can be stored

// Arrays to store book titles, years, and editions
string bookTitles[MAX_BOOKS];
int bookYears[MAX_BOOKS];
string bookEditions[MAX_BOOKS];  // Array to store editions
int bookCount = 0;  // To keep track of how many books are added

// Function to add a book
void Add() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full, cannot add more books!" << endl;
        return;
    }
    
    string title, edition;
    int year;
    
    cout << "Book Title: ";
    cin.ignore();  // To clear any leftover newline character
    getline(cin, title);  // Use getline to allow spaces in the title
    
    cout << "Published Year: ";
    cin >> year;
    
    cout << "Edition (e.g., 1st, 2nd, Revised, etc.): ";
    cin.ignore();  // To clear the input buffer again before taking the edition input
    getline(cin, edition);  // Use getline to allow spaces in the edition

    // Store the book details in the arrays
    bookTitles[bookCount] = title;
    bookYears[bookCount] = year;
    bookEditions[bookCount] = edition;  // Store edition

    bookCount++;  // Increment the book count to move to the next book

    cout << "Book stored into Library!" << endl;
}

// Function to display all books
void Display() {
    if (bookCount == 0) {
        cout << "No books in the library." << endl;
        return;
    }

    cout << "\t\t\t\t\tBooks in the library are:" << endl;
    for (int i = 0; i < bookCount; i++) {
        cout << "Book " << i + 1 << ": " << bookTitles[i] << " (" << bookYears[i] << "), Edition: " << bookEditions[i] << endl;
    }
}

// Function to search for a book by both title and edition
void Search() {
    string searchTitle, searchEdition;
    
    cout << "Enter the title to search: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, searchTitle);

    cout << "Enter the edition to search: ";
    getline(cin, searchEdition);  // Get the edition of the book to search for

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        // Check if both the title and edition match
        if (bookTitles[i] == searchTitle && bookEditions[i] == searchEdition) {
        	SetConsoleTextAttribute(h,100);
            cout << "Found Book: " << bookTitles[i] << " (" << bookYears[i] << "), Edition: " << bookEditions[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
    	SetConsoleTextAttribute(h,120);
        cout << "Book not found!" << endl;
        
    }
}

int main() {
    int choice;
    
    SetConsoleTextAttribute(h,14);
    cout << "\t\t\t\t\t\t             **********************************\n" << endl;
    cout << "\t\t\t\t\t\t             *                                *\n" << endl;
    cout << "\t\t\t\t\t\t             *                                *\n" << endl;
    cout << "\t\t\t\t\t\t             *  ----------------------------  *\n" << endl;
    cout << "\t\t\t\t\t\t             *  TUFIANS  WELCOME  TO  LIBRARY *\n" << endl;
    cout << "\t\t\t\t\t\t             *  ----------------------------  *\n" << endl;
    cout << "\t\t\t\t\t\t             *                                *\n" << endl;
    cout << "\t\t\t\t\t\t             *                                *\n" << endl;  
    cout << "\t\t\t\t\t\t             **********************************\n" << endl;
    do {
    	SetConsoleTextAttribute(h,3);
    	cout << "**********************************" << endl;
    	cout << "Menu:" << endl;
    cout << "Enter 1 for ADD Book" << endl;
    cout << "Enter 2 for Display Books" << endl;
    cout << "Enter 3 to Search for Book Title and Edition" << endl;
    cout << "Enter 4 for EXIT" << endl;
    cout << "**********************************" << endl; 
    
        cin >> choice;
        switch (choice) {
            case 1:
            	SetConsoleTextAttribute(h,6);
                Add();
                break;
            case 2:
            	SetConsoleTextAttribute(h,4);
                Display();
                break;
            case 3:
            	SetConsoleTextAttribute(h,6);
                Search();  // Call the Search function to search for a book by both title and edition
                break;
            case 4:
            	SetConsoleTextAttribute(h,10);
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
            	SetConsoleTextAttribute(h,100);
                cout << "Sorry You entered an invalid key!" << endl;
        }
    } while (choice != 4);  // Loop until user chooses to exit
     // Set background to red and text to bright white

    return 0;
}
