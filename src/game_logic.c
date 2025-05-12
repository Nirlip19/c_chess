#include "../header/header.h" 

Square squares[64] ; 



void init_squares(){ 

       int index = 0 ; 

       for( int y = 0 ; y <= 700 ; y+=100){ 
           for( int x = 0 ; x <= 700 ; x+=100){  
               squares[index].pose.x = x ; 
               squares[index].pose.y = y ; 
               index++ ; 

         } 
        
       } 




} 

