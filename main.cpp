#include <iostream>
#include <iomanip>
#include "ShoppingCart.h"
using namespace std;

void PrintMenu() {
    cout << "MENU\n";
    cout << "a - Add item to cart\n";
    cout << "d - Remove item from cart\n";
    cout << "c - Change item quantity\n";
    cout << "i - Output items' descriptions\n";
    cout << "o - Output shopping cart\n";
    cout << "q - Quit\n";
}

void ExecuteMenu(char choice, ShoppingCart& cart) {
    switch (choice) {
        case 'a': {
            // Add item to cart
            string name, description;
            int price, quantity;
            cout << "ADD ITEM TO CART\n";
            cout << "Enter the item name:\n";
            getline(cin >> ws, name);
            cout << "Enter the item description:\n";
            getline(cin >> ws, description);
            cout << "Enter the item price:\n";
            cin >> price;
            cout << "Enter the item quantity:\n";
            cin >> quantity;
            ItemToPurchase item(name, description, price, quantity);
            cart.AddItem(item);
            break;
        }
        case 'd': {
            // Remove item from cart
            string name;
            cout << "REMOVE ITEM FROM CART\n";
            cout << "Enter name of item to remove:\n";
            getline(cin >> ws, name);
            cart.RemoveItem(name);
            break;
        }
        case 'c': {
            // Change item quantity
            string name;
            int quantity;
            cout << "CHANGE ITEM QUANTITY\n";
            cout << "Enter the item name:\n";
            getline(cin >> ws, name);
            cout << "Enter the new quantity:\n";
            cin >> quantity;
            ItemToPurchase item(name, "", 0, quantity);
            cart.ModifyItem(item);
            break;
        }
        case 'i': {
            // Output items' descriptions
            cart.PrintDescriptions();
            break;
        }
        case 'o': {
            // Output shopping cart
            cart.PrintTotal();
            break;
        }
        case 'q':
            // Quit
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid option! Please try again.\n";
    }
}

int main() {
    string customerName, currentDate;
    cout << "Enter customer's name:\n";
    getline(cin >> ws, customerName);
    cout << "Enter today's date:\n";
    getline(cin >> ws, currentDate);

    ShoppingCart cart(customerName, currentDate);
    char choice;
    do {
        PrintMenu();
        cout << "Choose an option:\n";
        cin >> choice;
        cin.ignore(); // ignore newline character
        ExecuteMenu(choice, cart);
    } while (choice != 'q');

    return 0;
}
