#include <iostream>
bool check_square(int board[9][9], int row, int col);
bool check_row(int board[9][9], int row, int col);
bool check_col(int board[9][9], int row, int col);
bool current_space(int row, int col, int i, int j);
bool sudoku_solver(int board[9][9], int row, int col);
bool sudoku_solver(int board[9][9]);
void printBoard (int array[9][9]);
void clearScreen();

bool sudoku_solver(int board[9][9]){
    return sudoku_solver(board,0,0);
}

bool sudoku_solver(int board[9][9], int row, int col) {
    //Base Case Return the board if the coverCells are 80
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
	  else{
	    return false;
	 }
 }

  board[row][col] = 0;
  return false;
}

//Check the square region
bool check_square(int board[9][9], int row, int col){
  int row_lower{0};
  int row_upper{0};
  int col_lower{0};
  int col_upper{0};

  //Check the row range
  if(row < 3){
    row_lower = 0;
    row_upper = 2;
  }
  else if(row >= 3 && row < 6){
    row_lower = 3;
    row_upper = 5;
  }
  else{
    row_lower = 6;
    row_upper = 8;
  }

  //Check the col range
  if(col < 3){
    col_lower = 0;
    col_upper = 2;
  }
  else if(col >= 3 && col < 6){
    col_lower = 3;
    col_upper = 5;
  }
  else{
    col_lower = 6;
    col_upper = 8;
  }

  //Check the square.
  for(int it_row = row_lower; it_row <= row_upper; ++it_row){
    for(int it_col = col_lower; it_col <= col_upper; ++it_col){
      if(!current_space(row, col, it_row, it_col) && board[row][col] == board[it_row][it_col])
        return false;
    }
  }
  return true;
}

//Check the row
bool check_row(int board[9][9], int row, int col){
    for(int i{0}; i < 9; ++i){
        if(board[row][col] == board[i][col] && !current_space(row,col,i,col)){
          return false;
        }
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

void clearScreen(){
  std::cout << " \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n " << std::endl;
}
