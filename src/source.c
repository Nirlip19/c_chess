#include <stdio.h> 
#include <math.h> 
#include <SDL2/SDL.h> 
#include <stdbool.h> 
#include <SDL2/SDL_image.h>
#include "../header/header.h" 
#define PIECE_NUM 32 

SDL_Window * std_window = 0 ; 
SDL_Renderer * std_render = 0 ; 

bool is_loop_running = true ; 

enum player{ WHITE , BLACK } ; 

bool whose_playing = WHITE  ; 


int mouse_pose_x ; 
int mouse_pose_y ; 

Piece white_pawn1 ; 
Piece white_pawn2 ; 
Piece white_pawn3 ; 
Piece white_pawn4 ; 
Piece white_pawn5 ; 
Piece white_pawn6 ; 
Piece white_pawn7 ; 
Piece white_pawn8 ; 

Piece black_pawn1 ; 
Piece black_pawn2 ; 
Piece black_pawn3 ; 
Piece black_pawn4 ; 
Piece black_pawn5 ; 
Piece black_pawn6 ; 
Piece black_pawn7 ; 
Piece black_pawn8 ; 


Piece white_rook1 ; 
Piece white_rook2 ; 
Piece white_bishop1 ; 
Piece white_bishop2 ; 
Piece white_king ; 
Piece white_queen  ; 
Piece white_night1 ; 
Piece white_night2 ; 


Piece black_rook1 ; 
Piece black_rook2 ; 
Piece black_bishop1 ; 
Piece black_bishop2 ; 
Piece black_king ; 
Piece black_queen  ; 
Piece black_night1 ; 
Piece black_night2 ; 


Piece *piece_list[PIECE_NUM] ;   


void flip_board(){

      if( whose_playing == WHITE)
          whose_playing = BLACK ;   

      else
          whose_playing = WHITE ; 
} 
 
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
      SDL_GetMouseState( &mouse_pose_x , &mouse_pose_y) ; 

      while ( SDL_PollEvent(&event)){  

           switch( event.type) { 

             case SDL_QUIT: 

                 is_loop_running = false ; 

             case SDL_MOUSEBUTTONDOWN: 

                 if(event.button.button == SDL_BUTTON_LEFT){ 

                   update() ; 
                   witch_piece_is_selected() ; 
                       
                 }
              case SDL_KEYDOWN: 

                  switch( event.key.keysym.sym ){  
                      case SDLK_f:    
                          flip_board() ;
                          break ;  
                      case SDLK_r : 
                          init_pieces() ; 
                          break ;  
                  } 

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


void init_pieces(){

 piece_list[0] = &white_rook1 ;  
 piece_list[1] = &white_night1 ;  
 piece_list[2] = &white_bishop1 ;  
 piece_list[3] = &white_queen ;  
 piece_list[4] = &white_king  ;  
 piece_list[5] = &white_bishop2  ;  
 piece_list[6] = &white_night2  ;  
 piece_list[7] = &white_rook2  ;  
 piece_list[8] = &white_pawn1  ;  
 piece_list[9] = &white_pawn2  ;  
 piece_list[10] =&white_pawn3  ;  
 piece_list[11] = &white_pawn4  ;  
 piece_list[12] = &white_pawn5  ;  
 piece_list[13] = &white_pawn6  ;  
 piece_list[14] = &white_pawn7  ;  
 piece_list[15] = &white_pawn8  ;  


 piece_list[16] = &black_rook1 ;  
 piece_list[17] = &black_night1 ;  
 piece_list[18] = &black_bishop1 ;  
 piece_list[19] = &black_queen ;  
 piece_list[20] = &black_king  ;  
 piece_list[21] = &black_bishop2  ;  
 piece_list[22] = &black_night2  ;  
 piece_list[23] = &black_rook2  ;  
 piece_list[24] = &black_pawn1  ;  
 piece_list[25] = &black_pawn2  ;  
 piece_list[26] = &black_pawn3  ;  
 piece_list[27] = &black_pawn4  ;  
 piece_list[28] = &black_pawn5  ;  
 piece_list[29] = &black_pawn6  ;  
 piece_list[30] = &black_pawn7  ;  
 piece_list[31] = &black_pawn8  ;  


     if(!whose_playing){ //white is playing  
                        
         //loading for white 
         int index = 0 ; 
         for( int y = 700 ; y >= 600   ; y-=100 ){ 
               
             for( int x = 0 ; x <= 700 ; x+=100){ 
                      piece_list[index]->pose.x = x ; 
                      piece_list[index]->pose.y = y ; 
                      piece_list[index]->is_selected =false ; 
                      index++ ; 
                    
             } 
           } 
          //loading for black
          for( int y = 0 ; y  <= 100 ; y+=100){ 
                 
              for( int x = 0 ; x <= 700 ; x+=100) { 

                      piece_list[index]->pose.x =x ; 
                      piece_list[index]->pose.y = y ; 
                      piece_list[index]->is_selected =false ; 
                      index++ ; 
              } 

          } 

         }else{ 

         int index = 16 ; 
         for( int y = 700 ; y >= 600   ; y-=100 ){ 
               
             for( int x = 0 ; x <= 700 ; x+=100){ 
                      piece_list[index]->pose.x = x ; 
                      piece_list[index]->pose.y = y ; 
                      piece_list[index]->is_selected =false ; 
                      index++ ; 
                    
             } 
           } 
          index = 0 ;  
          for( int y = 0 ; y  <= 100 ; y+=100){ 
                 
              for( int x = 0 ; x <= 700 ; x+=100) { 

                     piece_list[index]->pose.x =x ; 
                     piece_list[index]->pose.y = y ; 
                     piece_list[index]->is_selected =false ; 
                     index++ ;  
              } 

          }

         }   

} 




void load_piece(const char * piece_name ,Piece piece ){
 
     SDL_Rect rect ; 
     rect.h = 100; 
     rect.w = 100 ; 
     rect.x = piece.pose.x ; 
     rect.y = piece.pose.y ;  

     SDL_Surface  * img = IMG_Load(piece_name) ; 
     SDL_Texture  * texture = SDL_CreateTextureFromSurface( std_render , img) ; 

     SDL_RenderCopy( std_render , texture , NULL , &rect ) ; 
     
     SDL_FreeSurface(img) ; 
     SDL_DestroyTexture(texture) ;  
       

} 
void load_chess_board(){ 

        SDL_Rect rect ; 
        rect.h = 800  ; 
        rect.w = 800 ; 
        rect.x =0  ; 
        rect.y = 0  ; 
        
        SDL_Texture * texture ; 
        SDL_Surface * img = IMG_Load("images/rect-8x8.png") ;
        texture = SDL_CreateTextureFromSurface(std_render , img) ; 

        SDL_RenderCopy(std_render , texture , &rect , NULL ) ; 

        SDL_FreeSurface(img) ; 
        SDL_DestroyTexture(texture) ; 
        
      
        load_piece("images/white-pawn.png" , white_pawn1) ;  
        load_piece("images/white-pawn.png" , white_pawn2) ;  
        load_piece("images/white-pawn.png" , white_pawn3) ;  
        load_piece("images/white-pawn.png" , white_pawn4) ;  
        load_piece("images/white-pawn.png" , white_pawn5) ;  
        load_piece("images/white-pawn.png" , white_pawn6) ;  
        load_piece("images/white-pawn.png" , white_pawn7) ;  
        load_piece("images/white-pawn.png" , white_pawn8) ;  
        load_piece("images/white-rook.png" , white_rook1) ;  
        load_piece("images/white-rook.png" , white_rook2) ;  
        load_piece("images/white-bishop.png" , white_bishop1) ;  
        load_piece("images/white-bishop.png" , white_bishop2) ;  
        load_piece("images/white-knight.png" , white_night1) ;  
        load_piece("images/white-knight.png" , white_night2) ;  
        load_piece("images/white-queen.png" , white_queen) ;  
        load_piece("images/white-king.png" , white_king) ;  
        
      
        load_piece("images/black-pawn.png" , black_pawn1) ;  
        load_piece("images/black-pawn.png" , black_pawn2) ;  
        load_piece("images/black-pawn.png" , black_pawn3) ;  
        load_piece("images/black-pawn.png" , black_pawn4) ;  
        load_piece("images/black-pawn.png" , black_pawn5) ;  
        load_piece("images/black-pawn.png" , black_pawn6) ;  
        load_piece("images/black-pawn.png" , black_pawn7) ;  
        load_piece("images/black-pawn.png" , black_pawn8) ;  
        load_piece("images/black-rook.png" , black_rook1) ;  
        load_piece("images/black-rook.png" , black_rook2) ;  
        load_piece("images/black-bishop.png" , black_bishop1) ;  
        load_piece("images/black-bishop.png" , black_bishop2) ;  
        load_piece("images/black-knight.png" , black_night1) ;  
        load_piece("images/black-knight.png" , black_night2) ;  
        load_piece("images/black-queen.png" , black_queen) ;  
        load_piece("images/black-king.png" , black_king) ;  
        
} 

void render_settings(int r  , int g  , int b  ){ 

    SDL_SetRenderDrawColor( std_render ,  r , g , b ,255) ; 
       
    SDL_RenderClear( std_render) ; 

    load_chess_board() ; 

    SDL_RenderPresent( std_render) ; 
} 

void   witch_piece_is_selected(){ 

           int mouse_converted_x = (mouse_pose_x / 100) * 100  ;  
           int mouse_converted_y = (mouse_pose_y / 100) * 100  ;      

           for( int i = 0 ; i < PIECE_NUM ; i++){ 

                 if( piece_list[i]->pose.x == mouse_converted_x && piece_list[i]->pose.y == mouse_converted_y){ 
                      if( piece_list[i]->is_selected == true ) piece_list[i]->is_selected = false   ;  
                      else if( piece_list[i]->is_selected == false ) piece_list[i]->is_selected = true    ;  
                       printf("found\n") ; 
                       break ; 
                  }    
           } 

} 

void update_piece_pose(Piece * piece ){
           
           int mouse_converted_x = (mouse_pose_x / 100) * 100  ;  
           int mouse_converted_y = (mouse_pose_y / 100) * 100  ;

           if( piece->is_selected){ 

                piece->pose.x = mouse_converted_x ; 
                piece->pose.y = mouse_converted_y ;  
           }

} 
 
void update(){  
    
    for( int i = 0;  i< PIECE_NUM; i++)
        update_piece_pose( piece_list[i]) ;    

} 
