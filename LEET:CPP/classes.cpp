#include "classes.h"

// Class Conctructor
FreqStack::FreqStack() : valueMap({}), countMap({}), maxCount(0) {}

// Pop the most Frequent Element
int FreqStack::pop() {
  // get current maximum frequency value
  int res = valueMap[maxCount].top();
  // Update count value stack
  valueMap[maxCount].pop();

  // Update current maximum count value and count map
  countMap[res]--;

  // only upgrade if there are no other elements with the same count
  if (valueMap[maxCount].empty())
    maxCount--;

  return res;
}

// Push a value into the stack
void FreqStack::push(int val) {
  // upgrade the count map or add a new value
  countMap[val]++;

  // Upgrade current max count
  maxCount = std::max(maxCount, countMap[val]);

  // upgrade the value map
  valueMap[countMap[val]].push(val);
}

void FloodFill::fill(std::vector<std::vector<int>> &image, int sr, int sc,
                     int newColor) {
  if ((sr < rows && sc < cols) && (sr >= 0 && sc >= 0)) {
    int curVal = image[sr][sc];

    // Edge case where the new color is equal to the current value
    if (newColor == curVal)
      return;

    if (curVal == pxlValue) {
      // Upadte current pixel
      image[sr][sc] = newColor;

      // Fill next neighbors
      fill(image, sr - 1, sc, newColor);
      fill(image, sr + 1, sc, newColor);
      fill(image, sr, sc - 1, newColor);
      fill(image, sr, sc + 1, newColor);
    }
  }
}

std::vector<std::vector<int>>
FloodFill::floodFill(std::vector<std::vector<int>> &image, int sr, int sc,
                     int newColor) {
  // Store image array properties
  pxlValue = image[sr][sc];
  rows = image.size();
  cols = image[0].size();

  // BFS Function call
  fill(image, sr, sc, newColor);
  return image;
}

int IslandMaxArea::bfs(int row, int col) {
  // Return 0 if already seen this spot our if out of bounds
  if (row >= gRows || col >= gCols || row < 0 || col < 0 || seen[row][col] ||
      island[row][col] == 0)
    return 0;

  // Update bool map
  seen[row][col] = true;

  // Count current spot and move to the next
  return 1 + bfs(row - 1, col) + bfs(row + 1, col) + bfs(row, col - 1) +
         bfs(row, col + 1);
}

int IslandMaxArea::maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
  // Store Island Properties
  gRows = grid.size();
  gCols = grid[0].size();
  seen = std::vector<std::vector<bool>>(gRows, std::vector<bool>(gCols));
  island = grid;

  // BFS Algorithm --- Look in each connected structure for the new maximum area
  int ans = 0;
  for (int i = 0; i < gRows; i++) {
    for (int j = 0; j < gCols; j++) {
      ans = std::max(ans, bfs(i, j));
    }
  }
  return ans;
}

void Populate::dfs(Node *node, Node *next) {
  // base case current node is null
  if (node == nullptr)
    return;

  node->next = next;

  // traverse to the left
  dfs(node->left, node->right);

  // traverse to the right with next pointer pointing to
  // current node next if exist
  dfs(node->right, (node->next != nullptr) ? node->next->left : nullptr);
}

Node *Populate::connect(Node *root) {
  dfs(root, nullptr);
  return root;
}

// LEETCODE : Permutations --- Algorithms I
void Combinations::backtrack(int start, std::vector<int> &comb) {
  // Base Case
  if (comb.size() == combSize) {
    // Copy the Current Combination array and pass it to the result array
    res.push_back(std::vector<int>(comb));
    return;
  }

  for (int i = start; i <= end; i++) {
    comb.push_back(i);
    backtrack(i + 1, comb);
    comb.pop_back();
  }
}

std::vector<std::vector<int>> Combinations::combine(int n, int k) {
  // Calculate the Permutation Formula
  end = n;
  combSize = k;

  // Start the recursive backtracking solution
  std::vector<int> comb;
  backtrack(1, comb);
  return res;
}

std::vector<std::vector<int>> Permutations::permute(std::vector<int> &nums) {
  // Store information
  permutation = std::vector<int>(nums);

  // Call the Backtracking Solution
  backtrack(0);
  return result;
}

void Permutations::backtrack(int begin) {
  // Base Case
  if (begin >= permutation.size()) {
    result.push_back(permutation);
    return;
  }

  // Each loop we swap the first element with each other element
  // and each recursive call swap the swapped elements with their
  // next element untill begin reaches the end
  for (int i = begin; i < permutation.size(); i++) {
    std::swap(permutation[begin], permutation[i]);
    backtrack(begin + 1);

    // The Backtracking part where we reset the array in order to begin the next
    // loop and preserve the First Element in its place
    std::swap(permutation[begin], permutation[i]);
  }
}

void LetterPermutation::dfs(int pos) {
  // Base Case
  if (pos == input.size()) {
    res.push_back(input);
    return;
  }
  dfs(pos + 1);

  // Each time we have Two Options if it is a string
  // we convert to uppercase and continue or lowercase
  if (isalpha(input[pos])) {
    input[pos] =
        islower(input[pos]) ? toupper(input[pos]) : tolower(input[pos]);
    dfs(pos + 1);
  }
}

std::vector<std::string>
LetterPermutation::letterCasePermutation(std::string s) {
  // Store info
  input = std::string(s);

  // backtrack
  dfs(0);
}

int SplitArray::splitArray(std::vector<int> &nums, int m) {
  // Store Input Information
  arrNums = std::vector<int>(nums);
  groups = m;

  // Binary Seach Approach we need to find the minimum most
  // possible summation of the splitted groups
  // We define our maximum most summation to be the whole array sum
  // and the minimum most possible summation is the maximum element of the array
  int left = INT_MIN;
  int rght = 0;
  for (auto number : arrNums) {
    rght += number;
    left = std::max(left, number);
  }
  int res = rght;

  while (left <= rght) {
    int mid = left + ((rght - left) / 2);

    if (canSplit(mid)) {
      // If we can split the array into subarrays which has
      // a maximum sum less than the mid then we update our
      // parameters
      res = mid;
      rght = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return res;
}

bool SplitArray::canSplit(int candidate) {
  int arrCount = 0;
  int curSum = 0;
  // Check if we can split the array into sub arrays
  // whose maximum summation is smaller than the candidate result

  for (auto number : arrNums) {
    curSum += number;
    if (curSum > candidate) {
      arrCount += 1;
      curSum = number;
    }
  }
  return arrCount + 1 <= groups;
}

bool PalindromeByRem::validPalindrome(std::string s) {
  // Two Pointers Approach
  int left = 0;
  int rght = s.size() - 1;

  while (left < rght) {
    if (s[left] != s[rght])
      return (isPalindrome(left, rght - 1, s) ||
              isPalindrome(left + 1, rght, s));
    left++;
    rght--;
  }
  // THere is No mismatch in the whole String so
  return true;
}

bool PalindromeByRem::isPalindrome(int left, int rght, std::string s) {
  bool isPalindrom = true;

  // Two Pointers Approach
  while (left < rght) {
    // If Mismatch Return False
    if (s[left] != s[rght])
      return !isPalindrom;

    // Advance both Pointers
    left++;
    rght--;
  }
  return isPalindrom;
}

KthLargest::KthLargest(int k, std::vector<int> &nums) {
  // Initialize the Min Heap
  this->k = k;
  this->minHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>(
      nums.begin(), nums.end());

  while (this->minHeap.size() > this->k) {
    // Removing Smaller Elements
    this->minHeap.pop();
  }
}

int KthLargest::add(int val) {
  this->minHeap.push(val);

  if (this->minHeap.size() > this->k)
    this->minHeap.pop();
  return this->minHeap.top();
}

std::vector<int> BinarySearchDouble::searchRange(std::vector<int> &nums,
                                                 int target) {
  // Call The Binary Search Algorithm Twice
  int left = binarySearch(nums, target, true);
  int rght = binarySearch(nums, target, false);

  return {left, rght};
}

int BinarySearchDouble::binarySearch(std::vector<int> nums, int target,
                                     bool leftBias) {
  // Regular Binary Search
  int left = 0;
  int rght = nums.size() - 1;
  int idx = -1;

  while (left <= rght) {
    int mid = left + (rght - left) / 2;

    if (target < nums[mid])
      rght = mid - 1;
    else if (target > nums[mid])
      left = mid + 1;
    else {
      idx = mid;
      if (leftBias)
        rght = mid - 1;
      else
        left = mid + 1;
    }
  }

  return idx;
}

std::vector<int> StringAngrams::findAnagrams(std::string s, std::string p) {
  // Base Case Check
  if (p.size() > s.size())
    return {};

  // Initialize both Hashmaps
  std::map<char, int> sCountMap;
  std::map<char, int> pCountMap;

  std::vector<int> res;
  // Count the Frequencies in the First String and add the
  // Frequencies of the First Window in the second string
  int ctr = 0;
  for (auto c : p) {
    pCountMap[c]++;
    sCountMap[s[ctr]]++;
    ctr++;
  }

  // Add the First
  if (compMaps(sCountMap, pCountMap)) {
    res.push_back(0);
  }

  int i = 0;
  for (int j = p.size(); j < s.size(); j++) {
    sCountMap[s[j]]++;
    sCountMap[s[i]]--;

    // Remove the Character if already Reached 0 Counts
    if (sCountMap[s[i]] == 0)
      sCountMap.erase(s[i]);

    // Increment the left ptr to the next position
    i++;

    if (compMaps(sCountMap, pCountMap))
      res.push_back(i);
  }
  return res;
}

template <typename Map>
bool StringAngrams::compMaps(Map const &leftMap, Map const &rghtMap) {
  return leftMap.size() == rghtMap.size() &&
         std::equal(leftMap.begin(), leftMap.end(), rghtMap.begin());
}

int CountIslands::numIslands(std::vector<std::vector<char>> &grid) {
  if (grid.empty())
    return 0;

  gridRows = grid.size();
  gridCols = grid[0].size();
  int islandsCount = 0;

  gridIsland = grid;
  seen = std::vector<std::vector<bool>>(gridRows, std::vector<bool>(gridCols));

  for (int r = 0; r < gridRows; r++) {
    for (int c = 0; c < gridCols; c++) {
      if (grid[r][c] == '1' && !seen[r][c]) {
        bfs(r, c);
        islandsCount++;
      }
    }
  }
  return islandsCount;
}
void CountIslands::bfs(int row, int col) {
  std::queue<std::pair<int, int>> neighbors;
  std::vector<std::vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  seen[row][col] = 1;
  neighbors.push({row, col});

  while (!neighbors.empty()) {
    int r = neighbors.front().first;
    int c = neighbors.front().second;
    neighbors.pop();
    for (auto direction : directions) {
      int dr = r + direction[0];
      int dc = c + direction[1];

      if (dr >= 0 && dr < gridRows && dc >= 0 && dc < gridCols &&
          gridIsland[dr][dc] == '1' && !seen[dr][dc]) {
        neighbors.push({dr, dc});
        seen[dr][dc] = 1;
      }
    }
  }
}

int NumberOfIslands::findCircleNum(std::vector<std::vector<int>> &isConnected) {
  visited = std::vector<bool>(isConnected.size());
  int islandsCount = 0;
  for (int city = 0; city < isConnected.size(); city++) {
    if (!visited[city]) {
      bfs(isConnected, city);
      islandsCount++;
    }
  }
  return islandsCount;
}
void NumberOfIslands::bfs(std::vector<std::vector<int>> &isConnected, int cur) {
  for (int nextCity = 0; nextCity < isConnected.size(); nextCity++) {
    if (isConnected[cur][nextCity] && !visited[nextCity]) {
      visited[nextCity] = 1;
      bfs(isConnected, nextCity);
    }
  }
}

bool IsSubTree::isSubtree(TreeNode *root, TreeNode *subRoot) {
  if (subRoot == nullptr)
    return true;
  if (root == nullptr)
    return false;

  if (isSameTree(root, subRoot))
    return true;
  return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}

bool IsSubTree::isSameTree(TreeNode *root, TreeNode *subRoot) {
  if (root == nullptr && subRoot == nullptr)
    return true;
  if (root != nullptr && subRoot != nullptr && root->val == subRoot->val)
    return (isSameTree(root->left, subRoot->left) &&
            isSameTree(root->right, subRoot->right));
  return false;
}

MyStack::MyStack() {}
void MyStack::push(int x) {
  // Add Input to Object Queue
  this->qStack.push(x);
  int ctr = this->qStack.size();
  while (ctr > 1) {
    int temp = this->qStack.front();
    this->qStack.pop();
    this->qStack.push(temp);
    ctr--;
  }
}

int MyStack::pop() {
  int temp = this->qStack.front();
  this->qStack.pop();
  return temp;
}
int MyStack::top() { return this->qStack.front(); }
bool MyStack::empty() { return this->qStack.empty(); }
