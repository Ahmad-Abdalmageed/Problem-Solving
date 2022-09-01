class Solution
{
public:
  vector<string> findItinerary(vector<vector<string>> &tickets);

private:
  unordered_map<string, std::multiset<string>> _adjacencyList;
  vector<string> _route;
  void dfs(string start);
};


vector<string> Solution::findItinerary(vector<vector<string>> &tickets)
{
  // Build sorted Adjacency List
  for (auto const &ticket : tickets)
  {
    _adjacencyList[ticket[0]].insert(ticket[1]);
  }
  dfs("JFK");

  // Insertion in the Multiset follows a Descending Sorted Order
  // To order in smallest Lexical Order we reverse the Array
  std::reverse(_route.begin(), _route.end());
  return _route;
}

void Solution::dfs(string start)
{
  // Get First String in Order of the Multiset

  while (!_adjacencyList[start].empty())
  {
    string destination = *_adjacencyList[start].begin();

    // Visited-Like Solution to multidirectional destinations
    _adjacencyList[start].erase(_adjacencyList[start].begin());
    dfs(destination);
  }
  // Add the route to Results
  _route.push_back(start);
}
