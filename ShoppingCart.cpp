#include <iostream>
#include <cctype>
#include <algorithm>
#include "ItemToPurchase.h"  // Include the header instead of the .cpp file
#include "ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string cname, string date) {
    customerName = cname;
    currentDate = date;
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName) {
    bool found = false;
    cout << endl;
    for (size_t i = 0; i != cartItems.size(); ++i) {
        if (cartItems[i].GetName() == itemName) {
            found = true;
            cartItems.erase(cartItems.begin() + i);
            break;
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(string name, string descr, int price, int quantity) {
    bool found = false;
    for (int i = 0; i != cartItems.size(); ++i) {
        if (cartItems.at(i).GetName() == name) {
            found = true;
            if (descr != "none")
                cartItems.at(i).SetDescription(descr);
            if (price != 0)
                cartItems.at(i).SetPrice(price);
            if (quantity != 0)
                cartItems.at(i).SetQuantity(quantity);
            cout << "Item is Modified." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing modified." << endl <<endl;
    }
}

int ShoppingCart::GetNumItemsInCart() {
    int qty = 0;
    for (auto i = cartItems.begin(); i != cartItems.end(); ++i) {
        qty += i->GetQuantity();
    }
    return qty;
}

int ShoppingCart::GetCostOfCart() {
    int cost = 0;
    for (auto i = cartItems.begin(); i != cartItems.end(); ++i) {
        cost += i->GetQuantity() * i->GetPrice();
    }
    return cost;
}

void ShoppingCart::PrintTotal() {
    cout<< "OUTPUT SHOPPING CART" <<endl;
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   cout << "number of items: " << GetNumItemsInCart() << endl;
   cout << endl;
   if (GetNumItemsInCart() == 0){
      cout << "SHOPPING CART IS EMPTY" << endl;
   }
    for (auto i = cartItems.begin(); i != cartItems.end(); ++i) {
        i->PrintItemCost();
        cout << endl;
    }
    cout <<endl << "Total: $" << GetCostOfCart() << endl <<endl;
}

void ShoppingCart::PrintDescriptions() {
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout<<endl;
    cout << "Item Descriptions" << endl;
    for (auto i = cartItems.begin(); i != cartItems.end(); ++i) {
        i->PrintItemDescription();
        cout << endl;
    }
    cout<<endl;
}

