#include <stdio.h> 
#include <SDL2/SDL.h> 
#include <stdbool.h> 
#include "../header/header.h" 

SDL_Window * std_window = 0 ; 
SDL_Renderer * std_render = 0 ; 

bool is_loop_running = true ; 
 
void init_and_check( ){ 
    
    if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) >= 0 )  
        printf("\n\ninitializition was successfull\n\n") ; 
    else 
        printf("\n\nproblem with iniatializing\n\n") ; 

} 


void create_window(const char * title ,int  w_start , int h_start , 
                   int hight ,int  wight ,
                    SDL_WindowFlags flag ){  

        if( std_window == 0) { 

            std_window = SDL_CreateWindow(title , w_start ,h_start , hight , wight ,flag ) ;  
            printf("\n\nwindow created\n\n") ; 

        }else 

             printf("\n\nwindow was already initialized\n\n")  ;  

}

void create_renderer(){

        if( std_window == 0 ) 

             printf("\n\ncan't create renderer without window\n\n") ; 

        else if ( std_render == 0 ) {  
             
            std_render = SDL_CreateRenderer(std_window , -1  , 0 ) ; 
            printf("\n\nrenderer was created\n\n") ; 
        } 

        else 
             printf("\n\nrenderer was already created\n\n") ; 
         
}

void clean_up(){ 

        SDL_DestroyWindow(std_window) ; 
        SDL_DestroyRenderer(std_render) ; 
        SDL_Quit() ; 


       
}   


void handle_input(){ 
       
      SDL_Event event ; 

      while ( SDL_PollEvent(&event)){  

           switch( event.type) { 

             case SDL_QUIT: 

                 is_loop_running = false ; 

                 break ;

             default : 

                 break ;

           } 

      } 

   } 


void main_loop(){ 

      while( is_loop_running ){ 
           handle_input() ; 
           render_settings( 255  , 255  , 255 ) ; 

        }  

  } 


void render_settings(int r  , int g  , int b  ){ 

    SDL_SetRenderDrawColor( std_render ,  r , g , b ,255) ; 
       
    SDL_RenderClear( std_render) ; 

    SDL_RenderPresent( std_render) ; 
} 
