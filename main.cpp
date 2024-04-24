
#include <iostream>
#include <limits>
#include "ShoppingCart.h"

using namespace std;

// Function prototypes
void PrintMenu();
void ExecuteMenu(char option, ShoppingCart& theCart);

int main() {
    string customerName, currentDate;
    char menuOption;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl;
    getline(cin, currentDate);

    ShoppingCart myCart(customerName, currentDate);
    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;

    do {
        PrintMenu();
        cin >> menuOption;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

        // As long as we don't want to quit, keep executing the menu commands
        if (menuOption != 'q') {
            ExecuteMenu(menuOption, myCart);
        }

    } while (menuOption != 'q');

    return 0;
}

void PrintMenu() {
    cout << "\nMENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << "\nChoose an option: ";
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
    string itemName, itemDescription;
    int itemPrice, itemQuantity;

    switch (option) {
        case 'a': {
            // Add item to cart logic here
            cout << "ADD ITEM TO CART" << endl;
            break;
        }
        case 'd': {
            // Remove item from cart logic here
            cout << "REMOVE ITEM FROM CART" << endl;
            break;
        }
        case 'c': {
            // Change item quantity logic here
            cout << "CHANGE ITEM QUANTITY" << endl;
            break;
        }
        case 'i': {
            // Output items' descriptions logic here
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            break;
        }
        case 'o': {
            // Output shopping cart logic here
            cout << "OUTPUT SHOPPING CART" << endl;
            break;
        }
        case 'q': {
            // No need to do anything here as the main loop will handle quitting
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}
