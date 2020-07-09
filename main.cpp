#include <iostream>

/*
1.-Crea un programa en C++ para guardar las notas de N alumnos, N tiene que ser mayor
o igual que 20 o menor o igual que 30, esto se debe de verificar en el programa,
y en caso de que el número de alumnos este fuera del rango se debe de mostrar la
opción de ingresar de nuevo el número de alumnos.

2.-Una vez que tengamos los notas guardadas dentro de un arreglo, hay que sumar todas
las calificaciones, mostrar el promedio del salón, mostrar el alumno con nota más
alta, mostrar alumnos con nota promedio (rango de promedio -1 a promedio +1) y
el alumno con menor nota.

3.-A los alumnos que tiene una nota menor o igual a 6 se les encargó un trabajo,
este trabajo suma un punto más a su nota. Se debe de utilizar el arreglo con las
notas originales para generar otro arreglo con las notas modificadas de estos
alumnos. Imprimir las dos notas en columnas diferentes.
Al final se debe de mostrar la opción para volver a calcular más notas de alumnos,
o finalizar el programa.*/
using namespace std;
int main(int argc, char** argv) {
	int cantidad=0,suma=0,promedio=0,max=0,min=0,prom=0,alumno1=0,alumno2=0,alumno3=0;
	int nota[cantidad]={};
	int notaEx[cantidad]={};
	char var='s';
	do{
		system("cls");
		//ingresar los alumnos
		cout<<"Ingrese la cantidad de alumnos: "<<endl;
		do{
			cin>>cantidad;
			//validar que sea la cantidad correcta
			if(cantidad<20 || cantidad>30){
				cout<<"Ingrese una cantidad entre 20 a 30 alumnos"<<endl;
			}
		}while(cantidad<20 || cantidad>30);	
		
		//ingresas notas de cada alumno
		for(int i=0; i<cantidad;i++){
			//guardar las notas
			cout<<"Ingrese nota del alumno "<<(i+1)<<" : "<<endl;
			cin>>nota[i];
			//sumar notas
			suma = suma+nota[i];
			//calcular nota maxima
			if(nota[i]>max){
				max = nota[i];
				alumno1 = i+1;
			}
			//calcular nota minima
			if (min == 0) {
				min = nota[i];
				alumno2 = i+1;
			}
			if(nota[i]<min){
				min = nota[i];
				alumno2 = i+1;
			}
		}
		//promedio
		promedio=suma/cantidad;
		cout<<"El promedio del salon es de: "<<promedio<<endl;
		
		//imprimir nota maxima
		cout<<"La nota maxima es de: "<<max<<" y es del alumno: "<<alumno1<<endl;
		//calcular alumnos promedio
		for(int i=1;i<cantidad;i++){
			if(nota[i]>(promedio -1) && nota[i]<(promedio +1)){
				alumno3= i+1;
				cout << "La nota promedio es de" << nota[i]<<" y es del alumno: "<<alumno3<<endl;
			}	
		}	
		//imprimirnota  minima
		cout<<"La nota minima es de: "<<min<<" y es del alumno: "<<alumno2<<endl;
		
		//imprimir la suma de las notas
		cout<<"La suma de la nota de los "<<cantidad<<" es de: "<<suma<<endl;
		
		//trabajo extra
		cout<<"Nota inicial y final de los alumnos: "<<endl;
		for(int i=1;i<cantidad;i++){
			if(nota[i]<=6){
				cout<<"Nota original: "<<nota[i]<<" del alumno: "<<alumno2<<endl;
				notaEx[i] = nota[i]+1;
				cout<<"Nota final: "<<notaEx[i]<<" del alumno: "<<alumno2<<endl;
			}
		}
		//opcion de continuar
		cout<<"Desea continuar?"<<"S/N"<<endl;
		cin>>var;
	}while(var=='s'||var=='S');
	return 0;
}
