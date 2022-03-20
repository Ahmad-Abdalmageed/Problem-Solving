#ifndef LEETCODECLASS
#define LEETCODECLASS

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include "leetdef.hpp"

/*
 * LEET CODE: Generate Parentheses
 */
class GenParen{
public:
    std::vector<std::string> generateParenthesis(int n){
        pSize = n;
        backTrackParens("", 0, 0);
        return res;

    }

    void backTrackParens(std::string s, int nClosed, int nOpen){
        std::cout << s << std::endl;
        // Base Case appen result
        if(nClosed==nOpen && nOpen==pSize){
            res.push_back(s);
            return;
        }

        // Add an open Parentheses 
        if(nOpen < pSize){
            s.push_back('(');
            backTrackParens(s, nClosed, nOpen+1);
            s.pop_back();
        }

        // Closed Parentheses 
        if(nClosed < nOpen){
            s.push_back(')');
            backTrackParens(s, nClosed+1, nOpen);
            s.pop_back();
        }
    }

    GenParen(): pSize(0), res({}){

    }

private:
    int pSize;
    std::vector<std::string> res;
};

class DeleteEarn{
public:
    int deleteAndEarn(std::vector<int>& nums){
        inSize = nums.size();

        // Sort 
        sort(nums.begin(), nums.end());
        return dp(0, nums);
    }

    int dp(int idx, std::vector<int> nums){
        // BASE CASE
        if(idx >= inSize) return 0;

        // Memoization
        if(points.find(idx) != points.end()) return points[idx];

        // take the current point into earning
        // calculate next idx, or leave
        int point = nums[idx];
        int nidx = idx + 1;
        while(idx<inSize && nums[idx] == nums[nidx]){
            point = point + nums[nidx];
            nidx++;
        }
        while(nidx < inSize && nums[idx] == nums[nidx]-1){
            nidx++;
        }
        

        // Add max earn into memo
        points.insert({idx, std::max(point + dp(nidx, nums), dp(idx+1, nums))});  
        
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
    void fill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor);
    std::vector<std::vector<int>> res;
    int pxlValue;
    int rows;
    int cols;

public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor);

};

// LEETCODE: Max Area of Island
class IslandMaxArea {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid);

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
    Node* connect(Node* root);
private:
    void dfs(Node* node, Node* next);
};

#endif // DEBUG