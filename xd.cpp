#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <fstream>
using namespace std ;
int cantidad, i = 0,choice, choiceusermode, option,optionclient, buscar;
float costo [50], codigo [50] ;
string name[100] ;
int clienmode () ; //declarar  funciones//
int menu () ;
int usermode () ;
void Clear();


int  menu (){ //funcion void menu prncipal//
cout<< "///////////////////bienvenido a sistema/////////////////////////////\n" ;
cout << "\nque deseas hacer?";
cout<< "\n1. user mode";
cout << "\n2. client mode";
cout << "\n" ;
cin >>choice;//almacena eleccion//
}


void Clear() //limpiar pantalla del usuario/cliente
{
    cout << "\x1B[2J\x1B[H"; //codigo ANSI LIMPIAR PANTALLA//
}


int usermode (){ //funcion usuario para ingresar y mostrar productos//
    cout << "\n\t////////////////////////USERMODE///////////////////////////////////7\n";
    cout << "\n1. ingresar productos" ;
    cout << "\n2. mostrar productos en existencia" ;
    cout<<  "\n3.cambiar modo cliente"<< endl ;
    cout << "\n que desea hacer?\n";
    cin >> choiceusermode ; //almacena eleccion de la funcion//
    if(choiceusermode == 1){ //inicia condicion de eleccion del menu principal//
    Clear ();
    cout << "\n\t////////////////////////USERMODE///////////////////////////////////7\n";
    cout << "actualmente hay "<< i<< " productos\n";
    cout << "ingrese el/los productos siguientes(cantidad)\n";
    cin >> cantidad ;
    while (i<cantidad)//funcion while para evaluar  la cantidad//
    {
    Clear () ;
    cout << "\n\t////////////////////////USERMODE///////////////////////////////////7\n";
    cout << "ingrese el nombre de el producto "<<i+1<< "\n" ;
    cin.ignore();
    getline(cin,name[i]);
    cout << "\ningrese el costo\n";
    cin >>costo[i] ;
    cout << "ingrese codigo(solo numeros)\n";
    cin >> codigo [i] ;
    i++; //aumenta los productos respecto a la cantidad dada//
    }
    cout << " 1  volver al menu usuario\n 1234 para menu principal \n otra tecla = salir\n"; 
    cin>> option ;
    if (option == 1)
    {
        return usermode () ;
    }
    


    }else if (choiceusermode == 2){// si no pasa eleccion 1, se ejecuta eleccion 2//
        Clear();
        cout<< "los productos son\n"<<endl ;
        for ( i = 0; i < cantidad; i++) //bucle para imprimir la base de datos//
        {
        cout<<"\n****** producto "<<i+1<<"********\n";
        cout << "nombre:"<< name[i]<<"\n" ;
        cout << "costo:" << costo[i]<<"\n" ;
        cout << "codigo:"<< codigo[i]<<"\n" ;
        }
        cout << "\n 1  volver al menu usuario\n  1234 para el menu principal\n  otra tecla =  salir \n"; 
        cin>> option ;
        if (option == 1)
        {
            return usermode () ;
        }
        
    }else if (choiceusermode ==3)
    {
        Clear () ;
        return clienmode() ;
    }
    
    
}

int clienmode(){ //funcion cliente para presentar los productos y elegir compras
    cout << "\n\a\tclient mode\n/////////////////Bienvenido a la tienda UPY///////////\n";
        for ( i = 0; i < cantidad; i++)
        {
            cout<<"\n\a\t            ****** producto "<<i+1<<"********      \n";
            cout << "           nombre: "<< name [i]<< "\n" ;
            cout << "           costo  :" << costo [i] << "\n" ;
            cout <<  "          codigo :"<< codigo [i] << "\n" ;
            cout<<"\n\a\t+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
               
        } 
    cout << "elija el codigo del producto que desee" ;
    cin >> buscar;  
    cout << "desea seguir comprando?\n"<< endl ;
    cout << "3 = si \t otra tecla salir = salir"<< endl ;  
    //podemos regresar con la "contraseña" 1234 desde el clientmode hasta main menú //
    cin >> option ;
    if (option == 3)
    {
        Clear () ;
        return clienmode () ;
    }
    
} 


int main (){

do{//ejecuta mientras option = 1234//
    Clear ();
    menu() ;
    
    switch (choice) //evalua choice//
    {
    case 1 :
        Clear ();
        usermode ();
    
    break;
    case 2 :
    
        Clear () ;
        clienmode () ;
    break;
        

    

    }
    

}while(option == 1234);

}



