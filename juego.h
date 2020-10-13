#define EXITO 0
#define ERROR -1
#define FILAS 20
#define COLUMNAS 80
#define POSICIONES_TOTALES FILAS*COLUMNAS
#define MUERTAS 'M'
#define VIVAS 'V'

/*
 * Pre: Nada
 * Pos: Inicializa el mensaje de entrada y devuelve la cantidad de Celulas Vivas a Insertar
 * */
int mensajeInicializador();

/*
 * Pre: Recibe la cantidad de celulas con vida
 * Pos: Inicializó el tablero de juego
 * */
char** inicializador(int* celulasVivas);

/*
 * Pre: Recibe una matriz de chars (FILAS * COLUMNAS)
 * Pos: Lo llena de 'M' (Celulas Muertas)
 * */
int rellenarTableroDeMuertas(char** tablero);

/*
 * Pre: Recibe una matriz de chars (FILAS * COLUMNAS)  y una cantidad de celulas vivas
 * Pos: Le pide la posicion al usuario e inserta las celulas vivas en dichas posiciones
 * */
int asignarCelulas(char** tablero, int celulasVivas);

/*
 * Pre: Recibe una matriz de chars (FILAS * COLUMNAS)
 * Pos: La imprime por pantalla
 * */
int imprimirTablero(char** tablero);

/*
 * Pre: Recibe una matriz de chars (FILAS * COLUMNAS), una cantidad de celulas vivas, dos strings de los numeros
 * historicos de las muertes y nacimientos de las celulas y el numero de turno
 * Pos: Imprime la matriz, la cantidad de celulas vivas, la cantidad de celulas que nacieron y murieron en ese turno,
 * el promedio de nacimientos y muertes a lo largo del juego y si el juego se congelo (No hay movimiento en 2 turnos)
 * */
int siguienteTurno(char** campo, int* celulasVivas, int* cantidadDeNacimientosCadaTurno, int* cantidadDeMuertesCadaTurno, int turno);

/*
 * Pre: Recibe una matriz de chars (FILAS * COLUMNAS), una cantidad de celulas vivas, un puntero a una direccion de
 * memoria que guarda los nacimientos y otro a las muertes (En ese turno).
 * Pos: Actualiza el tablero. Si la celula viva no tiene 2 o 3 celulas vivas al lado se muere. Si la celula muerta tiene
 * 3 celulas vivas al lado revive.
 * */
int actualizarTablero(char** campo, int* celulasVivas, int* nacimientos, int* muertes);