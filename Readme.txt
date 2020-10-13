1)¿Que es Debug?

Debuguear es el acto de buscar el error en el codigo. 
Puede ser un error en el codigo (Algo mal escrito) o de funcionalidad (No funciona como yo quiero que funcione).
Para debugguear lo mejor es usar el debugguer, aunque a muchos le gusta el metodo de llenado de printf's.

2)¿Que es breakpoints?

Son puntos en los que le marcamos al programa que frene. Para poder ver que valores tienen nuestras variables,
en ese momento.

3)¿Qué es "Step into", "Step Over" y "Step Out"?

Step into: Frenarse en un breakpoint y ver la siguiente linea para saber que esta pasando.
Step Over: Frenarse en un breakpoint y ver la linea actual para saber que esta pasando.
Step Out:  Salirse del breakpoint para que el programa se siga ejecutando.

Manual de usuario:
Le decis cuantas celulas vivas queres (Entre 0 y 1600).
Le decis en que posiciones queres cada celula viva, entre 0 y 20 para las filas y entre 0 y 80 para las columnas.
Después con H te muestra que podes hacer, con R reinicias el programa, con T lo terminas y con S sigue.

Manual de programador:
En el .h esta definida cada funcion del "juego.cpp".
En el main se crean las variables necesarias, manda a inicializar el juego y se corre.

Informe del trabajo realizado:
En el main mando a inicializar el juego y después corro el loop de ejecución.
Mientras que en el "juego.cpp", lo inicializo, imprimo el tablero, paso al siguiente turno y hago lo necesario para que
siga corriendo el tablero.