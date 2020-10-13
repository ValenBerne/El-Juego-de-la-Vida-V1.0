#include <iostream>
#include "juego.h"
using namespace std;

int mensajeInicializador(){
    cout << "Bienvenido Jugador!" << endl;
    cout << "Cuantos casilleros queres vivos? (Podes elegir entre 0 y 1600)" << endl;
    int cantidadDeVivos;
    cin >> cantidadDeVivos;
    cout << endl;
    return cantidadDeVivos;
}

char** inicializador(int* celulasVivas){
    char** tablero    =   new char*[FILAS];
    for(int i=0; i<FILAS; i++) tablero[i]    =   new char[COLUMNAS];

    asignarCelulas(tablero, *celulasVivas);

    imprimirTablero(tablero);

    cout << endl << "Ahora que queres hacer? (Presiona H para ayuda)" << endl;

    return tablero;
}

int rellenarTableroDeMuertas(char** tablero){
    for(int i=0; i<FILAS; i++){
        for(int j=0; j<COLUMNAS; j++){
            tablero[i][j]   =   MUERTAS;
        }
    }
    return EXITO;
}

int asignarCelulas(char** tablero, int celulasVivas){

    rellenarTableroDeMuertas(tablero);

    int celulasInsertadas =   0;
    int latitud             =   0;
    int longitud            =   0;
    while(celulasInsertadas   <   celulasVivas){
        cout    <<  "En que fila queres insertar la proxima celula?"    <<  endl;
        cin     >>  latitud;
        while(latitud   <   0   ||  latitud >   FILAS){
            cout    <<  "Hay un maximo de " <<  FILAS   <<  " filas, elegí otro numero (Y un minimo de 1)"   <<  endl;
            cin     >>  latitud;
        }
        cout    <<  "En que columna queres insertar la proxima celula?" <<  endl;
        cin     >>  longitud;
        while(longitud   <   0   ||  longitud >   COLUMNAS){
            cout    <<  "Hay un maximo de " <<  COLUMNAS   <<  " columnas, elegí otro numero (Y un minimo de 1)"   <<  endl;
            cin     >>  longitud;
        }

        if(tablero[latitud-1][longitud-1]   ==  VIVAS){
            cout    <<  "En esa posición ya hay una celula viva, elegí otra"    <<  endl;
        }
        else{
            cout    <<  "(" <<  latitud <<  ")("    <<  longitud    <<  ") Vamos a insertar esta celula"    <<  endl;
            tablero[latitud-1][longitud-1]   =  VIVAS;
            celulasInsertadas++;
        }
    }

    return EXITO;
}

int imprimirTablero(char** tablero){
    for(int i=0; i<FILAS; i++){
        for(int j=0; j<COLUMNAS; j++){
            cout << tablero[i][j];
        }
        cout << endl;
    }
    return EXITO;
}

int siguienteTurno(char** campo, int* celulasVivas, int* cantidadDeNacimientosCadaTurno, int* cantidadDeMuertesCadaTurno, int turno){
    int* nacimientosEsteTurno  =   new int;
    int* muertesEsteTurno      =   new int;

    actualizarTablero(campo, celulasVivas, nacimientosEsteTurno, muertesEsteTurno);

    cantidadDeNacimientosCadaTurno[turno]   =   *nacimientosEsteTurno;
    cantidadDeMuertesCadaTurno[turno]       =   *muertesEsteTurno;

    int promedioNacimientosPorTurno         =   0;
    int promedioMuertesPorTurno         =   0;
    turno++;
    for(int i=0; i<=turno; i++){
        promedioNacimientosPorTurno =   promedioNacimientosPorTurno + cantidadDeNacimientosCadaTurno[i];
        promedioMuertesPorTurno     =   promedioMuertesPorTurno     + cantidadDeMuertesCadaTurno[i];
    }
    promedioNacimientosPorTurno =   promedioNacimientosPorTurno/turno;
    promedioMuertesPorTurno     =   promedioMuertesPorTurno/turno;

    imprimirTablero(campo);
    cout    << endl;
    cout    << "Cantidad de celulas vivas: "            << *celulasVivas                       << endl;
    cout    << "Nacimientos: "                          << *nacimientosEsteTurno              << endl;
    cout    << "Muertes: "                              << *muertesEsteTurno                  << endl;
    cout    << "Promedio de nacimientos por turno: "    << promedioNacimientosPorTurno       << endl;
    cout    << "Promedio de muertes por turno: "        << promedioMuertesPorTurno           << endl;

    if(*nacimientosEsteTurno   ==  0   &&  *muertesEsteTurno  ==  0 &&  turno >= 2){
        if(cantidadDeNacimientosCadaTurno[turno-2]  ==  0   &&  cantidadDeMuertesCadaTurno[turno-2] ==  0){
            cout    <<  "El campo se congelo -> No sufrio moodificaciones en dos turnos"    <<  endl;
        }
        else{
            cout    << "El juego no esta congelado -> Se modifico este turno o el anterior" <<  endl;
        }
    }
    else{
        cout << "No hubo los suficientes turnos para analizar si el juego esta congelado" << endl;
    }

    cout    << "Que queres hacer?"   << endl;

    delete nacimientosEsteTurno;
    delete muertesEsteTurno;

    return EXITO;
}

int actualizarTablero(char** campo, int* celulasVivas, int* nacimientos, int* muertes){
    int vivas_cerca =   0;
    *nacimientos     =   0;
    *muertes         =   0;

    char** tablero    =   new char*[FILAS];
    for(int i=0; i<FILAS; i++){
        tablero[i]    =   new char[COLUMNAS];
    }

    for(int i=0; i<FILAS; i++){
        for(int j=0; j<COLUMNAS; j++){
            if(i-1>=0){
                if(j-1>=0){
                    if(campo[i-1][j-1]  ==  VIVAS){
                        vivas_cerca++;
                    }
                }
                if(campo[i-1][j]  ==  VIVAS){
                    vivas_cerca++;
                }
                if(j+1<=COLUMNAS){
                    if(campo[i-1][j+1]  ==  VIVAS){
                        vivas_cerca++;
                    }
                }
            }
            if(j-1  >=  0){
                if(campo[i][j-1]    ==  VIVAS){
                    vivas_cerca++;
                }
            }
            if(j+1  <  COLUMNAS){
                if(campo[i][j+1]    ==  VIVAS){
                    vivas_cerca++;
                }
            }
            if(i+1  <  FILAS){
                if(j-1>=0){
                    if(campo[i+1][j-1]  ==  VIVAS){
                        vivas_cerca++;
                    }
                }
                if(campo[i+1][j]  ==  VIVAS){
                    vivas_cerca++;
                }
                if(j+1<=COLUMNAS){
                    if(campo[i+1][j+1]  ==  VIVAS){
                        vivas_cerca++;
                    }
                }
            }

            if(campo[i][j]  ==  VIVAS   &&  vivas_cerca  !=  2   &&  vivas_cerca !=  3){
                tablero[i][j] =   MUERTAS;
                *muertes    =   *muertes    +   1;
            }
            else if(campo[i][j]  ==  MUERTAS   &&  vivas_cerca  ==  3){
                tablero[i][j] =   VIVAS;
                *nacimientos    =   *nacimientos    +   1;
            }
            vivas_cerca =   0;
        }
    }

    for(int i=0; i<FILAS; i++){
        for(int j=0; j<COLUMNAS; j++){
            if(tablero[i][j]    ==  MUERTAS) {
                campo[i][j] = MUERTAS;
            }
            else if(tablero[i][j]    ==  VIVAS){
                campo[i][j]    =   VIVAS;
            }
        }
    }

    for(int i=0; i<FILAS; i++){
        delete[] tablero[i];
    }
    delete[] tablero;

    *celulasVivas   =   *celulasVivas   +   *nacimientos -   *muertes;
    return EXITO;
}

















