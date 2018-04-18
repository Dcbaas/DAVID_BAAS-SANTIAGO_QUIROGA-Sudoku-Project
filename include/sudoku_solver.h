#include <iostream>
bool check_square(int board[9][9], int row, int col);
bool check_row(int board[9][9], int row, int col);
bool check_col(int board[9][9], int row, int col);
bool current_space(int row, int col, int i, int j);
bool sudoku_solver(int board[9][9], int row, int col);
bool sudoku_solver(int board[9][9]);
void printBoard (int array[9][9]);

bool sudoku_solver(int board[9][9]){
    return sudoku_solver(board,0,0);
}

bool sudoku_solver(int board[9][9], int row, int col) {
//    std::cout << "Current BOARD" << std::endl;
 //   printBoard(board);
    //Base Case Return the board if the coverCells are 80
  if(row == 8 && col == 9)
    std::cout << "here1 now" << std::endl;
    if (row == 8 && col == 9) {
        std::cout << "FINAL" << std::endl;
        printBoard(board);
            return true;
        }

        //Check if the row counter has gone over 9 and go to next row.
        if (col == 9) {
            ++row;
            col = 0;
        }
        //If the observed cell is covered.
        if (board[row][col] == 0){
            for (int index{1}; index < 10; ++index) {
                board[row][col] = index;
                if (check_square(board, row, col) && check_row(board, row, col) && check_col(board, row, col)){
                    if (sudoku_solver(board, row, col + 1))
                        return true;
		}
            }
        }
        else{
	  if(sudoku_solver(board, row, col + 1))
	    return true;
	  else
	    return false;
	}
  if(row == 1 && col == 6){
    std::cout << "Failure" << std::endl;
    printBoard(board);
    return true;
  }
  board[row][col] = 0;
  return false;
}
//Check the square region
bool check_square(int board[9][9], int row, int col){
    //check top sq regions
    if(row < 3){
        //check the upper left sq.
        if(col < 3){
            for(int i{0}; i < 3; ++i){
                for(int j{0}; j < 3; ++j){
                    if(board[row][col] == board[i][j] && !current_space(row,col,i,j))
                        return false;
                }
            }
        }
            //check the upper middle sq.
        else if(col > 2 && col < 6){
            for(int i{3}; i < 6; ++i){
                for(int j{0}; j < 3; ++j){
                    if(board[row][col] == board[i][j] && !current_space(row,col,i,j))
                        return false;
                }
            }
        }
            //check the upper right corner
        else{
            for(int i{6}; i < 9; ++i){
                    for(int j{0}; j < 3; ++j){
                        if(board[row][col] == board[i][j] && !current_space(row,col,i,j))
                            return false;
                    }
            }
        }
    }
        //Check the middle sections.
    else if(row > 2 && row < 6){
        //check the middle left sq.
        if(col < 3){
            for(int i{0}; i < 3; ++i){
                for(int j{2}; j < 6; ++j){
                    if(board[row][col] == board[i][j] && !current_space(row,col,i,j))
                        return false;
                }
            }
        }
            //check the center sq.
        else if(col > 2 && col < 6){
            for(int i{3}; i < 6; ++i){
                for(int j{2}; j < 6; ++j){
                    if(board[row][col] == board[i][j] && !current_space(row,col,i,j))
                        return false;
                }
            }
        }
            //check the middle right corner
        else{
            for(int i{6}; i < 9; ++i){
                    for(int j{2}; j < 6; ++j){
                        if(board[row][col] == board[i][j] && !current_space(row,col,i,j))
                            return false;
                    }
            }
        }
    }
    //Check the lower sections.
    else{
//check the lower left sq.
        if(col < 3){
            for(int i{0}; i < 3; ++i){
                for(int j{6}; j < 9; ++j){
                    if(board[row][col] == board[i][j] && !current_space(row,col,i,j))
                        return false;
                }
            }
        }
            //check the lower middle sq.
        else if(col > 2 && col < 6){
            for(int i{3}; i < 6; ++i){
                for(int j{6}; j < 9; ++j){
                    if(board[row][col] == board[i][j] && !current_space(row,col,i,j))
                        return false;
                }
            }
        }
            //check the lower right corner
        else{
            for(int i{6}; i < 9; ++i){
                    for(int j{6}; j < 9; ++j){
                        if(board[row][col] == board[i][j] && !current_space(row,col,i,j))
                            return false;
                    }
            }
        }
    }
    return true;
}

//Check the row
bool check_row(int board[9][9], int row, int col){
    for(int i{0}; i < 9; ++i){
        if(board[row][col] == board[i][col] && !current_space(row,col,i,col))
        return false;
    }
    return true;
}

//check the coloum
bool check_col(int board[9][9], int row, int col){
    for(int i{0}; i < 9; ++i){
        if(board[row][col] == board[row][i] && !current_space(row,col,row,i))
            return false;
    }
    return true;
}

bool current_space(int row, int col, int i, int j){
    if(row == i && col == j)
        return true;
    return false;
}

void printBoard (int board[9][9]) {
    for (int i{0}; i < 9; ++i) {
        for (int j{0}; j < 9; ++j)
            std::cout << "[" << board[i][j] << "]";
        std::cout << std::endl;
    }
}
