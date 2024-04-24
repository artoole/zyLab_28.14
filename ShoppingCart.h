#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h" // Ensure this file has include guards too.

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(std::string cname, std::string date);
    std::string GetCustomerName() const;
    std::string GetDate() const;
    void AddItem(ItemToPurchase item);
    void RemoveItem(std::string itemName);
    void ModifyItem(std::string name, std::string descr, int price, int quantity);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();

private:
    std::string customerName;
    std::string currentDate;
    std::vector<ItemToPurchase> cartItems;
};

#endif // SHOPPING_CART_H

