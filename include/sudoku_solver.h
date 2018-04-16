



int[][] sudoku_solver(int board[][]){
 return sudoku_solver(board,0,0) 
}

int[][] sudoku_solver(int board[][], int x, int y,int cover_cells){
  //Base Case Return the board if the coverCells are 82 
  if(cover_cells == 82)
    return board;

  //Check if the x counter has gone over 9 and turnover
  if(x == 9){
    y += 1;
    x = 0;
  }
  //If the observed cell is covered.
  if(board[x][y] != 0)
    return sudoku_solver(board, x+1, y, cover_cells + 1);
}

bool check_square(int board[][], int x, int y,){
  //check top sq regions
  if(y <=2){
    //check the upper left sq.
    if(x <=2){
      for(int i{0}; i < 3; ++i){
        for(int j{0}; j < 3; ++j){
          if(board[x][y] == board[i][j]
            return false;
        }
      }
    }
    //check the upper middle sq.
    else if(x > 2 && x < 6){
      for(int i{3}; i < 6; ++i){
        for(int j{0}; j < 3; ++j){
          if(board[x][y] == board[i][j])
            return false;
        }
      }
    }
    //check the upper right corner
    else{
      for(int i{6}; i < 9; ++i{
        for(int j{0}; j < 3; ++j){
          if(board[x][y] == board[i][j])
            return false; 
        }
      }
    }
  }
  //Check the middle row.        
  else if(y > 2 && y < 6){
    //check the middle left sq.
    if(x <=2){
      for(int i{0}; i < 3; ++i){
        for(int j{2}; j < 6; ++j){
          if(board[x][y] == board[i][j]
            return false;
        }
      }
    }
    //check the center sq.
    else if(x > 2 && x < 6){
      for(int i{3}; i < 6; ++i){
        for(int j{2}; j < 6; ++j){
          if(board[x][y] == board[i][j])
            return false;
        }
      }
    }
    //check the middle right corner
    else{
      for(int i{6}; i < 9; ++i{
        for(int j{2}; j < 6; ++j){
          if(board[x][y] == board[i][j])
            return false; 
        }
      }
    }
  }
  else{
//check the lower left sq.
    if(x <=2){
      for(int i{0}; i < 3; ++i){
        for(int j{6}; j < 9; ++j){
          if(board[x][y] == board[i][j]
            return false;
        }
      }
    }
    //check the lower middle sq.
    else if(x > 2 && x < 6){
      for(int i{3}; i < 6; ++i){
        for(int j{6}; j < 9; ++j){
          if(board[x][y] == board[i][j])
            return false;
        }
      }
    }
    //check the lower right corner
    else{
      for(int i{6}; i < 9; ++i{
        for(int j{6}; j < 9; ++j){
          if(board[x][y] == board[i][j])
            return false; 
        }
      }
    }
  }
  return true;
}

bool check_row(int board[][], int x int y){
  for(int i{0}; i < 9; ++i){
   if(board[x][y] == board[i][y])
     return false;
  }
  return true;
}

bool check_col(int board[][], int x, int y){
  for(int i{0}; i < 9; ++i){
    if(board[x][y] == board[x][i])
      return false;
  }
  return true;
}

bool current_space(int x, int y, int i, int j){
  if(x == i && y == j)
    return true;
  return false; 
}
