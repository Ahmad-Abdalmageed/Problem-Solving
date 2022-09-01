class Solution {
public:
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
  unordered_set<string> wordSet(wordList.begin(), wordList.end());
  if (wordSet.find(endWord) == wordSet.end())
    return 0;

  queue<string> wordQueue;
  wordQueue.push(beginWord);

  unordered_set<string> visited;
  visited.insert(beginWord);

  int result = 1;

  // Loop each Interval
  while (!wordQueue.empty())
  {
    int iterWindow = wordQueue.size();
    for (int iter = 0; iter < iterWindow; iter++)
    {
      string word = wordQueue.front();
      wordQueue.pop();

      if (word == endWord)
        return result;

      // Change Each Char of word
      for (int charIdx = 0; charIdx < word.size(); charIdx++)
      {
        char oldChar = word[charIdx];
        for (int change = 0; change < 26; change++)
        {
          word[charIdx] = change + 'a';
          if (wordSet.count(word) && !visited.count(word))
          {
            wordQueue.push(word);
            visited.insert(word);
          }
          word[charIdx] = oldChar;
        }
      }
    }
    result++;
  }
  return 0;
}

};