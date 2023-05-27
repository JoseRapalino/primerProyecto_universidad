//ATENCION ES PROBABLE QUE AL COMPILAR EL HEADER DE ERROR, YA QUE LAS LIBRERIAS SOLO SE DECLARAN EN EL MAIN PARA EVITAR EXCESO DE LIBRERIAS, CARGAR EL ARCHIVO Y COMPILAR EL MAIN.CPP

//LOS TERRIBLES FUNCIONES AUXILIARES 		
	//***** PARTE DE LOS MALVADOS Y ODIOSOS *******
	
			//la cadena de binarios sale al reves, por eso es necesario esta semi-burbuja para ordenarla
			void ordenarCadenaBinario(char *binario, int &contBin) {
			    
			    for (int i = 0; i < contBin / 2; i++) {
			        char temp = binario[i];
			        binario[i] = binario[contBin - i - 1];
			        binario[contBin - i - 1] = temp;
				}
			}
			//ver si el numero binario es malvado u odioso
			bool verificarMalvadoOdioso(char *binario, int &contBin,int &numUnos){
				
					for(int i = 0; i < contBin; i++){
						//comparacion a char ya que creamos el vector como cadena de caracteres
						if(binario[i] == '1'){
							numUnos++; //se contara el numero de unos, ya que si es par es malvado y si es impar es odioso
						}
					}
					
					//validacion de si es par devolvera true = malvado, impar false = odioso
					if(numUnos % 2 == 0){
						return true;
					}
					else{
						return false;
					}
			}
			
	//binario a decimal
	
	bool validarBinario(int &cont, char *binario, int x, int y){
		
		cin>>binario;
		
		for(int i = 0; i < 33; i++){
				
			if(binario[i] == '1' or binario[i] == '0'){
				cont++;
			}
			else if(binario[i] == '\0'){
				return false;
			}
			else{
				cont = 0;
				gotoxy(x,y); cout << "                              ";
				return true;
			}
		}
		
	}
			
	//*********** PARTE DE LOS NUMEROS CURIOSOS
	
			bool NumeroCurioso(int n) {
			    int divisor = 10;
			    while (n >= divisor) {
			        divisor *= 10;
			    }
			    return potencia(n,2) % divisor == n;
			}
	
	// ******** PARTE DE LOS NUMEROS INFELICES
	
		int NumeroInfeliz(int n){
			int z1 = n, z2 = n;
			do{
				z1 = SumaDeCuadrado(z1);
				z2 = SumaDeCuadrado(SumaDeCuadrado(z2));
			}while(z1!=z2);
			return z1!=1;
		}
	
		
// ESTA FUNCION ME SIRVE PARA CALCULAR NUMEROS FELICES, NARCISISTAS Y PODEROSOS, REALIZANDO LEVES MODIFICACIONES CON AYUDA DE LOS PARAMETROS ENVIADOS
// num = numero natural, char opc sera un char que me dira cual validara si [F]elices, [N]arcisista [P]oderoso
// numCopy es la var que guarda el valor del num
//i el n de iteracciones que hara, en los casos de NARCISISTA Y PODEROSO, solo es necesario un ciclo para hallar la respuesta
// pero con los felices es mucho mas extenso, hay una pseudo-regla que dice que si el numero no es feliz entrara en un ciclo infinito de periodo 8
// aunque hay numeros felices gigantes que llegan a necesitar hasta 243 iteracciones para ser hallados, tomare la primera regla y solo usare 10 ciclos como max para hallar numeros felices
int sumaExponentes(int num, int numCopy, char opc, int i, int x, int y){
	
	//var que guardara la suma de las potencias en x iteraccion
	int auxNum = 0;
	//array donde se guardaran los digitos de cada suma, use 10 por que el numero INT mas grande tiene 10 digitos
	int numeroSpace[10];
	//var que contara la iteracciones para cortar el codigo si el numero no es feliz, segun la formula si el numero no es feliz entrara en un bucle infinito de periodo 8
	int iteraciones = 0;
	//contara los digitos de la suma de las potencias
	int cont = 0;
	//las variables x, y son solo para ubicar el gotoxy
	int Xcopy = x;
	
	do{
		//op para sacar el ultimo digito y almacenarlo
		numeroSpace[cont] = num % 10;
		if(num / 10){
			num /= 10; 
			cont++;
		}else{
			
			//for inverso ya que los digitos se almacenaron al reves
			for(int i = cont; i >= 0; i--){
				gotoxy(Xcopy+=6,y);
				std::cout << numeroSpace[i] << "^";
				if(opc == 'F'){
					std::cout <<"2"<<" + ";
					numeroSpace[i] = potencia(numeroSpace[i], 2);
				}
				else if(opc == 'N'){
					std::cout <<cont+1<<" + ";
					numeroSpace[i] = potencia(numeroSpace[i], cont+1);
				}
				else if(opc == 'P'){
					std::cout <<cont-i+1<<" + ";
					numeroSpace[i] = potencia(numeroSpace[i], cont-i+1);
				}
					
				auxNum += numeroSpace[i];
			}
			
			std::cout<<"\b\b";
			
			std::cout << " = " << auxNum << std::endl << std::endl;
			
			cont = 0;
			if(auxNum == numCopy) return auxNum;
			num = auxNum;
			auxNum = 0;
			iteraciones++;
			//estetica
			y++;
			Xcopy = x;
		}
	
		
	}while(iteraciones < i);
	return auxNum;
}		


// PARTE DE LOS SEMI PERFECTOS INCISO B
/* 
dos parametros, n natural y x el numero de divisores de n
 num y x. La función devuelve un valor booleano true si num es semi-perfecto, es decir, si se puede expresar como la 
 suma de algunos de sus divisores y false en caso contrario.
*/

bool SemiPerfecto(int num, int x) {
    int cont = 0;
    int divs[x];

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            divs[cont++] = i;
        }
    }

    // iterar a través de todas las combinaciones posibles
    for (int i = 0; i < potencia(2, cont); i++) {
        int sum = 0;
        // verificar qué divisores se deben incluir en la suma
        for (int j = 0; j < cont; j++) {
            if ((i / (int)potencia(2, j)) % 2 == 1) {
                sum += divs[j];
            }
        }
        if (sum == num) {
            cout << "Los divisores que se suman para obtener " << num << " son: ";
            // mostrar los divisores que se sumaron
            for (int j = 0; j < cont; j++) {
                if ((i / (int)potencia(2, j)) % 2 == 1) {
                    cout << divs[j] << " ";
                }
            }
            return true;
        }
    }
    return false;
}

//********** PARTE DE LOS NUMEROS PRIMOS ***************

//*********** FUNCION BOOLEANA QUE VALIDA SI ES PRIMO 

	bool primo(int a){
		int z=0;
		for(int i=1;i<(a/2)+1;i++){
			if(a%i==0){
				z++;
			}
		}
		if(z>1){
			return false;
		}else{
			return true;
		}
	}
	
// FUNCION DE LOS COPRIMOS

int calcularMCD(int n1, int n2){
	int x;
	while(n2 != 0){
		x = n2;
		n2 = n1 % n2;
		n1 = x;
	}
	return n1;
}

bool coprimos(int n1, int n2){
	return calcularMCD(n1,n2) == 1;
}
	
	
// FUNCION QUE ME VALIDA SI UN NUMERO ES SOCIABLE O NO

 long long int suma_divisores(int n){
	int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;

}

bool sociable(int n1){
	static long long int n2=n1,i=0;
	do{
		n1=suma_divisores(n1);
		if(i>200){
			return false;
		}
		i++;
	}while(n1!=n2 and i>0);
	return true;
}

// 	*********** FUNCION QUE VALIDA LA ENTRADA DE NUMEROS NATURALES Y PRIMOS ***********
// el n es numero que mando por referencia, si no hay ningun error en la entrada, se asignara el valor correctamente
// x, y estetica pata gotoxy, char S = si es primo, debe validar que el caracter ingresado sea numerico, natural y primo, si mando diferente de S solo validara que sea numerico, natural

bool validarNatural(int &n, int x, int y, char esPrimo){

	if(!(cin>>n) or n < 0){
		fflush(stdin);
		cin.clear();
		gotoxy(x,y); cout << "                                      ";
		return true;
	}
	else if(esPrimo == 'S'){
		
		int z=0;
		for(int i=1;i<(n/2)+1;i++){
			if(n%i==0){
				z++;
			}
		}
		if(z>1){
			gotoxy(x,y); cout << "                                      ";
			return true;
		}else{
			return false;
		}
	}
	else{
		return false;
	}
}


//funcion auxiliar, ayuda a mostrar la suma de divisores en el main

void printSumaDiv(int n){
		cout << n << " = ";
		for(int i = 1; i < n; i++){
			if(n % i == 0){
				cout << i  << " + ";		
			}
		}
}

//funcion auxiliar, ayuda a mostrar los divisores de los numeros primos

void printDivPrimo(int n){
	cout << n << " = ";
	for(int i = 1; i <= n; i++){
		if(n % i == 0){
			cout << i  << "  ";		
		}
	}
}




