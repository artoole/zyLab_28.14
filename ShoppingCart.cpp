#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
public:
    // Constructors
    ShoppingCart(const string& customerName = "none", const string& currentDate = "January 1, 2016");
    
    // Public member functions
    string GetCustomerName() const;
    string GetDate() const;
    void AddItem(const ItemToPurchase& item);
    void RemoveItem(const string& itemName);
    void ModifyItem(const ItemToPurchase& item);
    int GetNumItemsInCart() const;
    int GetCostOfCart() const;
    void PrintTotal() const;
    void PrintDescriptions() const;
    
private:
    // Private data members
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};

#endif
