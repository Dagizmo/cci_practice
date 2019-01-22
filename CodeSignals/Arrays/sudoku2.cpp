#include <vector>

using namespace std;

bool sudoku2(std::vector<std::vector<char>> grid) {
    bool validateBox[9][10] = { false };
    bool validateRow[9][10] = { false };
    bool validateCol[9][10] = { false };
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; ++j)
        {
            if ( grid[i][j] != '.' )
            {
                int number = grid[i][j] - '0';
                int box = j/3 + (( i/3) * 3) ;
                
                if (validateBox[box][number]  || validateRow[i][number] || validateCol[j][number] )
                {
                   return false;
                }
                else
                {
                    validateBox[box][number] = true;
                    validateRow[i][number] = true;
                    validateCol[j][number] = true;                 
                }
              
            }
        }
    }
    
    return true;
}
