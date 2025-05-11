#ifndef HEADER
#define HEADER 
#include <SDL2/SDL.h> 

extern bool is_loop_running  ; 
extern SDL_Window * std_window ;
extern SDL_Renderer * std_render ; 

void create_window(const char *,int, int , int,int ,SDL_WindowFlags  ) ; 
void create_renderer() ;
void clean_up() ; 
void init_and_check() ;  

void handle_input() ; 
void main_loop() ; 
void render_settings( int  ,int   ,int  ) ; 
#endif 
