#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numeros[5] = {1,2,3,4,10};
	int suma=0,mayor=0;

	for(int i=0;i<5;i++){
		suma += numeros[i];

		if(numeros[i]>mayor){
			mayor = numeros[i];
		}
	}

	if(mayor == suma-mayor){
		cout<<"El numero "<<mayor<<" es la suma de los demas";
	}
	else{
		cout<<"No existe ningun numero que sea la suma de los demas";
	}

	getch();
	return 0;
}
