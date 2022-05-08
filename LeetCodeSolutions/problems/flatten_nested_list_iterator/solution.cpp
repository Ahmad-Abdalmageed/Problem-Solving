/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(std::vector<NestedInteger> &nestedList);
    int next();
    bool hasNext();
    void dfs(int pos, std::vector<NestedInteger> const &nestedList);
private:
    std::queue<int> nestedList;
};

NestedIterator::NestedIterator(std::vector<NestedInteger> &nestedList){
  // Initialize Iterator's Queue for flatten integers
  this->dfs(0, nestedList);
}

int NestedIterator::next(){
  // Return the Queue's Top and Pop it
  int next = this->nestedList.front();
  this->nestedList.pop();
  return next;
}

bool NestedIterator::hasNext(){
  // Check Empty Queue
  return !this->nestedList.empty();
}

void NestedIterator::dfs(int pos, std::vector<NestedInteger> const &nestedList){
  // Base Case: Position out of bounds
  if(pos == nestedList.size()) return;

  // Add to the Queue if the current List is a Single Integer
  if(nestedList[pos].isInteger()) this->nestedList.push(nestedList[pos].getInteger());
  else dfs(0, nestedList[pos].getList());
  dfs(pos+1, nestedList);
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */