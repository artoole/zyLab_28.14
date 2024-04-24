#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
ItemToPurchase(); //default constructor
ItemToPurchase(string name,string descr,int price,int quantity);
void SetName(string name);
string GetName() const;
void SetPrice(int price);
int GetPrice() const;
void SetQuantity(int quantity);
int GetQuantity() const;
void SetDescription(string descr);
string GetDescription() const;
void PrintItemCost();
void PrintItemDescription();

private:
string itemName;
string itemDescription;
int itemPrice;
int itemQuantity;
};

#endif
