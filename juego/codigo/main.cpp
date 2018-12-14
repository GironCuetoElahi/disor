//
//  main.cpp
//  Juegodelavida
//
//  Created by ITO on 12/14/18.
//  Copyright © 2018 Elahi Giron Cueto. All rights reserved.
//


#include <iostream>
#include <SDL2/SDL.h>
#include "Graficos.h"

using namespace std;




const int ANIMATION_RATE   = 220; /* ACTUALIZAR animacion cada 220 millisegundos  */



int main() {
    Uint32 ticks;
    
    /* el tablero del juego*/
    int grid[TAMAÑO_TABLERO][TAMAÑO_TABLERO];
    
    /* Crea la ventana y lo renderiza. mata el programa si hay
     * fallo*/
    if(!inicializar_pantalla()) {
        return 1;
    }
    
    /* establece que cada celda de la cuadrícula esté muerta*/
    init_grid( grid, TAMAÑO_TABLERO );
    
    
    /*realizar un seguimiento del tiempo transcurrido para que podamos representar la animación a una
     * framerate sensible*/
    ticks = SDL_GetTicks();
    
    /* adelantar la simulación hasta que el usuario decida abandonar */
    while(!g_user_quit) {
        /* eventos: boton, movimiento del mouse, etc */
        manejar_eventos( grid, TAMAÑO_TABLERO );
        
        /* dibuja el juego en la pantalla */
        mostrar_tablero( grid, TAMAÑO_TABLERO );
        
        /* avanzar el juego si es apropiado */
        if(g_animating && (SDL_GetTicks() - ticks) > ANIMATION_RATE ) {
            step( grid, TAMAÑO_TABLERO );
            ticks = SDL_GetTicks();
        }
        
    }
    
    /* Limpiar pantalla cuando se termine*/
    cerrar_pantalla();
    return 0;
}




