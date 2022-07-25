/*
The assignment for the end of course you must create a code, of a point of sale. You are free to choose the implemented method.

But you are restricted to follow the next requirements:

-A menu for choosing between a cotization, cashout(corte de caja), or just saling.
-You are free to choose the amount of money to start the day. and after the cashout, the same amount of money has to be. 
-The code must include operations of every ITEM, (Discounts if is it necessary).
-The program must ask to the user, the payment method, (Cash, debit or credit.) 
-At the terminal must include all every operation of each item as well as how were it payed(The sum of every ITEM)(ticket)
-Also must include a .txt file with the ticket ready to print. 
-Every Section of the code must be explained as a comment, it is not necessary to comment each line of code. 
-At the start of the program, all team member's name must be presented. 

					Brianna Ayelen Balam Velasco
					Jesus Javier Can Noh
					Damaris Yuselin Dzul Uc
*/
#include <iostream>
#include <stdio.h>
#include <array>
#include<string.h>
#include<stdlib.h>

using namespace std;
//Declaration of the 2 arrays for the product's information
	//Product's names
	array<string, 15>productName = {
		"Dark chocolate brownie",
		"Chocolate cake",
		"Vainila cake",
		"Cheesecake",
		"Apple pie",
		"Blueberry muffins",
		"Chocolate fudge",
		"Red velvet cake",
		"Carrot cake",
		"Tiramisu cake",
		"Peanut butter cake",
		"Nutella strawberry cake",
		"Pistachio macron",
		"Rainbow cupcake",
		"Banana chocolate cupcake",		
	};
	
	//Product's prices
	array<double, 15>productPrice = {
		20.50,
		400,
		400,
		350,
		250,
		15.50,
		10.50,
		450,
		380,
		450,
		480,
		450,
		20.50,
		18.50,
		18.50,			
	};
	
	double initialAmount = 1500.50; //Declaration of initial Amount
	int action, i, productQuantity, productCode; //Declaration of the int action that will be use for the switch-case function to store to store the action that the customer wants to perform 
	int amount; //La vdd no se como explicar este xd
	double total;
	
void productSearch(){
	int counter = 0;
	
	for(i=0; i<15; i++){
		
		if(i == productCode){
			cout<<"  "<<productCode<<"\t\t";
			cout<<productName[i]<<"\t     ";
			cout<<productQuantity<<"\t\t\t ";
			cout<<productPrice[i]<<endl;
			
			cout<<"=======================================================================================" << endl;
		}
		
		if(i == productCode){
			cout<<" TOTAL                                                           "<<productQuantity * productPrice[i]<<endl;
		}
		
	}
}


int main(){	
	
	//Initialization of the menu
	cout<< "\n\a\t ****** Welcome to UPY bakery ****** \n"<<endl;
	cout<< "Our menu is: \n";
	for(int i=0; i<15; i++){					
		cout<<"\t CODE: "<<i<<"\t NAME: "<<productName[i]<<"\t PRICE: "<<productPrice[i]<<endl;				
	}
	
	
	do{
		
	cout<< "\n What do you want to do?"<<endl;
	cout<< " \a\t Press 1 for COTIZATION \n"<<"\a\t Press 2 for CASHOUT \n"<<"\a\t Press 3 for SALING \n"<<"\a\t Press 4 for EXIT \n\n";
	cin>>action;
	
	//Intialization of switch-case function
	switch (action){
		
		case 1:		
	
			cout<<"\n Enter the code of the products that you want to quote: "<<endl;
			cin>>productCode;
			
			cout<<"\n How many pieces do you want? "<<endl;
			cin>>productQuantity;
			
			cout<<"=======================================================================================" << endl;
			cout<<"  CODE  "<<"\t DESCRIPTION \t"<<"\t QUANTITY \t"<<"\t PRICE \t"<<endl;
			cout<<"=======================================================================================" << endl;
        	
			//cout<<ProductName[i]<<"     ";
			
            productSearch();
            cout<<"=======================================================================================" << endl;

			
	}
	
	/*switch (action){
			
		case 2:	

			
			}*/
			
	
	
	}while (action != 4);	
	
	return 0;
}
