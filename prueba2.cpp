#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <fstream>
using namespace std ;
int cantidad, i = 0,choice, choiceusermode, option,optionclient, buscar, productQuantity;

struct productData{
	float costo [50];
	int codigo [50] ;
	char name[100] ;
}productos[200];

int clienmode () ; //declarar  funciones//
int menu () ;
int usermode () ;
FILE* fichero;
//void productSearch();
/*void Clear();*/


int  menu (){ //funcion void menu prncipal//
cout<< "\n\t///////////////////Bienvenido a sistema/////////////////////////////\t\n" ;
cout << "\n Que desea hacer?";
cout<< "\n 1. User mode";
cout << "\n 2. Client mode";
cout << "\n" ;
cin >>choice;//almacena eleccion//
}


/*void Clear() //limpiar pantalla del usuario/cliente
{
    cout << "\x1B[2J\x1B[H"; //codigo ANSI LIMPIAR PANTALLA//
}*/


int usermode (){ //funcion usuario para ingresar y mostrar productos//
    cout << "\n\t////////////////////////USER MODE///////////////////////////////////\n";
    cout << "\n1. Ingresar productos" ;
    cout << "\n2. Mostrar productos en existencia" ;
    cout<<  "\n3. Cambiar modo cliente"<< endl ;
    cout << "\n Que desea hacer?\n";
    cin >> choiceusermode ; //almacena eleccion de la funcion//
    
    if(choiceusermode == 1){ //inicia condicion de eleccion del menu principal//
    //Clear ();
	    cout << "\n\t////////////////////////USER MODE///////////////////////////////////\n";
	    cout << "Actualmente hay "<< i<< " Productos \n";
	    cout << "Ingrese la cantidad de productos diferentes que desea ingresar al inventario:\n";
	    cin >> cantidad ;
	    
	    while(i<cantidad){
		
	       
			fichero = fopen("products.dat", "wt");
			if(fichero == NULL){
			    printf("No se pudo encontrar el archivo \n");    	
			}else{
		    	//while (i<cantidad){//funcion while para evaluar  la cantidad//   	
	
					
					for(i=0; i<cantidad; i++){
					
						cout<<"\n\a\t ****** Producto "<<i+1<<" ********\n";
					
						puts("\n Ingrese el nombre del producto: \n");
						cin.ignore();
						scanf("%c", &productos[i].name);
						getchar();
						fprintf(fichero, "%s \n", productos[i].name);
			
					    
					    puts("\n Ingrese el costo: \n");
					    scanf("%f", &productos[i].costo);
					    getchar();
					    fprintf(fichero, "%f \n", productos[i].costo);
					    
					    puts("\n Ingrese codigo (solo numeros):\n");
					    scanf("%f", &productos[i].codigo);
					    getchar();
					    fprintf(fichero, "%d \n", productos[i].codigo);
					    
					    //i++; //aumenta los productos respecto a la cantidad dada//
					}
				//}
				
				fclose(fichero);
	  
	    	}
	    }
    cout << "\n Presione 1 para Volver al menu usuario\n Presione 1,2,3 o 4 para Menu principal \n Presione otra tecla para Salir\n"; 
    cin>> option ;
    if (option == 1)
    {
        return usermode () ;
    }
    


    }else if (choiceusermode == 2){// si no pasa eleccion 1, se ejecuta eleccion 2//
        //Clear();
        cout<< "Los productos son: \n"<<endl ;
        for ( i = 0; i < cantidad; i++) //bucle para imprimir la base de datos//
        {
        cout<<"\n****** Producto "<<i+1<<" ********\n";
        cout << "Nombre:"<< productos[i].name<<"\n" ;
        cout << "Costo:" << productos[i].costo<<"\n" ;
        cout << "Codigo:"<< productos[i].codigo<<"\n" ;
        }
        cout << "\n Presione 1 para Volver al menu usuario\n Presione 1,2,3 o 4 para Menu principal \n Presione otra tecla para Salir\n"; 
        cin>> option ;
        if (option == 1)
        {
            return usermode () ;
        }
        
    }else if (choiceusermode ==3)
    {
        //Clear () ;
        return clienmode() ;
    }
    
    
}

int clienmode(){ //funcion cliente para presentar los productos y elegir compras
    cout << "\n\a\t/////////////////CLIENT MODE///////////////// \n\t/////////////////Bienvenido a la tienda UPY///////////\t\n";
        for ( i = 0; i < cantidad; i++)
        {
            cout<<"\n\a\t            ****** Producto "<<i+1<<" ********      \n";
            cout << "           nombre: "<< productos[i].name<< "\n" ;
            cout << "           costo: " << productos[i].costo << "\n" ;
            cout <<  "          codigo: "<< productos[i].codigo << "\n" ;
            cout<<"\n\a\t+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
               
        } 
    cout << " Elija el codigo del producto que desee adquirir: \n" ;
    cin >> buscar;  
    
    cout<<" Cuantas piezas desea adquirir?: \n";
    cin>>productQuantity;
    

    
    cout << " Desea seguir comprando? \n"<< endl ;
    cout << " 3 = si \t\n Otra tecla = salir\t\n"<< endl ;  
    //podemos regresar con la "contraseña" 1234 desde el clientmode hasta main menú //
    cin >> option ;
    if (option == 3)
    {
        //Clear () ;
        return clienmode () ;
    }
    
} 

/*void productSearch(){
	for(i=0; i<15; i++){
		if(i == buscar){
			cout<<"Total: "<<productQuantity * costo[i];
		}
	}
}*/


int main (){

do{//ejecuta mientras option = 1234//
    //Clear ();
    menu() ;
    
    switch (choice) //evalua choice//
    {
    case 1 :
        //Clear ();
        usermode ();
    
    break;
    case 2 :
    
        //Clear () ;
        clienmode () ;
    break;
        

    

    }
    

}while(option == 1234);

}



