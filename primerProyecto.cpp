//el main del programa

/*
			PROYECTO PRIMER CORTE 

	JOSE CARLOS RAPALINO BLANCO 0222220010

		DOCENTE: NOHEMY CASTRO GENES

		UNIVERSIDAD DE CARTAGENA

		FACULTAD DE INGENIERIA

	SEGUNDO SEMESTRE INGENIERIA DE SISTEMAS

*/

//definimos las librerias a utilizar
#include <string.h>
#include <windows.h>
#include <iostream>
#include <conio.h>

//llamamos los metodos necesarios del standard
using std::endl; using std::cout; using std::cin;

//definimos los acortadores
#define pause cout<<endl<<endl; system("pause");

//llamamos a nuestras librerias propias .header
#include "funcionesInterfaces.h"
#include "funcionesPrincipales.h"
#include "funcionesAuxiliares.h"



int main(){
	//funcion para mostrar caracteres especiales españoles
	setlocale(LC_ALL, "SPANISH");
	

	//variable de las opciones del programa
	char opcion;
	char opcionSecundaria;

	//presentacion del programa
	musica();
	
	//creacion del loop infinito del programa
	while(1){
		
		opcion = menuPrincipal();
			
		opcionSecundaria = menuSecundario(opcion);
		
	// ******** BODY **********
	// el cuerpo del programa como tal que llamara a las funciones esenciales
		
		system("cls");
		bordes();
		
		gotoxy(95,9); color(h,14); cout << " PARA VER EL HISTORIAL ";
		gotoxy(95,10); color(h,14); cout << " DE NUMEROS INGRESADOS ";
		gotoxy(95,11); color(h,14); cout << " PRESIONAR TECLAS ";
		gotoxy(95,12); color(h,14); cout << " ARRIBA Y ABAJO ";
		
		
		//LOS TERRIBLES
		if(opcion == 'A'){
			
			//NUMERO MALVADO
			if(opcionSecundaria == '1'){
					//n a ingresar, el contador de digitos que saldra el binario, el numero de unos del binario
					int n, contBin = 0, numUnos = 0;
					char binario[33]; // 32 espacios ya que los int son de 32 bits y el binario mas largo que es el int maximo de c++ tiene 32 digitos + el char de escape '\0'
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS MALVADOS ";
			
					color(h,7);
					gotoxy(25,5); cout << " todo número natural cuya expresión en base 2 ";
					gotoxy(25,6); cout << " (binaria) contiene un número par de unos.";	
					
					gotoxy(30,10); color(h,2); cout << " INGRESE UN NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(n, 36, 12,'N'));
						
					
					//llamo a funcion ubicada en "funcionesPrincipales.h"
					enteroToBinario(n, binario, contBin);
					//llamo a funcion ubicada en "funcionesAuxiliares.h"
					ordenarCadenaBinario(binario, contBin);
					
					color(h,10); barraProgreso(30,16);
					
					gotoxy(30,15); color(h,14); cout << "El numero en binario es: " << binario;
					color(h,4);
					//llamo a funcion ubicada en "funcionesAuxiliares.h"
					if(verificarMalvadoOdioso(binario, contBin, numUnos)){
						color(h,2);
						gotoxy(30,17); cout << "El numero es super malvado ya que cuenta con ";
						gotoxy(30,18); cout << numUnos << " <- esta cantidad de unos PAR ";
					}
					else{
						color(h,4);
						gotoxy(30,17); cout << "El numero no es nada malvado ya que cuenta con ";
						gotoxy(30,18); cout << numUnos << " <- esta cantidad de unos IMPAR ";
					}
				char siono;
				gotoxy(25,20); color(h,14); cout << " ¿Desea convertir un numero Binario a Decimal? -> [S/N]  - ";  cin>>siono; siono = toupper(siono);
				
				if(siono == 'S'){
					char binario[33]; //el numero entero mas grande en binario tiene 32 digitos mas el caracter nuelo '\0'
					int contBin = 0; //contador de digitos 
					
					do{
						gotoxy(25,22); color(h,14); cout << " Ingrese el numero en base Binaria - "; 
					}while(validarBinario(contBin,binario, 61,22)); //funcion ubicada en "funcionesAuxiliares.h
					
					int decimal = BinarioDecimal(binario, contBin , 0); //funcion ubicada en "funcionesPrincipales.h
					
					color(h,10); barraProgreso(30,25);
					
					gotoxy(25,24); color(h,11); cout << " El Binario "<<binario<<" en decimal es:  "<<decimal;
			
				}
				
			}
			//NUMERO ODIOSO
			else if(opcionSecundaria == '2'){
					//n a ingresar, el contador de digitos que saldra el binario, el numero de unos del binario
					int n, contBin = 0, numUnos = 0;
					char binario[33]; // 32 espacios ya que los int son de 32 bits y el binario mas largo que es el int maximo de c++ tiene 32 digitos + el char de escape '\0'
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS ODIOSOS ";
			
					color(h,7);
					gotoxy(25,5); cout << " todo número natural cuya expresión en base 2 ";
					gotoxy(25,6); cout << " (binaria) contiene un número impar de unos.";	
					
					gotoxy(30,10); color(h,2); cout << " INGRESE UN NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(n, 36, 12,'N'));
						
					
					//llamo a funcion ubicada en "funcionesPrincipales.h"
					enteroToBinario(n, binario, contBin);
					//llamo a funcion ubicada en "funcionesAuxiliares.h"
					ordenarCadenaBinario(binario, contBin);
					
					color(h,10); barraProgreso(30,16);
					
					gotoxy(30,15); color(h,14); cout << "El numero en binario es: " << binario;
					
					color(h,4);
					
					//llamo a funcion ubicada en "funcionesAuxiliares.h"
					if(!verificarMalvadoOdioso(binario, contBin, numUnos)){
						color(h,2);
						gotoxy(30,17); cout << "El numero es super odioso ya que cuenta con ";
						gotoxy(30,18); cout << numUnos << " <- esta cantidad de unos IMPAR ";
					}
					else{
						color(h,4);
						gotoxy(30,17); cout << "El numero no cae nada odioso ya que cuenta con ";
						gotoxy(30,18); cout << numUnos << " <- esta cantidad de unos PAR ";
					}
					
				char siono;
				gotoxy(25,20); color(h,14); cout << " ¿Desea convertir un numero Binario a Decimal? -> [S/N]  - ";  cin>>siono; siono = toupper(siono);
				
				if(siono == 'S'){
					char binario[33]; //el numero entero mas grande en binario tiene 32 digitos mas el caracter nuelo '\0'
					int contBin = 0; //contador de digitos 
					
					do{
						gotoxy(25,22); color(h,14); cout << " Ingrese el numero en base Binaria - "; 
					}while(validarBinario(contBin,binario, 61,22)); //funcion ubicada en "funcionesAuxiliares.h
					
					int decimal = BinarioDecimal(binario, contBin , 0); //funcion ubicada en "funcionesPrincipales.h
					
					color(h,10); barraProgreso(30,25);
					
					gotoxy(25,24); color(h,11); cout << " El Binario "<<binario<<" en decimal es:  "<<decimal;
			
				}
				
			}
			//NUMERO AMBICIOSO
			else if(opcionSecundaria == '3'){
				
					//n natural a ingresar
					int n, z1, z2;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS AMBICIOSOS ";
			
					color(h,7);
			
					gotoxy(22,5); cout << " todo número que cumple que la secuencia que se forma al sumar ";
					gotoxy(22,6); cout << " sus divisores propios, después los divisores propios del  ";	
					gotoxy(22,7); cout << " resultado de esa suma, después los del número obtenido";
					gotoxy(22,8); cout << " acaba en un número perfecto.";		
				
					gotoxy(30,10); color(h,2); cout << " INGRESE UN NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(n, 36, 12,'N'));
					
					color(h,10); barraProgreso(30,16);
					
					//llamo a funcion ubicada en "funcionesPrincipales.h"
					//z1 guardara la suma de divisores de n y z2 la suma de los divisores de z1
					
					//para mostrar los divisores de n
					gotoxy(30,14); 	color(h,14); 
					printSumaDiv(n);
					z1 = sumaDivisoresPropios(n);
					cout << "\b\b = " << z1 ;
					
					//para mostrar los divisores de z1
					gotoxy(30,18); 	color(h,14); 
					printSumaDiv(z1);				
					z2 = sumaDivisoresPropios(z1);
					cout << "\b\b = " << z2 ;	
				
					color(h,2);
					if(z1 == z2){
						color(h,2);
						gotoxy(25,20); cout << " El numero es tan ambicioso ya que la ";
						gotoxy(25,21); cout << " suma de sus divisores y la suma de los divisores  ";
						gotoxy(25,22); cout << " propios de esos divisores dio un numero perfecto ";
					}
					else{
						color(h,4);
						gotoxy(25,20); cout << " El numero NO tiene una pizca de ambicioso ya que la ";
						gotoxy(25,21); cout << " suma de sus divisores y la suma de los divisores  ";
						gotoxy(25,22); cout << " propios de esos divisores NO dio un numero perfecto ";
					}
			
			}
			//NUMERO CURIOSO
			else if(opcionSecundaria == '4'){
				
					//n natural a ingresar
					int n;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS CURIOSOS ";
			
					color(h,7);
			
					gotoxy(22,5); cout << " todo número natural n que cumple que n^2 tiene al propio";
					gotoxy(22,6); cout << " n como última cifra. Por ejemplo, 25 y 36 son números curiosos";
					gotoxy(22,7); cout << " [5]^2 = 2[5] y [6]^2 = 3[6] ";		
				
					gotoxy(30,10); color(h,2); cout << " INGRESE UN NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(n, 36, 12,'N'));
					
					color(h,10); barraProgreso(30,16);
					
					gotoxy(36,15); color(h,14); cout << n << " ^2  =  " << potencia(n,2);
					
					//llamo a funcion ubicada en "funcionesAuxiliares.h"		
					color(h,2);
					
					if(NumeroCurioso(n)){
						color(h,2);
						gotoxy(25,18); cout << " El numero es demasiado curioso ya que la ";
						gotoxy(25,19); cout << " ultima cifra de n^2 termino siendo el mismo numero ";
					}
					else{
						color(h,4);
						gotoxy(25,18); cout << " El numero no es nada curioso ya que la ";
						gotoxy(25,19); cout << " ultima cifra de n^2 termino siendo otro numero numero ";
					}
				
				
			}
			//NUMERO INFELIZ
			else if(opcionSecundaria == '5'){
				
					//n natural a ingresar
					int n;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS INFELICES ";
			
					color(h,7);
			
					gotoxy(22,5); cout << " Como lo dice el titulo todo número natural que no es un número feliz.";
					gotoxy(22,6); cout << " será un numero infeliz, osea si sumamos los cuadrados de sus digitos ";
					gotoxy(22,7); cout << " y repetimos el proceso nos debe dar un numero diferente de 1 ";		
				
					gotoxy(30,10); color(h,2); cout << " INGRESE UN NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(n, 36, 12,'N'));
					
					color(h,10); barraProgreso(30,16);
						
					//llamo a funcion ubicada en "funcionesAuxiliares.h"
					// 4 parametros, n  = numero, 1 = hasta que la suma de cuadrados sea 1, osea mi var flag
					// 'F' es de feliz, en este caso para hallar al infeliz, asi mi funcion sabra que tendra que buscar un numero feliz , 10 son las iteracciones del codigo, ya que si el numero no es feliz entrara en un bucle infinito de periodo 8
					// para ver mas detalles ir a "funcionesAuxiliares.h" linea 38
					//30 y 14 son mis parametros que posicionaran la respuesta en la pantalla, meramente estetico
					color(h,14);
					if(!sumaExponentes(n, 1, 'F', 10, 30, 14) == 1){
						color(h,2);
						gotoxy(30,25); cout << "El numero es tan infeliz que da ganas de llorar ya que la suma ";
						gotoxy(30,26); cout << " de sus digitos al cuadrado nunca dará 1 ";
					}
					else{
						color(h,4);
						gotoxy(30,25); cout << "El numero no tiene nada de infeliz ya que la suma";
						gotoxy(30,26); cout << " de sus digitos al cuadrado dió 1";
					}
				
			}
			else if(opcionSecundaria == 'D'){
				system("cls");
				continue;	
			}			
		}
		
		//LOS ENVIDIADOS
		else if(opcion == 'B'){
			
			//NUMERO FELIZ
			if(opcionSecundaria == '1'){
				
					//n natural a ingresar
					int n;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS FELICES ";	
					color(h,7);
			
					gotoxy(22,5); cout << " todo número natural que cumple que si sumamos los cuadrados de sus";
					gotoxy(22,6); cout << " dígitos y seguimos el proceso con los resultados obtenidos";	
					gotoxy(22,7); cout << " el resultado es 1. Por ejemplo, el número 203 es un número feliz";	
					gotoxy(22,8); cout << " ya que 2^2 + 0^2 + 3^2 = 13; 1^2 + 3^2 =10; 1^2 + 0^2 = [1]     ";	
					
					
					gotoxy(30,10); color(h,2); cout << " INGRESE UN NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(n, 36, 12,'N'));
					
					color(h,10); barraProgreso(30,16);
						
					//llamo a funcion ubicada en "funcionesAuxiliares.h"
					// 4 parametros, n  = numero, 1 = hasta que la suma de cuadrados sea 1, osea mi var flag
					// 'F' es de feliz, asi mi funcion sabra que tendra que buscar un numero feliz , 10 son las iteracciones del codigo, ya que si el numero no es feliz entrara en un bucle infinito de periodo 8
					// para ver mas detalles ir a "funcionesAuxiliares.h" linea 38
					//30 y 14 son mis parametros que posicionaran la respuesta en la pantalla, meramente estetico
					color(h,14);
					if(sumaExponentes(n, 1, 'F', 10, 30, 14) == 1){
						color(h,2);
						gotoxy(30,25); cout << "El numero es felizmente feliz ya que la suma ";
						gotoxy(30,26); cout << " de sus digitos al cuadrado dio 1 ";
					}
					else{
						color(h,4);
						gotoxy(30,25); cout << "El numero es super triste ya que la suma";
						gotoxy(30,26); cout << " de sus digitos nunca dará 1";
					}			
			}
			//NUMERO PERFECTO
			else if(opcionSecundaria == '2'){
				
					//n natural a ingresar
					int n;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS PERFECTOS ";
			
					color(h,7);
			
					gotoxy(22,5); cout << " todo número natural que es igual a la suma de sus divisores propios ";
					gotoxy(22,6); cout << " Por ejemplo, 6 es un número perfecto ya que sus divisores propios son";	
					gotoxy(22,7); cout << " 1, 2, y 3 y se cumple que 1 + 2 + 3 = 6";	
				
					gotoxy(30,10); color(h,2); cout << " INGRESE UN NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(n, 36, 12,'N'));
					
					color(h,10); barraProgreso(30,16);
						
					//llamo a funcion ubicada en "funcionesPrincipales.h"
					color(h,2);
					//donde se guardara la suma de los divisores
					int suma = sumaDivisoresPropios(n,2,1);
					if(suma == n){
						color(h,2);
						gotoxy(30,14); cout << " El numero es muy perfecto ya que la suma ";
						gotoxy(30,15); cout << " de sus divisores dio el mismo numero ";
					}
					else{
						color(h,4);
						gotoxy(30,14); cout << " El numero no tiene nada de perfecto ya que la suma";
						gotoxy(30,15); cout << " de sus divisores NO dio el mismo numero";
					}
					//para mostrar los divisores
					gotoxy(30,17); color(h,14); cout << " LOS DIVISORES DEL NUMERO:  ";	
					
					gotoxy(30,19); 
					//mostrar los divisores de n
					printSumaDiv(n);
					cout << "\b\b = " << suma ;
			
			}
			//NUMERO SEMI-PERFECTO
			else if(opcionSecundaria == '3'){
				
					//n natural a ingresar
					int n;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS SEMI-PERFECTOS ";
			
					color(h,7);
			
					gotoxy(22,5); cout << " todo número natural que cumple que es igual a la suma de algunos ";
					gotoxy(22,6); cout << " de sus divisores propios. Por ejemplo, 18 es semiperfecto ";	
					gotoxy(22,7); cout << " ya que sus divisores son 1, 2, 3, 6, 9";	
					gotoxy(22,8); cout << " y se cumple que 3 + 6 + 9 = 18";	
				
					gotoxy(30,10); color(h,2); cout << " INGRESE UN NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(n, 36, 12,'N'));
					
					color(h,10); barraProgreso(30,16);
						
					gotoxy(22,14); color(h,14); cout << " LOS DIVISORES DEL NUMERO:  ";	
					
					//contara cuantos divisores tiene el numero
					int cont = 0;
					//para mostrar los divisores
					gotoxy(22,16); 
					for(int i = 1; i < n; i++){
						if(n % i == 0){
							cout << i  << "  ";
							cont++;
						}
					}
					
					//llamo a funcion ubicada en "funcionesAuxiliares.h"
					gotoxy(22,18); 	color(h,14);
					if(SemiPerfecto(n, cont)){
						color(h,2);
						gotoxy(30,20); cout << " El numero es semi-perfecto ya que la suma ";
						gotoxy(30,21); cout << " de algunos de sus divisores dio el mismo numero ";
					}
					else{
						color(h,4);
						gotoxy(30,20); cout << " El numero no tiene nada de semi-perfecto ya que la suma";
						gotoxy(30,21); cout << " de algunos sus divisores NO dio el mismo numero";
					}
				
				
			}
			//NUMERO PODEROSO
			else if(opcionSecundaria == '4'){
				
					//n natural a ingresar
					int n;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS PODEROSOS ";
			
					color(h,7);
			
					gotoxy(22,5); cout << " Un número es poderoso si es igual a la suma de sus dígitos elevados ";
					gotoxy(22,6); cout << " a sus respectivas posiciones. Por ejemplo, el numero 89 ya que";	
					gotoxy(22,7); cout << " 89 = 8^1 + 9^2 = 8 + 81 = 89";	
				
					gotoxy(30,10); color(h,2); cout << " INGRESE UN NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(n, 36, 12,'N'));
					
					color(h,10); barraProgreso(30,16);
					
					//llamo a funcion ubicada en "funcionesAuxiliares.h"
					// 4 parametros, n  = numero, n = hasta que la suma de potencias sea igual a num, osea mi var flag
					// 'P' es de poderoso, asi mi funcion sabra que tendra que buscar un numero poderoso, 1 son las iteracciones del codigo, ya que solo se necesita un ciclo para hallarlo
					// para ver mas detalles ir a "funcionesAuxiliares.h" linea 38
					//30 y 14 son mis parametros que posicionaran la respuesta en la pantalla, meramente estetico
					color(h,14);
					if(sumaExponentes(n, n, 'P', 1, 30, 14) == n){
						color(h,2);
						gotoxy(30,18); cout << " El numero es tan poderoso como superman ya que la suma ";
						gotoxy(30,19); cout << " de sus digitos a la k potencia dio el mismo numero ";
					}
					else{
						color(h,4);
						gotoxy(30,18); cout << " El numero no tiene una pizca de poderoso ya que la suma";
						gotoxy(30,19); cout << " de sus digitos a la k potencia NO dio el mismo numero";
					}
			
			}
			//NUMERO NARCISISTA
			else if(opcionSecundaria == '5'){
				
					//n natural a ingresar
					int n;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS NARCISISTAS ";
			
					color(h,7);
			
					gotoxy(22,5); cout << " todo número de k dígitos que cumple que es igual ";
					gotoxy(22,6); cout << " a la suma de las potencias k de sus dígitos es un número narcisista";	
					gotoxy(22,7); cout << " Por ejemplo, 153 es un número narcisista de 3 dígitos";	
					gotoxy(22,8); cout << " ya que 1^3 + 5^3 + 3^3 = 153.";	
					
					
					gotoxy(30,10); color(h,2); cout << " INGRESE UN NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(n, 36, 12,'N'));
						
					color(h,10); barraProgreso(30,16);
					
					//llamo a funcion ubicada en "funcionesAuxiliares.h"
					// 4 parametros, n  = numero, n = hasta que la suma de potencias sea igual a num, osea mi var flag
					// 'N' es de narcisista, asi mi funcion sabra que tendra que buscar un numero narcisista , 1 son las iteracciones del codigo, ya que solo se necesita un ciclo para hallarlo
					// para ver mas detalles ir a "funcionesAuxiliares.h" linea 38
					//30 y 14 son mis parametros que posicionaran la respuesta en la pantalla, meramente estetico
					color(h,14);
					if(sumaExponentes(n, n, 'N', 1, 30, 14) == n){
						color(h,2);
						gotoxy(30,18); cout << " El numero es muy narcisista ya que la suma ";
						gotoxy(30,19); cout << " de sus digitos a la k potencia dio el mismo numero ";
					}
					else{
						color(h,4);
						gotoxy(30,18); cout << " El numero no tiene nada de narcisista ya que la suma";
						gotoxy(30,19); cout << " de sus digitos a la k potencia NO dio el mismo numero";
					}
			
			}
			else if(opcionSecundaria == 'D'){
				system("cls");
				continue;
			}

		}
		
		//LOS MAS CERCANOS
		else if(opcion == 'C'){
			
			//NUMERO PRIMO
			if(opcionSecundaria == '1'){
				
					//n natural a ingresar
					int p;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS PRIMOS ";
			
					color(h,7);
			
					gotoxy(18,5); cout << " todo número natural mayor que 1 que cumple que sus únicos divisores";
					gotoxy(18,6); cout << " son el 1 y el propio número. Ejemplos: 2, 3, 5, etc... ";	
			
					gotoxy(30,10); color(h,2); cout << " INGRESE EL PRIMER NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(p, 36, 12,'N'));
					
					color(h,10); barraProgreso(30,16);
					
					gotoxy(30,15); color(h,14); cout << " LOS DIVISORES DEL NUMERO:  ";	
				
					//para mostrar los divisores de p
					gotoxy(30,17); 	color(h,14); 
					printDivPrimo(p);
					
					color(h,2);
					if(primo(p)==true){
						color(h,2);
						gotoxy(25,20); cout << " El numero es primo ya que sus unicos divisores ";
						gotoxy(25,21); cout << " son el 1 y el propio numero ";
					}
					else{
						color(h,4);
						gotoxy(25,20); cout << " El numero no es primo ya que sus divisores ";
						gotoxy(25,21); cout << " son 1. mayores a dos y 2. diferentes a uno y el mismo ";
					}
				
			
			}
			//NUMERO PRIMOS GEMELOS
			else if(opcionSecundaria == '2'){
				
					//n natural a ingresar
					int p, p2;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS PRIMOS GEMELOS ";
			
					color(h,7);
			
					gotoxy(22,5); cout << " Dos números primos se denominan primos gemelos si su diferencia ";
					gotoxy(22,6); cout << " es igual a 2, es decir, una pareja de la forma (p,p+2) ";	
					gotoxy(22,7); cout << " siendo p un número primo. Por ejemplo las parejas (3,5) y (17,19)";
					gotoxy(22,8); cout << " son dos parejas de primos gemelos ";		
				
					gotoxy(30,10); color(h,2); cout << " INGRESE EL PRIMER NUMERO PRIMO ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(p, 36, 12,'S'));
					
					gotoxy(30,14); color(h,2); cout << " INGRESE EL SEGUNDO NUMERO PRIMO ";
					gotoxy(32,16); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,16);	
					}while(validarNatural(p2, 36, 16,'S'));
					
					color(h,10); barraProgreso(30,20);
					
					gotoxy(30,18); color(h,14); cout << " LOS DIVISORES DEL NUMERO:  ";	
				
					//para mostrar los divisores de p
					gotoxy(30,20); 	color(h,14); 
					printDivPrimo(p);
					
					//para mostrar los divisores de p2
					gotoxy(30,21); 	color(h,14); 
					printDivPrimo(p2);
				
					color(h,2);
					if(((p+2)==p2) or (p==(p2+2))){
						color(h,2);
						gotoxy(25,23); cout << " los numeros son primos gemelos de nacimiento ";
						gotoxy(25,24); cout << " ya que su diferencia es de 2  ";
					}
					else{
						color(h,4);
						gotoxy(25,23); cout << " los numeros NO son primos gemelos, ni se parecen";
						gotoxy(25,24); cout << " ya que su diferencia NO es de 2  ";
					}
			
			}
			//NUMERO PRIMOS PRIMOS
			else if(opcionSecundaria == '3'){
				
					//n natural a ingresar
					int p, p2;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS PRIMOS PRIMOS ";
			
					color(h,7);
			
					gotoxy(18,5); cout << " Dos números primos se denominan primos primos (del inglés cousin prime) ";
					gotoxy(18,6); cout << " si su diferencia es igual a 4, es decir, una pareja de la forma (p,p+4) ";	
					gotoxy(18,7); cout << " siendo p un número primo. Por ejemplo las parejas (3,7) y (7,11)";
					gotoxy(18,8); cout << " son dos parejas de primos primos ";		
				
					gotoxy(30,10); color(h,2); cout << " INGRESE EL PRIMER NUMERO PRIMO ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(p, 36, 12,'S'));
					
					gotoxy(30,14); color(h,2); cout << " INGRESE EL SEGUNDO NUMERO PRIMO ";
					gotoxy(32,16); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,16);	
					}while(validarNatural(p2, 36, 16,'S'));
					
					color(h,10); barraProgreso(30,20);
					
					gotoxy(30,18); color(h,14); cout << " LOS DIVISORES DEL NUMERO:  ";	
				
					//para mostrar los divisores de p
					gotoxy(30,20); 	color(h,14); 
					printDivPrimo(p);
					
					//para mostrar los divisores de p2
					gotoxy(30,21); 	color(h,14); 
					printDivPrimo(p2);
				
					color(h,2);
					if(((p+4)==p2) or (p==(p2+4))){
						color(h,2);
						gotoxy(25,23); cout << " los numeros son primos primos de familia ";
						gotoxy(25,24); cout << " ya que su diferencia es de 4  ";
					}
					else{
						color(h,4);
						gotoxy(25,23); cout << " los numeros NO son primos primos, ni son familia";
						gotoxy(25,24); cout << " ya que su diferencia NO es de 4  ";
					}
				
			}
			//NUMERO PRIMOS SEXY
			else if(opcionSecundaria == '4'){
				
				//n natural a ingresar
					int p, p2;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS PRIMOS SEXYS ";
			
					color(h,7);
			
					gotoxy(18,5); cout << " Dos números primos se denominan primos sexys (del inglés sexy prime) ";
					gotoxy(18,6); cout << " si su diferencia es igual a 6, es decir, una pareja de la forma (p,p+6) ";	
					gotoxy(18,7); cout << " siendo p un número primo. Por ejemplo las parejas (5,11) y (11,17)";
					gotoxy(18,8); cout << " son dos parejas de primos sexys ";		
				
					gotoxy(30,10); color(h,2); cout << " INGRESE EL PRIMER NUMERO PRIMO ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(p, 36, 12,'S'));
					
					gotoxy(30,14); color(h,2); cout << " INGRESE EL SEGUNDO NUMERO PRIMO ";
					gotoxy(32,16); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,16);	
					}while(validarNatural(p2, 36, 16,'S'));
					
					color(h,10); barraProgreso(30,20);
					
					gotoxy(30,18); color(h,14); cout << " LOS DIVISORES DEL NUMERO:  ";	
				
					//para mostrar los divisores de p
					gotoxy(30,20); 	color(h,14); 
					printDivPrimo(p);
					
					//para mostrar los divisores de p2
					gotoxy(30,21); 	color(h,14); 
					printDivPrimo(p2);
				
					color(h,2);
					if(((p+6)==p2) or (p==(p2+6))){
						color(h,2);
						gotoxy(25,23); cout << " los numeros son primos super sexys, que calor ";
						gotoxy(25,24); cout << " ya que su diferencia es de 6 ";
					}
					else{
						color(h,4);
						gotoxy(25,23); cout << " los numeros NO son nada primos sexys ";
						gotoxy(25,24); cout << " ya que su diferencia NO es de cerca 6 ";
					}
				
			}
			//NUMERO COPRIMO
			else if(opcionSecundaria == '5'){
				
					//n natural a ingresar
					int p, p2;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS COPRIMOS ";
			
					color(h,7);
			
					gotoxy(18,5); cout << " son aquellos pares de números que no tienen divisores en común, salvo el 1 ";
					gotoxy(18,6); cout << " Por ejemplo 10 y 12 NO son coprimos ya que el 2 es su divisor en común. ";	
					gotoxy(18,7); cout << " ENTONCES: si dos números son primos, por lo tanto son coprimos";
				
					gotoxy(30,10); color(h,2); cout << " INGRESE EL PRIMER NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(p, 36, 12,'N'));
					
					gotoxy(30,14); color(h,2); cout << " INGRESE EL SEGUNDO NUMERO NATURAL ";
					gotoxy(32,16); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,16);	
					}while(validarNatural(p2, 36, 16,'N'));
					
					color(h,10); barraProgreso(30,20);
					
					gotoxy(30,18); color(h,14); cout << " LOS DIVISORES DEL NUMERO:  ";	
				
					//para mostrar los divisores de p
					gotoxy(30,20); 	color(h,14); 
					printDivPrimo(p);
					
					//para mostrar los divisores de p2
					gotoxy(30,21); 	color(h,14); 
					printDivPrimo(p2);
					
					color(h,2);
					if(coprimos(p,p2)){
						color(h,2);
						gotoxy(25,23); cout << " los numeros son super coprimos ya que ambos";
						gotoxy(25,24); cout << " no tienen ningun divisor en comun salvo el 1";
					}
					else{
						color(h,4);
						gotoxy(25,23); cout << " los numeros NO son nada coprimos ";
						gotoxy(25,24); cout << " ya que tienen varios divisores en común ";
					}
				
			}
			//NUMERO AMIGO
			else if(opcionSecundaria == '6'){
				
					//n natural a ingresar
					int p, p2, z1 = 0, z2 = 0;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS AMIGOS ";
			
					color(h,7);
			
					gotoxy(18,5); cout << " parejas de números que cumplen que la suma de los divisores propios ";
					gotoxy(18,6); cout << " de cada uno de ellos da como resultado el otro número. Por ejemplo, ";	
					gotoxy(18,7); cout << " 220 y 284 son números amigos";
				
					gotoxy(30,10); color(h,2); cout << " INGRESE EL PRIMER NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(p, 36, 12,'N'));
					
					gotoxy(30,14); color(h,2); cout << " INGRESE EL SEGUNDO NUMERO NATURAL ";
					gotoxy(32,16); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,16);	
					}while(validarNatural(p2, 36, 16,'N'));
					
					color(h,10); barraProgreso(30,20);
					
					gotoxy(20,18); color(h,14); cout << " LA SUMA DE LOS DIVISORES DEL NUMERO:  ";	
				
					gotoxy(20,20); printSumaDiv(p); //para mostrar los divisores de p
					z1 = sumaDivisoresPropios(p);
					cout << "\b\b = " << z1 ;
					
					gotoxy(20,22); printSumaDiv(p2); //para mostrar los divisores de p2
					z2 = sumaDivisoresPropios(p2);
					cout << "\b\b = " << z2 ;
					
				
					color(h,2);
					if((z1 == p2) and (z2 == p)){
						color(h,2);
						gotoxy(25,25); cout << " los numeros son super amiguitos ya que ambas sumas";
						gotoxy(25,26); cout << " de divisores dio el otro numero";
					}
					else{
						color(h,4);
						gotoxy(25,25); cout << " los numeros NO son nada amigos, ni se conocen ";
						gotoxy(25,26); cout << " ya que ambas sumas de divisores NO dio el otro numero ";
					}
				
			}
			//NUMERO NOVIOS O CASI AMIGOS
			else if(opcionSecundaria == '7'){
				
					//n natural a ingresar
					int p, p2, z1 = 0 , z2 = 0;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS NOVIOS ";
			
					color(h,7);
			
					gotoxy(18,5); cout << " Dos números a y b, de modo que la suma de los divisores de a, ";
					gotoxy(18,6); cout << " la suma de los divisores de b, y a + b + 1 den lo mismo. ";	
					gotoxy(18,7); cout << " Ejemplo: 48 y 75 son numeros novios ";
				
					gotoxy(30,10); color(h,2); cout << " INGRESE EL PRIMER NUMERO NATURAL ";
					gotoxy(32,12); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,12);	
					}while(validarNatural(p, 36, 12,'N'));
					
					gotoxy(30,14); color(h,2); cout << " INGRESE EL SEGUNDO NUMERO NATURAL ";
					gotoxy(32,16); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,16);	
					}while(validarNatural(p2, 36, 16,'N'));
					
					color(h,10); barraProgreso(30,20);
					
					gotoxy(20,18); color(h,14); cout << " LA SUMA DE LOS DIVISORES DEL NUMERO:  ";	
				
					gotoxy(20,20); printDivPrimo(p);
					sumaDivisores(p, 1, z1);
					cout << "\b\b = " << z1;
					
					//para mostrar los divisores de p2
					gotoxy(20,21); printDivPrimo(p2);
					sumaDivisores(p2, 1, z2);
					cout << "\b\b = " << z2 ;
					
					gotoxy(20,23); cout<<p<<" + "<<p2<<" + 1 = "<<p+p2+1;
				
					color(h,2);
					if(z1==(p+p2+1) and z2==(p+p2+1)){
						color(h,2);
						gotoxy(25,25); cout << " los numeros son super novios ya que a + b + 1 ";
						gotoxy(25,26); cout << " dieron lo mismo";
					}
					else{
						color(h,4);
						gotoxy(25,25); cout << " los numeros NO son novios, se odian";
						gotoxy(25,26); cout << " ya que a + b + 1 no dieron lo mismo ";
					}
			}
			//NUMERO SOCIABLES
			else if(opcionSecundaria == '8'){
				
					//n natural a ingresar
					int p, p2;
				
					gotoxy(45,3); color(h,14); cout << " NUMEROS SOCIABLES ";
			
					color(h,7);
			
					gotoxy(18,5); cout << " Los números sociables, o una secuencia de números sociables, ";
					gotoxy(18,6); cout << " está formada por una cantidad finita de números de forma que la  ";	
					gotoxy(18,7); cout << " suma de los divisores del primer número es igual al segundo ";
					gotoxy(18,8); cout << " la suma de los divisores de este igual al tercero, y así hasta ";
					gotoxy(18,9); cout << " el último número, cuya suma de divisores es igual al primer numero ";
					
					gotoxy(30,12); color(h,2); cout << " INGRESE EL PRIMER NUMERO NATURAL ";
					gotoxy(32,13); color(h,14); cout << " - "; 
					
					do{
						gotoxy(36,13);	
					}while(validarNatural(p, 36, 13,'N'));
				
					
					color(h,10); barraProgreso(30,20);				
				
					color(h,2);
					if(sociable(p)){
						color(h,2);
						gotoxy(25,20); cout << " los numeros son super sociables ya que la secuencia ";
						gotoxy(25,21); cout << " de sumas de divisores termino dando el primer numero ";
					}
					else{
						color(h,4);
						gotoxy(25,20); cout << " los numeros son NO SON NADA sociables ya que la secuencia";
						gotoxy(25,21); cout << " de sumas de divisores NUNCA dará el primer numero ";
					}				
			}
			else if(opcionSecundaria == 'D'){
				system("cls");
				continue;
			}			
		}
		
		gotoxy(95,3); color(h,14); cout << " PARA IR AL MENÚ ";
		gotoxy(95,4); color(h,14); cout << " PRESIONA CUALQUIER ";
		gotoxy(95,5); color(h,14); cout << " TECLA";		
		getch();	
		system("cls");	
	}
	
	
	return 0;
}
