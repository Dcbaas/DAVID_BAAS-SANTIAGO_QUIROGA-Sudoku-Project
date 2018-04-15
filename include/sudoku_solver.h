



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
