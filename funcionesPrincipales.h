// AQUI SE UBICAN LAS FUNCIONES RECURSIVAS PEDIDAS EN REQUERIMIENTOS TECNICOS PUNTO 4

//ATENCION ES PROBABLE QUE AL COMPILAR EL HEADER DE ERROR, YA QUE LAS LIBRERIAS SOLO SE DECLARAN EN EL MAIN PARA EVITAR EXCESO DE LIBRERIAS, CARGAR EL ARCHIVO Y COMPILAR EL MAIN.CPP

//***** FUNCION RECURSIVA DECIMAL A BINARIO *******

		/*funcion que me convierte numero entero a binario recibe 3 parametros, n = numero entero, char *binario el vector donde se almacenara el numero convertido,  NOTA: use char por que me fue mas facil la concatenacion para la recursividad, contBin almacenara la cant de digitos del N binario*/
		void enteroToBinario(int n, char *binario, int &contBin){
			
			//cuando n sea cero significa que ya no se puede dividir mas y no hay residuos que almacenar
		    if (n == 0) {
		        *binario = '\0';
		        return;
		    }
		    
			contBin++;
			
		    enteroToBinario(n / 2, binario + 1, contBin); // Llamada recursiva, se divide el n entre dos y sube de pos el vector
		
		    *binario = (n % 2) + '0'; // Concatenar el dígito binario más significativo al inicio de la cadena
		}
		


//********** FUNCION RECURSIVA PARA DIVISORES *********** 
bool sumaDivisores(int num, int divisor, int& suma){
	if(num % divisor == 0){
		suma += divisor;
	}
	if(num == divisor){
		return true;
	}
	sumaDivisores(num, divisor + 1, suma);
}	
		
		
// ******* FUNCION RECURSIVA PARA LA POTENCIA DE N EXP ****** 

long long potencia(int a,int b){
	if(b==0){
		return 1;
	}else{
		return a*potencia(a,b-1);
	}
}	

//***** FUNCION RECURSIVA BINARIO A DECIMAL *******

/*La función convierte un número binario en un número decimal usando la técnica recursiva.
 La función recibe un arreglo de caracteres que representa el número binario y un contador que indica la posición actual del dígito 
 en el arreglo. La función retorna el resultado final que se obtiene de la suma de las potencias de 2 y los resultados de las llamadas recursivas.
  tiliza la función recursiva potencia para calcular la potencia de 2 correspondiente a la posición actual del dígito.
  parametros enviados, char binario debe estar lleno ya caracteres con el numero binario
  contBin el numero de digitos del binario, cont iniciado en 0
*/
int BinarioDecimal(char binario[], int contBin, int cont){
    if(binario[cont] == '\0'){
        return 0;
    }
    int decimal = BinarioDecimal(binario, contBin,  cont+1);
    if(binario[cont] == '1'){
        decimal += potencia(2, contBin - 1 - cont);
    }
    return decimal;
}


// ************ FUNCION RECURSIVA SUMA DIVISORES PROPIOS *************++

int sumaDivisoresPropios(int n, int i = 2, int suma = 1){
    // Si n es menor o igual a 1, la suma de sus divisores propios es 0
    if(n <= 1){
        return 0;
    }
    // Si i es mayor que la raíz cuadrada de n, se han considerado todos los divisores posibles
    if(i * i > n){
        return suma;
    }
    // Si i es un divisor de n, se suma a la suma actual
    if (n % i == 0){
        suma += i;
        // Si i es distinto de la raíz cuadrada de n, se suma también su complemento como divisor
        if(i != n/i){
            suma += n/i;
        }
    }
    // Se continúa la búsqueda con el siguiente posible divisor
    return sumaDivisoresPropios(n, i+1, suma);
}


// ************* FUNCION RECURSIVA PARA LA SUMA DE CUADRADOS

int SumaDeCuadrado(int n){
    if (n == 0){
        return 0;
    }else{
        int digit = n % 10;
        return digit * digit + SumaDeCuadrado(n / 10);
    }
}

// ********* FUNCION RECURSIVA PARA SUMAR DIGITOS 
int sumaDigitos(int num){
	if(num == 0){
		return 0;
	}
	return num % 10 + sumaDigitos(num / 10);
}

