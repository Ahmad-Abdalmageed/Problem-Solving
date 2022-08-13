class Solution
{
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word);

private:
  std::vector<std::vector<char>> board_;
  int boardCols_;
  int boardRows_;

  bool backtrack(std::string word, int curIdx, int curRow, int curCol);
};


bool Solution::exist(std::vector<std::vector<char>> &board, std::string word)
{
  board_ = board;
  boardRows_ = board.size();
  boardCols_ = board[0].size();

  // For every char on board
  for (int i = 0; i < boardRows_; i++)
  {
    for (int j = 0; j < boardCols_; j++)
    {
      // Skip Current Positon if not matches the first char in word
      if (board_[i][j] == word[0])
      {
        if (backtrack(word, 0, i, j))
        {
          return true;
        }
      }
    }
  }

  // REached end without match
  return false;
}
bool Solution::backtrack(std::string word, int curIdx, int curRow, int curCol)
{
  // out of Bounds or current board char is not equal to char in word at curIdx
  if (curRow < 0 || curCol < 0 || curRow >= boardRows_ || curCol >= boardCols_ || board_[curRow][curCol] != word[curIdx])
  {
    return false;
  }

  // Current Idx reached end of word
  if (curIdx == word.size() - 1)
  {
    return true;
  }

  // Mark Visited Spot
  board_[curRow][curCol] = '#';

  // DFS into al four directions
  if (backtrack(word, curIdx + 1, curRow + 1, curCol) ||
      backtrack(word, curIdx + 1, curRow - 1, curCol) ||
      backtrack(word, curIdx + 1, curRow, curCol + 1) ||
      backtrack(word, curIdx + 1, curRow, curCol - 1))
  {
    return true;
  }

  // Backtrack visited Spot
  board_[curRow][curCol] = word[curIdx];

  // Reached end without finding match
  return false;
}
