class Solution {
public:
  // LEETCODE: 36. Valid Sudoku
  bool isValidSudoku(vector<vector<char>> &board)
  {
    //  Create Flags for each condition
    std::vector<std::vector<bool>> cFlag(9, std::vector<bool>(9, false));
    std::vector<std::vector<bool>> kFlag(9, std::vector<bool>(9, false));
    std::vector<std::vector<bool>> rFlag(9, std::vector<bool>(9, false));

    for (int r = 0; r < 9; r++)
    {
      for (int c = 0; c < 9; c++)
      {
        if (board[r][c] != '.')
        {
          int num = board[r][c] - '0' - 1;
          /*
          *  For the Conversion of the 2d index to 1d index we use the
          *  following eq:
          *  x1D = row * row_size + col >>>>> concatenating rows
          *
          *
          *  To divide the board into 3 peaces each row we divide by 3
          */

          int k = (r / 3) * 3  + c / 3;
          if (rFlag[r][num] || cFlag[c][num] || kFlag[k][num])
            return false;
          rFlag[r][num] = cFlag[c][num] = kFlag[k][num] = true;
        }
      }
    }
    return true;
  }

};