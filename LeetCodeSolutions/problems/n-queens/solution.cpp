class Solution
{
public:
  std::vector<std::vector<std::string>> solveNQueens(int n);

private:
  int _n;
  std::set<int> _visitedCols;
  std::set<int> _visitedNDiagonals;
  std::set<int> _visitedPDiagonals;
  std::vector<std::string> _board;
  std::vector<std::vector<std::string>> _result;

  void backtrack(int curRow);
};

void Solution::backtrack(int curRow)
{
  // Reached End Row
  if (curRow == _n)
  {
    _result.push_back(_board);
    return;
  }

  // Loop Cols
  for (int col = 0; col < _n; col++)
  {
    // Skip Attack Spots
    if (_visitedCols.find(col) != _visitedCols.end() ||
        _visitedNDiagonals.find(curRow - col) != _visitedNDiagonals.end() ||
        _visitedPDiagonals.find(curRow + col) != _visitedPDiagonals.end())
    {
      continue;
    }

    // Mark Attack Spots
    _visitedCols.insert(col);
    _visitedNDiagonals.insert(curRow - col);
    _visitedPDiagonals.insert(curRow + col);

    _board[curRow][col] = 'Q';

    // Back Track

    // Loop Rows
    backtrack(curRow + 1);

    _visitedCols.erase(col);
    _visitedNDiagonals.erase(curRow - col);
    _visitedPDiagonals.erase(curRow + col);

    _board[curRow][col] = '.';
  }
}

std::vector<std::vector<std::string>> Solution::solveNQueens(int n)
{
  _n = n;

  // Create nXn Board
  std::string row = "";
  for (int i = 0; i < n; i++)
  {
    row += '.';
  }
  _board = std::vector<std::string>(n, row);

  backtrack(0);
  return _result;
}

