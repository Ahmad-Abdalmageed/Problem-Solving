class TrieNode
{
public:
  TrieNode *children[26];
  bool endOfWord;

  TrieNode()
  {
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    endOfWord = false;
  }
};

class Solution {
public:
  std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words);

private:
  TrieNode *root = new TrieNode();
  std::vector<std::string> result;
  int boardRows;
  int boardCols;

  void insert(std::string word);
  void dfs(int curRow, int curCol, std::vector<std::vector<char>> &board, std::string word, TrieNode *curNode);
};


void Solution::insert(std::string word)
{
  TrieNode *node = root;
  int curr = 0;

  for (int i = 0; i < word.size(); i++)
  {
    curr = word[i] - 'a';
    if (node->children[curr] == NULL)
    {
      node->children[curr] = new TrieNode();
    }
    node = node->children[curr];
  }

  node->endOfWord = true;
}

void Solution::dfs(int curRow, int curCol, std::vector<std::vector<char>> &board, std::string word, TrieNode *curNode)
{
  // Out of Bounds Codition
  if (curRow < 0 || curRow >= boardRows || curCol < 0 || curCol >= boardCols ||
      board[curRow][curCol] == '#')
  {
    return;
  }

  char curBoardChar = board[curRow][curCol];
  // Get Current Prefix
  curNode = curNode->children[curBoardChar - 'a'];

  // Prefix not found
  if (curNode == nullptr)
    return;

  // Add current position on board to the backtracking variable
  word += board[curRow][curCol];

  // Add to result if reached an end of word
  if (curNode->endOfWord)
  {
    result.push_back(word);
    curNode->endOfWord = false; // Prevents searching the same word twice
  }

  // mark positon as visited
  board[curRow][curCol] = '#';

  dfs(curRow + 1, curCol, board, word, curNode);
  dfs(curRow - 1, curCol, board, word, curNode);
  dfs(curRow, curCol + 1, board, word, curNode);
  dfs(curRow, curCol - 1, board, word, curNode);

  // Backtracking
  board[curRow][curCol] = curBoardChar;
}

std::vector<std::string> Solution::findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
{
  // Create the Trie
  for (auto const &word : words)
  {
    insert(word);
  }

  //  Get Board Size
  boardRows = board.size();
  boardCols = board[0].size();

  TrieNode *startNode = root;

  // DFS for every Character on board
  for (int i = 0; i < boardRows; i++)
  {
    for (int j = 0; j < boardCols; j++)
    {
      dfs(i, j, board, "", startNode);
    }
  }

  return result;
}
