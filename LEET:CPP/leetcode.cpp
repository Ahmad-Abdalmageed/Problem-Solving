/*
 * LEET CODE Problems Solution
 * LIST : Algorithms
 *
 */

#include "leetdef.hpp"
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target);
int removeDuplicates(vector<int> &nums);
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);
string longestPalindrome(string s);
string convert(string s, int numRows);
int reverse(int x);
int myAtoi(string s);
bool isPalindrome(int x);
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
bool isMatch(string s, string p);
bool find(int i, int j, string s, string p);
int maxArea(vector<int> &height);
string intToRoman(int num);
int romanToInt(string s);
string longestCommonPrefix(vector<string> &strs);
vector<vector<int>> threeSum(vector<int> &nums);
int threeSumClosest(vector<int> &nums, int target);
int majorityElement(vector<int> &nums);
vector<string> letterCombinations(string digits);
int compareVersion(string version1, string version2);
vector<int> countBits(int n);
bool isSubsequence(string s, string t);
int numberOfArithmeticSlices(vector<int> &nums);
bool isValid(string s);
double champagneTower(int poured, int query_row, int query_glass);
vector<string> generateParenthesis(int n);
int deleteAndEarn(vector<int> &nums);
ListNode *mergeKLists(vector<ListNode *> &lists);
ListNode *mergeLists(ListNode *head1, ListNode *head2);
ListNode *swapPairs(ListNode *head);
int countOrders(int n);
vector<int> lps(string needle);
bool validateStackSequences(vector<int> &pushed, vector<int> &popped);
vector<int> sortedSquares(vector<int> &nums);
void rotate(vector<int> &nums, int k);
ListNode *rotateRight(ListNode *head, int k);
void moveZeroes(vector<int> &nums);
vector<int> twoSum2(vector<int> &numbers, int target);
void reverseString(vector<char> &s);
string reverseWords(string s);
int scoreOfParentheses(string s);
string removeDuplicateLetters(string s);
bool match(vector<int> a, vector<int> b);
int lengthOfLongestSubstring(string s);
int minDominoRotations(vector<int> &tops, vector<int> &bottoms);
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2);
vector<int> partitionLabels(string s);
string getSmallestString(int n, int k);
vector<vector<int>> updateMatrix(vector<vector<int>> &mat);
int brokenCalc(int startValue, int target);
ListNode *reverseList(ListNode *head);
int numRescueBoats(vector<int> &people, int limit);
int twoCitySchedCost(vector<vector<int>> &costs);
vector<int> kWeakestRows(vector<vector<int>> &mat, int k);
bool searchMatrix(vector<vector<int>> &matrix, int target);
bool checkPossibility(vector<int> &nums);
ListNode *swapNodes(ListNode *head, int k);
int lastStoneWeight(vector<int> &stones);
int calPoints(vector<string> &ops);
vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k);
int findMin(vector<int> &nums);
int search(vector<int> &nums, int target);
int findPeakElement(vector<int> &nums);
ListNode *deleteDuplicates(ListNode *head);
bool backspaceCompare(string s, string t);
vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                         vector<vector<int>> &secondList);

void logIntArr(vector<int>);
void logString(string s);
void logMap(map<int, int> m);
int getMax(vector<int> nums, int part);
int getMin(vector<int> nums, int part);

/* Main Programm
 * Usage: Unit Tests and Code Checks
 */

int main(int argc, const char **argv) {
  std::cout << "HELLO LEETCODE !! "
            << "/n";
  std::string s = "";
  std::cout << s.size();
  return 0;
}
// LEETCODE : 986. Interval List Intersections --- ALGORITHMS II
vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                         vector<vector<int>> &secondList) {
  // Find the Intersection between every interval
  // Two Pointers Approach
  int i = 0, j = 0;
  std::vector<std::vector<int>> res;

  while (i < firstList.size() && j < secondList.size()) {
    // Find A[i] N B[j]
    // left -- Startpoint
    // rght -- Endpoint
    int left = std::max(firstList[i][0], secondList[j][0]);
    int rght = std::min(firstList[i][1], secondList[j][1]);

    if (left <= rght) {
      res.push_back({left, rght});
    }

    // Remove the Interval with smallest endpoint
    if (firstList[i][1] < secondList[j][1])
      i++;
    else
      j++;
  }
  return res;
}

// LEETCODE: 844. Backspace String Compare -- ALGORITHMS II
bool backspaceCompare(string s, string t) {
  // Two Pointers Approach --- REVERSED Iteration
  int sPtr = s.size() - 1, tPtr = t.size() - 1;
  int skipS = 0, skipT = 0;

  while (sPtr >= 0 || tPtr >= 0) {
    // Find Position of next non Backspace Char
    while (sPtr >= 0) {
      if (s[sPtr] == '#') {
        skipS++;
        sPtr--;
      } else if (skipS > 0) {
        skipS--;
        sPtr--;
      } else {
        // Found Next Non Back Space
        break;
      }
    }

    while (tPtr >= 0) {
      if (t[tPtr] == '#') {
        skipT++;
        tPtr--;
      } else if (skipT > 0) {
        skipT--;
        tPtr--;
      } else {
        // Found Next Non Back Space
        break;
      }
    }

    // Compare Found Chars
    if (sPtr >= 0 && tPtr >= 0 && s[sPtr] != t[tPtr])
      return false;
    if ((sPtr >= 0) != (tPtr >= 0))
      return false;

    sPtr--;
    tPtr--;
  }
  return true;
}

// LEETCODE: 82. Remove Duplicates from Sorted List II --- ALGORITHM II
ListNode *deleteDuplicates(ListNode *head) {
  // Create a Dummy Node
  ListNode *dummy = new ListNode(0, head);
  // initiate Two Pointers
  ListNode *left = dummy;
  ListNode *rght = head;

  while (rght != nullptr) {

    // Move Both Pointers untill duplicate Found
    while (rght->next != nullptr && rght->next->val != rght->val) {
      rght = rght->next;
      left = left->next;
      std::cout << rght->val << "\n";
      std::cout << left->val << "\n";
    }

    // Duplicate Found, Move Only Rght
    while (rght != nullptr && rght->next->val == rght->val) {
      rght = rght->next;
    }

    // Delete Nodes
    left->next = rght->next;
    rght = rght->next;
  }
  return dummy->next;
}

// LEETCODE: Find Peak Element --- ALGORITHMS II
int findPeakElement(vector<int> &nums) {
  // Binary Search Algorithm
  int left = 0;
  int rght = nums.size() - 1;

  while (left < rght) {
    int mid = left + (rght - left) / 2;

    // Find Peak
    if (nums[mid] > nums[mid + 1])
      rght = mid;
    else
      left = mid + 1;
  }
  return left;
}

// LEETCODE: Find Minimum in Sorted Rotated Array --- ALGORITHM II
int findMin(vector<int> &nums) {
  // Binary Search Algorithm
  int left = 0;
  int rght = nums.size() - 1;
  int res = INT_MAX;

  while (left <= rght) {
    // Base Case if Array is Sorted
    if (nums[left] <= nums[rght]) {
      res = min(nums[left], res);
      break;
    }
    int mid = left + (rght - left) / 2;

    // Update the current Result
    if (nums[mid] < res)
      res = nums[mid];

    if (nums[mid] >= nums[left])
      left = mid + 1;
    else
      rght = mid - 1;
  }
  return res;
}

// LEETCODE: 33. Search in Rotated Sorted Array
int search(vector<int> &nums, int target) {
  // Discrete Binary Search
  int left = 0;
  int rght = nums.size() - 1;

  // Binary Search
  while (left <= rght) {
    int mid = left + (rght - left) / 2;

    // Case Found
    if (target == nums[mid])
      return mid;

    // Two Casees : 1 - Left Sorted Portion
    if (nums[left] <= nums[mid]) {
      if (target > nums[mid] || target < nums[left])
        left = mid + 1;
      else
        rght = mid - 1;
    } else {
      if (target < nums[mid] || target > nums[rght])
        rght = mid - 1;
      else
        left = mid + 1;
    }
  }

  // Case Not Found
  return -1;
}

// LEETCODE: Shift 2D Grid -- DAILY
vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
  // Store Grid Informations
  int rows = grid.size(), cols = grid[0].size();
  vector<vector<int>> res(rows, vector<int>(cols));

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int pos1D = (r * cols + c + k) % (rows * cols);
      int newR = pos1D / cols, newC = pos1D % cols;
      res[newR][newC] = grid[r][c];
    }
  }
  return res;
}

// LEETCODE: Baseball Game
int calPoints(vector<string> &ops) {
  // Create Score Stack
  std::stack<int> score;
  int res = 0;

  // Loop the Given Operations and operate on stack
  for (auto op : ops) {
    // Operations
    if (op == "D")
      score.push(score.top() * 2);
    else if (op == "C")
      score.pop();
    else if (op == "+") {
      int last_score = score.top();
      score.pop();
      int prev_score = score.top();
      score.push(last_score);
      score.push(last_score + prev_score);
    }

    // Score Extraction
    else {
      score.push(std::stoi(op));
    }
  }

  while (!score.empty()) {
    res += score.top();
    score.pop();
  }
  return res;
}

// LEET CODE: REverse Bits -- Algorithm I
uint32_t reverseBits(uint32_t n) {
  uint32_t res = 0;

  for (int i = 0; i < 32; i++) {
    uint32_t bit = (n >> i) & 1;
    res |= (bit << (31 - i));
  }
  return res;
}

// LEETCODE: Triangle --- Algorithms I
int minimumTotal(vector<vector<int>> &triangle) {
  if (triangle.empty())
    return 0;

  // Create a DP Array
  std::vector<int> dp = triangle[triangle.size() - 1];

  for (int row = triangle.size() - 1; row >= 0; row--) {
    for (int i = 0; i < triangle[row].size(); i++) {
      dp[i] = triangle[row][i] + std::min(dp[i], dp[i + 1]);
    }
  }
  return dp[0];
}

// LEETCODE: House Robber -- ALGORITHM I
int rob(vector<int> &nums) {
  int house1 = 0, house2 = 0;

  // [house1 , house2, n, n+1, n+2, ......]
  for (int n : nums) {
    int temp = std::max(n + house1, house2);
    house1 = house2;
    house2 = temp;
  }
  return house2;
}

// LEETCODE: Last Stone Weight
int lastStoneWeight(vector<int> &stones) {
  // Convert the Stones Array to /max Heap
  std::make_heap(stones.begin(), stones.end());

  while (stones.size() > 1) {
    // Take the Last two stones and smash them
    int stone1 = stones.front();
    std::pop_heap(stones.begin(), stones.end());
    stones.pop_back();

    int stone2 = stones.front();
    std::pop_heap(stones.begin(), stones.end());
    stones.pop_back();

    if (stone1 != stone2) {
      stones.push_back(stone1 - stone2);
      std::push_heap(stones.begin(), stones.end());
    }
  }
  return stones.size() ? stones.front() : 0;
}

// LEETCODE : 3SUM with multiplicity
// int threeSumMulti(vector<int>& arr, int target) {
//     // Divide into Two Problems and solve with two pointers approach
//     std::sort(arr.begin(), arr.end());
//     int mod = 10^9 + 7;
//     int ctr = 0;

//     for(int i = 0; i < arr.size()-2; i++){
//         std::vector<int> count(101, 0);
//         for(int j = i+1; j<arr.size(); j++){
//             int k = target - arr[i] - arr[j];
//             if(k>=0 && k <=100 && count[k] > 0){
//                 ctr += count[k];
//                 ctr %= mod;
//             }
//             count[arr[j]]++;
//         }
//     }
//     return ctr;
// }
int threeSumMulti(vector<int> &arr, int target) {
  // Divide into Two Problems and solve with two pointers approach
  std::sort(arr.begin(), arr.end());
  int mod = 1000000007;
  std::vector<long> count(101, 0);
  long ctr = 0;
  for (auto i : arr)
    count[i]++;

  for (int i = 0; i <= 100; i++) {
    for (int j = i; j <= 100; j++) {
      int k = target - i - j;
      if (k < 0 || k > 100)
        continue;
      if (i == j && j == k)
        ctr += (count[i] * (count[i] - 1) * (count[i] - 2)) / 6;
      else if (i == j && j != k)
        ctr += ((count[i] * (count[i] - 1)) / 2) * count[k];
      else if (i < j && j < k)
        ctr += count[i] * count[j] * count[k];
    }
  }
  return (int)(ctr % mod);
}

// LEETCODE : Swapping Nodes in Linked List-- Daily
// MEMORY LIMIT EXCEEDED
// ListNode* swapNodes(ListNode* head, int k){
//     // Store List in Array

//     std::vector<int> listData;
//     ListNode* curNode = head;

//     while(curNode!=nullptr){
//         listData.push_back(curNode->val);
//     }
//     int listSize = listData.size();

//     std::swap(listData[k-1], listData[listSize-k]);
//     curNode = head;
//     ListNode* dummy = new ListNode(0);
//     curNode = dummy;
//     for(auto val: listData){
//         curNode->next = new ListNode(val);
//         curNode= curNode->next;
//     }
//     return dummy->next;
// }
ListNode *swapNodes(ListNode *head, int k) {
  ListNode *dummy = new ListNode(0, head);
  ListNode *preLeft = dummy;
  ListNode *preRght = dummy;
  ListNode *left = head;
  ListNode *rght = head;

  for (int ctr = 0; ctr < k - 1; ctr++) {
    preLeft = left;
    left = left->next;
  }

  ListNode *curNode = left;
  while (curNode->next != nullptr) {
    preRght = rght;
    rght = rght->next;
    curNode = curNode->next;
  }

  if (left == rght)
    return head;
  preRght->next = left;
  preLeft->next = rght;
  ListNode *temp = left->next;
  left->next = rght->next;
  rght->next = temp;
  return dummy->next;
}

// LEETCODE: Next Permutation
void nextPermutation(vector<int> &nums) {
  // Find the First Decreasing element from the right
  int i = nums.size() - 2;
  while (i >= 0 && nums[i + 1] <= nums[i]) {
    i--;
  }

  // Find the Element just larger than i, if i exists
  if (i >= 0) {
    int j = nums.size() - 1;
    while (nums[j] <= nums[i]) {
      j--;
    }

    // Swap both numbers
    std::swap(nums[i], nums[j]);
  }
  std::reverse(nums.begin() + i + 1, nums.end());
}

// LEETCODE: Non-decreasing Array
bool checkPossibility(vector<int> &nums) {
  int opCount = 0;

  for (int i = 1; i < nums.size(); i++) {
    if (nums[i - 1] > nums[i]) {
      if (opCount || (i > 1 && i < nums.size() - 1) &&
                         (nums[i - 2] > nums[i] && nums[i + 1] < nums[i - 1]))
        return false;
      opCount += 1;
    }
  }
  return true;
}

// LEETCODE: Search a 2d Matrix -- Daily
bool searchMatrix(vector<vector<int>> &matrix, int target) {
  bool found = false;

  // Case where target is out of bounds
  if (target > matrix[matrix.size() - 1][matrix[0].size() - 1])
    return found;
  if (target < matrix[0][0])
    return found;

  // Binary search each row for the target
  for (auto row : matrix) {
    int i = 0;
    int j = row.size() - 1;

    // Target does not exit in this row
    if (target > row[j])
      continue;

    // if Target exists in this row search this row
    int mid = i + (j - i) / 2;

    while (!found && i < j) {

      if (row[mid] > target)
        j = mid;

      else if (row[mid < target])
        i = mid + 1;

      else
        found = true;
    }
  }

  return found;
}

// LEETCODE: the K Weakest Rows in a Matrix -- DAILY
vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
  // Store the Count of each row's Soldiers and row i idx
  std::vector<std::vector<int>> countSols;
  std::vector<int> res;

  // Find the index of the first zero in each row
  for (int row = 0; row < mat.size(); row++) {
    int left = 0;
    int rght = mat[row].size() - 1;

    while (left <= rght) {
      int mid = left + (rght - left) / 2;
      if (mat[row][mid] == 0)
        rght = mid - 1;
      else
        left = mid + 1;
    }
    // here the Count of Soldiers is the left pointer
    countSols.push_back({left, row});
  }

  // Use Two pointers approach to return the Weakest
  // First we sort the array based on the number of soldiers
  std::sort(countSols.begin(), countSols.end());

  int left = 0;
  int rght = 1;
  int count = 0;

  while (count < k && rght < countSols.size()) {
    // Move if the left is weaker
    if (countSols[rght][0] > countSols[left][0]) {
      left++;
      rght++;
    } else if (countSols[rght][0] > countSols[left][0]) {
      // Swap same Soldier count rows
      std::swap(countSols[rght], countSols[left]);
    }
    count++;
  }
  for (int i = 0; i < k; i++) {
    res.push_back(countSols[i][1]);
  }

  return res;
}

// LEETCODE: Two City Schedulling  -- Daily
int twoCitySchedCost(vector<vector<int>> &costs) {
  // Greedy Solution of finding the best candidates to go to
  // City B and based on that the remaining can go to city A
  // We Calculate how Expensive it is to send a person to city B
  // By Calculating the Difference between the cost for every person
  std::vector<std::vector<int>> diff;
  int totalCost = 0;

  // Loop and Calculate the Difference between trip to A and trip to B
  for (auto cost : costs) {
    diff.push_back({cost[1] - cost[0], cost[0], cost[1]});
  }

  // Sort the Resulting array according to the first value
  std::sort(diff.begin(), diff.end());

  // Select the lower costing trips to city A
  for (int i = 0; i < costs.size(); i++) {
    if (i < costs.size() / 2)
      totalCost += diff[i][2];
    else
      totalCost += diff[i][1];
  }

  return totalCost;
}

// LEETCODE: Boats to save people -- ALGORITHM I
int numRescueBoats(vector<int> &people, int limit) {
  // First Sort the people's weights
  std::sort(people.begin(), people.end());
  int boatCount = 0;
  int i = 0;
  int j = people.size() - 1;

  // as Long as the Heaviest person can share a boat with the lightest person
  // then do so , if they can't then they get their own boat
  while (i <= j) {
    // The Heavier person gets his own boat unless he can share
    boatCount++;

    if (people[i] + people[j] <= limit)
      i++;
    j--;
  }
  return boatCount;
}
// LEETCODE: Reverse a Linked list
ListNode *reverseList(ListNode *head) {
  // Base case when head == null
  if (head == nullptr)
    return nullptr;

  // Recursively reverse the nodes
  ListNode *newHead = head;

  if (head->next != nullptr) {
    // Parse to the end of the list and return the last node as the new head
    newHead = reverseList(head->next);
    // Make the last node point to the current node --- the node before
    head->next->next = head;
  }

  // turns the first node into a tail
  head->next = nullptr;

  return newHead;
}

// LEETCODE: Rotten Oranges --- ALGORITHMS I
int orangesRotting(vector<vector<int>> &grid) {
  // Create a Queue to hold rotten oranges which we can then loop
  // and calculate the time simultaniously
  std::queue<std::pair<int, int>> rotOranges = {};
  int time = 0, fresh = 0;

  int rows = grid.size(), cols = grid[0].size();

  // Append Rotten to Queue and count the Fresh Oranges
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (grid[i][j] == 1)
        fresh += 1;
      if (grid[i][j] == 2)
        rotOranges.push({i, j});
    }
  }

  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  // For each Rotten Orange append adjasent oranges to Rot queue
  // and Increase time by one unit increase
  while (!rotOranges.empty() && fresh > 0) {

    // for the First Added rotten oranges loop to add neighbors
    for (int orange = rotOranges.size(); orange >= 0; --orange) {
      // Extract Current Orange Coordinates and remove it from queue
      int oRow = rotOranges.front().first;
      int oCol = rotOranges.front().second;
      rotOranges.pop();

      // Add neighbors to the queue using dirs
      for (auto dir : dirs) {
        // Calculate neighbor coordinates
        int new_oRow = oRow + dir[0];
        int new_oCol = oCol + dir[1];

        // check boundary
        if (new_oRow < 0 || new_oRow == rows || new_oCol < 0 ||
            new_oCol == cols || grid[new_oRow][new_oCol] != 1)
          continue;

        grid[new_oRow][new_oCol] = 2;
        rotOranges.push({new_oRow, new_oCol});
        fresh -= 1;
      }
    }
    time += 1;
  }

  // Return if all oranges are rotten
  return (fresh == 0) ? time : -1;
}

// LEETCODE: Broken Calclator -- Daily
int brokenCalc(int startValue, int target) {
  // we have two options
  // First Multiply the start by 2
  // Second Decrement the resultant by one
  // while the obvious way of multiplication and
  // Subtraction is tempting but we can think backwards

  /* We can also think about it this way. From X to Y, the only way to go is
  either -1 or x2. Any such path leading to Y also means that there exists a
  path from Y back to X through +1 or /2. The key is that going from X to Y is
  not deterministic, because one can choose to x2, or -1 first and then x2.
  However, going from Y to X is deterministic, because we cannot do /2 when Y is
  an odd number. Therefore, whenever Y is an odd number, the only thing we can
  do is +1 and then /2. Therefore, going from Y to X is straightforward.
  */
  int result = startValue;
  int opCount = 0;

  while (target > startValue) {
    opCount++;
    if (target % 2 == 0)
      target++;
    else
      target /= 2;
  }
  return opCount + (startValue - target);
}

// LEETCODE: 01 Matrix
vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
  // Initialize the values needed
  int rows = mat.size();
  int cols = mat[0].size();
  std::queue<std::pair<int, int>> zeros;
  std::vector<std::vector<int>> dist(rows, vector<int>(cols, INT_MAX));

  // Loop and push each zero location inside the queue
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (mat[i][j] == 0) {
        dist[i][j] = 0;
        zeros.push({i, j});
      }
    }
  }

  // for the all neighbors arround the zero-cell
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!zeros.empty()) {
    // Extract the current zero cell
    std::pair<int, int> curr = zeros.front();
    zeros.pop();

    for (auto dir : dirs) {
      int new_r = curr.first + dir[0];
      int new_c = curr.second + dir[1];

      // Check Boundary
      if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
        // if the neighbor is equal to one and its distance in the array is
        // not updated , update it to the nearest zero distance
        if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
          dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
          zeros.push({new_r, new_c});
        }
      }
    }
  }
  return dist;
}

// LEETCODE: Smallest String given a numeric value
string getSmallestString(int n, int k) {
  std::string alpha = "_bcdefghijklmnopqrstuvwxy_";

  // Remove n spaces from the result to be replaced by a's
  k -= n;

  // intialize the resulting string with as many z's as it can take
  std::string res((k / 25), 'z');

  // If k is still larger than 25 fill with any alphabet with that number
  if (k % 25)
    res = alpha[k % 25] + res;

  // add as many a's to the prefix of the result
  return std::string(n - res.size(), 'a') + res;
}

// LEETCODE: Partition Labels --- DAILY
vector<int> partitionLabels(string s) {
  vector<int> ans;
  // Init a Vector of 26 letters that will hold the last appearence of each
  // letter in the string
  vector<int> last(26, 0);

  // Append the last appearence of each character
  for (int i = 0; i < s.size(); i++) {
    last[s[i] - 'a'] = i;
  }

  // Calculate thge size of each partition
  int j = 0, anchor = 0;
  for (int i = 0; i < s.size(); i++) {
    // j holds the last appearence of the first character in the parition
    j = max(j, last[s[i] - 'a']);

    if (i == j) {
      ans.push_back(i - anchor + 1);
      anchor = i + 1;
    }
  }
  return ans;
}

// LEETCODE: Merge Two Trees -- ALGORITHM I
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
  // Return if any of the nodes are null
  if (root1 == nullptr)
    return root2;
  if (root2 == nullptr)
    return root1;

  root1->val += root2->val;

  root1->left = mergeTrees(root1->left, root2->left);
  root1->right = mergeTrees(root1->right, root2->right);

  return root1;
}

// LEETCODE: Minimum Domino rotations
int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
  // Select the First Domino, Since there must exit at least one
  // value in the first domino common in all dominos , if none then there
  // are no possible rotations available

  vector<int> targets = {tops[0], bottoms[0]};

  for (auto target : targets) {
    int topMissing = 0;
    int bottomMissing = 0;

    for (int i = 0; i < tops.size(); i++) {
      // If neither the top or the bottom have the target then skip
      if (tops[i] != target && bottoms[i] != target)
        break;

      // Calculate the missing spots of the target
      if (tops[i] != target)
        topMissing++;
      if (bottoms[i] != target)
        bottomMissing++;

      // Return the minimum missin spots for minimum rotations applicable
      if (i == tops.size() - 1)
        return min(topMissing, bottomMissing);
    }
  }

  // If there exits no solution
  return -1;
}

// LEET CODE: Permutation in string ALGORITHMS I
bool checkInclusion(string s1, string s2) {

  // Case s1 > s2
  if (s1.size() > s2.size())
    return false;

  //  create an array of frequencies of both strings for
  // first s1 size chars
  vector<int> charCountS1(26, 0);
  vector<int> charCountS2(26, 0);

  for (int i = 0; i < s1.size(); i++) {
    charCountS1[s1[i] - 'a']++;
    charCountS2[s2[i] - 'a']++; // Contains count of first (s1.size()) elements
  }

  // Sliding window technique ... move the window and calculate current window
  // freq.
  for (int i = 0; i < s2.size() - s1.size(); i++) {
    // Return if already matches
    if (match(charCountS1, charCountS2))
      return true;

    // Move window to the right by adding and removing characters from the
    // wnidow
    charCountS2[s2[i + s1.size()] - 'a']++; // Add next char to window
    charCountS2[s2[i] - 'a']--;             // remove first char from window
  }

  // may still have not returned so last check
  return match(charCountS1, charCountS2);
}

// bool checkInclusion(string s1, string s2) {
//     // Case s1 > s2
//     if(s1.size() > s2.size()) return false;

//     //  create an array of frequencies of the first String
//     vector<int> charCountS1(26, 0);
//     for(char a: s1){
//         charCountS1[int(a) - int('a')]++;
//     }

//     // For each window os s1 size in s2 find and calculate chars frequencies
//     // and compare these counts to s1 counts return true if identical
//     for(int i = 0; i <= (s2.size() - s1.size()) ; i++){
//         // create new windows array
//         vector<int> charCountS2(26, 0);

//         // count frequencies
//         for(int j = 0 ; j < s1.size(); j++){
//             charCountS2[ s2[i + j] - 'a']++;
//         }
//         // True if matches
//         if(match(charCountS1, charCountS2)) return true;
//     }
//     return false;
// }

bool match(vector<int> a, vector<int> b) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i])
      return false;
  }
  return true;
}

// LEET CODE: Longest substring without repetition ALGORITHMS I
int lengthOfLongestSubstring(string s) {
  int res = 0;
  int i = 0;
  set<char> found;

  for (int j = 0; j < s.size(); j++) {
    //  remove Repeating chars from substring and count current lenght
    while (found.find(s[j]) != found.end()) {
      found.erase(s[i]);
      i++;
    }
    found.insert(s[j]);
    res = max(res, j - i + 1);
  }
  return res;
}

// LEET CODE: Remove duplicate Letters --- Daily
string removeDuplicateLetters(string s) {
  map<char, int> letterToIdx;

  // Add the Latest Index of every character in S
  for (int i = 0; i < s.size(); i++) {
    letterToIdx[s[i]] = i;
  }

  // Structures which will monitor the string
  string sequence = "";
  set<char> seen;

  // Loop s and always add the smallest ordered character if it is already
  // present latter in the string
  for (int i = 0; i < s.size(); i++) {
    // If already seen coninue looping
    if (seen.find(s[i]) != seen.end())
      continue;

    // while current character is less than top of stack and stack top is
    // present later in the string --- remove stack
    while (!sequence.empty() && sequence.back() > s[i] &&
           letterToIdx[sequence.back()] > i) {
      seen.erase(sequence.back());
      sequence.pop_back();
    }

    // Otherwise add current character
    seen.insert(s[i]);
    sequence.push_back(s[i]);
  }

  // Return Stack as a String
  return sequence;
}

//  LEET CODE : MIDDLE OF Linked list, ALGORITHMS I
ListNode *middleNode(ListNode *head) {
  // Two pointer solution with fast and slow runners
  ListNode *slow = head;
  ListNode *fast = head;

  while (fast->next->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }

  return slow;
}

/*
 * LEET CODE: Parentheses Score
 */
int scoreOfParentheses(string s) {
  stack<char> sequence;
  int score = 0;
  int balance = 0;
  char lstP;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      balance++;
    } else {
      balance--;
      if (s[i - 1] == '(')
        score += 1 << balance;
    }
  }
  return score;
}
// int scoreOfParentheses(string s){
//     stack<char> sequence;
//     int score = 0;

//     // Loop each char and record current depth in the stack
//     for(char p: s){
//         if(p == '('){
//             sequence.push(score);
//             score = 0;
//         } else {
//             int current_depth = sequence.top();
//             sequence.pop();
//             score = current_depth + max(score*2, 1);
//         }
//     }
//     return score;
// }

/*
 * LEET CODE: REVERSE WORDS IN STRING
 * ALGORITHMS I
 */
string reverseWords(string s) {
  int i = 0;
  int j = 0;

  while (j < s.size()) {
    // Find the end of the first word
    while (j < s.size() && s[j] != ' ')
      j++;

    // Swap each word in place
    reverse(s.begin() + i, s.begin() + j);

    // Update pointers
    i = j + 1;
    j = i;
  }
  return s;
}

/*
 * LEET CODE: REVERSE STRINGS
 * ALGORITHMS I
 *
 */
void reverseString(vector<char> &s) {
  int left = 0;
  int rght = s.size() - 1;

  while (left < rght) {
    char temp = s[left];
    s[left] = s[rght];
    s[rght] = temp;
    left++;
    rght--;
  }
}

/*
 * LEET CODE : TWO SUM II
 *
 */
vector<int> twoSum2(vector<int> &numbers, int target) {
  int left = 0;
  int rght = numbers.size() - 1;
  vector<int> res;

  while (left < rght) {
    if (numbers[left] + numbers[rght] < target)
      left++;
    else if (numbers[left] + numbers[rght] > target)
      rght--;
    else {
      res.push_back(left + 1);
      res.push_back(rght + 1);
      break;
    }
  }

  return res;
}

/*
 * LEET CODE: Move Zeros
 * ALGORITHMS 1
 */
void moveZeroes(vector<int> &nums) {
  int i = 0;
  int j = 0;

  // Loop the array using pointer j to find the zeros
  while (j < nums.size()) {
    // If current postion holds a non-zero element, swap it with the last
    // position i
    if (nums[j] != 0) {
      // Swapping
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
      i++;
    }
    j++;
  }
}

/*
 * LEET CODE: Rotate Linked List
 */
ListNode *rotateRight(ListNode *head, int k) {
  // count the linked list size to get to the
  // desired node at size - k - 1
  int listSize = 1;
  ListNode *tail = head;

  while (tail->next != nullptr) {
    tail = tail->next;
    listSize++;
  }

  // Fix K for cases with k > list size
  k = k % listSize;

  // for multiples of the same size of the list we do nothing
  if (k == 0)
    return head;

  ListNode *new_tail = head;
  ListNode *new_head = nullptr;

  // Move the new head ptr size - k - 1 steps
  for (int steps = 0; steps < listSize - k - 1; steps++) {
    new_tail = new_tail->next;
  }

  // Make the tail of the list point to the head
  tail->next = head;

  // Make tail points to null and save new head
  new_head = new_tail->next;
  new_tail->next = nullptr;

  return new_head;
}

/*
 * LEET CODE: Rotate Array
 */
void rotate(vector<int> &nums, int k) {
  // Modify K so that it include cases where the K is
  // larger than the entire array size
  k = k % nums.size();

  // the O(1) Solution
  // We first reverse the entire array
  reverse(nums.begin(), nums.end());

  // We then reverse two portions the first portion
  // is the portion from 0 -> (K-1)
  reverse(nums.begin(), nums.begin() + k);

  // Then reverse the rest of the array
  // k-> end
  reverse(nums.begin() + k, nums.end());
}

/*
 * LEET CODE: Squares of Sorted Array
 * ALGORITHMS 1
 */
vector<int> sortedSquares(vector<int> &nums) {
  vector<int> res;
  int left = 0;
  int rght = nums.size() - 1;

  while (left < rght) {
    if (abs(nums[rght]) > abs(nums[left])) {
      res.push_back((nums[rght]) * nums[rght]);
      rght--;
    }
    if (abs(nums[rght]) <= abs(nums[left])) {
      res.push_back((nums[left]) * nums[left]);
      left++;
    }
  }

  reverse(res.begin(), res.end());
  return res;
}

/*
 * LEET CODE: Check Stack sequences
 */

bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
  stack<int> s;
  int iPushed = 0;
  int iPopped = 0;

  // Push and pop the stack according to the sequence
  while (iPushed < pushed.size()) {
    s.push(pushed[iPushed]);

    // check stack top and first element in popped
    while (!s.empty() && popped[iPopped] == s.top()) {
      s.pop();
      iPopped++;
    }
    iPushed++;
  }

  if (s.empty())
    return true;
  else
    return false;
}

/*
 * LEET CODE: Divide two integers
 */

int divide(int dividend, int divisor) {

  // Edge cases : OVERFLOW in minimum direction
  if (dividend == INT32_MIN && divisor == -1)
    return INT32_MAX;
  if (dividend == INT32_MIN && divisor == 1)
    return INT32_MIN;

  // Keep both numbers with the same neative sign as to be always in valid
  // 32-bit range
  int up = (dividend > 0) ? -dividend : dividend;
  int down = (divisor > 0) ? -divisor : divisor;

  // Determine the calculation sign
  bool negative = (dividend < 0) ^ (divisor < 0);

  // Find the maximum exponential increase of the accumlator
  int exp_inc = down;
  int multiplier = 1;

  int qoutient = 0;

  // Keep doubling the accumlator untill overflow or maximum value
  while ((exp_inc >= (INT32_MIN >> 1)) && (up <= exp_inc + exp_inc)) {
    // Increase the accum by accum and double the multiplier
    exp_inc += exp_inc;
    multiplier <<= 1;
  }

  while (up <= down) {
    if (up <= exp_inc) {
      up -= exp_inc;
      qoutient += multiplier;
    }
    exp_inc >>= 1;
    multiplier >>= 1;
  }
  return negative ? -qoutient : qoutient;
}

/*
 * LEET CODE: Implement stringstr
 */
int strStr(string haystack, string needle) {
  // Empty string case
  if (needle == "")
    return 0;

  // needle longer than haystack
  if (needle.size() > haystack.size())
    return -1;

  int i = 0;
  int j = 0;
  // Preprocess the needle for lps
  vector<int> needleLPS = lps(needle);

  while (i < haystack.size()) {
    // while matching substrings continue to advance
    if (haystack[i] == needle[j]) {
      i++;
      j++;
    } else {
      // found a non matching substrings only advance the haystack pointer
      if (j == 0)
        i++;

      // backtrack the needle pointer untill matching substrings
      else
        j = needleLPS[j - 1];
    }

    // at reaching the end of the needle return the substring starting position
    if (j == needle.size())
      return i - needle.size();
  }

  // case no matches found
  return -1;
}

vector<int> lps(string needle) {
  vector<int> lps(needle.size(), 0);
  int prvLPS = 0;
  int curLPS = 1;

  // find the portion of the needle where
  // the needle suffix is the needle prefix
  while (curLPS < needle.size()) {
    if (needle[curLPS] == needle[prvLPS]) {
      lps[curLPS] = prvLPS + 1;
      prvLPS++;
      curLPS++;
    } else if (prvLPS == 0) {
      lps[curLPS] = 0;
      curLPS++;
    } else {
      prvLPS = lps[prvLPS - 1];
    }
  }
  return lps;
}

/* ---- BRUTE FORCE SOLUTION ----
int strStr(string haystack, string needle) {
    //  Case Empty string
    if(needle=="") return 0;

    // Case needle is longer than haystack
    if(needle.size()>haystack.size()) return -1;

    for(int i=0; i < haystack.size(); i++){
        if(haystack[i] == needle[0]){
            int j = 0;
            // for each character in the string haystack check all needle
characters and update needle pointer while( ((i + j) < haystack.size()) && (j <
needle.size()) && ( haystack[i + j] == needle[j] )){ j++;
            }

            // if needle pointer reaches the needle end then we found our match
            if( j == needle.size() ) return i;
        }
    }
    return -1;
}
*/
/*
 * LEET CODE:  Count All Valid Pickup and Delivery Options
 */
int countOrders(int n) {
  const long long MOD = 1e9 + 7;
  long long pickups = 1;
  long long deliver = 1;

  // Calculate all possible pick up senarios
  // NPN --- n!
  for (int i = 2; i <= n; i++) {
    pickups = (pickups * i) % MOD;
  }

  // Calculate all possible delivery options
  // 2n-1 --- 3, 1
  for (int i = 3; i < (2 * n); i = i + 2) {
    deliver = (deliver * i) % MOD;
  }
  return (deliver * pickups) % MOD;
}

/*
 * LEET CODE: Swap Nodes in Pairs
 */
ListNode *swapPairs(ListNode *head) {
  ListNode *NEW_LIST = new ListNode(0);

  if (head == nullptr)
    return head;

  NEW_LIST->next = head;
  ListNode *PRV_NODE = NEW_LIST;
  ListNode *CUR_NODE = PRV_NODE->next;

  while (CUR_NODE != nullptr && CUR_NODE->next != nullptr) {
    // Swap both heads with consideration of the rest of the list
    ListNode *list = CUR_NODE->next->next;
    ListNode *temp = CUR_NODE->next;

    CUR_NODE->next = list;
    temp->next = CUR_NODE;
    PRV_NODE->next = temp;

    // Update Pointers
    PRV_NODE = CUR_NODE;
    CUR_NODE = list;
  }
  return NEW_LIST->next;
}

/*
 * LEET CODE : MERGE K SORTED LISTS
 */
ListNode *mergeKLists(vector<ListNode *> &lists) {
  if (lists[0] == nullptr || lists.size() == 0)
    return nullptr;
  while (lists.size() > 1) {
    vector<ListNode *> NEW_LISTS;
    for (int i = 0; i < lists.size(); i = i + 2) {
      NEW_LISTS.push_back(mergeLists(
          lists[i], ((i + 1) < lists.size()) ? lists[i + 1] : nullptr));
    }
    lists.swap(NEW_LISTS);
  }
  return lists[0];
}

// Merge Two Sorted Linked Lists
ListNode *mergeLists(ListNode *head1, ListNode *head2) {
  ListNode *CUR_HEAD1 = head1;
  ListNode *CUR_HEAD2 = head2;
  ListNode *NEW_LIST = new ListNode(0);
  ListNode *TRAV_LIST = NEW_LIST;

  while (CUR_HEAD1 != nullptr && CUR_HEAD2 != nullptr) {
    if (CUR_HEAD1->val < CUR_HEAD2->val) {
      TRAV_LIST->next = new ListNode(CUR_HEAD1->val);
      CUR_HEAD1 = CUR_HEAD1->next;
    } else {
      TRAV_LIST->next = new ListNode(CUR_HEAD2->val);
      CUR_HEAD2 = CUR_HEAD2->next;
    }
    TRAV_LIST = TRAV_LIST->next;
  }

  while (CUR_HEAD1 != nullptr) {
    TRAV_LIST->next = new ListNode(CUR_HEAD1->val);
    CUR_HEAD1 = CUR_HEAD1->next;
    TRAV_LIST = TRAV_LIST->next;
  }
  while (CUR_HEAD2 != nullptr) {
    TRAV_LIST->next = new ListNode(CUR_HEAD2->val);
    CUR_HEAD2 = CUR_HEAD2->next;
    TRAV_LIST = TRAV_LIST->next;
  }
  return NEW_LIST->next;
}

/*
 * LEET CODE : DELETE EARN ____ DP Solution
 */
int deleteAndEarn(vector<int> &nums) {
  map<int, int> NUM_FREQ;
  for (auto num : nums) {
    if (NUM_FREQ.find(num) == NUM_FREQ.end()) {
      NUM_FREQ.insert({num, 1});
    } else {
      NUM_FREQ[num] += 1;
    }
  }
  logMap(NUM_FREQ);

  // Sort and remove duplicates
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());

  int PRE_EARN = 0;
  int CUR_EARN = 0;

  for (int i = 0; i < nums.size(); i++) {
    int POINTS = nums[i] * NUM_FREQ[nums[i]];

    if (i > 0 && (nums[i] == nums[i - 1] + 1)) {
      int temp = CUR_EARN;
      CUR_EARN = max(PRE_EARN + POINTS, CUR_EARN);
      PRE_EARN = temp;
    } else {
      int temp = CUR_EARN;
      CUR_EARN = CUR_EARN + POINTS;
      PRE_EARN = temp;
    }
  }
  return CUR_EARN;
}
/*
 * LEET CODE : Champagne Tower
 */

double champagneTower(int poured, int query_row, int query_glass) {
  // Get the first rows number of glasses
  vector<double> glasses = {(double)poured};

  for (int row = 0; row <= query_row; row++) {
    vector<double> NEXT_ROW(glasses.size() + 1.0, 0.0);

    for (int glass = 0; glass < glasses.size(); glass++) {

      double pour = (glasses[glass] - 1.0) / 2.0;

      if (pour > 0.0) {
        NEXT_ROW[glass] += pour;
        NEXT_ROW[glass + 1] += pour;
      }
    }
    glasses.swap(NEXT_ROW);
  }
  return min(1.0, glasses[query_glass]);
}
/*
 * LEET CODE : Is Valid Parentheses
 */

// bool isValid(string s){
//     // Loop each element in string
//     // if oppenning Parentheses add to stack
//     // if clossing Parentheses remove from stack
//     // return true only if VALID is equal to zero
//     std::stack<char> ORDER;
//     std::map<char, char> PARENTHESES {
//         {'}', '{'},
//         {')', '('},
//         {']', '['}
//     };
//     for(auto p: s){
//         // If opeening paren. then add to stack order
//         if(PARENTHESES.find(p) != PARENTHESES.end()){
//             if(!ORDER.empty() && ORDER.top() == PARENTHESES[p]){
//                 ORDER.pop();
//             } else {
//                 return false;
//             }
//         }
//         // Clossing Parenthese Check
//         else{
//             ORDER.push(p);
//         }
//     }
//     if(ORDER.empty()) return true;
//     else return false;
// }
bool isValid(string s) {
  // Loop each element in string
  // if oppenning Parentheses add one to VALIDATION
  // if clossing Parentheses minus one to VALIDATION
  // return true only if VALID is equal to zero
  stack<char> ORDER;
  for (auto p : s) {
    switch (p) {
    case '{':
      ORDER.push('}');
      break;
    case '(':
      ORDER.push(')');
      break;
    case '[':
      ORDER.push(']');
      break;
    default:
      if (ORDER.empty() || p != ORDER.top())
        return false;
      else
        ORDER.pop();
    }
  }
  return ORDER.empty();
}

/*
 * LEET CODE: Arithmatci Slices
 */
int numberOfArithmeticSlices(vector<int> &nums) {
  int SUBSEQ_COUNT = 0;
  int CUMULATIVE_COUNT = 0;
  int DIFF = INT32_MAX;

  if (nums.size() <= 2)
    return 0;
  for (int i = 1; i < nums.size(); i++) {
    int NEW_DIFF = nums[i] - nums[i - 1];
    // Check the last two numbers for the arithmatic sequence
    if (NEW_DIFF == DIFF) {
      CUMULATIVE_COUNT += 1;
      // Add the cumulative Count to the Result
      SUBSEQ_COUNT += CUMULATIVE_COUNT;

    } else {
      // Restart Cumulative counter when finds a different sequence
      CUMULATIVE_COUNT = 0;
      DIFF = NEW_DIFF;
    }
  }

  return SUBSEQ_COUNT;
}

/*
 * LEET CODE: Is Subsequence
 */

bool isSubsequence(string s, string t) {
  // Using two pointer technique
  int i = 0;
  int j = 0;

  // bool IS_SUBSEQUENCE ;
  // if(s.empty() && t.empty()) return true;

  while (i < s.size() && j < t.size()) {
    cout << s[i] << " == " << t[j] << " ? " << endl;
    cout << i << " " << j << endl;
    if (s[i] == t[j])
      i++;
    j++;
  }
  if (i == s.size())
    return true;
  else
    return false;
}
/*
 * LEET CODE: Remove nth node from the end
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *dummy = new ListNode(0, head);

  ListNode *left = dummy;
  ListNode *right = head;

  // Shift the right pointer by n Spaces
  for (int i = 0; i < n; i++) {
    right = right->next;
  }

  // Find the nth Node from the end
  while (right != nullptr) {
    right = right->next;
    left = left->next;
  }

  // Delete Node
  left->next = left->next->next;

  return dummy->next;
}

/*
 * LEET CODE: Counting Bits
 */
// vector<int> countBits(int n) {
//     vector<int> count = {};
//     int ONES_COUNT=0;
//     for(int BINARY_NUMBERS = 0; BINARY_NUMBERS<=n; BINARY_NUMBERS++){
//         int qout = BINARY_NUMBERS;
//         int rem = 0;
//         while(qout > 0){
//             rem = qout%2;
//             // cout << "BINARY: " << BINARY_NUMBERS <<" REMAINING " << rem <<
//             endl; if(rem==1) ONES_COUNT++; qout=qout/2;
//         }
//         count.push_back(ONES_COUNT);
//         ONES_COUNT = 0;
//     }
//     return count;
// }
vector<int> countBits(int n) {
  vector<int> ONES(n + 1, 0);
  int offset = 1;
  for (int nBins = 1; nBins <= n; nBins++) {
    if (offset * 2 == nBins) {
      offset = nBins;
    }
    ONES[nBins] = 1 + ONES[nBins - offset];
  }
  return ONES;
}

/*
 * LEET CODE: Compare Version Numbers
 */
int compareVersion(string version1, string version2) {
  int v1 = 0, v2 = 0;
  int i = 0, j = 0;

  while (i < version1.size() || j < version2.size()) {
    cout << i << j << endl;
    // Excluding any leading zeros
    while (i < version1.size() && version1[i] != '.') {
      cout << "V1 : " << version1[i] << endl;
      v1 = v1 * 10 + (version1[i] - '0');
      i++;
    }
    while (j < version2.size() && version2[j] != '.') {

      cout << "V2 : " << version2[j] << endl;

      v2 = v2 * 10 + (version2[j] - '0');
      j++;
    }

    // check both versions
    if (v1 < v2) {
      return -1;
    } else if (v1 > v2) {
      return 1;
    }

    // Reset revisions and increment counters
    // after ther dot operator
    v1 = 0;
    v2 = 0;
    i++;
    j++;
  }
  return 0;
}

/*
 * LEET CODE: Letter Combinations of a phone number
 */
class Solution {
public:
  void backtrack(int curI, string curStr) {
    if (curStr.size() == input.size()) {
      cout << curStr << endl;
      res.push_back(curStr);
      return;
    }
    for (auto c : phone[input[curI]]) {
      backtrack(curI + 1, curStr + c);
    }
  }

  vector<string> letterCombinations(string digits) {
    input = digits;
    if (digits != "") {
      backtrack(0, "");
    }
    return res;
  }

private:
  string input;
  vector<string> res = {};
  map<char, string> phone = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                             {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                             {'8', "tuv"}, {'9', "wxyz"}};
};

/*
 * LEET CODE : Majority Number
 */
// int majorityElement(vector<int>& nums) {
//     map<int, int> table;
//     for(auto num: nums){
//         if(table.find(num) != table.end()){
//             table[num] = table[num] + 1;
//         }else {
//             table[num] = 1;
//         }
//         cout << "num : " << num << " : " << table[num] << endl;
//     }
//     int count = 0;
//     int res;
//     auto itr = table.begin();
//     while(itr != table.end()){
//         if(itr->second > count){
//             count = itr->second;
//             res = itr->first;
//         }
//         itr++;
//     }
//     return res;
// }
// Randomization Solution
int majorityElement(vector<int> &nums) {
  int res;
  while (true) {
    int count = 0;
    int idx = rand() % nums.size();
    for (auto num : nums) {
      if (num == nums[idx])
        count++;
    }
    if (count > nums.size() / 2) {
      return nums[idx];
    }
  }
}

/*
 * LEET CODE : 3SUM
 */
vector<vector<int>> threeSum(vector<int> &nums) {
  // Sort the Input Array to skip duplicates
  sort(nums.begin(), nums.end());
  logIntArr(nums);
  vector<vector<int>> res;
  // Fix the first two numbers
  // Search for the third number which equals to
  // z = -( x + y ) and append to the result
  for (int i = 0; i < nums.size(); i++) {
    int lptr = i + 1;
    int rptr = nums.size() - 1;

    // check for duplicate .. Exit loop and skip to the next
    if (i > 0 && nums[i] == nums[i - 1]) {

    } else {
      while (lptr < rptr) {
        int summation = nums[i] + nums[lptr] + nums[rptr];
        if (summation < 0) {
          lptr++;
        } else if (summation > 0) {
          rptr--;
        } else {
          res.push_back({nums[i], nums[rptr], nums[lptr]});
          cout << "ADDING : " << lptr << " " << rptr << " " << i << endl;
          lptr++;
          while (lptr < rptr && nums[lptr - 1] == nums[lptr]) {
            lptr++;
          }
        }
      }
    }
  }

  return res;
}

/*
 * LEET CODE: Longest Common Prefix
 */
string longestCommonPrefix(vector<string> &strs) {
  string pfx = "";

  // Take the first String as an arbitrary point
  for (int iPfx = 0; iPfx < strs[0].size(); iPfx++) {
    // Loop each character and check if it is a common prefix among other
    // strings
    for (auto str : strs) {
      if (iPfx == str.size() || str[iPfx] != strs[0][iPfx])
        return pfx;
    }
    // Append the character to the pfx holder
    pfx.push_back(strs[0][iPfx]);
  }
  return pfx;
}

/*
 * LEET CODE: Roman to Integer
 */
int romanToInt(string s) {
  int res = 0;
  int i = 0;
  map<char, int> romans = {
      {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
      {'X', 10},   {'V', 5},   {'I', 1},
  };

  while (i < s.size()) {
    if (i + 1 < s.size() && romans[s[i + 1]] > romans[s[i]]) {
      res = res + (romans[s[i + 1]] - romans[s[i]]);
      i = i + 2;
    } else {
      res = res + romans[s[i]];
      i++;
    }
  }
  return res;
}

/*
 * LEET CODE: Integers to Roman
 */
string intToRoman(int num) {
  string conversion = "";
  map<int, string, greater<int>> romans = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"},
  };
  int remain = num;

  for (auto itr = romans.begin(); itr != romans.end(); ++itr) {
    // Calculate the Number of Repeatitons
    int reps = remain / itr->first;

    // Append to the Conversion String repeated times
    if (reps > 0) {
      for (reps; reps > 0; reps--) {
        conversion.append(itr->second);
      }
      remain = remain % (itr->first);
    }
  }
  return conversion;
}

/*
 *
 * LEET CODE: Container with most Water
 */
int maxArea(vector<int> &height) {
  int area = 0;
  int current;
  int i = 0;
  int j = height.size() - 1;

  while (j > i) {
    current = min(height[i], height[j]) * (j - i);
    area = max(current, area);
    if (height[i] < height[j]) {
      i++;
    } else {
      j--;
    }
  }
  return area;
}

/*
 * LEET CODE: Regular Expression Matching
 */
bool isMatch(string s, string p) {
  // Call the Finder Function
  return find(0, 0, s, p);
}

// Top Down DP Solution
bool find(int i, int j, string s, string p) {
  bool match;

  // Match is found when both pointers reach the end
  if (i >= s.size() && j >= p.size())
    return true;

  // Match is not found when Pattern pointer reaches the end
  if (j >= p.size())
    return false;

  // Find the Match
  match = ((s[i] == p[j]) || (p[j] == '.')) && i < s.size();

  // Case: Next element is *
  if (j + 1 < p.size() && p[j + 1] == '*') {
    // Choose whether to use the star or not
    return ((find(i + 1, j, s, p) && match) || (find(i, j + 2, s, p)));
  }

  if (match) {
    return find(i + 1, j + 1, s, p);
  }

  // No match found return false
  return false;
}
/*
 * LEET CODE: Add Two Numbers
 */
// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
// }

/*
 * LEECODE: TWO SUM
 *
 *
 */
// vector<int> twoSum(vector<int> & nums, int target){
//     vector<int> res;
//     for(unsigned int i = 0; i < nums.size(); i++){
//         for(unsigned int j =  i + 1; j < nums.size(); j++){
//             if(nums[i] + nums[j] == target){
//                 res.push_back(i);
//                 res.push_back(j);
//             }
//         }
//     }

//     return res;
// }

// Using Maps
vector<int> twoSum(vector<int> &nums, int target) {
  vector<int> res;
  map<int, int> table;

  for (unsigned int i = 0; i < nums.size(); i++) {
    int comp = target - nums[i];

    if (table.find(comp) != table.end()) {
      res.push_back(i);
      res.push_back(table[comp]);
    }

    table.insert({nums[i], i});
  }

  return res;
}

/*
 * LEET CODE: Remove Duplicates from Sorted Array
 *
 */

// int removeDuplicates(vector<int>& nums)
// {
//     // Define the parsing pointers for the first two elements
//     int i = 0;
//     for(int j = 1; j < nums.size(); j++){
//         if(nums[i] != nums[j]){
//             i = i + 1;
//             nums[i] = nums[j];
//         }
//     }
//     return i+1;
// }

int removeDuplicates(vector<int> &nums) {
  vector<int>::iterator res = unique(nums.begin(), nums.end());
  nums.erase(res, nums.end());
  return nums.size();
}

/*
 * LEET CODE: Median of Two Sorted Arrays
 *
 */

// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     // Calculated the size of both arrays combined
//     unsigned int size = (nums1.size() + nums2.size());
//     vector<int> resArr;
//     int i = 0;
//     int j = 0;
//     int count;
//     double res;

//     for(count = 0; count <= (int)(size/2); count++){
//         if(nums1[i] <= nums2[j] && i < nums1.size()){
//             resArr.push_back(nums1[i]);
//             i++;
//         }
//         if (nums1[i] > nums2[j] && j < nums2.size()){
//             resArr.push_back(nums2[j]);
//             j++;
//         }
//     }
//     // Even Case
//     if(size % 2 == 0){
//         if(i >= nums1.size()){
//             resArr.push_back(nums2[j]);
//         } else if(j >= nums2.size()){
//             resArr.push_back(nums1[i]);
//         }
//         res = (*(resArr.end()-1) + *(resArr.end() - 2)) / 2.0 ;
//     } else {
//         res = *(resArr.end()-1);
//     }

//     return res;
// }

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  //  Swapping Arrays to search the smaller array always
  if (nums2.size() < nums1.size()) {
    vector<int> temp = nums2;
    nums2 = nums1;
    nums1 = temp;
  }

  int lo = 0;
  int hi = nums1.size();
  int totSize = nums1.size() + nums2.size();

  while (lo <= hi) {
    int partX = (lo + hi) / 2;
    int partY = ((totSize + 1) / 2) - partX;

    // Calculate Left and Right Partitions (Elements) of both arrays
    int lX = getMax(nums1, partX);
    int rX = getMin(nums1, partX);

    int lY = getMax(nums2, partY);
    int rY = getMin(nums2, partY);

    // Check Median Condition == LeftX <= Righty and Lefty <= RightX
    if ((lX <= rY) && (lY <= rX)) {
      //  Even Case Return Average
      if (totSize % 2 == 0) {
        return (max(lX, lY) + min(rX, rY)) / 2.0;
      } else {
        return max(lX, lY);
      }
    }

    //  Shifting the partitioning Point
    if (lX > rY) {
      hi = partX - 1;
    } else {
      lo = partX + 1;
    }
  }
  // Not Sorted Case, Search Failed
  return -1;
}

int getMax(vector<int> nums, int part) {
  if (part == 0) {
    return numeric_limits<int>::min();
  } else {
    return nums[part - 1];
  }
}
int getMin(vector<int> nums, int part) {
  if (part == nums.size()) {
    return numeric_limits<int>::max();
  } else {
    return nums[part];
  }
}

/*
 *
 * LEET CODE: Longest Palindromic Substring
 *
 */
// string longestPalindrome(string s){
//     int max = 0;
//     string res;
//     if (s.size() == 1){
//         return s ;
//     }
//     for(unsigned int i = 0; i < s.size(); i++){
//         for(unsigned int j = i+1; j < s.size(); j++){
//                 string subs = s.substr(i, j - i);
//                 string sRev(subs);
//                 reverse(sRev.begin(), sRev.end());
//                 if(!(subs.compare(sRev)) && (subs.size() > max)){
//                     max = subs.size();
//                     res = subs;
//                 }
//         }
//     }
//     if (res.size() == 0){
//         return string(1, s[0]);
//     }
//     return res;
// }

string longestPalindrome(string s) {
  int max = 0;
  string res;
  if (s.size() == 1) {
    return s;
  }

  for (unsigned int i = 0; i < s.size(); i++) {

    // Odd Case .. Center Expansion
    int left = i; // Do not Use Unsigned Int
    int right = i;

    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      if ((right - left + 1) > max) {
        max = right - left + 1;
        res = s.substr(left, right - left + 1);
      }
      left--;
      right++;
    }

    // Even Case
    left = i;
    right = i + 1;
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      if ((right - left + 1) > max) {
        max = right - left + 1;
        res = s.substr(left, right - left + 1);
      }
      left--;
      right++;
    }
  }
  return res;
}

/*
 *
 * LEET CODE: Zigzag Conversion
 */
// string convert(string s, int numRows){
//     string res;
//     int row;
//     int element;
//     for(row = 0; row <= numRows; row++){
//         // Redefine the Next Element Finder
//         element = 0;

//         // Add the First Element in the Row
//         res.push_back(s[row]);

//         while(element <= s.size() - 1){
//             //  Calculate the Next Element in the Zigzag
//             element = row + element + (numRows-1)*2;

//             // Check element bounds
//             if( element > s.size()) break ;

//             //  Add the Elements in the Middle Zigzag
//             if(row>0 && row < numRows){
//                 cout << "mid : " << element - 2 *row << endl;
//                 res.push_back(s[element - 2*row]);
//             }
//             res.push_back(s[element]);
//             cout << element << endl;
//         }
//     }
//     return res;

// }
string convert(string s, int numRows) {
  string res;
  int element;

  // Edge Case, numRows == 1
  if (numRows == 1)
    return s;

  // Element incrementing and Zigzag Formation
  for (int r = 0; r <= numRows - 1; r++) {
    element = 2 * (numRows - 1);
    for (int i = r; i < s.size(); i = i + element) {
      res.push_back(s[i]);

      // Case : Middle Rows Elements
      if ((r > 0) && (r < numRows - 1) && (i + element - 2 * r < s.size())) {
        res.push_back(s[i + element - 2 * r]);
      }
    }
  }

  return res;
}

/*
 * LEET CODE: Reverse Integer
 *
 *
 */
int reverse(int x) {
  int digit;
  int res = 0;
  int MAX = 2147483647;
  int MIN = -MAX;

  while (x != 0) {
    //  Check Result out of bounds
    if (res > MAX / 10 || (res == MAX / 10 && digit >= MAX % 10))
      return 0;
    if (res < MIN / 10 || (res == MIN / 10 && digit <= MIN % 10))
      return 0;

    // Extract each digit from X and Reverse
    digit = x % 10;
    x = x / 10;
    res = (res * 10) + digit;
  }

  return res;
}

/*
 * LEET CODE : String to Integer (ATOI)
 */
int myAtoi(string s) {
  int res = 0;
  int digit;
  int sign = 1;
  int MAX = INT32_MAX;
  int MIN = INT32_MIN;
  int c = 0;

  // Increment untill first non-white space is found and ignore + sign
  while ((int)s[c] == 32)
    c++;

  // Check Char for sign
  if ((int)s[c] == 45 || (int)s[c] == 43) {
    sign = s[c] == '-' ? -1 : 1;
    c++;
  }
  // Only convert characters in range of digits
  // 0 - 9 --> 48 - 57
  while ((int)s[c] >= 48 && (int)s[c] <= 57) {
    // Convert Current Digit
    digit = (s[c] - '0') * sign;
    // Check for Bounds

    if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10))
      return MAX;
    if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10))
      return MIN;

    // Shft the result left by one
    //  Add the converted digit
    res = res * 10 + digit;

    // Increment
    c++;
  }

  return res;
}

/*
 * LEET CODE: Palindrom Number
 */

bool isPalindrome(int x) {
  int xRev = 0;
  int digit;
  int MAX = INT32_MAX;
  int MIN = INT32_MIN;

  // Return False if Negative Number
  if (x < 0 || x % 10 == 0)
    return 0;

  // Reverse the Input and Compare to Original
  while (x > xRev) {
    xRev = xRev * 10 + x % 10;
    x = x / 10;
  }
  if (xRev == x || xRev / 10 == x)
    return true;
  else
    return false;
}

void logIntArr(const vector<int> arr) {
  for (unsigned int i = 0; i < arr.size(); i++) {
    cout << i << " : " << arr[i] << endl;
  }
}

void logMap(map<int, int> m) {
  for (auto element : m) {
    cout << element.first << " : " << element.second << endl;
  }
}