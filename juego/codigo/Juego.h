//
//  Juego.h
//  Juegodelavida
//
//  Created by ITO on 12/14/18.
//  Copyright © 2018 Elahi Giron Cueto. All rights reserved.
//

#ifndef Juego
#define Juego

#include <SDL2/SDL.h>
#include "Graficos.h"
#include "Regla.h"
#include "Tablero.h"

const int CELULA_VIVA        = 1;  /* VALOR NUMERICO DE LA CELULA VIVA       */
const int CELULA_MUERTA       = 0;  /* VALOR NUMERICO DE LA CELULA MUERTA     */




/* Inicializa la cuadrícula para que todas las celdas estén muertas */
void init_grid( int grid[][TAMAÑO_TABLERO], int size ) {
    int x,y;
    
    /* itera todo el tablero y lo inicializa */
    for( y=0; y<size; y++ ) {
        for( x=0; x<size; x++ ) {
            grid[y][x] = CELULA_MUERTA;
        }
    }
}

/* cuenta el numero de vecinos vivos alrededor de las celulas (x,y) */
int contar_vecinos_vivos( int grid[][TAMAÑO_TABLERO], int size, int x, int y ) {
    int i,j;
    int count;
    
    /* cuenta el numero de vecinos vivos */
    count = 0;
    for(i=y-1; i<=y+1; i++) {
        for(j=x-1; j<=x+1; j++) {
            /* Aesegurarrnos de salirnos de los limietes */
            if( i >= 0 && j >= 0 && i < size && j < size) {
                /* Si la celula está viva, entonces la agregamos */
                if( grid[i][j] == CELULA_VIVA ) {
                    count++;
                }
            }
        }
    }
    
    /* nuestro bucle cuenta las celulas en el centro del vecindario. lo eliminamos del count*/
    if( grid[y][x] != CELULA_MUERTA) {
        count--;
    }
    
    return count;
}

/* actualiza el estado de una celula a viva o muerta dependiendo del numero de vecinos que tiene*/
void actualizar_celula(int grid[][TAMAÑO_TABLERO], int size, int x, int y,
                 int num_vecinos) {
    if( num_vecinos == NUM_REPRODUCCION ) {
        /* cobran vida debido a la reproduccion*/
        grid[y][x] = CELULA_VIVA;
    } else if (num_vecinos > NUM_SOBREPOBLACION
               || num_vecinos < NUM_SOLEDAD) {
        /* mueron debido a la sobrepoblacion/soledad*/
        grid[y][x] = CELULA_MUERTA;
    }
}

#endif
