#include <iostream>
#include <iomanip>
using namespace std;


#include "ShoppingCart.h"


bool showMenu = true;
void PrintMenu() {
   cout<<"MENU"<<endl;
   cout<<"a - Add item to cart\nd - Remove item from cart\nc - Change item quantity\ni - Output items' descriptions\no - Output shopping cart\nq - Quit"<<endl;
   cout<<endl;
   
   

}

void ExecuteMenu(char option, ShoppingCart& theCart) {
	string name,descr;
	int price,quantity;
	if(option=='a')
	{
	      cout << "ADD ITEM TO CART" << endl;
			cout << "Enter the item name:" << endl;
			getline(cin, name);
			cout << "Enter the item description:" << endl;
			getline(cin, descr);
			cout << "Enter the item price:" << endl;
			cin >> price;
cin.ignore();
			cout << "Enter the item quantity:" << endl;
			cin >> quantity;
cin.ignore();
			cout << endl;
			ItemToPurchase item(name,descr,price,quantity);
			theCart.AddItem(item);
		}
		else if(option=='d')
		{
		   cout << "REMOVE ITEM FROM CART"<<endl;
			cout << "Enter name of item to remove:";
			getline(cin, name);
			theCart.RemoveItem(name);
			cout << endl;
		}
		else if(option=='c')
		{
		   cout << "CHANGE ITEM QUANTITY" << endl;
			cout << "Enter the item name:" << endl;
			getline(cin, name);
			cout << "Enter the new quantity:" << endl;
			cin >> quantity;
cin.ignore();
			theCart.ModifyItem(name,"none",0,quantity);
			}
			else if(option=='i')
			{
			theCart.PrintDescriptions();
			}
			else if(option=='o')
		{
			theCart.PrintTotal();
		}

		showMenu = true;
	
}

int main() {

string cname,tdate;

cout<<"Enter customer's name:"<<endl;
getline(cin,cname);
cout<<"Enter today's date:"<<endl;
getline(cin,tdate);
ShoppingCart cart(cname,tdate);
cout<<endl;
cout<<"Customer name: "<<cname<<endl;
cout<<"Today's date: "<<tdate<<endl <<endl;
char ch = ' ';
showMenu = true;
while(ch!='q')
{
	if(showMenu){
	   PrintMenu();
	   showMenu = false;
	}
	//clear input buffer before prompting for second item
	cout<<"Choose an option:"<<endl;
	cin >> ch;
	cin.ignore();
	if(ch == 'q'){
	   break;
	}
	else if(ch == 'a' || ch == 'c' || ch == 'd' || ch == 'i' || ch == 'o'){
	  ExecuteMenu(ch,cart);	 
	}
}



 

return 0;
}
