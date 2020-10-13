#include <iostream>
#include "juego.h"
#define SIGASIGA 's'
#define SIGA 'S'
#define REINICIAR 'r'
#define REINICIO 'R'
#define TERMINAR 't'
#define TERMINADO 'T'
#define AYUDA 'h'
#define HELP 'H'
using namespace std;

int main(){
    int* celulasVivas   = new int;
    *celulasVivas   =   mensajeInicializador();
    char** campoDeJuego;
    campoDeJuego  =   inicializador(celulasVivas);

    bool ejecucion  =   true;
    char comando;
    int turno  =   0;
    int* cantidadDeNacimientosCadaTurno   =   new int[100];
    int* cantidadDeMuertesCadaTurno   =   new int[100];

    while(ejecucion){
        cin >> comando;
        if(comando  ==  SIGASIGA    ||  comando ==  SIGA){
            siguienteTurno(campoDeJuego, celulasVivas, cantidadDeNacimientosCadaTurno, cantidadDeMuertesCadaTurno, turno);
            turno++;
        }
        else if(comando ==  REINICIAR   ||  comando ==  REINICIO){
            *celulasVivas   =   mensajeInicializador();
            campoDeJuego      =   inicializador(celulasVivas);
            *cantidadDeMuertesCadaTurno  =   0;
            *cantidadDeMuertesCadaTurno  =   0;
            turno   =   0;
        }
        else if(comando ==  TERMINAR    ||  comando ==  TERMINADO){
            ejecucion   = false;
        }
        else if(comando ==  AYUDA   ||  comando ==  HELP){
            cout << "Podes mandar S para seguir, R para reiniciar y T para terminar" << endl;
        }
        else{
            cout << "Solo podes mandar S para seguir, R para reiniciar y T para terminar" << endl;
        }
    }
    for(int i=0; i<FILAS; i++){
        delete campoDeJuego[i];
    }
    delete campoDeJuego;
    cout << "Juego terminado!";
    return 0;
}
