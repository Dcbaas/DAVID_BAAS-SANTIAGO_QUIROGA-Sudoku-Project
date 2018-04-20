#include <iostream>
/******************************************************************************
 * The sudoku_solver.h solves a sudoku puzzle using backtracing
 *
 * Author: David Baas, Santiago Quiroga
 * Version: 4/18/2018
 ******************************************************************************/
bool check_square(int board[9][9], int row, int col);
bool check_row(int board[9][9], int row, int col);
bool check_col(int board[9][9], int row, int col);
bool current_space(int row, int col, int i, int j);
bool sudoku_solver(int board[9][9], int row, int col);
bool sudoku_solver(int board[9][9]);
void printBoard (int array[9][9]);
void clearScreen();

 /******************************************************************************
 * This sudoku_solver function is a driver function called by the main method
 * to start using the second sudoku_solver function
 * Parameter: board The current broard.
 ******************************************************************************/
bool sudoku_solver(int board[9][9]){
    return sudoku_solver(board,0,0);
}

/******************************************************************************
* The sudoku_solver function takes the board and linnerally adds numbers to
* each space. It then verifies if the number entered is valid. If it is, it
* recursively calls itself to look at the next space. If all possible numbers
* for a given space are found invalid the function recurses back on itself
* to attempt to solve the sudoku board until it is finished
*
* Parameter: board The current broard
* Parameter: row to check
* Parameter: coloum to check.
* Returns true if the board is solved, false otherwise.
******************************************************************************/
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

/******************************************************************************
* The check_square function looks at the square region of the space being
* manipulated and checks if there are any duplicate values.
*
* Parameter: board The current broard
* Parameter: row to check
* Parameter: coloum to check.
* Return: True if the there is not conflict. False otherwise
******************************************************************************/
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

/******************************************************************************
* The check_row function looks at the row of the space being
* manipulated and checks if there are any duplicate values.
*
* Parameter: board The current broard
* Parameter: row to check
* Parameter: coloum to check.
* Return: True if the there is not conflict. False otherwise
******************************************************************************/
bool check_row(int board[9][9], int row, int col){
    for(int i{0}; i < 9; ++i){
        if(board[row][col] == board[i][col] && !current_space(row,col,i,col)){
          return false;
        }
    }
    return true;
}

/******************************************************************************
* The check_square function looks at the coloum of the space being
* manipulated and checks if there are any duplicate values.
*
* Parameter: board The current broard
* Parameter: row to check
* Parameter: coloum to check.
* Return: True if the there is not conflict. False otherwise
******************************************************************************/
bool check_col(int board[9][9], int row, int col){
    for(int i{0}; i < 9; ++i){
        if(board[row][col] == board[row][i] && !current_space(row,col,row,i))
            return false;
    }
    return true;
}

/******************************************************************************
* Checks if the space being is the space being manipulated.
*
* Parameter the row being manipulated
* Parameter: the col being manipulated
* Parameter: The row being checked
* Parameter: the col being checked
* Return: True if the there is not conflict. False otherwise
******************************************************************************/
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
