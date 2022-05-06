#ifndef LEETCODECLASS
#define LEETCODECLASS

#include "leetdef.hpp"
#include <algorithm>
#include <climits>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

/*
 * LEET CODE: Generate Parentheses
 */
class GenParen {
public:
  std::vector<std::string> generateParenthesis(int n) {
    pSize = n;
    backTrackParens("", 0, 0);
    return res;
  }

  void backTrackParens(std::string s, int nClosed, int nOpen) {
    std::cout << s << std::endl;
    // Base Case appen result
    if (nClosed == nOpen && nOpen == pSize) {
      res.push_back(s);
      return;
    }

    // Add an open Parentheses
    if (nOpen < pSize) {
      s.push_back('(');
      backTrackParens(s, nClosed, nOpen + 1);
      s.pop_back();
    }

    // Closed Parentheses
    if (nClosed < nOpen) {
      s.push_back(')');
      backTrackParens(s, nClosed + 1, nOpen);
      s.pop_back();
    }
  }

  GenParen() : pSize(0), res({}) {}

private:
  int pSize;
  std::vector<std::string> res;
};

class DeleteEarn {
public:
  int deleteAndEarn(std::vector<int> &nums) {
    inSize = nums.size();

    // Sort
    sort(nums.begin(), nums.end());
    return dp(0, nums);
  }

  int dp(int idx, std::vector<int> nums) {
    // BASE CASE
    if (idx >= inSize)
      return 0;

    // Memoization
    if (points.find(idx) != points.end())
      return points[idx];

    // take the current point into earning
    // calculate next idx, or leave
    int point = nums[idx];
    int nidx = idx + 1;
    while (idx < inSize && nums[idx] == nums[nidx]) {
      point = point + nums[nidx];
      nidx++;
    }
    while (nidx < inSize && nums[idx] == nums[nidx] - 1) {
      nidx++;
    }

    // Add max earn into memo
    points.insert({idx, std::max(point + dp(nidx, nums), dp(idx + 1, nums))});

    return points[idx];
  }

private:
  int inSize;
  std::map<int, int> points;
};

// LEET CODE : Maximum Frequency Stack -- DAILY
class FreqStack {
public:
  FreqStack();
  void push(int val);
  int pop();

private:
  std::map<int, std::stack<int>> valueMap;
  std::map<int, int> countMap;
  int maxCount = 0;
};

// LEETCODEL FLood Fill --- ALGORITHM I
class FloodFill {
private:
  void fill(std::vector<std::vector<int>> &image, int sr, int sc, int newColor);
  std::vector<std::vector<int>> res;
  int pxlValue;
  int rows;
  int cols;

public:
  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image,
                                          int sr, int sc, int newColor);
};

// LEETCODE: Max Area of Island
class IslandMaxArea {
public:
  int maxAreaOfIsland(std::vector<std::vector<int>> &grid);

private:
  int bfs(int row, int col);
  int gRows = 0;
  int gCols = 0;
  std::vector<std::vector<int>> island;
  std::vector<std::vector<bool>> seen;
};

// LEETCODE: Populating Next Right Pointers in Each Node -- ALGORITHM I
class Populate {
public:
  Node *connect(Node *root);

private:
  void dfs(Node *node, Node *next);
};

// LEETCODE: Combinations -- Algorithms I
class Combinations {
public:
  std::vector<std::vector<int>> combine(int n, int k);

private:
  int end;
  void backtrack(int start, std::vector<int> &comb);
  int combSize;
  std::vector<std::vector<int>> res;
};

// LEETCODE: Permutations -- Algorithms I
class Permutations {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums);

private:
  void backtrack(int begin);
  std::vector<int> permutation;
  std::vector<std::vector<int>> result;
};

class LetterPermutation {
public:
  std::vector<std::string> letterCasePermutation(std::string s);

private:
  std::string input;
  void dfs(int pos);
  std::vector<std::string> res;
};

// LEETCODE: Split Array Largest Sum -- DAILY
class SplitArray {
public:
  int splitArray(std::vector<int> &nums, int m);

private:
  std::vector<int> arrNums;
  int groups;
  bool canSplit(int candidate);
};

class PalindromeByRem {
public:
  bool validPalindrome(std::string s);

private:
  bool isPalindrome(int left, int rght, std::string s);
};

class KthLargest {
public:
  KthLargest(int k, std::vector<int> &nums);
  int add(int val);

private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  int k;
};

class BinarySearchDouble {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target);

private:
  int binarySearch(std::vector<int> nums, int target, bool leftBias);
};

class StringAngrams {
public:
  std::vector<int> findAnagrams(std::string s, std::string p);

private:
  template <typename Map> bool compMaps(Map const &leftMap, Map const &rghtMap);
};

class CountIslands {
public:
  int numIslands(std::vector<std::vector<char>> &grid);

private:
  void bfs(int row, int col);
  int gridRows;
  int gridCols;
  std::vector<std::vector<bool>> seen;
  std::vector<std::vector<char>> gridIsland;
};

class NumberOfIslands {
public:
  int findCircleNum(std::vector<std::vector<int>> &isConnected);

private:
  void bfs(std::vector<std::vector<int>> &isConnected, int cur);
  std::vector<bool> visited;
};

class IsSubTree {
public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot);
  bool isSameTree(TreeNode *root, TreeNode *subRoot);
};

class MyStack {
public:
  MyStack();
  void push(int x);
  int pop();
  int top();
  bool empty();

private:
  std::queue<int> qStack;
  int qStackTop;
};

#endif // DEBUG