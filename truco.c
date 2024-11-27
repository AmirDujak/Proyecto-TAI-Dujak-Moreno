#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *palos[4] = { "Oro", "Copas", "Basto", "Espadas" };
int numeros[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12};
int baraja[40] = {0}; // mazo de 40 cartas siendo cada 10 cartas del 0 al 9 un palo
int mano1[][3] = {{1,1,1},{1,1,1}};
int PM = 0;
int PJ = 0;
int trucoCantado = 0;
int rgpc = 0;
int rgj = 0;
//int palabra = 1; // 1 canta truco el jugador, 0 canta truco el oponente



///*
//Funcion donde se registra si se ha cantado truco y en que situación está el juego
// */
//int cantarTruco(int eleccion){
//
//}

/*
Calcula el envido del jugador correspondientes
*/
int calcularEnvido(int *cartas){
    if(cartas[0]/10 == cartas[1]/10){
        if(cartas[0]%10 < 7 && cartas[1]%10 < 7){
            return (cartas[0]%10)+(cartas[1]%10)+22;
        }
        else if(cartas[0]%10 < 7){
            return (cartas[0]%10)+21;
        }
        else if(cartas[1]%10 < 7){
            return (cartas[1]%10)+21;
        }
        else{
            return 20;
        }
    }
    else if(cartas[0]/10 == cartas[2]/10){
        if(cartas[0]%10 < 7 && cartas[2]%10 < 7){
            return (cartas[0]%10)+(cartas[2]%10)+22;
        }
        else if(cartas[0]%10 < 7){
            return (cartas[0]%10)+21;
        }
        else if(cartas[2]%10 < 7){
            return (cartas[2]%10)+21;
        }
        else{
            return 20;
        }
    }
    else if(cartas[2]/10 == cartas[1]/10){
        if(cartas[2]%10 < 7 && cartas[1]%10 < 7){
            return (cartas[2]%10)+(cartas[1]%10)+22;
        }
        else if(cartas[2]%10 < 7){
            return (cartas[2]%10)+21;
        }
        else if(cartas[1]%10 < 7){
            return (cartas[1]%10)+21;
        }
        else{
            return 20;
        }
    }
    else{
        int mayor = 0;
        if(cartas[0]%10 < 7){
            mayor = (cartas[0]%10)+1;
            if(cartas[1]%10 < 7){
                if(mayor < (cartas[1]%10)+1){
                    mayor=(cartas[1]%10)+1;
                }
            }
            if(cartas[2]%10 < 7){
                if(mayor < (cartas[2]%10)+1){
                    mayor=(cartas[2]%10)+1;
                }
            }
        }
        else if(cartas[1]%10 < 7){
                mayor=(cartas[1]%10)+1;
            if(cartas[2]%10 < 7){
                if(mayor < (cartas[2]%10)+1){
                    mayor=(cartas[2]%10)+1;
                }
            }
        }
        else if(cartas[2]%10 < 7){
            mayor=(cartas[2]%10)+1;
        }
        return mayor;
    }
}

/*
Calcula el valor de una carta del jugador
*/
int calcularValor(int carta){

    if(carta%10 == 3){
        return 0;
    }
    else if(carta%10 == 4){
        return 1;
    }
    else if(carta%10 == 5){
        return 2;
    }
    else if(carta%10 == 6 && (carta/10 == 2 || carta/10 == 1)){
        return 3;
    }
    else if(carta%10 == 7){
        return 4;
    }
    else if(carta%10 == 8){
        return 5;
    }
    else if(carta%10 == 9){
        return 6;
    }
    else if(carta%10 == 0 && (carta/10 == 0 || carta/10 == 1)){
        return 7;
    }
    else if(carta%10 == 1){
        return 8;
    }
    else if(carta%10 == 2){
        return 9;
    }
    else if(carta%10 == 6 && carta/10 == 0){
        return 10;
    }
    else if(carta%10 == 6 && carta/10 == 3){
        return 11;
    }
    else if(carta%10 == 0 && carta/10 == 2){
        return 12;
    }
    else if(carta%10 == 0 && carta/10 == 3){
        return 13;
    }
    return 0;
}


/*
Devuelve 1 si ha ganado el jugador, devuelve 0 si gano la computadora
 */
int definirGanadorMano(int cartaPC, int cartaJugador){
	if(calcularValor(cartaPC) > calcularValor(cartaJugador)){
		printf("El oponente se ha llevado la mano\n\n");
		rgpc++;
		return 0;
	}
	else{
		printf("Te haz llevado la mano\n\n");
		rgj++;
		return 1;
	}
}


/*
Crea una baraja de donde se verifica si ya fue sacada por un jugador
cuando se reparten
*/
void inicializarBaraja() {
    for (int i = 0; i < 40; i++) {
        baraja[i] = 0;
    }
}

/*
Recibe la cantidad de jugadores del main, así tambien una matriz
que contiene la mano de todos los jugadores.

Así tambien "reparte" las cartas a cada jugador en su vector correspondiente
*/
void repartirCartas(int jugadores, int cartas[][3]) {
    for (int j = 0; j < jugadores; j++) {
        for (int n = 0; n < 3; n++) {
            int palo, numero, carta;
            do {
                palo = rand() % 4; // los palos van del 0 al 3, siendo los indeces del vector Palos
                numero = rand() % 10; //los numeros val del 0 al 9. siendo estos los indeces del vector Numeros
                carta = (palo * 10) + numero; //representación de los numeros:
                        // decena es el indice del vector palos y la unidad el indice del vector numeros
            } while (baraja[carta] == 1); //verifica que la carta está en el maso para repetir lo anterior
            baraja[carta] = 1;
            cartas[j][n] = carta;
            mano1[j][n] = 1;
        }
    }
}

/*
Funcion que devuelve el numero que le corresponde al indice que recibe del vector numeros
*/
int numeroValido(int i) {
    return numeros[i];
}

/*
Imprime un mensaje señalando el jugador y cuales son las cartas en su mano
*/
void notificarCartas(int jugador, int *cartas) {
    printf("Jugador %d:\n", jugador + 1);
    for (int i = 0; i < 3; i++) {
        int palo = cartas[i] / 10; //saca indice del vector palo
        int numero = cartas[i] % 10; //saca el indice del vector numero
        if(mano1[jugador][i]){
            printf("  Carta %d: %d de %s. Vale %d\n", i + 1, numeroValido(numero), palos[palo], calcularValor(cartas[i]));
        }
    }
}

///*
//
// */
//int jugarPC(){
//
//}

/*
El jugador baja una carta
 */
int bajarCarta(int cartas[][3]){
	int op = 0;
	char c;
	notificarCartas(0, cartas[0]);
	int valorEnMesa = 0;
	do{
		printf("Elija una carta valida para bajar: ");
		scanf("%d", &op);
		while((c=getchar())!='\n' && c!=EOF);
	} while (op < 1 || op > 3 || !mano1[0][op-1]);
	mano1[0][op-1] = 0;
	valorEnMesa = calcularValor(cartas[0][op-1]);
	printf("Tiraste el %d de %s\n", numeros[cartas[0][op-1]%10], palos[cartas[0][op-1]/10]);
	return(valorEnMesa);
}
/*
El jugador baja una carta
 */
int bajarCartaPC(int cartas[][3]){
	int valorEnMesa = 0;
	static int op = 0;
	valorEnMesa = calcularValor(cartas[1][op]);
	mano1[1][op] = 0;
	op++;
	if(op==3){
		op = 0;
	}
	printf("El oponente tiro el %d de %s\n", numeros[cartas[1][op-1]%10], palos[cartas[1][op-1]/10]);
	return(valorEnMesa);
}

/*
respuestas de la maquina al envido cantado por el jugador
 */
int respuestaEnvido(int eleccion, int cartas[][3]){
	int opcion = 0;
	char c;
	if(eleccion == 1){ // envido
		if(rand()%2){
			printf("El oponente ha aceptado el Envido\n");
			if(calcularEnvido(cartas[0]) > calcularEnvido(cartas[1])){
				printf("Ganas el Envido, te llevas 2 punto\n");
				PJ += 2;
				printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
			}
			else{
				printf("El oponente gana el Envido, se lleva 2 punto por tener %d\n", calcularEnvido(cartas[1]));
				PM += 2;
				printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
			}
		}
		else{
			printf("El oponente se ha negado al Envido y te lleva 1 punto\n");
			PJ += 1;
			printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
		}
	}
	else if(eleccion == 2){ // real envido
		if(rand()%2){
			printf("El oponente ha aceptado el Real Envido\n");
			if(calcularEnvido(cartas[0]) > calcularEnvido(cartas[1])){
				printf("Ganas el Envido, te llevas 3 punto\n");
				PJ += 3;
				printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
			}
			else{
				printf("El oponente gana el Real Envido, se lleva 3 punto por tener %d\n", calcularEnvido(cartas[1]));
				PM += 3;
				printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
			}
		}
		else{
			printf("El oponente se ha negado al Real Envido y te lleva 1 punto\n");
			PJ += 1;
			printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
		}
	}
	else if(eleccion == 3){ // falta envido
		if(rand()%2){
			printf("El oponente ha aceptado el Falta Envido\n");
			int faltaEnvido = 0;
			if(PM > 15 && PJ > 15){
				faltaEnvido = 30 - PM;
				if(30-PJ < faltaEnvido){
					faltaEnvido = 30-PJ;
				}
			}
			else if(PM < 15){
				faltaEnvido = 30 - PM;
				if(15-PJ < faltaEnvido){
					faltaEnvido = 15-PJ;
				}
			}
			else if(PJ > 15){
				faltaEnvido = 30 - PJ;
				if(15-PM < faltaEnvido){
					faltaEnvido = 15-PM;
				}
			}
			else{
				if(PJ > PM){
					faltaEnvido = 15 - PJ;
				}
				else if(PJ < PM){
					faltaEnvido = 15 - PM;
				}
				else{
					faltaEnvido = 15 - PM;
				}

			}
			if(calcularEnvido(cartas[0]) > calcularEnvido(cartas[1])){
				printf("Ganas el Falta Envido, te llevas %d puntos\n", faltaEnvido);
				PJ += faltaEnvido;
				printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
			}
			else{
				printf("El oponente gana el Falta Envido, se lleva %d punto por tener %d\n",faltaEnvido,  calcularEnvido(cartas[1]));
				PM += faltaEnvido;
				printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
			}

		}
		else{
			printf("El oponente se ha negado al Falta Envido y te llevas 1 punto\n");
			PJ += 1;
			printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
		}
	}
	do {
		printf("Que desea hacer? Ingrese el numero que corresponda\n");
		printf("1) Cantar Truco (jugar por dos puntos)\n");
		printf("2) Bajar una carta\n");
		printf("3) Irse al mazo\n");
		scanf("%d", &opcion);
		while((c=getchar())!='\n' && c!=EOF);
	} while (opcion < 1 || opcion > 3);
	if(opcion == 2){
		return 5;
	}
	else if(opcion == 3){
		return 6;
	}
	else{
		return opcion;
	}
}


/*
Funcion que controla la primera mano del jugador
 */
int juegaJugadorMano1(int cartas[][3]){
	int opcion = 0;
	int cartaPC, cartaJugador;
	char c;
	notificarCartas(0, cartas[0]);
	printf("        --------Ronda Nueva--------\n");
	printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
	do {
		printf("Que desea hacer? Ingrese el numero que corresponda\n");
		printf("1) Cantar Truco (jugar por dos puntos)\n");
		printf("2) Cantar Envido (tienes %i tantos)\n", calcularEnvido(cartas[0]));
		printf("3) Cantar Real Envido (tienes %i tantos)\n", calcularEnvido(cartas[0]));
		printf("4) Cantar Falta Envido (tienes %i tantos)\n", calcularEnvido(cartas[0]));
		printf("5) Bajar una carta\n");
		printf("6) Irse al mazo\n");
		scanf("%d", &opcion);
		while((c=getchar())!='\n' && c!=EOF);
	} while (opcion < 1 || opcion > 6);
	if(opcion == 2){
		opcion = respuestaEnvido(1, cartas);
	}
	else if(opcion == 3){
		opcion = respuestaEnvido(2, cartas);
	}
	else if(opcion == 4){
		opcion = respuestaEnvido(3, cartas);
	}
	if(opcion == 1){
		trucoCantado = 1;
		cartaJugador = bajarCarta(cartas);
		cartaPC = bajarCartaPC(cartas);
		definirGanadorMano(cartaPC, cartaJugador);
		return 1;
	}
	else if(opcion == 5){
		cartaJugador = bajarCarta(cartas);
		cartaPC = bajarCartaPC(cartas);
		definirGanadorMano(cartaPC, cartaJugador);
		return 1;
	}
	else{
		printf("Acabas de regalar al rival dos puntos\n");
		PM += 2;
		return 0;
	}
}

/*
Funcion que controla la segunda mano del jugador
 */
int juegaJugadorMano2(int cartas[][3]){
	int opcion = 0;
	int cartaPC, cartaJugador;
	char c;
	notificarCartas(0, cartas[0]);
	printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
	do {
		printf("Que desea hacer? Ingrese el numero que corresponda\n");
		if(!trucoCantado){
			printf("1) Cantar Truco (jugar por dos puntos)\n");
		}
		printf("2) Bajar una carta\n");
		printf("3) Irse al mazo\n");
		scanf("%d", &opcion);
		while((c=getchar())!='\n' && c!=EOF);
	} while (opcion < 1 || opcion > 3 || trucoCantado == opcion);

	if(opcion == 1){
		trucoCantado = 1;
		cartaJugador = bajarCarta(cartas);
		cartaPC = bajarCartaPC(cartas);
		definirGanadorMano(cartaPC, cartaJugador);
		return 1;
	}
	else if(opcion == 2){
		cartaJugador = bajarCarta(cartas);
		cartaPC = bajarCartaPC(cartas);
		definirGanadorMano(cartaPC, cartaJugador);
		return 1;
	}
	else{
		if(!trucoCantado){
			printf("Acabas de regalar al rival un punto\n");
			PM += 1;
			return 0;
		}
		else{
			printf("Acabas de regalar al rival dos puntos\n");
			PM += 2;
			return 0;
		}
	}
}

int juegaJugadorMano3(int cartas[][3]){
	int opcion = 0;
	int cartaPC, cartaJugador;
	char c;
	notificarCartas(0, cartas[0]);
	printf("Puntos Maquina: %d          Puntos jugador: %d\n", PM, PJ);
	do {
		printf("Que desea hacer? Ingrese el numero que corresponda\n");
		if(!trucoCantado){
			printf("1) Cantar Truco (jugar por dos puntos)\n");
		}
		printf("2) Bajar una carta\n");
		printf("3) Irse al mazo\n");
		scanf("%d", &opcion);
		while((c=getchar())!='\n' && c!=EOF);
	} while (opcion < 1 || opcion > 3 || trucoCantado == opcion);

	if(opcion == 1){
		trucoCantado = 1;
		cartaJugador = bajarCarta(cartas);
		cartaPC = bajarCartaPC(cartas);
		definirGanadorMano(cartaPC, cartaJugador);
		return 1;
	}
	else if(opcion == 2){
		cartaJugador = bajarCarta(cartas);
		cartaPC = bajarCartaPC(cartas);
		definirGanadorMano(cartaPC, cartaJugador);
		return 1;
	}
	else{
		if(!trucoCantado){
			printf("Acabas de regalar al rival un punto\n");
			PM += 1;
			return 0;
		}
		else{
			printf("Acabas de regalar al rival dos puntos\n");
			PM += 2;
			return 0;
		}
	}
}

int main(void) {
    srand(time(NULL));

	int cartas[2][3] = {0};
	int seguir = 0;
	do{
		trucoCantado = 0;
		rgj = 0;
		rgpc = 0;
		inicializarBaraja();
		repartirCartas(2, cartas);
		seguir = juegaJugadorMano1(cartas);
		if(seguir){
			seguir = juegaJugadorMano2(cartas);
		}
		if(seguir && rgj < 2 && rgpc < 2){
			seguir = juegaJugadorMano3(cartas);
		}
		if(trucoCantado){
			if(rgpc > rgj){
				PM += 2;
			}
			else{
				PJ += 2;
			}
		}
		else{
			if(rgpc > rgj){
				PM += 1;
			}
			else{
				PJ += 1;
			}
		}
	}while(PM < 30 && PJ < 30);
}


//! Luis hdp el 1 de espadas pierde contra el 4 de espadas en el código...

//! Errores observados: Realicé un falta envido y terminé con -4 puntos. El 1 de espadas perdió contra un 4 de espadas (el 1 de espadas es la carta más poderosa).

//? Retocar el código en las vacaciones como un pequeño side project. Solucionar los errores que hay en el código. Agregar las funciones que faltan (flor y demás). Intentar pasar el código a Java luego de realizar el curso de Java de CoderHouse. Intentar agregar una GUI básica en Java una vez portado el código y mejorar la GUI para empezar con el portafolio. 