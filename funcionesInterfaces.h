
//ATENCION ES PROBABLE QUE AL COMPILAR EL HEADER DE ERROR, YA QUE LAS LIBRERIAS SOLO SE DECLARAN EN EL MAIN PARA EVITAR EXCESO DE LIBRERIAS, CARGAR EL ARCHIVO Y COMPILAR EL MAIN.CPP

//LA SIGUIENTE TARRANGANA DE CODIGO SU UNICO FIN ES PARA MERA ESTETICA, AQUI NO SE EJECUTA NADA DEL PROYECTO

// ******** PARTE DE LA INTERFAZ DEL PROGRAMA ********

   //FUNCION GOTOXY, hace que podamos ubicar los mensajes en la pantalla mas facilmente, usando los ejes X, ejes Y
   // no interfiere con el rendimiento del programa, solo estetica
	void gotoxy(int x, int y) {
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}
		
// *************** PARTE DEL MENU ******

	//Metodos que me ayudaran a darle colores a la interfaz
		
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	#define color SetConsoleTextAttribute	
    #define h hConsole
 	
	//funcion para crear el recuadro de la interfaz
	void bordes(){
		
		//constantes, mi pantalla tendra 80 de ancho por 28 de alto
		const int X = 80, Y = 28;
		
		//doble for para recorrer los ejes
		for(int y = 0; y < Y; y++){
			for(int x = 0; x < X; x++){
				
				color(h,14);
				//uso de gotoxy para imprimirlo en cada eje Pos inicial, central y final
				if(y == 0){
					gotoxy(x+15,y); cout << "_";
				}
				if(y == Y-1){
					gotoxy(x+15,y); cout << "_";
				}
				if(x == 0 and y > 0){
					gotoxy(x+15,y); cout << "|";
				}
				if(x == X-1 and y > 0){
					gotoxy(x+15,y); cout << "|";
				}
					
			}
		}
	}
	
	//funcion de barra de progreso estetica
	
	void barraProgreso(int x, int y) {
	    int progreso = 0;
	    while (progreso <= 100) {
	        gotoxy(x,y); cout << "[";
	        int pos = 30 * progreso / 100; // Longitud de la barra
	        for (int i = 0; i < 30; ++i) {
	            if (i <= pos) cout << "=";
	            else cout << " ";
	        }
	        cout << "]" << endl;
	        progreso += 10; // Incremento de progreso
	        Sleep(100);
	    }
	    Beep(700, 500);
	    gotoxy(x,y); cout<<"                                                    ";
	}

	
	/* ******* FUNCION QUE ME CONTROLA EL CURSOR DE LA INTERFAZ  ********
	
	los demas parametros definen el campo en el que se movera la flecha
	posXinit y posYinit definen en que posicion comenzara la flecha y tambien es un limite para que no sobrepase
	posXmax y posYmax hasta q pos llegara y no podra sobrepasar
	los saltos es cuantos caracteres se movera, si quiero que vaya en dos en dos o en 10 en 10, etc...
	char menu ubicara en que menu esta
	
	ejemplo los parametros para el menu principal son:
	
	tecla, 20 , 5 , 55, 17 , 35, 12, N
	
	para los menu secundarios A y B:
	
	tecla, 37, 15 , 37, 25 , 0 , 2, N
	
	para el menu C:
	aqui mando el char S para activar el comportamiento unico en este menu
	
	tecla, 37, 13 , 37, 26 , 0 , 2, S

	*/
	
	int flecha( int posXinit, int posYinit, int posXmax, int posYmax, int saltoEnX, int saltoEnY, char menu){
		
		int ejeY = posYinit; //val inicial eje y
		int ejeX =  posXinit; //val inicial eje x
		int auxX, auxY;
		
		//var que guardara el valor en ascii de las teclas presionadas
		int tecla = 0;
		color(h,9);
		//los sprites 
		std::string flecha = "->";
		std::string borrador = "  ";
		
		do{
		
			//funcion kbhit, solo se activa cuando hay una pulsacion en el teclado
			if(_kbhit()){
				
				Beep(700, 100);
				
				//extrae el valor en ascii de la tecla presionada
				tecla = _getch();
				
				//guardar el valor para saber que posicion borrar cuando se modifique
				auxX = ejeX;
				auxY = ejeY;
				
				gotoxy(auxX,auxY); cout << borrador;
					
						//arriba
						if(tecla == 72){
							//valido que este en el menu C
							if(menu == 'S'){
								//todos los menus tienen un comportamiento standard, van de x en x, en cambio el C primero va de 1 en 1 y luego en 2 en 2, para este if
								if(ejeY <= 16){
									ejeY--;
								}
								else{
									ejeY -= saltoEnY;
								}
								//que no sobrepase el eje Y
								if(ejeY < posYinit){
									ejeY = posYinit;
									//si lo sobrepasa se borrara y reseteara la posicion a la ultima guardada
									gotoxy(auxX,ejeY); cout << borrador;
								}
								//se impreme la flecha a su nueva posicion
								gotoxy(ejeX,ejeY); cout << flecha;
							}
							else{
								
							//la distancia que hay entre las columnas
								ejeY -= saltoEnY;
						
								if(ejeY < posYinit){
									ejeY = posYinit;
									gotoxy(auxX,ejeY); cout << borrador;
								}
								gotoxy(ejeX,ejeY); cout << flecha;
							}
							
							//lo demas es lo mismo solo invirtiendo o cambiando los parametros respecto a los ejes X y Y	
						}
						//abajo
						else if(tecla == 80){
							
							if(menu == 'S'){
				
								if(ejeY < 16){
									ejeY++;
								}
								else{
									ejeY += saltoEnY;
								}
							
								if(ejeY > posYmax){
									ejeY = posYmax;
									gotoxy(auxX,ejeY); cout << borrador;
								}
								gotoxy(ejeX,ejeY); cout << flecha;
							}
							else{
							
								ejeY += saltoEnY;
						
								if(ejeY > posYmax){
									ejeY = posYmax;
									gotoxy(auxX,ejeY); cout << borrador;
								}
								gotoxy(ejeX,ejeY); cout << flecha;
							}
						}
						
						//izquierda
						else if(tecla == 75){
								
								ejeX -= saltoEnX;
						
								if(ejeX <  posXinit){
									ejeX =  posXinit;
									gotoxy(auxX,ejeY); cout << borrador;
								}
								gotoxy(ejeX,ejeY); cout << flecha;
									
						}
						//derecha
						else if(tecla == 77){
								
								ejeX += saltoEnX;
						
								if(ejeX > posXmax){
									ejeX = posXmax;
									gotoxy(auxX,ejeY); cout << borrador;
								}
								gotoxy(ejeX,ejeY); cout << flecha;		
					
						}
						else{
							gotoxy(auxX,auxY); cout << flecha;
						}
				
			}
			
		}while(tecla != 13); //el 13 es el valor del enter en ascii, hasta que el usuario no de enter estara en loop infinito
		
		
		//esto me ayudara a saber en que posicion se encuentra el cursor y que tema esta eligiendo cuando el usuario de enter
		return ejeX+ejeY;
	}

	// ******** CONEXION **********
	// FUNCION QUE HARA LA CONEXION ENTRE MIS OTRAS FUNCIONES, sirve para validar y mantener estable el programa

	char conexion(char opcion, int sumaEjes){
		
		switch(opcion){
		
				//LOS TERRIBLES
				case 'A':
				//LOS ENVIDIADOS
				case 'B':
					//ambas sumas en case A y B son iguales
					switch(sumaEjes){
						
						//EL CASE ES LA SUMA DE MIS EJES X, Y EJ: X = 37 , Y = 15; CASE 52, ASI SE EN QUE TEMA ESTA EL USUARIO
						//NUMERO MALVADO //NUMERO FELIZ
						case 52: return '1';
						//NUMERO ODIOSO //NUMERO PERFECTO
						case 54: return '2';
						//NUMERO AMBICIOSO //NUMERO SEMI-PERFECTO
						case 56: return '3';
						//NUMERO CURIOSO 	//NUMERO PODEROSO
						case 58: return '4';
						//NUMERO INFELIZ //NUMERO NARCISISTA
						case 60: return '5';
						//SALIR	
						case 62: return 'D';
					}
					
					break;
					
				//LOS MAS CERCANOS
				case 'C':
					
					switch(sumaEjes){
					
						//NUMERO PRIMO
						case 50: return '1';
						//NUMERO PRIMOS GEMELOS
						case 51: return '2';
						//NUMERO PRIMOS PRIMOS
						case 52: return '3';
						//NUMERO PRIMOS SEXY
						case 53: return '4';
						//NUMERO COPRIMO
						case 55: return '5';
						//NUMERO AMIGO
						case 57: return '6';
						//NUMERO NOVIOS O CASI AMIGOS
						case 59: return '7';
						//NUMERO SOCIABLES
						case 61: return '8';
						//SALIR	
						case 63: return 'D';
						
					}
				break;
		}
		
	}
	
	
	void salirPro(int x, int y, int i){
		gotoxy(x,y++); color(h,i); cout <<" _______ _______ ___     ___ _______ __    _ ______  _______    \n";
		gotoxy(x,y++); color(h,i); cout <<"|       |       |   |   |   |       |  |  | |      ||       |  \n";
		gotoxy(x,y++); color(h,i); cout <<"|  _____|   _   |   |   |   |    ___|   |_| |  _    |   _   | \n";
		gotoxy(x,y++); color(h,i); cout <<"| |_____|  |_|  |   |   |   |   |___|       | | |   |  | |  |  \n";
		gotoxy(x,y++); color(h,i); cout <<"|_____  |       |   |___|   |    ___|  _    | |_|   |  |_|  |  \n";
		gotoxy(x,y++); color(h,i); cout <<" _____| |   _   |       |   |   |___| | |   |       |       |  \n";
		gotoxy(x,y++); color(h,i); cout <<"|_______|__| |__|_______|___|_______|_|  |__|______||_______| \n";
		
		y+= 3;
		
		gotoxy(x,y++); color(h,i); cout <<" ______  _______ ___        _______ ______   _______ _______ ______   _______ __   __ _______  \n";		
		gotoxy(x,y++); color(h,i); cout <<"|      ||       |   |      |       |    _ | |       |       |    _ | |       |  |_|  |       |\n";		
		gotoxy(x,y++); color(h,i); cout <<"|  _    |    ___|   |      |    _  |   | || |   _   |    ___|   | || |   _   |       |   _   |\n";	
		gotoxy(x,y++); color(h,i); cout <<"| | |   |   |___|   |      |   |_| |   |_||_|  | |  |   | __|   |_||_|  |_|  |       |  |_|  |\n";	
		gotoxy(x,y++); color(h,i); cout <<"| |_|   |    ___|   |___   |    ___|    __  |  |_|  |   ||  |    __  |       |       |       |\n";	
		gotoxy(x,y++); color(h,i); cout <<"|       |   |___|       |  |   |   |   |  | |       |   |_| |   |  | |   _   | ||_|| |   _   |\n";	
		gotoxy(x,y++); color(h,i); cout <<"|______||_______|_______|  |___|   |___|  |_|_______|_______|___|  |_|__| |__|_|   |_|__| |__|\n";
		
		color(h,4); barraProgreso(x+20,y+5);
	}
	
	
	//funcion que valide la entrada del menu principal 
	char opcionPrincipal(int sumaEjes){
		
		switch(sumaEjes){
			
			case 25:
				return 'A';
			case 60:
				return 'B';		
			case 37:
				return 'C';
			case 72:
				system("cls");
				salirPro(10,5,14);
				exit(0);
				break;
				
		}
		
	}
	

	//funcion que muestra las opciones del menu
	char menuPrincipal(){
	
		system("cls");
		
		//llamo a mi interfaz
		bordes();
		
		gotoxy(98,15); color(h,14); cout << "HECHO POR:";
		gotoxy(98,17); color(h,14); cout << "JOSE RAPALINO";
		gotoxy(98,18); color(h,14); cout << "0222220010";
		
		//gotoxy para añadir el mensaje a la posicion deseada, color para estetica
		gotoxy(43,3); color(h,14); cout << " LA FAMILIA NUMEROSA ";
		gotoxy(23,5); color(h,2); cout << " [A] LOS TERRIBLES ";
		gotoxy(25,6); color(h,7); cout << " 1. Número Malvado ";
		gotoxy(25,7); cout << " 2. Número Odioso ";
		gotoxy(25,8); cout << " 3. Número Ambicioso ";
		gotoxy(25,9); cout << " 4. Número Curioso ";
		gotoxy(25,10); cout << " 5. Número Infeliz ";
		gotoxy(58,5); color(h,2); cout << " [B] LOS ENVIDIADOS ";
		gotoxy(60,6); color(h,7); cout << " 1. Número Feliz ";
		gotoxy(60,7); cout << " 2. Número Perfecto ";
		gotoxy(60,8); cout << " 3. Número Semiperfecto ";
		gotoxy(60,9); cout << " 4. Número Poderoso "; 
		gotoxy(60,10); cout << " 5. Número Narcisista ";
		gotoxy(23,17); color(h,2); cout << " [C] LOS MÁS CERCANOS ";
		gotoxy(25,18); color(h,7); cout << " 1. Números Primos ";
		gotoxy(25,19); cout << " 1.1 Primos Gemelos ";
		gotoxy(25,20); cout << " 1.2 Primos Primos ";
		gotoxy(25,21); cout << " 1.3 Primos sexy ";
		gotoxy(25,22); cout << " 2. Números Coprimos ";
		gotoxy(25,23); cout << " 3. Números Amigos ";
		gotoxy(25,24); cout << " 4. Números novios o casi amigos ";
		gotoxy(25,25); cout << " 5. Números Sociables ";
		gotoxy(58,17); color(h,4); cout << " [D] SALIR ";
		
		gotoxy(95,3); color(h,14); cout << " Muevase con las ";
		gotoxy(95,4); color(h,14); cout << " teclas direccionales ";
		gotoxy(95,7); color(h,14); cout << " PRESIONE ENTER ";
		gotoxy(95,8); color(h,14); cout << " PARA ELEGIR ";
		
		int opcionUser;
	
		//lo llevo a mi funcion que controla el cursor, retorna la suma de los ejes X y Y de la pantalla, asi sabre en que opcion esta
		//ejemplo 20 , 5 que la posicion inicial de la flecha sea eje X 20, eje Y 5, 'N' es una condicion unica para el menu C
		opcionUser = flecha( 20, 5, 55, 17, 35, 12, 'N');
	
		//llama a mi funcion que verifica la suma de ejes y retorna la opcion elegida
		return opcionPrincipal(opcionUser);
	}
	
	//segundo menu que entra con mas claridad en cada opcion, recibe la opcion del menu principal 
	char menuSecundario(char opcion){
		
		system("cls");
		
		bordes();

		//var que guarda la eleccion del usuario
		char opcionSecundaria;
		
		// [A] LOS TERRIBLES
		if(opcion == 'A'){
			
			gotoxy(45,3); color(h,14); cout << " LOS TERRIBLES ";
			
			color(h,7);
			gotoxy(25,5); cout << " Los 'números terribles' son números con ";
			gotoxy(25,6); cout << " propiedades complejas, en matemáticas son";	
			gotoxy(25,7); cout << " estudiados en ramas como teoría de números ";
			gotoxy(25,8); cout << " y complejidad computacional. A pesar de su    ";			
			gotoxy(25,9); cout << " complejidad, su estudio ha llevado a ";
			gotoxy(25,10); cout << " importantes descubrimientos y aplicaciones en  ";
			gotoxy(25,11); cout << " tecnologías como criptografía y codificación de información. ";
		
			
			gotoxy(40,15); color(h,2); cout << " [1] Número Malvado ";
			gotoxy(40,17); cout << " [2] Número Odioso ";
			gotoxy(40,19); cout << " [3] Número Ambicioso ";
			gotoxy(40,21); cout << " [4] Número Curioso ";
			gotoxy(40,23); cout << " [5] Número Infeliz ";
			gotoxy(40,25); color(h,4); cout << " [D] SALIR ";
				
		}
		
		// [B] LOS ENVIDIADOS
 		else if(opcion == 'B'){
			
			gotoxy(45,3); color(h,14); cout << " LOS ENVIDIADOS ";
			
			color(h,7);
			gotoxy(35,5); cout << "Los 'números envidiados' son números en la ";
			gotoxy(35,6); cout << "matemática que poseen propiedades ";	
			gotoxy(35,7); cout << "interesantes y deseables, como el número ";
			gotoxy(35,8); cout << "pi o el número de oro. Estos números ";			
			gotoxy(35,9); cout << "tienen importancia en muchas áreas de ";
			gotoxy(35,10); cout << "la matemática y su estudio ha llevado a  ";
			gotoxy(35,11); cout << "importantes descubrimientos y avances en ";
			gotoxy(35,12); cout << "la comprension del universo";
			 
			gotoxy(40,15); color(h,2); cout << " [1] Número Feliz ";
			gotoxy(40,17); cout << " [2] Número Perfecto ";
			gotoxy(40,19); cout << " [3] Número Semiperfecto ";
			gotoxy(40,21); cout << " [4] Número Poderoso "; 
			gotoxy(40,23); cout << " [5] Número Narcisista ";
			gotoxy(40,25); color(h,4); cout << " [D] SALIR ";
			
		
		}
		
		// [C] LOS MAS CERCANOS
		else if(opcion == 'C'){
			
			gotoxy(45,3); color(h,14); cout << " LOS MÁS CERCANOS ";
			
			color(h,7);
			gotoxy(35,5); cout << "Los números más cercanos en matemáticas ";
			gotoxy(35,6); cout << "son aquellos que tienen una diferencia ";	
			gotoxy(35,7); cout << "mínima entre ellos. Son importantes en ";
			gotoxy(35,8); cout << "muchas áreas de las matemáticas, desde la ";			
			gotoxy(35,9); cout << "geometría hasta la criptografía, ya que";
			gotoxy(35,10); cout << "se utilizan para simplificar cálculos y ";
			gotoxy(35,11); cout << "garantizar la seguridad de los datos.";
			
			gotoxy(40,13); color(h,2); cout << " [1] Números Primos ";
			gotoxy(43,14); cout << " [2] Primos Gemelos ";
			gotoxy(43,15); cout << " [3] Primos Primos ";
			gotoxy(43,16); cout << " [4] Primos sexy ";
			gotoxy(40,18); cout << " [5] Números Coprimos ";
			gotoxy(40,20); cout << " [6] Números Amigos ";
			gotoxy(40,22); cout << " [7] Números novios o casi amigos ";
			gotoxy(40,24); cout << " [8] Números Sociables ";
			gotoxy(40,26); color(h,4); cout << " [D] SALIR ";
		
		}
		
	
		int opcionUser;
	
			//lo llevo a mi funcion que controla el cursor, la var opcion puede ser A , B , C asi sabre en que opcion esta
			if(opcion == 'C'){
				opcionUser = flecha( 37, 13, 40, 26, 0, 2, 'S');
			}else{
				opcionUser = flecha( 37, 15, 40, 25, 0, 2, 'N');
			}
							
	
		//llama a mi funcion que verifica la suma de ejes y retorna la opcion elegida
		return conexion(opcion, opcionUser);
	}
	

	
	void proyecto(int x, int y, int i){                                           
		 gotoxy(x,y++); color(h,i); cout <<"	¯¦¦¦¯¯¯¦¦_¯¦¦¦¯¯¯¦¦_   __¦¯¯¦¦_ ¯¦¦¦¯   ¯¦¦¯¦¦¦¯¯¯¦¦¦  __¦¯¯¯¦_¦¦¦¯¯¦¦¯¯¦¦¦ __¦¯¯¦¦_     ¯¦¦¦¯¯¯¦¦_¯¦¦¦¯¯¯¦¦_ ";
		 gotoxy(x,y++); color(h,i); cout <<"	  ¦¦   ¯¦¦_ ¦¦   ¯¦¦__¦¦¯    ¯¦¦_ ¦¦¦   _¦   ¦¦    ¯¦_¦¦¯     ¯¦¯   ¦¦   ¯¦¦¦¯    ¯¦¦_     ¦¦   ¯¦¦_ ¦¦    ¦¦ ";
		 gotoxy(x,y++); color(h,i); cout <<"	  ¦¦   _¦¦  ¦¦   _¦¦ ¦¦¯      ¯¦¦  ¦¦¦ _¦    ¦¦   ¦  ¦¦¯       ¯    ¦¦    ¦¦¯      ¯¦¦     ¦¦   _¦¦  ¦¦    ¦¦ ";
		 gotoxy(x,y++); color(h,i); cout <<"	  ¦¦¦¦¦¦¦   ¦¦¦¦¦¦¦  ¦¦        ¦¦   ¦¦¦¦     ¦¦¦¦¦¦  ¦¦             ¦¦    ¦¦        ¦¦     ¦¦¦¦¦¦¦   ¦¦¯¯¯¦__ ";
		 gotoxy(x,y++); color(h,i); cout <<"	  ¦¦        ¦¦  ¦¦_  ¦¦_      _¦¦    ¦¦      ¦¦   ¦  _¦_            ¦¦    ¦¦_      _¦¦     ¦¦        ¦¦    ¯¦ ";
		 gotoxy(x,y++); color(h,i); cout <<"	  ¦¦        ¦¦   ¯¦¦_¯¦¦_    _¦¦¯    ¦¦      ¦¦     _¦¦¦_     _¯    ¦¦    ¯¦¦_    _¦¦¯     ¦¦        ¦¦    _¦ ";
		 gotoxy(x,y++); color(h,i); cout <<"	_¦¦¦¦_    _¦¦¦¦_ _¦¦¦_ ¯¯¦¦¦¦¯¯    _¦¦¦¦_  _¦¦¦¦¦¦¦¦¦¦ ¯¯¦¦¦¦¦¯   _¦¦¦¦_    ¯¯¦¦¦¦¯¯     _¦¦¦¦_    _¦¦¦¦¦¦¦¦  ";
	}
	
	void primerCorte(int x, int y, int i){
		gotoxy(x,y++); color(h,i); cout <<" _                                 \n";
		gotoxy(x,y++); color(h,i); cout <<"|_)  _ .__  _   _    _  _   __|_ _  \n";
		gotoxy(x,y++); color(h,i); cout <<"|   |  ||||(/_ |    (_ (_) |  |_(/_  \n";
	}
	
	void joseRapalino(int x, int y, int i){
		gotoxy(x,y++); color(h,i); cout <<"    __ _____ _____ _____    _____ _____ _____ _____ __    _ _____ _____ \n";
		gotoxy(x,y++); color(h,i); cout <<" _ |  |     |   __|   __|  | __  |  _  |  _  |  _  |  |  | |   | |     | \n";
		gotoxy(x,y++); color(h,i); cout <<"| |_| |  |  |__   |   __|  |    -|     |   __|     |  |__| | | | |  |  | \n";
		gotoxy(x,y++); color(h,i); cout <<"|_____|_____|_____|_____|  |__|__|__|__|__|  |__|__|_____|_|_|___|_____| \n";
        y += 3;  
		x += 10;                                                          
		gotoxy(x,y++); color(h,i-2); cout <<" __   __   __   __   __   __   __   __      __  \n";
		gotoxy(x,y++); color(h,i-2); cout <<"|  |  __|  __|  __|  __|  __| |  | |  | /| |  | \n";
		gotoxy(x,y++); color(h,i-2); cout <<"|__| |__  |__  |__  |__  |__  |__| |__|  | |__| \n";
	}
	
		//creacion en beep de la melodia de presentacion
	
	void musica(){
		
		const int C    = 261;
		const int Cis  = 277;
		const int D    = 293;
		const int Dis  = 311;
		const int E    = 329;
		const int F    = 349;
		const int Fis  = 369;
		const int G    = 391;
		const int Gis  = 415;
		const int A    = 440;
		const int Ais  = 466;
		const int H    = 493;
		const int Takt = 1700;
		
		
		proyecto(0, 2, 14);
		primerCorte(40,10,10);
		joseRapalino(25,15,13);			
		Beep(E * 2, Takt / 4);
	    Beep(H * 1, Takt / 8);
	    Beep(C * 2, Takt / 8);
	    Beep(D * 2, Takt / 4);
	    Beep(C * 2, Takt / 8);
	    Beep(H * 1, Takt / 8);
	    Beep(A * 1, Takt / 4);
	    Beep(A * 1, Takt / 8);
	    Beep(C * 2, Takt / 8);    
	    Beep(E * 2, Takt / 8);
	    Beep(E * 2, Takt / 8);
	    Beep(D * 2, Takt / 8);
	    Beep(C * 2, Takt / 8);
	    Beep(H * 1, Takt / 2.5);
    
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(E * 2, Takt / 4);
        Beep(C * 2, Takt / 4);
        Beep(A * 1, Takt / 4);
        Beep(A * 1, Takt / 4);
        Sleep(Takt / (8 / 3));
        Beep(D * 2, Takt / 3.25);
        Beep(F * 2, Takt / 8);
        Beep(A * 2, Takt / 8);
        Beep(A * 2, Takt / 8);
        Beep(G * 2, Takt / 8);
        Beep(F * 2, Takt / 8);
        Beep(E * 2, Takt / 3);

        Beep(C * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(D * 2, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(H * 1, Takt / 4);
        Beep(H * 1, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(E * 2, Takt / 4);
        Beep(C * 2, Takt / 4);
        Beep(A * 1, Takt / 4);
        Beep(A * 1, Takt / 4);
		
	}
	

	
	
