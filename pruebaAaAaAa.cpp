#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

struct productData{
	string name[100];
	float price;
	int code;
}products[100];

int i, registerQuantity, adminChoice, adminOption, mainChoice, clientChoice, productQuantity, productCode;
int mainMenu();
int clientMode();
void dataPetition();
int adminMode();


	
int mainMenu(){
	
	cout<< "\n\a\t ****** Welcome to Besties Shop ****** \n"<<endl;
	cout<<" Press 1 to Admin Mode"<<endl;
	cout<<" Press 2 to Client Mode \n"<<endl;
	
	cout<<" What do you want to do?"<<endl;
	cin>>mainChoice;
	
	if(mainChoice == 1){
		
		adminMode();
		
	}else if(mainChoice == 2){
		
		clientMode();
		
	}
}	


void dataPetition(){

	FILE* fichero;
	
	fichero = fopen("products.dat", "wt");
	if(fichero == NULL){
		printf("We cannot found the file \n");
	}else{
		cout<<" How many items do you want to enter:"<<endl;
		cin>>registerQuantity;
		
		cout<<"\n Enter the following data:"<<endl;
		
		for(i=0; i<registerQuantity; i++){
			
			cout<<"\n\a\t ****** Product "<<i+1<<" ********\n";
			
			cout<<" Code: "<<i<<endl;
			
			puts(" Product name (without spaces): \n");
			//cin.ignore();
			//getline(cin, products[i].name);
			scanf("%s", &products[i].name);
			fprintf(fichero, "%s \n", products[i].name);
			
			puts("\n Price: \n");
			scanf("%f", &products[i].price);
			getchar();
			fprintf(fichero, "%f \n\n", products[i].price);
			
			/*puts("\n Code: \n");
			scanf("%d", &products[i].code);
			getchar();
			fprintf(fichero, "%d \n\n", products[i].code);*/		

		}
	}	
	fclose(fichero);
}



int adminMode(){
	
		cout<<"\n\t////////////////////////ADMIN MODE///////////////////////////////////"<<endl;
		
		cout<<"\n Press 1 to Enter items"<<endl;
		cout<<" Press 2 to Show list of products"<<endl;
		cout<<" Press 3 to Switch to Client Mode"<<endl;
		cout<<" Press 4 to Exit \n"<<endl;
		
		cout<<" What do you want to do?"<<endl;
		cin>>adminChoice;
		
		if(adminChoice == 1){
			
				dataPetition();
				
		}else if(adminChoice == 2){
			
			cout<<" The products that are in the list are: \n"<<endl;
			
				for(i=0; i<registerQuantity; i++){
					
					cout<<"\n\a\t ****** Product "<<i+1<<" ********\n";
					cout<<" Code: "<<i<<endl;
					cout<<" Name: "<<products[i].name<<endl;
					cout<<" Price: "<<products[i].price<<endl;					
				}
								
		}else if(adminChoice == 3){
			
			clientMode();
			
		}else if(adminChoice == 4){
			
			return 0;
			
		}
		
		cout<<"\n Press 1 to Return to Admin Menu"<<endl;
		cout<<" Press 2 to Return to Main Menu"<<endl;
		cout<<" Press 3 to Switch to Client Mode"<<endl;
		cout<<" Press 4 to Exit \n"<<endl;
		
		cout<<" What do you want to do?"<<endl;
		cin>>adminOption;
		
		if(adminOption == 1){
			
			return adminMode();
			
		}else if(adminOption == 2){
			
			return mainMenu();
			
		}else if(adminOption == 3){
			
			clientMode();
			
		}else if(adminOption == 4){
			
			return 0;
			
		}
		
}

void productSearch(){
	
		int counter = 0;
	
	for(i=0; i<registerQuantity; i++){
		
		if(i == productCode){
			cout<<"  "<<i<<"\t\t";
			cout<<products[i].name<<"\t     ";
			cout<<productQuantity<<"\t\t\t ";
			cout<<products[i].price<<endl;
			
			cout<<"=======================================================================================" << endl;
		}
		
		if(i == productCode){
			cout<<" TOTAL                                                           "<<productQuantity * products[i].price<<endl;
		}
		
	}
}

int clientMode(){
	
	cout <<"\n\t////////////////////////WELCOME TO BESTIES SHOP///////////////////////////////////\n"<<endl;
	
	cout<<"Our menu is: \n";
	for(i=0; i<registerQuantity; i++){
					
		cout<<"\n\a\t ****** Product "<<i+1<<" ********\n";
		cout<<" Code: "<<i<<endl;
		cout<<" Name: "<<products[i].name<<endl;
		cout<<" Price: "<<products[i].price<<endl;
	}
	
	cout<<"\n Press 1 for Cotization"<<endl;
	cout<<" Press 2 for Saling"<<endl;
	cout<<" Press 3 to Exit \n"<<endl;
	
	cout<<" What do you want to do?"<<endl;
	cin>>clientChoice;
	
	if(clientChoice == 1){
		
		cout<<"\n Enter the code of the products that you want to quote: "<<endl;
			cin>>productCode;
			
			cout<<"\n How many pieces do you want? "<<endl;
			cin>>productQuantity;
			
			cout<<"=======================================================================================" << endl;
			cout<<"  CODE  "<<"\t DESCRIPTION \t"<<"\t QUANTITY \t"<<"\t PRICE \t"<<endl;
			cout<<"=======================================================================================" << endl;
        	
				
            productSearch();
            
            cout<<"=======================================================================================" << endl;

	}
	
	
}


int main(){
	
	mainMenu();
	
	return 0;
}
