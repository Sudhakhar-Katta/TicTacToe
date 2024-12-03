// game.h
#ifndef GAME_H
#define GAME_H

typedef struct {
    char* name;
    char piece;
} Player;

typedef struct {
    char** contents;
    int dimensions;
    char blank_char;
} Board;

typedef struct {
    Board board;
    int curr_player_turn;
} Game;

#endif // GAME_H
