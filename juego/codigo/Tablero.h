//
//  Tablero.h
//  Juegodelavida
//
//  Created by ITO on 12/14/18.
//  Copyright © 2018 Elahi Giron Cueto. All rights reserved.
//

#ifndef Tablero
#define Tablero

#include <SDL2/SDL.h>
#include "Graficos.h"
#include "Juego.h"


const int TAMAÑO_TABLERO        = 30; /* ALTO Y ANCHO DE LAS CELDAS     */
const int TAMAÑO_VENTANA      = 800; /* alto y ancho de pantalla en pixeles    */
const int TAMAÑO_CELULAS        = TAMAÑO_VENTANA/TAMAÑO_TABLERO; /* tamaño de celulas en pixeles */
int  contar_vecinos_vivos ( int grid[][TAMAÑO_TABLERO], int size, int x, int y );
void actualizar_celula             ( int grid[][TAMAÑO_TABLERO], int size, int x, int y,
                              int num_vecinos );
void set_celula                ( int grid[][TAMAÑO_TABLERO], int size, int x, int y,
                              int val );


/* establece la celula en el tablero en las coordenadas (x, y) al valor pasado como argumento */

void set_celula( int grid[][TAMAÑO_TABLERO], int size, int x, int y, int val ) {
    /* nos aseguramos de que estamos dentro de los límites de la cuadrícula antes de intentar */
    /* acceder a la celda                                                 */
    if ( x >= 0 && x < size && y>=0 && y< size ) {
        /* si X y Y son validas, actualiza el valor de la celula */
        grid[y][x] = val;
    }
}

/* Avanza el juego de la vida por un paso*/
void step( int grid[][TAMAÑO_TABLERO], int size ) {
    int x, y;
    int counts[TAMAÑO_TABLERO][TAMAÑO_TABLERO];
    
    /* el avance debe realizarse en dos pasos: contar los vecinos para */
    /* cada celula, luego actualice el estado de cada celula. Entonces, dos para bucles y */
    /* una matriz 2D adicional          */
    
    /* Cuente los vecinos para cada celda y almacene el conteo. */
    for(y=0; y<size; y++) {
        for(x=0; x<size; x++) {
            counts[y][x] = contar_vecinos_vivos(grid, size, x,y);
        }
    }
    
    /* Actualiza la celula a vivo o muerto dependiendo del número de vecinos */
    for(y=0; y<TAMAÑO_TABLERO; y++) {
        for(x=0; x<TAMAÑO_TABLERO; x++) {
            actualizar_celula(grid, size, x, y, counts[y][x]);
        }
    }
}

#endif


