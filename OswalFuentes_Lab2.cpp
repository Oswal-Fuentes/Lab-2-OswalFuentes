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
	euler+=1;//Equivalente a (1/factorial(0))= 1
	cout<<"El resultado es: "<<euler<<endl;
	cout<<"\n";	
	break;
      } 
      case 2:{
	float coordenadas[7];
	cout<<"Ingrese coordenada x del vertice a: ";
        cin>>coordenadas[0];
	cout<<"Ingrese coordenada y del vertice a: ";
        cin>>coordenadas[1];
	cout<<"Ingrese coordenada x del vertice b: ";
        cin>>coordenadas[2];
	cout<<"Ingrese coordenada y del vertice b: ";
        cin>>coordenadas[3];
	cout<<"Ingrese coordenada x del vertice c: ";
        cin>>coordenadas[4];
	cout<<"Ingrese coordenada y del vertice c: ";
        cin>>coordenadas[5];
	cout<<"Ingrese coordenada x del vertice d: ";
        cin>>coordenadas[6];
	cout<<"Ingrese coordenada y del vertice d: ";
        cin>>coordenadas[7];
	float trape_lado1=0,trape_lado2=0,trape_lado3=0,trape_lado4=0;//Lados trapecios
	float tri1_lado1=0,tri1_lado2=0, tri1_lado3=0;//Lados triangulo 1
	float tri2_lado1=0,tri2_lado2=0, tri2_lado3=0;//Lados triangulo 2
	float semi_tri1=0,semi_tri2=0;//Semiperimetro triangulo 1 y 2
	float peri_tri1=0,peri_tri2=0;//Perimetro triangulos 1 y 2
	float alt1_tri1=0,alt2_tri1=0,alt3_tri1=0;//Alturas triangulo 1
	float alt1_tri2=0,alt2_tri2=0,alt3_tri2=0;//Alturas triangulo 2
	
	//Lados triangulo 1
	tri1_lado1=pow( pow( coordenadas[6]-coordenadas[0] , 2 )  +  pow( coordenadas[7]-coordenadas[1]  , 2 )   ,0.5);//lado c
	tri1_lado2=pow( pow( coordenadas[0]-coordenadas[2] , 2 )  +  pow( coordenadas[1]-coordenadas[3]  , 2 )   ,0.5);//lado a
	tri1_lado3=pow( pow( coordenadas[2]-coordenadas[6] , 2 )  +  pow( coordenadas[3]-coordenadas[7]  , 2 )   ,0.5);//lado b
	//Lados triangulo 2
	tri2_lado1=tri1_lado3;//lado c
        tri2_lado2=pow( pow( coordenadas[2]-coordenadas[4] , 2 )  +  pow( coordenadas[3]-coordenadas[5]  , 2 )   ,0.5);//lado a
        tri2_lado3=pow( pow( coordenadas[4]-coordenadas[6] , 2 )  +  pow( coordenadas[5]-coordenadas[7]  , 2 )   ,0.5);//lado b
	//Semiperimetro triangulos 1 y 2	
	semi_tri1=(tri1_lado1+tri1_lado2+tri1_lado3)/2;
	semi_tri2=(tri2_lado1+tri2_lado2+tri2_lado3)/2;
	//Perimetro triangulos 1 y 2
	peri_tri1=tri1_lado1+tri1_lado2+tri1_lado3;
	peri_tri2=tri2_lado1+tri2_lado2+tri2_lado3;
	//Alturas triangulo 1
	alt1_tri1=(2/tri1_lado2) * pow( semi_tri1*(semi_tri1 - tri1_lado2)*(semi_tri1 - tri1_lado3)*(semi_tri1 - tri1_lado1)  , 0.5);//altura a
	alt2_tri1=(2/tri1_lado3) * pow( semi_tri1*(semi_tri1 - tri1_lado2)*(semi_tri1 - tri1_lado3)*(semi_tri1 - tri1_lado1)  , 0.5);//altura b
	alt3_tri1=(2/tri1_lado1) * pow( semi_tri1*(semi_tri1 - tri1_lado2)*(semi_tri1 - tri1_lado3)*(semi_tri1 - tri1_lado1)  , 0.5);//altura c
	//Alturas triangulo 2
	alt1_tri2=(2/tri2_lado1) * pow( semi_tri2*(semi_tri2 - tri2_lado1)*(semi_tri2 - tri2_lado3)*(semi_tri2 - tri2_lado1)  , 0.5);//altura c
	alt2_tri2=(2/tri2_lado2) * pow( semi_tri2*(semi_tri2 - tri2_lado2)*(semi_tri2 - tri2_lado3)*(semi_tri2 - tri2_lado1)  , 0.5);//altura a
	alt3_tri2=(2/tri2_lado3) * pow( semi_tri2*(semi_tri2 - tri2_lado2)*(semi_tri2 - tri2_lado3)*(semi_tri2 - tri2_lado1)  , 0.5);//altura b
	//Lados trapecios
	trape_lado1=tri1_lado2;
	trape_lado2=tri1_lado3;	
	trape_lado3=tri2_lado2;
	trape_lado4=tri2_lado3;
	float area=0;
	area=(tri2_lado1+alt2_tri1/2)+(tri2_lado1+alt1_tri2/2);
	
	cout<<"Los lados del trapezoide miden: "<<endl
	<<"Lado 1: "<<trape_lado1<<endl
	<<"Lado 2: "<<trape_lado2<<endl 
	<<"Lado 3: "<<trape_lado3<<endl 
	<<"Lado 4: "<<trape_lado4<<endl;
	cout<<"\n";
		
	cout<<"Los lados del triangulo 1 miden: "<<endl
        <<"Lado 1: "<<tri1_lado1<<endl
        <<"Lado 2: "<<tri1_lado2<<endl
        <<"Lado 3: "<<tri1_lado3<<endl;
        cout<<"\n";

	cout<<"Los lados del triangulo 2 miden: "<<endl
        <<"Lado 1: "<<tri2_lado1<<endl
        <<"Lado 2: "<<tri2_lado1<<endl
        <<"Lado 3: "<<tri2_lado1<<endl;
        cout<<"\n";
	
	cout<<"Semiperimetro triangulo 1 : "<<semi_tri1<<endl
        <<"Semiperimetro triangulo 2:  "<<semi_tri2<<endl
        <<"Perimetro triangulo 1: "<<peri_tri1<<endl
        <<"Perimetro triangulo 2: "<<peri_tri2<<endl;
        cout<<"\n";

	cout<<"Las alturas del triangulo 1 miden: "<<endl
        <<"Altura 1: "<<alt1_tri1<<endl
        <<"Altura 2: "<<alt2_tri1<<endl
        <<"Altura 3: "<<alt3_tri1<<endl;
	cout<<"\n";

	cout<<"Las alturas del triangulo 2 miden: "<<endl
        <<"Altura 1: "<<alt1_tri2<<endl
        <<"Altura 2: "<<alt2_tri2<<endl
        <<"Altura 3: "<<alt3_tri2<<endl;
        cout<<"\n";

	cout<<"El area del trapezoide es: "<<area<<endl;  
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

