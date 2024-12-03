
#include <stdio.h>
#include <stdbool.h>
#include "struct.h"

bool all_same(char* values, int len){
    for(int i=0;i<len;++i){
        if(values[i]==values[0]){
            return true;
        }
    }
    return false;
}

bool some_won_diagonally_right(Board* board) {
    /*
      Checks the diagonal from top-right to bottom-left for uniformity.
      Example:
         X 
        X
       X
    */
    char top_right = board->contents[0][board->dimensions - 1];

    // If the top-right element is blank, return false immediately
    if (top_right == board->blank_char) {
        return false;
    }

    // Traverse the diagonal from top-right to bottom-left
    for (int i = 1; i < board->dimensions; ++i) {
        if (board->contents[i][board->dimensions - 1 - i] != top_right) {
            return false; // Mismatch found
        }
    }

    return true; // All elements match and are not blank
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
    return someone_won_diagonally_left(board) || some_won_diagonally_right(board);
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

bool someone_won(Board* board){
    return someone_won_horizontally(board) || someone_won_vertically(board) || someone_won_diagonally(board);
}
