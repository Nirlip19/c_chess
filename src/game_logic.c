#include "../header/header.h" 
#include <stdbool.h> 

Square squares[64] ; 



void init_squares(){ 

       int s_index = 0 ; 
       for( int y = 700 ; y >= 0 ; y-=100){ 
           for( int x = 0 ; x <= 700 ; x+=100){  
               squares[s_index].pose.x = x ; 
               squares[s_index].pose.y = y ; 
               s_index++ ; 

         } 
        
       }  
} 

void connect_square_to_piece(){ 

     int ind = 0 ;
     for( int j = 0 ; j < 64 ; j++ ){ 

          for( int i = 0 ; i < 32 ; i++){   

             if( (piece_list[i]->pose.x == squares[j].pose.x) && (piece_list[i]->pose.y == squares[j].pose.y)){

                 piece_list[i]->square = &squares[j] ; 
                 piece_list[i]->square->is_fill = true; 

            }  

     }

    } 
}

void print_s_state(){

       printf("\n\n") ; 

       for(int i = 0 ; i < 64 ; i++){ 
         
         if( (i+1) % 8 == 0) 

             printf("%d\n" , squares[i].is_fill) ; 

         else
             printf("%d " , squares[i].is_fill ) ; 

       } 


} 
