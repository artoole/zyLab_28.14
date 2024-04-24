#include <iostream>
#include <iomanip>
using namespace std;


#include "ShoppingCart.h"



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
			cout << "Enter the item name:" << endl;
			getline(cin, name);
			cout << "Enter the item description:" << endl;
			getline(cin, descr);
			cout << "Enter the item price:" << endl;
			cin >> price;
			cout << "Enter the item quantity:" << endl;
			cin >> quantity;
			
			ItemToPurchase item(name,descr,price,quantity);
			theCart.AddItem(item);
		}
		else if(option=='d')
		{
			cout << "Enter the item name to remove:" << endl;
			getline(cin, name);
			theCart.RemoveItem(name);
			
		}
		else if(option=='c')
		{
			cout << "Enter the item name:" << endl;
			getline(cin, name);
			cout << "Enter the new quantity:" << endl;
			cin >> quantity;
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
		else{
		   cout<<"Choose an option: ";  
		   cout<<endl;
		 }

		
	
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
cout<<"Today's date: "<<tdate<<endl;
cout<<endl;
char ch;


PrintMenu();
cin>>ch;
while(ch!='q')
{
	
	//clear input buffer before prompting for second item
	cin.ignore();
	ExecuteMenu(ch,cart);
	
	
}



 

return 0;
}
