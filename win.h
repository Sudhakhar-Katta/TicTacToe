#ifndef WIN_H
    #define WIN_H
    #include <stdbool.h>
    #include "struct.h"
    bool some_won_diagonally_right(Board* board);
    bool some_won_diagonally_left(Board* board);
    bool some_won_diagonally(Board* board);
    bool some_won_vertically(Board* board);
    bool someone_won_horizontally(Board* board);
    bool someone_won();

#endif