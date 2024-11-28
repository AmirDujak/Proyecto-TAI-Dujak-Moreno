Variables globales del programa:
palos: Este array de cadenas de caracteres se utiliza para almacenar los nombres de los cuatro palos de la baraja española: Oro, Copas, Basto y Espadas.

números: Este arreglo de enteros contiene los valores numéricos de las cartas. Los valores 10, 11 y 12 suelen representar el sota, caballo y rey, respectivamente.

baraja: Este arreglo de enteros representa el mazo de cartas. Cada posición del arreglo corresponde a una carta. Por ejemplo, la posición 0 podría representar el 1 de Oro, la posición 10 el 1 de Copas, y así sucesivamente. Al inicializar todas las posiciones con 0, se indica que todas las cartas están disponibles para ser repartidas.

mano1: Este arreglo bidimensional de enteros representa la mano de los jugadores. Cada fila del arreglo representa una mano de tres cartas. Los valores dentro del arreglo indican si la carta se encuentra en la mano del jugador correspondiente, 1 indica que está en la mano, 0 que está en la mesa.

PM, PJ: Estas variables se utilizan para llevar el puntaje del juego. PM representa los puntos de la computadora, y PJ los puntos del jugador.

trucoCantado: Esta variable indica si se ha cantado truco durante la ronda actual. Un valor de 1 significa que se ha cantado truco.

rgpc, rgj: Estas variables se utilizan para contar las rondas ganadas por cada jugador. rgpc cuenta las rondas ganadas por la computadora, y rgj cuenta las rondas ganadas por el jugador.

Funciones:
CalcularEnvido: está diseñada para tomar el valor del envido de una mano de tres cartas y devolver la suma del envido.

CalcularValor: La función determina el valor según el poder de una carta en el juego de Truco, en función de su combinación específica de palo y número.
 
definirGanadorMano: se encarga de retornar el ganador de una mano en el juego de truco, basándose en el valor de las cartas jugadas por el jugador y la computadora. La función devuelve 1 si el jugador gana y 0 si la computadora gana.

inicializarBaraja: tiene como objetivo preparar el mazo de cartas para un nuevo juego de truco. Su principal tarea es establecer un estado inicial en el que todas las cartas estén disponibles para ser repartidas.

numeroValido: Esta función parece diseñada para obtener el valor numérico de una carta a partir de su índice en el arreglo números.

repartirCartas: se encarga de distribuir de manera aleatoria tres cartas a cada jugador, asegurando que ninguna carta se repita.

bajarCarta: simula la acción de un jugador al elegir y descartar una carta de su mano durante la ronda.

bajarCartaPC: Esta función simula la acción de la computadora al jugar una carta durante la ronda.

respuestaEnvido: Esta función simula la respuesta de la computadora a un envido cantado por el jugador.

juegaJugadorMano1, juegaJugadorMano2 y juegaJugadorMano3: Estas funciones controlan el flujo del juego en cada una de las tres manos posibles en una partida de truco. Permiten al jugador realizar diferentes acciones como cantar envido, truco o bajar una carta.

Problemas:
Definición de qué sucede en caso de que exista un empate dentro de la función definirGanadorMano.
Solución: si no gana la computadora, la ronda se le otorga directamente al jugador
Errores en el valor de las cartas, no es común, pero se da la ronda al jugador con la carta baja.
Solución: aún no encontrada.
Errores en el cuento de puntos del envido, una vez otorgado el ganador, no suma correctamente.
Solución: aún no encontrada.

Descripción:
	Inicialmente se planeó como repartir las cartas y qué formato tendrán las cartas, se definió que las cartas sean definidas como números enteros así será más fácil identificarlas para su posterior valoración según las reglas del Truco. Luego vimos como tener en cuenta el repartir las cartas y no repetirlas, creando funciones solo para el control de las cartas, separando de las funciones implementadas para el flujo del juego y reglas en general.
El main es el cerebro del juego, coordinando todas las acciones y controlando el flujo de la partida. Las demás funciones se encargan de tareas más específicas, como manejar las cartas, calcular puntos y gestionar las interacciones con el jugador. Dentro del main está el bucle principal del juego continúa hasta que un jugador alcanza 30 puntos. En cada iteración, se reinician las variables de la partida, se barajan y reparten las cartas, y se juegan las tres manos. La primera mano permite al jugador cantar envido o jugar una carta, y si no se decide la partida, se juegan la segunda y tercera mano. Al final de cada partida, se calculan y suman los puntos.


