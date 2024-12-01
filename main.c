#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    Board board;
    int curr_player_turn;
}Game;


typedef struct{
    char** contents;
    int dimensions;
    char blank_char;
}Board; 

typedef struct{
    char* name;
    char piece;
}Player;

/*
The following code about shows what content is need to create a board which would be the dimensiosn and the n*n grid and a blank character to emulate the empty box in a 
normal game of tic tac toe
*/

Board create_board(int dimensions,char blank_char){
    Board board;
    board.dimensions=dimensions;
    board.contents=(char**) malloc(dimensions*sizeof(char*));

    for(int i=0;i<dimensions;i++){
       board.contents[i]=(char*)malloc(dimensions*sizeof(char));
       for(int j=0;j< dimensions;j++){
            board.contents[i][j]=blank_char; 
       }
    }
    return board;
}
/*
SO when we start a tic toe game we want to have it empty so when the games starts the user can enter the dimensions 
and what they want their blank character to be to simulate the space in a regular tic tac game, and we return board because it is an object of Board and the 
function saying to return something that is Board
*/

int pick_who_goes_first(int num_players){
    return rand() % num_players;    
}
char* get_player_name(Player* players_in_game, int len){

    char* name= NULL;
    do{
        if(name != NULL){
            free(name);
            name=NULL;
        }

        printf("Enter your name: ");
        name=get_any_len_string();
        if(!is_valid_format(1,1)){
            printf("Your name can only be 1 word long.\n");
            continue;
        }else if(!is_player_in_game(name,players_in_game,len)){
            printf("%s is already in the game. Choose another name.\n");
        }else{
            break;
        }
    }while(true);
    return name;
}   

char* get_player_piece(Player* players_in_game,int len){
    char piece;
    while(true){
        piece=get_valid_char("Please choose your piece: ");
        if(is_piece_is_already_chosen(piece,players_in_game,len)){
            printf("You can't choose %c because another player has already choosen it\n");
        }else{
            return piece;
        }
    }
}


Player* players_pick_names_and_pieces(int num_players){
    Player* players= (Player*)calloc(num_players,sizeof(Player));
    for(int i=0;i<num_players;++i){
        players[i].name=get_player_name();
        players[i].piece=get_player_piece();
    }
}

Game setup_game(int dimensions, char blank_char){
    Game game;
    game.board=create_board(dimensions,blank_char);
    game.curr_player_turn=pick_who_goes_first(2);
    players_pick_pieces();
    return game;
}
bool some_won_diagonally_right(Board* board){
    /*
       X 
        X
         X
    */    
   char upper_right=board->contents[0][board->dimensions];
   for(int i=1; i< board->dimensions;++i){
        if(board->contents[i][i] != upper_right){
            return true;
        }
   }  
   return false;
}

bool some_won_diagonally_left(Board* board){
    /*
       X 
        X
         X
    */    
   char upper_left=board->contents[0][0];
   for(int i=1; i< board->dimensions;++i){
        if(board->contents[i][i] != upper_left){
            return true;
        }
   }  
   return false;
}

bool some_won_diagonally(Board* board){
    return someone_won_diagonally_left() || some_won_diagonally_right();
}

bool some_won_vertically(Board* board){
    for(int i=0;i<board->dimensions;++i){
        char* column=get_column_i();
        if(all_same(column,board->dimensions)){
            free(column);
            return true;
        }
        free(column);
    }
    return false;
}

bool someone_won_horizontally(Board* board){
    for(int i=0;i<board->dimensions;++i){
        if(all_same(board->contents[i],board->dimensions)){
            return true;
        }
    }
    return false;
}

bool someone_won(){
    return someone_won_horizontally() || someone_won_vertically() || someone_won_diagonally();
}

bool is_game_over(){
    return someone_won() ||  tie();
}

void take_turn(Game *game){
    Player* curr_player=get_curr_player();
    Move move= get_move();
    game ->board->contents[move.row][move.col]= curr_player->piece;
}



void play_game(Game *game){  // THis is a game pointer because we actually want the game not a copy
    while(!is_game_over()){
        take_turn();
        switch_turns();
    }
    announce_results();
}



int main(){

    setup_game();
    play_game();

    return 0;

}