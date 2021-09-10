// Assignment 1 21T2 COMP1511: Minesweeper
// minesweeper.c
//
// This program was written by Jake Edwards (z5165158)
// on 24/06/2021
//
// Version 1.0.0 (2021-06-19): Assignment released.


/*
Test 1
dcc -Werror minesweeper_ext.c -o minesweeper_ext
echo -e '3\n0 1\n1 1\n1 2\n4\n5 0 0\n5 1 0\n5 0 2\n5 1 1\n3 1 1\n5 1 1\n3 2 1' | ./minesweeper_ext

Test 2
dcc -Werror minesweeper_ext.c -o minesweeper_ext
echo -e '2\n1 0\n1 2\n4\n5 0 1\n3 1 1' | ./minesweeper_ext
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Possible square states.
#define VISIBLE_SAFE    0
#define HIDDEN_SAFE     1
#define HIDDEN_MINE     2

// The size of the starting grid.
#define SIZE            8

// The size of the flag list
#define FLAGS_SIZE      64

// The possible command codes.
#define DETECT_ROW      1
#define DETECT_SQUARE   2
#define REVEAL_CROSS    3
#define GAME_MODE       4
#define FLAG_MINE       5
#define DEFUSE          6

//Other Constants
#define COORDS_SIZE     2
#define ROW_INDEX       0
#define COL_INDEX       1
#define RUN             1
#define NONE            0 //maybe delete is 0 a magic number?
#define NUM_HINTS       3
// Add any extra #defines here.
#define DEFUSE_LENGTH_ONE 13

void  place_mines(int minefield[SIZE][SIZE], int number_mines);
void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);
int detect_row(int minefield[SIZE][SIZE],int row,int col,int col_length);
void init_command(int minefield[SIZE][SIZE], int flags[(FLAGS_SIZE)][COORDS_SIZE]);
int detect_square(int minefield[SIZE][SIZE], int row, int col, int side_length);
void reveal_cross(int debug_mode, int flags[(FLAGS_SIZE)][COORDS_SIZE], int minefield[SIZE][SIZE], int row,int col);
int check_square(int flags[(FLAGS_SIZE)][COORDS_SIZE], int minefield[SIZE][SIZE], int row, int col, int side_length);
int check_win(int minefield[SIZE][SIZE]);
int check_not_in_grid(int row, int col);
int check_in_grid(int row, int col);
void explode_mines(int debug_mode, int flags[(FLAGS_SIZE)][COORDS_SIZE], int minefield[SIZE][SIZE]);
void init_flags(int flags[(FLAGS_SIZE)][COORDS_SIZE]);
void place_flag(int flags[(FLAGS_SIZE)][COORDS_SIZE], int row, int col);
void print_gamemode_minefield(int flags[(FLAGS_SIZE)][COORDS_SIZE], int minefield[SIZE][SIZE]);
int check_in_flags(int flags[(FLAGS_SIZE)][COORDS_SIZE], int row, int col);
int check_square_for_flags(int flags[(FLAGS_SIZE)][COORDS_SIZE], int minefield[SIZE][SIZE], int row, int col, int side_length);
int force_unhide(int debug_mode, int flags[(FLAGS_SIZE)][COORDS_SIZE],int minefield[SIZE][SIZE],int row, int col);
void defuse_mines(int minefield[SIZE][SIZE], int row, int col);
void second_defuse(int minefield[SIZE][SIZE], int row, int col);
// Place your function prototyes here.

int main(void) {
    int minefield[SIZE][SIZE];
    int number_mines;
    int flags[FLAGS_SIZE][COORDS_SIZE];
    //int first_defuse_list[DEFUSE_LENGTH_ONE][COORDS_SIZE]
    
    init_flags(flags);
    initialise_field(minefield);
    printf("Welcome to minesweeper!\n");
    printf("How many mines? ");

    scanf("%d", &number_mines);
    
    printf("Enter pairs:\n");
    // Scan in the pairs of mines and place them on the grid.
    place_mines(minefield, number_mines);
   


    printf("Game Started\n");
    print_debug_minefield(minefield);
    init_command(minefield, flags);

    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been processed.


    return 0;
}


// Set the entire minefield to HIDDEN_SAFE.
void initialise_field(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            minefield[i][j] = HIDDEN_SAFE;
            j++;
        }
        i++;
    }
}


// Print out the actual values of the minefield.
void print_debug_minefield(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}





//places mines into array
void  place_mines(int minefield[SIZE][SIZE], int number_mines){

    int mine_row_val;
    int mine_col_val;
    int coords[number_mines][COORDS_SIZE];
    int valid = 2;
    
    //scan coordinate values for mines in temporary array
    for(int mine_count = 0; mine_count < number_mines; mine_count++) {
        for(int coord = 0; coord < COORDS_SIZE; coord++) {
            if (coord == ROW_INDEX) {
                scanf("%d", &mine_row_val);
                coords[mine_count][coord] = mine_row_val;
            }
            else {
                scanf("%d", &mine_col_val);
                coords[mine_count][coord] = mine_col_val;
            }        
        }   
    }

    
    //places only valid coords does not ask for a new set of coords
    
    int check = 0;
    for(int i = 0; i < number_mines; i++) {
        check = 0;
        if (coords[i][ROW_INDEX] >= 0 && coords[i][ROW_INDEX] < SIZE) {
            check++;
        }
        if (coords[i][COL_INDEX] >= 0 && coords[i][COL_INDEX] < SIZE) {
            check++;
        }
        if (check ==  valid) {
            mine_row_val = coords[i][ROW_INDEX];
            mine_col_val = coords[i][COL_INDEX];
            minefield[mine_row_val][mine_col_val] = HIDDEN_MINE;
        
        }
    
    }
   
}
//check if given indices are not within grid
int check_not_in_grid(int row, int col){
    return (row >= SIZE || row < 0 || col >= SIZE || col < 0);
}

//check if given indices are within grid (probably don't need both functions)
int check_in_grid(int row, int col){
    return (row < SIZE && row >= 0 && col < SIZE && col >= 0);
}

int detect_row(int minefield[SIZE][SIZE], int row, int col, int col_length){
    int num_mines = 0;
    int end_col = col+col_length-1;
    for(int col_idx = col;col_idx < col_length + col; col_idx++) {
        if (check_not_in_grid(row, col_idx)) {
            printf("Coordinates not on map\n");
            return 0;
        }
        else if (minefield[row][col_idx] == HIDDEN_MINE) {
            num_mines++;
        }
    }
    if (num_mines >= 0) {
        printf("There are %d mine(s) in row %d,from column %d to %d\n",
        num_mines, row, col, end_col);
    }
    return 1;
}

int detect_square(int minefield[SIZE][SIZE], int row, int col, int side_length){
    int row_centre = row;
    int col_centre = col;
    int num_mines = 0;
    
    if (check_not_in_grid(row_centre, col_centre)) {
        printf("Coordinates not on map\n");
        return 0;
    }
    
    int init_row = row_centre - side_length / 2;
    int init_col = col_centre - side_length / 2;
    int row_condition = (init_row + side_length);
    int col_condition = (init_col + side_length);
    //TODO: DEEPNESTING?
    for(int row_idx = init_row; row_idx < row_condition; row_idx++) {
        for(int col_idx = init_col; col_idx < col_condition; col_idx++) {
            if (check_in_grid(row_idx, col_idx) && 
            minefield[row_idx][col_idx] == HIDDEN_MINE) {
                num_mines++;
                
            }
        }
    
    }
   
    printf("There are %d mine(s) in the square centered", num_mines);
    printf(" at row %d, column %d of size %d\n", row_centre, col_centre
    , side_length);
    return 1;
}

//check if mines adjacent or not to a selected cell
int check_square(int flags[FLAGS_SIZE][COORDS_SIZE], int minefield[SIZE][SIZE], 
int row, int col, int side_length){
    int row_centre = row;
    int col_centre = col;
    int num_mines = 0;
    int num_flags = 0;
    
    if (check_not_in_grid(row_centre, col_centre)) {

        return -1;
    }
    int init_row = row_centre - side_length / 2;
    int init_col = col_centre - side_length / 2;
    int row_condition = (init_row + side_length);
    int col_condition = (init_col + side_length);
    
    //TODO: DEEPNESTING OR NEW FUNCTION?
    for(int row_idx = init_row; row_idx < row_condition; row_idx++) {
        for(int col_idx = init_col; col_idx < col_condition; col_idx++) {
            if (check_in_grid(row_idx, col_idx) &&
            minefield[row_idx][col_idx] == HIDDEN_MINE)  {
                num_mines++;
                
            }
            if (check_in_flags(flags, row_idx, col_idx)) {
                num_flags++;
            }
        }
    
    }
    
    /*For each of the 4 squares connected to the selected square, 
    that square should be revealed if there are an equal number 
    of mines and flagged squares in the 3x3 area surrounding that 
    square (i.e. 9 squares in total)
    */

    
    return num_mines;
}
//check if mines adjacent or not to a selected cell
int check_square_for_flags(int flags[FLAGS_SIZE][COORDS_SIZE], 
int minefield[SIZE][SIZE], int row, int col, int side_length){
    int row_centre = row;
    int col_centre = col;
    int num_mines = 0;
    int num_flags = 0;
    
    if (check_not_in_grid(row_centre, col_centre)) {

        return -2;
    }
    int init_row = row_centre - side_length / 2;
    int init_col = col_centre - side_length / 2;
    int row_condition = (init_row + side_length);
    int col_condition = (init_col + side_length);
    
    //TODO: DEEPNESTING OR NEW FUNCTION?
    for(int row_idx = init_row; row_idx < row_condition; row_idx++) {
        for(int col_idx = init_col; col_idx < col_condition; col_idx++) {
            if (check_in_grid(row_idx, col_idx) &&
            minefield[row_idx][col_idx] == HIDDEN_MINE)  {
                num_mines++;
                
            }
            if (check_in_flags(flags, row_idx, col_idx)) {
                num_flags++;
            }
        }
    
    }
    
    /*For each of the 4 squares connected to the selected square, 
    that square should be revealed if there are an equal number 
    of mines and flagged squares in the 3x3 area surrounding that 
    square (i.e. 9 squares in total)
    */

    
    return num_flags;
}

// Print out the actual values of the minefield.Doesn't error handle for invalid
//input
void print_gamemode_minefield(int flags[FLAGS_SIZE][COORDS_SIZE], 
int minefield[SIZE][SIZE]) {
    int tmp;
    int i = 0;
    int check_length = 3;
    printf("    ");
    while (i < SIZE) {
        printf("0%d ", i);
        i++;
    }
    printf("\n   -------------------------\n");
    i = 0;
    while (i < SIZE) {
        int j = 0;
        printf("0%d |", i);
        while (j < SIZE) {
            tmp =  check_square(flags, minefield, i, j, check_length);
            //TODO: might need to change logic for showing mines when game over
            if (check_in_flags(flags, i, j)) {
                printf("!! ");
            }
            else if (minefield[i][j] == HIDDEN_SAFE || minefield[i][j] 
            == HIDDEN_MINE) {
                printf("## ");
            }
            else if (minefield[i][j] == VISIBLE_SAFE && tmp <= NONE) {
                //error handle for outside grid cells i.e. if tmp = -1 etc.?
                printf("   ");
            }
            else {
                printf("0%d ", tmp);
            }
            j++;
        }
        
        printf("|\n");
        i++;
    }
    printf("   -------------------------\n");
}
/*
For each of the 4 squares connected to the selected square, that square should be 
"revealed" if there are an equal number of mines and flagged squares in the
3x3 area surrounding that square (i.e. 9 squares in total)
- THIS FUNCTION FORCES REVEAL
*/

//reveal value in all cases i.e. could be mine or not mine but must become unhidden
int force_unhide(int debug_mode, int flags[FLAGS_SIZE][COORDS_SIZE], 
int minefield[SIZE][SIZE], int row, int col){
    if (minefield[row][col] == HIDDEN_MINE) {
        return 1;
    }
    else {
        minefield[row][col] = VISIBLE_SAFE;
        return 0;
    }

}



//change values to explode mine for gameover sequence
void explode_mines(int debug_mode, int flags[FLAGS_SIZE][COORDS_SIZE], 
int minefield[SIZE][SIZE]){
    int tmp;
    int i = 0;
    int check_length = 3;
    printf("Game over\n");
    if (debug_mode == 1) {
        print_debug_minefield(minefield);
        exit(0);
    } 
    printf("xx\n/\\\n");
    printf("    ");
    while (i < SIZE) {
        printf("0%d ", i);
        i++;
    }
    printf("\n   -------------------------\n");
    i = 0;
    while (i < SIZE) {
        int j = 0;
        printf("0%d |", i);
        while (j < SIZE) {
            tmp =  check_square(flags, minefield, i, j, check_length);
            //TODO: might need to change logic for showing mines when game over
            //PROBABLY WRONG to include check in flags TODO
            
            
            if (minefield[i][j] == HIDDEN_MINE) {
                printf("() ");
            }
            else if (check_in_flags(flags, i, j)) {
                printf("!! ");
            }
            else if (minefield[i][j] == HIDDEN_SAFE) {
                printf("## ");
            }
            //error handle for outside grid cells i.e. if tmp = -1 etc.?
            else if (minefield[i][j] == VISIBLE_SAFE && tmp <= NONE) {
                printf("   ");
            }
            else {
                printf("0%d ", tmp); 
            }
            j++;
        }
        
        printf("|\n");
        i++;
    }
    printf("   -------------------------\n");
    exit(0);
}

void reveal_cross(int debug_mode, int flags[FLAGS_SIZE][COORDS_SIZE], 
int minefield[SIZE][SIZE], int row, int col){
    int up_row = row - 1;
    int up_col = col;
    int right_row = row;
    int right_col = col + 1;
    int down_row = row + 1;
    int down_col = col;
    int left_row = row;
    int left_col = col - 1;
    int check_length = 3;
    int gameover_bool = 0;
    //check to see if coords on grid
    if (check_not_in_grid(row, col)) {
        printf("Coordinates not on map\n");
        return;
    }    
    
    //check to see if mine selected
    if (check_in_flags(flags, row, col)) {
        /*"The selected square behaves the same, except if the selected 
        square is flagged, no squares will be revealed"  */
        return;
    }
    else if (minefield[row][col] ==  HIDDEN_MINE) {
        
        //function to reveal mines or change value of mines 
        //which gets converted to brackets
        explode_mines(debug_mode, flags, minefield);
    }
    //reveal if mine not selected
    else {
        minefield[row][col] = VISIBLE_SAFE;
    }
    //reveal if no mine adjacent to cell above selected
    
    
    /*TODO: put check_in_grid into check_Square  .. delete check_in_grid
    because not need?*/
   
    
    //reveal if no mine adjacent to cell above selected
    
    if (check_square(flags, minefield, up_row, up_col, check_length) == 
    check_square_for_flags(flags, minefield, up_row, up_col, check_length) && 
    check_in_flags(flags, up_row, up_col) == 0 ) {
        gameover_bool = force_unhide(debug_mode, flags, 
        minefield, up_row, up_col) + gameover_bool;
    }
    else if (check_square(flags, minefield, up_row, up_col, check_length)
     == 0) {
        minefield[up_row][up_col] = VISIBLE_SAFE;
    }

    //reveal if no mine adjacent to cell right of selected
    
    
    
    if (check_square(flags, minefield, right_row, right_col, check_length) == 
    check_square_for_flags(flags, minefield, right_row, right_col, check_length) 
    && check_in_flags(flags, right_row, right_col) == 0 ) {
        
    
        gameover_bool = force_unhide(debug_mode, flags, minefield, 
        right_row, right_col) + gameover_bool;
    
    }
    else if (check_square(flags, minefield, right_row, right_col, check_length) 
    == 0) {
    
        minefield[right_row][right_col] = VISIBLE_SAFE;
    }
   
    //reveal if no mine adjacent to cell below selected

    if (check_square(flags, minefield, down_row, down_col, check_length) == 
    check_square_for_flags(flags, minefield, down_row, down_col, check_length) 
    && check_in_flags(flags, down_row, down_col) == 0 ) {
        gameover_bool = force_unhide(debug_mode, flags, minefield, down_row, 
        down_col) + gameover_bool;
    }
    else if (check_square(flags, minefield, down_row, down_col, check_length)
     == 0) {
        minefield[down_row][down_col] = VISIBLE_SAFE;
    }
    
    //reveal if no mine adjacent to cell left of selected
    
    if (check_square(flags, minefield, left_row, left_col, check_length) == 
    check_square_for_flags(flags, minefield, left_row, left_col, check_length) 
    && check_in_flags(flags, left_row, left_col) == 0 ) {
        gameover_bool = force_unhide(debug_mode, flags, minefield, left_row, 
        left_col) + gameover_bool;
    }
    else if (check_square(flags, minefield, left_row, left_col, check_length)
     == 0) {
        minefield[left_row][left_col] = VISIBLE_SAFE;
    }
    
    if (gameover_bool > 0) {
        explode_mines(debug_mode, flags, minefield);
    }
    
    //check if hidden safe cells exist
    if (check_win(minefield) == 0) {
        printf("Game Won!\n");
        if (debug_mode == 1) {
            print_debug_minefield(minefield);
        }
        else if (debug_mode == 0) {
            printf("..\n\\/\n");
            print_gamemode_minefield(flags, minefield);
        }
        exit(0);
    }

}
int check_win(int minefield[SIZE][SIZE]){
    int check = 0;
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            if (minefield[i][j] == HIDDEN_SAFE) {
                check++;
            }
            j++;
        }
   
        i++;
    }
    return check;
}
//initalise all values in flags to be -1
void init_flags(int flags[FLAGS_SIZE][COORDS_SIZE]){
    for (int i = 0; i < FLAGS_SIZE; i++) {
        for(int j = 0; j < COORDS_SIZE; j++) {
            flags[i][j] = -1;
        }
    }
}
//place or remove flag in flag array
//TODO: change "magic Numbers"
void place_flag(int flags[FLAGS_SIZE][COORDS_SIZE], int row, int col) {
    //remove flag if exists
    for (int i = 0; i < (FLAGS_SIZE); i++) {
        if (flags[i][0] == row && flags[i][1] == col) {
            flags[i][0] = -1;
            flags[i][1] = -1;
            printf("Flag removed from row %d, column %d\n", row, col);
            return;    
        }
    }
    //place flag on first unused i.e. -1 value
    for (int i = 0; i < (FLAGS_SIZE); i++) {
        if (flags[i][0] == -1) {
            flags[i][0] = row;
            flags[i][1] = col;
            printf("Flag placed at row %d, column %d\n", row, col);
            return;
        }
    }
}

int check_in_flags(int flags[FLAGS_SIZE][COORDS_SIZE], int row, int col) {
    for (int i = 0; i < (FLAGS_SIZE); i++) {
        if (flags[i][0] == row && flags[i][1] == col) {
            return 1;
        }
    }
    return 0;
}

//HOW TO IMPLEMENT?
/*
double check_distance(int x_1,int y_1, int x_2,int y_2){
    return pow(pow(x_1-x_2,2),pow(y_1-y_2,2));
}
*/
void defuse_mines(int minefield[SIZE][SIZE], int row, int col){
    int first_defuse_list[DEFUSE_LENGTH_ONE][COORDS_SIZE] = {0};
    int num_mines_list = 0;
    int start_row = row - 1;
    int start_col = col - 1;
    
    
    int up_row = row + 2;
    int up_col = col;
    int right_row = row;
    int right_col = col + 2;
    int down_row = row + 2;
    int down_col = col;
    int left_row = row;
    int left_col = col - 2;

    //TODO: label magic numbers
    for(int row_idx = start_row; row_idx < start_row + 3; row_idx++) {
        for(int col_idx = start_col; col_idx < start_col + 3; col_idx++) {
            if (check_in_grid(row_idx, col_idx) && minefield[row_idx][col_idx] 
            == HIDDEN_MINE ) {
                minefield[row_idx][col_idx] = HIDDEN_SAFE;
                first_defuse_list[num_mines_list][0] = row_idx;
                first_defuse_list[num_mines_list][1] = col_idx;
                num_mines_list++;
            }
        }
    }
    if (check_in_grid(up_row, up_col) && minefield[up_row][up_col]
     == HIDDEN_MINE ) {
        minefield[up_row][up_col] = HIDDEN_SAFE;
        first_defuse_list[num_mines_list][0] = up_row;
        first_defuse_list[num_mines_list][1] = up_col;
        num_mines_list++;
    }
    if (check_in_grid(right_row, right_col) && minefield[right_row][right_col] 
    == HIDDEN_MINE ) {
        minefield[right_row][right_col] = HIDDEN_SAFE;
        first_defuse_list[num_mines_list][0] = right_row;
        first_defuse_list[num_mines_list][1] = right_col;
        num_mines_list++;
    }
    if (check_in_grid(down_row, down_col) && minefield[down_row][down_col]
     == HIDDEN_MINE ) {
        minefield[down_row][down_col] = HIDDEN_SAFE;
        first_defuse_list[num_mines_list][0] = down_row;
        first_defuse_list[num_mines_list][1] = down_col;
        num_mines_list++;
    }
    if (check_in_grid(left_row, left_col) && minefield[left_row][left_col]
     == HIDDEN_MINE ) {
        minefield[left_row][left_col] = HIDDEN_SAFE;
        first_defuse_list[num_mines_list][0] = left_row;
        first_defuse_list[num_mines_list][1] = left_col;
        num_mines_list++;
    }
    for(int iter = 0; iter < num_mines_list; iter++) {
        second_defuse(minefield, first_defuse_list[iter][0], 
        first_defuse_list[iter][1]);
    }

}

void second_defuse(int minefield[SIZE][SIZE], int row, int col){
    int start_row = row - 1;
    int start_col = col - 1;
    
    
    int up_row = row + 2;
    int up_col = col;
    int right_row = row;
    int right_col = col + 2;
    int down_row = row + 2;
    int down_col = col;
    int left_row = row;
    int left_col = col - 2;

    //TODO: label magic numbers
    for(int row_idx = start_row; row_idx < start_row + 3; row_idx++) {
        for(int col_idx = start_col; col_idx < start_col + 3; col_idx++) {
            if (check_in_grid(row_idx, col_idx) && minefield[row_idx][col_idx] 
            == HIDDEN_MINE ) {
                minefield[row_idx][col_idx] = HIDDEN_SAFE;
            }
        }
    }
    if (check_in_grid(up_row, up_col) && minefield[up_row][up_col]
     == HIDDEN_MINE ) {
        minefield[up_row][up_col] = HIDDEN_SAFE;
    }
    if (check_in_grid(right_row, right_col) && minefield[right_row][right_col] 
    == HIDDEN_MINE ) {
        minefield[right_row][right_col] = HIDDEN_SAFE;
    }
    if (check_in_grid(down_row, down_col) && minefield[down_row][down_col] 
    == HIDDEN_MINE ) {
        minefield[down_row][down_col] = HIDDEN_SAFE;
    }
    if (check_in_grid(left_row, left_col) && minefield[left_row][left_col] 
    == HIDDEN_MINE ) {
        minefield[left_row][left_col] = HIDDEN_SAFE;
    }
    
}

//initalise commands for reptition until end of game
void init_command(int minefield[SIZE][SIZE], 
int flags[FLAGS_SIZE][COORDS_SIZE]){
    int command;
    int var_a;
    int var_b;
    int var_c;
    int result = 1;
    int hint_var;
    int hint_count = 0;
    int debug_mode = 1;
    
    while (result == RUN) {
        if (scanf("%d", &command) == EOF) {
            exit(0);
        }
        if (command < GAME_MODE || command > GAME_MODE) {
            if (scanf("%d", &var_a) == EOF) {
                exit(0);
            }
            if (scanf("%d", &var_b) == EOF) {
                exit(0);
            }
        }
        //may need to change for extension
        if (command < REVEAL_CROSS) { 
            if (scanf("%d", &var_c) == EOF) {
                exit(0);
            }
        }    
        if (command == GAME_MODE) {
            if (debug_mode == 1) {
                debug_mode = 0;
                printf("Gameplay mode activated\n");
            }    
            else {
                debug_mode = 1;
                printf("Debug mode activated\n");
                //reset hint_count??
                hint_count = 0;
            }
        }
        if (hint_count >= NUM_HINTS) {
            printf("Help already used\n");
        }
        else if (command == DETECT_ROW && hint_count < NUM_HINTS) {
            hint_var = detect_row(minefield, var_a, var_b, var_c);
            hint_count = hint_count + hint_var;
        }
        else if (command == DETECT_SQUARE && hint_count < NUM_HINTS) {
            hint_var = detect_square(minefield, var_a, var_b, var_c);
            hint_count = hint_count + hint_var;
        }
        /*
        TODO:check
        Does reveal cross need
         && hint_count < NUM_HINTS in condition ?
        */
        else if (command == REVEAL_CROSS) {
            reveal_cross(debug_mode, flags, minefield, var_a, var_b);
        }
        else if (command ==  FLAG_MINE) {
            place_flag(flags, var_a, var_b);
        }
        else if (command ==  DEFUSE) {
            defuse_mines(minefield, var_a, var_b);
        }
        if (debug_mode == 1) {
            print_debug_minefield(minefield);
        }
        else if (debug_mode == 0) {
            printf("..\n\\/\n");
            print_gamemode_minefield(flags, minefield);
        }
    }
}
