/* Saling point program

		Brianna Ayelen Balam Velasco
		Jesus Javier Can Noh
		Damaris Yuselin Dzul Uc */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

struct productData{//structure for product data
	string name[100];
	float price;
	int code;	
}products[100];

int i, j, read, registerQuantity, adminChoice, adminOption, mainChoice, clientChoice, productQuantity, productCode, differentProducts, repeat, paymentMethod, paymentAmount, secondChance, exitTicket;
float productTotal, accountTotal=0, iva, grandTotal=0, change;
ofstream ticket;//file for ticket
ofstream quotation;//

int mainMenu();
int clientMode();
void dataPetition();
int adminMode();
int cotization();
int productSearch();
int salingTicket();
int saling ();
int payment();


	
int mainMenu(){ //main interface

	
	cout<< "\n\a\t ****** Welcome to Besties Shop ****** \n"<<endl;
	cout<<" Press 1 to Admin Mode"<<endl;
	cout<<" Press 2 to Client Mode \n"<<endl;
	
	cout<<" What do you want to do?"<<endl;
	cin>>mainChoice;
	
	if(mainChoice == 1){
		
		system ("clear");//clear screen
		
		adminMode(); //admin interface
		
	}else if(mainChoice == 2){
		
		system ("clear");
		
		clientMode();//client interface
		
	}
}	

void dataPetition(){ //read data from file

	FILE* fichero; //file pointer
	
	fichero = fopen("products.dat", "wt");//open file
	if(fichero == NULL){ //if file doesn't exist
		printf("We cannot found the file \n");
	}else{
		cout<<" How many items do you want to enter:"<<endl;
		cin>>registerQuantity;
		
		cout<<"\n Enter the following data:"<<endl;
		
		for(i=0; i<registerQuantity; i++){ //read the products data with  loop
			
			cout<<"\n\a\t ****** Product "<<i+1<<" ********\n";
			
			cout<<" Code: "<<i+1<<endl;//write code in terminal
			fprintf(fichero, "CODE: %d \n", i+1);//write code in file
			
			puts("\n Product name (for spaces use the underscore): \n");//write name in terminal
			scanf("%s", &products[i].name);
			fprintf(fichero, "NAME: %s \n", products[i].name); //write name in file
			
			puts("\n Price: \n");//write price in terminal
			scanf("%f", &products[i].price);
			fprintf(fichero, "PRICE: %f \n\n", products[i].price);//write price in file		

		}
	}	
	fclose(fichero);//close file
}

int adminMode(){//admin interface
	
		cout<<"\n\t////////////////////////ADMIN MODE///////////////////////////////////"<<endl;
		
		cout<<"\n Press 1 to Enter items"<<endl;
		cout<<" Press 2 to Show list of products"<<endl;
		cout<<" Press 3 to Switch to Client Mode"<<endl;
		cout<<" Press 4 to Exit \n"<<endl;
		
		cout<<" What do you want to do?"<<endl;
		cin>>adminChoice;
		
		if(adminChoice == 1){ //enter items
			
			system ("clear");//clear screen
			
			dataPetition();
				
		}else if(adminChoice == 2){//show list of products
			
			system ("clear");
			
			cout << "\n Currently there are "<< i<< " products\n"; //show the number of products
			
			if(i>0){
				
				system ("clear");
				
				cout<<"\n The products that are in the list are: \n"<<endl;
			
				for(i=0; i<registerQuantity; i++){
					
					cout<<"\n\a\t ****** Product "<<i+1<<" ********\n";
					cout<<" Code: "<<i+1<<endl;
					printf(" Name: %s \n", products[i].name);
					cout<<" Price: "<<products[i].price<<endl;
				}
										
			}else if(i==0){
					
				cout<<"\n Please return to Admin Menu in order to regiser products"<<endl;
			}
	
								
		}else if(adminChoice == 3){//switch to client mode
			
			system ("clear");
			
			clientMode();
			
		}else if(adminChoice == 4){//exit
			
			return 0;
			
		}
		
		cout<<"\n Press 1 to Return to Admin Menu"<<endl;
		cout<<" Press 2 to Return to Main Menu"<<endl;
		cout<<" Press 3 to Switch to Client Mode"<<endl;
		cout<<" Press 4 to Exit \n"<<endl;
		
		cout<<" What do you want to do?"<<endl;
		cin>>adminOption;
		
		if(adminOption == 1){//return to admin menu
			
			system ("clear");
			
			return adminMode();
			
		}else if(adminOption == 2){//return to main menu
			
			system ("clear");
			
			return mainMenu();
			
		}else if(adminOption == 3){//switch to client mode
			
			system ("clear");
			
			clientMode();
			
		}else if(adminOption == 4){//exit
			
			return 0;
			
		}
		
}

int productSearch(){ //search product by code
		
	
	FILE* quotation;//file pointer
	
	quotation = fopen("quotation.dat", "wt");//open file


	for(i=0; i<registerQuantity; i++){//search the product by code
			
		if(i+1 == productCode){ //if the code is correct
			
			cout<<"  "<<i+1<<"\t\t";//write code in terminal
			fprintf(quotation, "CODE: %d ", i+1);//write code in file
				
			printf(" %s \t\t\t", products[i].name);//write name in terminal
			fprintf(quotation, " DESCRIPTION: %s ", products[i].name);//write name in file
		
			cout<<productQuantity<<"\t\t\t";//write quantity in terminal
			fprintf(quotation, " QUANTITY: %d ", productQuantity);//write quantity in file
				
			cout<<products[i].price<<endl;//write price in terminal
			fprintf(quotation, " PRICE: %f ", products[i].price);//	write price in file
				
			
			cout<<"=======================================================================================" << endl;
		}
		
		if(i+1 == productCode){ //if the code is correct
				
			productTotal= productQuantity*products[i].price; //calculate the total price
				
			cout<<" PRODUCT TOTAL                                                       \t"<<productTotal<<endl;
			fprintf(quotation, " PRODUCT TOTAL: %f \n", productTotal);
		}
		
	}

	fclose(quotation);//close file
	
	accountTotal = productTotal+accountTotal; //calculate the total price 
}



int saling(){//saling interface
	
	cout <<"\n\t///////////////////////////////////////////////////////////////////////////////////\n"<<endl;
	
	cout<<"\t\t\t\t\t SUBTOTAL:  "<<accountTotal<<endl; //show the total price without IVA
	
	iva = accountTotal*0.16;//calculate IVA
	cout<<"\t\t\t\t\t IVA: "<<iva<<endl;//show IVA
	
	grandTotal = accountTotal+iva;//calculate the total price with IVA
	cout<<"\t\t\t\t\t GRAND TOTAL: "<<grandTotal<<endl;//show the total price with IVA
	
	cout <<"\n\t///////////////////////////////////////////////////////////////////////////////////\n"<<endl;
	
	cout<<"\n How would you like to pay?"<<endl;
	cout<<" Press 1 for CASH"<<endl;
	cout<<" Press 2 for CREDIT CARD"<<endl;
	cout<<" Press 3 for DEBIT CARD"<<endl;
	cin>>paymentMethod;
	
	if(paymentMethod == 1){//cash
		
		cout<<"\n Enter the amount you are paying with:"<<endl;
			cin>>paymentAmount;
			
			if(paymentAmount < grandTotal){//if the amount is less than the total price
				
				cout<<"\n Insufficient amount"<<endl;
				
				cout<<"\n Do you want to try again?"<<endl;	
				cout<<" Press 1 for YES"<<endl;
				cout<<" Press 2 for NO"<<endl;
				cin>>secondChance;
				
				if(secondChance == 1){//if the user wants to try again
					
					saling();
					
				}else if(secondChance == 2){//if the user doesn't want to try again
					
					return 0;
				}	
				
				
			}else if(paymentAmount > grandTotal){//if the amount is more than the total price
				
				change = paymentAmount - grandTotal;//calculate the change
				
				cout<<"\n Your change is "<<change;				
				cout<<"\n Wait a moment, we are printing your ticket \n"<<endl;
				
			}else if(paymentAmount > grandTotal){//if the amount is equal to the total price
				
				cout<<"\n Wait a moment, we are printing your ticket \n"<<endl;
				
			}
			
	}else if(paymentMethod == 2){//credit card
		
		cout<<"\n Succesfull payment"<<endl;
		cout<<"Wait a moment, we are printing your ticket \n"<<endl;
		
	}else if(paymentMethod == 3){//debit card
		
		cout<<"\n Succesfull payment"<<endl;
		cout<<"Wait a moment, we are printing your ticket \n"<<endl;
		
	}
	
}


int salingTicket(){ //print the saling ticket
	
	ofstream ticket;//file pointer
	ticket.open("ticket.txt", ios::out);//open file
	
	cout<<"=======================================================================================" << endl;
	
	cout<<"\t\t\t\t\t SALING \t\t\t\t\t"<<endl;
	cout<<"\t\t\t\t      BESTIES SHOP \t\t\t\t\t"<<endl;
	cout<<"\t\t\t Brianna Balam \t Javier Can \t Damaris Dzul \t"<<endl;
	
	cout<<"\n=======================================================================================" << endl;





	cout<<"\n=======================================================================================" << endl;
	
	cout<<"\n \t\t\t\t SUBTOTAL:   "<<accountTotal<<endl;//show the total price without IVA
	ticket<<"\n SUBTOTAL: "<<accountTotal;//write the total price without IVA in file
	
	
	cout<<"=======================================================================================" << endl;
	
	cout<<"\n \t\t\t\t IVA:    "<<iva;//show IVA
	ticket<<"\n IVA: "<<iva;//write IVA in file
	
	cout<<"\n \t\t\t\t GRAND TOTAL:    "<<grandTotal;//show the total price with IVA
	ticket<<"\n GRAND TOTAL: "<<grandTotal;//write the total price with IVA in file
		
	
	ticket.close();//close file
            
    cout<<"\n=======================================================================================" << endl;
	
}


int clientMode(){//client mode interface
	
	cout <<"\n\t////////////////////////WELCOME TO BESTIES SHOP///////////////////////////////////\n"<<endl;
	
	cout<<"Our list of articles is: \n";
	for(i=0; i<registerQuantity; i++){//show the list of articles
					
		cout<<"\n\a\t\t\t ****** Product "<<i+1<<" ********\n";
		cout<<"\n\t\t\t\t Code: "<<i+1<<endl;
		printf("\t\t\t\t Name: %s \n", products[i].name);
		cout<<"\t\t\t\t Price: "<<products[i].price<<endl;
	}
	
	cout <<"\n\t///////////////////////////////////////////////////////////////////////////////////\n"<<endl;
	
	cout<<"\n Press 1 for Quotation"<<endl;		
	cout<<" Press 2 to Exit \n"<<endl;
	cout<<" *To make a sale first you have to make a quotation"<<endl;
	
	cout<<" What do you want to do?"<<endl;
	cin>>clientChoice;
	
	if(clientChoice == 1){//if the user wants to make a quotation
		
		cotization();		
	
	}else{return 0 ;}//if the user doesn't want to make a quotation
	
}

int cotization(){//cotization interface
	
		cout<<"\n How many products do you want to quote? "<<endl;
		cin>>differentProducts;	
			
		for(j=0; j<differentProducts; j++){//loop for the number of products that the client wants to quote
			
			cout<<"\n Enter the code of the products that you want to quote: "<<endl;
			cin>>productCode;
			
			cout<<"\n How many pieces do you want? "<<endl;
			cin>>productQuantity;
			
			cout<<"=======================================================================================" << endl;
			cout<<"  CODE  "<<"\t DESCRIPTION \t\t"<<"\t QUANTITY \t"<<"\t PRICE \t"<<endl;
			cout<<"=======================================================================================" << endl;
        	
				
            productSearch();//search the product in the array
            
            cout<<"=======================================================================================" << endl;
        }
        
			cout<<"\n          \t\t\t\t\t\t\t SUBTOTAL:   "<<accountTotal<<endl;
			cout<<"\n      \t\t\t\t\t\t *SUBTOTAL amount is without IVA"<<endl;
            
            cout<<"\n=======================================================================================" << endl;
            
			cout << "\n Do you want to add more products to your quotation?"<<endl;
			
			cout<<"\n Press 1 for Add more products"<<endl;
			cout<<" Press 2 for Saling"<<endl;
			cout<<" Press 3 for Exit"<<endl;
			cin >> repeat;
			
			switch (repeat)//evaluate if the user wants to add more products or if it wants to switch to saling mode
			{
			case 1://add more products
				
				return cotization ();//return to the cotization interface
				break;
				
			case 2 ://saling mode
				
				saling();//call the saling interface
				salingTicket();//print the saling ticket
				break;
			}
			
		}

int main(){//main function
	
	mainMenu();//main menu interface
	
	return 0;//return to the operating system
}