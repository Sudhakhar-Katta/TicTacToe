typedef struct{
    char** contents;
    int dimensions;
    char blank_char;
}Board; 

/*
The following code about shows what content is need to create a board which would be the dimensiosn and the n*n grid and a blank character to emulate the empty box in a 
normal game of tic tac toe
*/

typedef struct 
{
    /* data */
}Game;


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


Game setup_game(){
    Game game;
    create_board();
    pick_who_goes_first();
    players_pick_pieces();
    return game;
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