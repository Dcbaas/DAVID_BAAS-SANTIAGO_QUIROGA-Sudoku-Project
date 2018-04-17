#include "sudoku_solver.h"
#include <iostream>

int main(int argc, char** argv){
  int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
                   { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
                   { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
                   { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
                   { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
                   { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
                   { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
                   { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
                   { 0, 7, 0, 0, 0, 0, 0, 3, 0 }
        };
        for(int i{0}; i < 9; ++j){
          for(int j{0}; j < 9; ++j)
            std::cout << "[" << board[i][j] <<"]";
          std::endl;
        }
        bool out = sudoku_solver(board);
        if(out)
          std::cout << "true" << std::endl;

        return 0;
}
