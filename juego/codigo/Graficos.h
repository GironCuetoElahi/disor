//
//  Graficos.h
//  Juegodelavida
//
//  Created by ITO on 12/14/18.
//  Copyright © 2018 Elahi Giron Cueto. All rights reserved.
//

#ifndef Graficos
#define Graficos

#include <SDL2/SDL.h>
#include "Juego.h"
#include "Tablero.h"
#include "Regla.h"




SDL_Renderer *g_renderer = NULL; /* dibujar la pantalla*/
SDL_Window   *g_window   = NULL; /* la pantalla nos la da el SISTEMA OPERATIVO*/

bool g_animating = false; /* controla si la simulación está animando o no */
bool g_user_quit = false; /* nos dice cuando el usuario termina el juego */


void init_grid               ( int grid[][TAMAÑO_TABLERO], int size );

void step                    ( int grid[][TAMAÑO_TABLERO], int size );

bool inicializar_pantalla     ( );
void mostrar_tablero           ( int grid[][TAMAÑO_TABLERO], int size );
void manejar_eventos           ( int grid[][TAMAÑO_TABLERO], int size );
void cerrar_pantalla       ( );

bool inicializar_pantalla() {
    
    /* Inicializa la libreria que hace todo el trabajo pesado de
     * gráficos */
    if( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "inicializar_pantalla- SDL_Init: %s\n",
                     SDL_GetError()
                     );
        return false;
    }
    
    /* Trata de crear una ventana (donde podemos ver el juego) y renderizarla */
    if( SDL_CreateWindowAndRenderer( TAMAÑO_VENTANA, TAMAÑO_VENTANA, SDL_WINDOW_RESIZABLE,
                                    &g_window, &g_renderer ) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "inicializar_pantalla- SDL_CreateWindowAndRenderer - %s\n",
                     SDL_GetError()
                     );
        return false;
    }
    
    /* Si todo sale bien Return true! */
    return true;
}

void mostrar_tablero( int grid[][TAMAÑO_TABLERO], int size ) {
    
    /* establecer el color a blanco */
    SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    
    /* limpiar la pantalla */
    SDL_RenderClear(g_renderer);
    
    /* establecer el color a negro */
    SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    
    /* dibujar la lineas de fila*/
    for(int i=0; i<size; i++) {
        SDL_RenderDrawLine(g_renderer,
                           
                           0, TAMAÑO_CELULAS*i,          /* x1, y1 */
                           TAMAÑO_VENTANA, TAMAÑO_CELULAS*i /* x2, y2 */
                           );
    }
    
    /* dibujar lineas de columna */
    for(int i=0; i<size; i++) {
        SDL_RenderDrawLine(g_renderer,
                           TAMAÑO_CELULAS*i, 0,           /* x1, y1 */
                           TAMAÑO_CELULAS*i, TAMAÑO_VENTANA  /* x2, y2 */
                           );
    }
    
    /* Set draw colour to blue */
    SDL_SetRenderDrawColor(g_renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    
    /* Render the game of life */
    for( int x=0; x<size; x++ ) {
        for( int y=0; y<size; y++) {
            if(grid[y][x] == CELULA_VIVA ) {
                SDL_Rect r = {
                    x*TAMAÑO_CELULAS, /*   x    */
                    y*TAMAÑO_CELULAS, /*   y    */
                    TAMAÑO_CELULAS,   /* ancho */
                    TAMAÑO_CELULAS    /* alto */
                };
                SDL_RenderFillRect(g_renderer, &r);
            }
        }
    }
    
    /* actualiza la pantalla para que el usuario pueda ver*/
    SDL_RenderPresent(g_renderer);
}

void manejar_eventos( int grid[][TAMAÑO_TABLERO], int size ) {
    SDL_Event event;
    
    /* obtener todos los eventos de la cola de eventos */
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT){
            /* el usuario ha salido del juego*/
            g_user_quit = true;
        }
        else if(event.type == SDL_MOUSEMOTION) {
            /* las células cobren vida o mátalos con el mouse.*/
            if ( event.motion.state & (SDL_BUTTON_LMASK | SDL_BUTTON_RMASK) ) {
                set_celula(
                         grid,
                         size,
                         event.motion.x/TAMAÑO_CELULAS, /* mouse x to grid index */
                         event.motion.y/TAMAÑO_CELULAS, /* mouse y to grid index */
                         (event.motion.state & SDL_BUTTON_LMASK)? /* que boton? */
                         CELULA_VIVA : CELULA_MUERTA);
            }
        }
        else if( event.type == SDL_MOUSEBUTTONDOWN ) {
            /* dar vida a una célula o matarla con un clic del ratón */
            set_celula( grid,
                     size,
                     event.button.x/TAMAÑO_CELULAS, /* mouse x to grid index */
                     event.button.y/TAMAÑO_CELULAS, /* mouse y to grid index */
                     (event.button.button==SDL_BUTTON_LEFT)? /* which button? */
                     CELULA_VIVA : CELULA_MUERTA);
        }
        else if( event.type == SDL_KEYDOWN ) {
            if (event.key.keysym.sym == SDLK_SPACE) {
                /* iniciar/parar animacion con space */
                g_animating = !g_animating;
            } else if (event.key.keysym.sym == SDLK_c ) {
                /* limpiar la pantalla con c. despues, para la animacion*/
                init_grid( grid, size );
                g_animating = false;
            }
        }
    }
}

void cerrar_pantalla() {
    /* Siempre libera recursos cuando hayas terminado */
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
    SDL_Quit();
}


#endif
