#ifndef HEADER
#define HEADER 
#include <SDL2/SDL.h> 

#define PIECE_NUM 32 

extern bool is_loop_running  ; 
extern SDL_Window * std_window ;
extern SDL_Renderer * std_render ; 
extern int mouse_pose_x ; 
extern int mouse_pose_y ; 

typedef struct { 

    int x; 
    int y ; 

} Pose ; 

typedef struct{ 

      Pose pose ; 
      bool is_fill ; 


} Square ; 

typedef struct { 

     Pose pose ; 
     bool is_selected  ; 
     bool first_move ; 

}  Piece ; 

extern Piece white_pawn1 ; 
extern Piece white_pawn2 ; 
extern Piece white_pawn3 ; 
extern Piece white_pawn4 ; 
extern Piece white_pawn5 ; 
extern Piece white_pawn6 ; 
extern Piece white_pawn7 ; 
extern Piece white_pawn8 ; 

extern Piece black_pawn1 ; 
extern Piece black_pawn2 ; 
extern Piece black_pawn3 ; 
extern Piece black_pawn4 ; 
extern Piece black_pawn5 ; 
extern Piece black_pawn6 ; 
extern Piece black_pawn7 ; 
extern Piece black_pawn8 ; 


extern Piece white_rook1 ; 
extern Piece white_rook2 ; 
extern Piece white_bishop1 ; 
extern Piece white_bishop2 ; 
extern Piece white_king ; 
extern Piece white_queen  ; 
extern Piece white_night1 ; 
extern Piece white_night2 ; 


extern Piece black_rook1 ; 
extern Piece black_rook2 ; 
extern Piece black_bishop1 ; 
extern Piece black_bishop2 ; 
extern Piece black_king ; 
extern Piece flack_queen  ; 
extern Piece black_night1 ; 
extern Piece black_night2 ; 


extern Piece * piece_list[PIECE_NUM] ;   
extern Square squears[64] ; 

void create_window(const char *,int, int , int,int ,SDL_WindowFlags  ) ; 
void create_renderer() ;
void clean_up() ; 
void init_and_check() ;  

void handle_input() ; 
void main_loop() ; 
void render_settings( int  ,int   ,int  ) ; 
void load_chess_board() ; 

void load_piece(const char * ,Piece ) ; 

void init_pieces() ; 
void move_piece() ; 

void update_piece_pose( Piece * piece ) ; 
void update()  ;

void   witch_piece_is_selected() ;  
void  load_moves() ; 
#endif 
