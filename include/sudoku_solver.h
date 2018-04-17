#include <iostream>
bool check_square(int board[9][9], int x, int y);
bool check_row(int board[9][9], int x, int y);
bool check_col(int board[9][9], int x, int y);
bool current_space(int x, int y, int i, int j);
bool sudoku_solver(int board[9][9], int x, int y);
bool sudoku_solver(int board[9][9]);
void printBoard (int array[9][9]);

bool sudoku_solver(int board[9][9]){
    return sudoku_solver(board,0,0);
}

bool sudoku_solver(int board[9][9], int x, int y) {
//    std::cout << "Current BOARD" << std::endl;
 //   printBoard(board);
    //Base Case Return the board if the coverCells are 80
  if(x == 8 && y == 9)
    std::cout << "here1 now" << std::endl;
    if (x == 8 && y == 9) {
        std::cout << "FINAL" << std::endl;
        printBoard(board);
            return true;
        }
    
        //Check if the x counter has gone over 9 and go to next row.
        if (y == 9) {
            ++x;
            y = 0;
        }
        //If the observed cell is covered.
        if (board[x][y] == 0){
            for (int index{1}; index < 10; ++index) {
                board[x][y] = index;
                if (check_square(board, x, y) && check_row(board, x, y) && check_col(board, x, y)){
                    if (sudoku_solver(board, x, y + 1))
                        return true;
		}
            }     
        }
        else{
	  if(sudoku_solver(board, x, y + 1))
	    return true;
	  else
	    return false;
	}
  if(x == 1 && y == 6){
    std::cout << "Failure" << std::endl;
    printBoard(board);
  }
  board[x][y] = 0;
  return false;
}
//Check the square region
bool check_square(int board[9][9], int x, int y){
    //check top sq regions
    if(y < 3){
        //check the upper left sq.
        if(x < 3){
            for(int i{0}; i < 3; ++i){
                for(int j{0}; j < 3; ++j){
                    if(board[x][y] == board[i][j] && !current_space(x,y,i,j))
                        return false;
                }
            }
        }
            //check the upper middle sq.
        else if(x > 2 && x < 6){
            for(int i{3}; i < 6; ++i){
                for(int j{0}; j < 3; ++j){
                    if(board[x][y] == board[i][j] && !current_space(x,y,i,j))
                        return false;
                }
            }
        }
            //check the upper right corner
        else{
            for(int i{6}; i < 9; ++i){
                    for(int j{0}; j < 3; ++j){
                        if(board[x][y] == board[i][j] && !current_space(x,y,i,j))
                            return false;
                    }
            }
        }
    }
        //Check the middle sections.
    else if(y > 2 && y < 6){
        //check the middle left sq.
        if(x < 3){
            for(int i{0}; i < 3; ++i){
                for(int j{2}; j < 6; ++j){
                    if(board[x][y] == board[i][j] && !current_space(x,y,i,j))
                        return false;
                }
            }
        }
            //check the center sq.
        else if(x > 2 && x < 6){
            for(int i{3}; i < 6; ++i){
                for(int j{2}; j < 6; ++j){
                    if(board[x][y] == board[i][j] && !current_space(x,y,i,j))
                        return false;
                }
            }
        }
            //check the middle right corner
        else{
            for(int i{6}; i < 9; ++i){
                    for(int j{2}; j < 6; ++j){
                        if(board[x][y] == board[i][j] && !current_space(x,y,i,j))
                            return false;
                    }
            }
        }
    }
    //Check the lower sections.
    else{
//check the lower left sq.
        if(x < 3){
            for(int i{0}; i < 3; ++i){
                for(int j{6}; j < 9; ++j){
                    if(board[x][y] == board[i][j] && !current_space(x,y,i,j))
                        return false;
                }
            }
        }
            //check the lower middle sq.
        else if(x > 2 && x < 6){
            for(int i{3}; i < 6; ++i){
                for(int j{6}; j < 9; ++j){
                    if(board[x][y] == board[i][j] && !current_space(x,y,i,j))
                        return false;
                }
            }
        }
            //check the lower right corner
        else{
            for(int i{6}; i < 9; ++i){
                    for(int j{6}; j < 9; ++j){
                        if(board[x][y] == board[i][j] && !current_space(x,y,i,j))
                            return false;
                    }
            }
        }
    }
    return true;
}

//Check the row 
bool check_row(int board[9][9], int x, int y){
    for(int i{0}; i < 9; ++i){
        if(board[x][y] == board[i][y] && !current_space(x,y,i,y))
        return false;
    }
    return true;
}

//check the coloum 
bool check_col(int board[9][9], int x, int y){
    for(int i{0}; i < 9; ++i){
        if(board[x][y] == board[x][i] && !current_space(x,y,x,i))
            return false;
    }
    return true;
}

bool current_space(int x, int y, int i, int j){
    if(x == i && y == j)
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
