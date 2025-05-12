#include <stdio.h> 
#include <SDL2/SDL.h> 
#include <stdbool.h> 
#include <stdlib.h> 
#include "./header/header.h"  

//clang -I/usr/include/SDL2/ -I./headers/header.h src/source.c  main.c -o main -lSDL2 -lSDL2_image

int main(){ 
     system("clear") ;      

     init_and_check() ; 
     create_window("chess" , 100 ,100 , 800 ,800 , SDL_WINDOW_SHOWN ) ; 
     create_renderer()  ;


     init_pieces() ; 
     init_squares() ;  
     main_loop() ; 

     clean_up() ; 


  }  
