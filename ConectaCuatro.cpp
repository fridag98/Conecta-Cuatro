//
//  conectacuatro.cpp
//  Prueba
//
//  Created by Frida Gutierrez Mireles A01039975 on 11/5/17.
//  Copyright © 2017 Frida. All rights reserved.
//

#include <iostream>
using namespace std;

//función que verifica si hay un empate. Lee el primer renglón 0 de cada columna para verificar si hay un '-' disponible, en caso de que no, regresa true y se muestra en la pantalla que es un empate.
bool verificarEmpate (char tableroCompleto[7][7]){
    for (int columna= 0; columna <= 6;  columna++){
        if (tableroCompleto[0][columna]== '-'){
            return false;
        }
    }
    return true;
}
//función que verifica si el jugador gana en diagonal izquierda. Va a regresar el signo en el cual se juntaron cuatro de ellos seguidos.
char verificarDiagonalIzquierda(char tableroCompleto[7][7]){
    for ( int i = 0; i <= 6 ; i++) {
        int contadorIguales = 0;
        char ultimoChar = '-';
        for ( int j = 0; j <= 6; j++ ) {
            int columna = j;
            int renglon = j + i;
            if ( renglon > 6 ) break;
            if ( tableroCompleto[renglon][columna] == '-') {
                contadorIguales = 0;
                ultimoChar = '-';
            }
            else {
                if ( tableroCompleto[renglon][columna] != ultimoChar ) {
                    contadorIguales = 1;
                    ultimoChar = tableroCompleto[renglon][columna];
                } else {
                    contadorIguales += 1;
                }
                if ( contadorIguales ==4 ) return ultimoChar;
            }
        }
    }
    for ( int i = 0; i <= 5; i++) {
        int contadorIguales = 0;
        char ultimoChar = '-';
        for ( int j = 0; j <= 5; j++ ) {
            int columna = j + (1+i);
            int renglon = j;
            if ( columna > 6 ) break;
            if ( tableroCompleto[renglon][columna] == '-') {
                contadorIguales = 0;
                ultimoChar = '-';
            }
            else {
                if ( tableroCompleto[renglon][columna] != ultimoChar ) {
                    contadorIguales = 1;
                    ultimoChar = tableroCompleto[renglon][columna];
                } else {
                    contadorIguales += 1;
                }
                if ( contadorIguales ==4 ) return ultimoChar;
            }
        }
    }
    return '-';
}
//función que verifica si el jugador gana en diagonal derecha. Va a regresar el signo en el cual se juntaron cuatro de ellos seguidos.
char verificarDiagonalDerecha(char tableroCompleto[7][7]){
    for ( int i = 0; i <= 6; i++) {
        int contadorIguales = 0;
        char ultimoChar = '-';
        int renglon = i;
        for ( int j = 6; j >= 0; j--) {
            int columna = j;
            if ( tableroCompleto[renglon][columna] == '-') {
                contadorIguales = 0;
                ultimoChar = '-';
            }
            else {
                if ( tableroCompleto[renglon][columna] != ultimoChar ) {
                    contadorIguales = 1;
                    ultimoChar = tableroCompleto[renglon][columna];
                } else {
                    contadorIguales += 1;
                }
                if ( contadorIguales ==4 ) return ultimoChar;
            }
            if ( renglon == 6 )
                break;
            else
                renglon++;
        }
    }
    for ( int i = 0; i <= 5; i++) {
        int contadorIguales = 0;
        char ultimoChar = '-';
        int columna = 5-i;
        for ( int j = 0; j <= 5; j++ ) {
            int renglon = j;
            if ( tableroCompleto[renglon][columna] == '-') {
                contadorIguales = 0;
                ultimoChar = '-';
            }
            else {
                if ( tableroCompleto[renglon][columna] != ultimoChar ) {
                    contadorIguales = 1;
                    ultimoChar = tableroCompleto[renglon][columna];
                } else {
                    contadorIguales += 1;
                }
                if ( contadorIguales ==4 ) return ultimoChar;
            }
        if ( columna == 6 )
            break;
        else
           columna--;
        }
    }
    return '-';
}
//función que verifica si el jugador gana de manera horizontal. Va a regresar el signo en el cual se juntaron cuatro de ellos seguidos.
char verificarRenglones(char tableroCompleto[7][7]){
    for ( int renglon = 6; renglon >= 0; renglon--) {
        int contadorIguales = 0;
        char ultimoChar = '-';
        for ( int columna = 0; columna <7; columna++) {
            if ( tableroCompleto[renglon][columna] == '-') {
                contadorIguales = 0;
                ultimoChar = '-';
            }
            else {
                if ( tableroCompleto[renglon][columna] != ultimoChar ) {
                    contadorIguales = 1;
                    ultimoChar = tableroCompleto[renglon][columna];
                } else {
                    contadorIguales += 1;
                }
                if ( contadorIguales ==4 ) return ultimoChar;
            }
        }
    }
    return '-';
}

//función que verifica si el jugador gana de manera vertical. Va a regresar el signo en el cual se juntaron cuatro de ellos seguidos.
char verificarColumnas(char tableroCompleto[7][7]){
    for ( int columna = 0; columna < 7; columna++) {
        int contadorIguales = 0;
        char ultimoChar = '-';
        for ( int renglon = 6; renglon >=0; renglon--) {
            if ( tableroCompleto[renglon][columna] == '-') {
                contadorIguales = 0;
                ultimoChar = '-';
            }
            else {
                if ( tableroCompleto[renglon][columna] != ultimoChar ) {
                    contadorIguales = 1;
                    ultimoChar = tableroCompleto[renglon][columna];
                } else {
                    contadorIguales += 1;
                }
                if ( contadorIguales ==4 ) return ultimoChar;
            }
        }
    }
    return '-';
}

//función que, de acuerdo al valor de la variable "turnoJugador" que se envió como parametro, insertará na 'X' o un 'O' en la columna que el usuarió pidió. La función busca el renglón más bajo de la columna requerida en la que haya un '-' disponible. En caso de que haya, el signo de '-' se sustituye por una 'X' o un 'O'. Si ya no hay un '-' disponible en esa columna, el programa no muestra ningún cambio en el tablero y sede el turno al siguiente jugador.
void insertarFicha(char tableroCompleto[7][7], int columnaInsertaFicha, int jugador){
    int siguienteRenglon = -1;
    
    for ( int i = 6; i >= 0; i--) {
        if ( tableroCompleto[i][columnaInsertaFicha-1] == '-') {
            siguienteRenglon = i;
            break;
        }
    }
    if ( siguienteRenglon != -1 ) {
        if ( jugador == 1 ) {
            tableroCompleto[siguienteRenglon][columnaInsertaFicha-1] = 'X';
        }
        else {
            tableroCompleto[siguienteRenglon][columnaInsertaFicha-1] = 'O';
        }
    }
}
//función que pregunta al usuario si desea seguir jugando o no. Mientras la respuesta sea diferente de 's' o 'n' se le volverá a preguntar. Cuando el usuaria teclee una 's' o una 'n' la comparará con la 'n'. Si es igual regresa verdadero y si no, regresa falso.
bool teQueiresSalir() {
    char respuesta;
    do {
        cout << "¿Desea seguir jugando? (s/n)" << endl;
        cin >> respuesta;
    } while ( tolower(respuesta) != 's' && tolower(respuesta) != 'n');
    return tolower(respuesta) == 'n';
}

//función que muestra en pantalla de quién es el turno para jugar. Así mismo, pregunta en qué columna el jugador desea insertar ficha. Si el jugador teclea una columna mayor que 7 o menor que 1, se le volverá a preguntar.
int capturarEnColumna(int jugador) {
    int columnaAInsertar;
    cout << endl << "Es turno del jugador" <<  " " << jugador << endl;
    do {
        cout << "¿En qué columna deseas insertar ficha?" << endl;
        cin >> columnaAInsertar;
    } while (columnaAInsertar > 7 || columnaAInsertar < 1);
    return columnaAInsertar;
}

//función que alterna al jugador.
int siguienteJugador(int jugador) {
    if ( jugador == 1) {
        return 2;
    }
    else {
        return 1;
    }
}

//función que pinta el tablero en la pantalla. Se llama cada vez que el jugador inserte una ficha para que se muestre en pantalla el tablero con sus nuevos valores.
void pintarTablero(char tableroCompleto[7][7]) {
    int renglon, columna;
    renglon=7, columna=7;
    cout << "   ";
    for (int c=0; c < renglon; c++){
        cout << (c+1) << "  ";
    }
    cout << endl;
    for (int c=0; c < renglon; c++){
        cout << (c+1) << " ";
        for(int i=0; i < columna; i++){
            cout << " " << tableroCompleto[c][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int renglon, columna, turnoJugador, columnaParaInsertarFicha;
    char signoInicial, tablero[7][7];
    bool hayQueSalir;
    
    renglon=7, columna=7, signoInicial= '-';
    for (int c=0; c < renglon; c++){
        for(int i=0; i < columna; i++){
            tablero[c][i]= signoInicial;
        }
    }
    
    //antes de que comience el juego, se llama a la función "pintarTablero" para que aparezca en pantalla el tablero con los signos iniciales: '-'.
    pintarTablero(tablero);
    turnoJugador=1;
    
    do {
        //llamar a la función "capturarEnColumna para saber en qué columna el jugador desea insertar su ficha.
        columnaParaInsertarFicha = capturarEnColumna(turnoJugador);
        
        //insertar la ficha en el renglón más bajo de la columna que el jugador estableció.
        insertarFicha(tablero, columnaParaInsertarFicha, turnoJugador);
        
        //cada vez que se inserte una ficha, se llamará a la función "pintarTablero" para que aparezca en pantalla con los nuevos valores que tomaron los renglones y columnas del tablero.
        pintarTablero(tablero);
        
        char ganador;
        ganador = verificarColumnas(tablero);
        if ( ganador != '-' ){
            if (ganador== 'X')
                turnoJugador = 1;
            else turnoJugador = 2;
            cout << "Ganó el jugador " << turnoJugador << endl;
            return 0;
        }
        else {
            ganador = verificarRenglones(tablero);
            if ( ganador != '-' ){
                if (ganador== 'X')
                    turnoJugador = 1;
                else turnoJugador = 2;
                cout << "Ganó el jugador " << turnoJugador << endl;
                return 0;
            }
            else {
                ganador = verificarDiagonalIzquierda(tablero);
                if ( ganador != '-' ){
                    if (ganador== 'X')
                        turnoJugador = 1;
                    else turnoJugador = 2;
                    cout << "Ganó el jugador " << turnoJugador << endl;
                    return 0;
                }
                else {
                    ganador = verificarDiagonalDerecha(tablero);
                    if ( ganador != '-' ){
                        if (ganador== 'X')
                            turnoJugador = 1;
                        else turnoJugador = 2;
                        cout << "Ganó el jugador " << turnoJugador << endl;
                        return 0;
                    }
                }
            }
        }
        
        //si la función regresa un valor de true, el juego termina y se muestra el letrero de empate.
        if (verificarEmpate(tablero)){
            cout << "Es un empate" << endl;
            return 0;
        }
        
        //llamar a la función "siguienteJugador" para alternar el valor de la variable "turnoJugador".
        turnoJugador = siguienteJugador(turnoJugador);
        
        hayQueSalir = teQueiresSalir();
        
        //si la variable "hayQueSalir" es falsa, es decir que en la función "teQuieresSalir" el usuario tecleó una 's' en lugar de una 'n', la condición de while la convertirá a verdadera y el juego continuara. Si la función regresa un valor de verdadedo, se convertirá a falso y el juego terminará.
    } while ( ! hayQueSalir);
    
    return 0;
}
