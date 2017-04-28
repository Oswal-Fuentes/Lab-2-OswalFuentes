#include <iostream>
#include <cmath>

using namespace std;
//Funcion Menu
int menu();
//Funcion factorial recursiva
int factorial(int i);

int main(){
bool salir=false;
  while(!salir){
    switch(menu()){
      case 1:{
	int x;
	float euler=0;
	cout<<"Ingrese el valor de x: ";
	cin>>x;
	for(int i=1;i<=10;i++){
          euler+=(pow(x,i))/factorial(i);
	}
	euler+=1;//Equivalente a (1/factorial) de 0 = 1
	cout<<"El resultado es: "<<euler<<endl;
	cout<<"\n";	
	break;
      } 
      case 2:{

  	break;
      }
      case 3:{
	salir=true;
        break;
      }
    }
  }
return 0;
}

int menu(){
  int opcion;
  bool valido=false;
  do{
    cout<<"-----MENU-----"<<endl
    <<"1.- Ejercicio 1"<<endl
    <<"2.- Ejercicio 2"<<endl
    <<"3.- Salir"<<endl;

  cout<<"Ingrese una opcion: ";
  cin>>opcion;

  if(opcion>0 && opcion < 4)
    valido=true;
  else{
    cout<<"Opcion no valida, intente de nuevo..."<<endl;
  }

  }while(!valido);

  return opcion;
}

int factorial(int num){
  if(num<0) return 0;
  else if(num>1)return num*factorial(num-1);
  return 1;
}

