#include "classes.h"

// Class Conctructor
FreqStack::FreqStack() : valueMap({}), countMap({}), maxCount(0){}

// Pop the most Frequent Element
int FreqStack::pop(){
    // get current maximum frequency value
    int res = valueMap[maxCount].top();
    // Update count value stack
    valueMap[maxCount].pop();
    
    // Update current maximum count value and count map
    countMap[res]--;

    // only upgrade if there are no other elements with the same count
    if(valueMap[maxCount].empty())
        maxCount--;

    return res;
}

// Push a value into the stack
void FreqStack::push(int val){
    // upgrade the count map or add a new value 
    countMap[val]++;

    // Upgrade current max count 
    maxCount = std::max(maxCount, countMap[val]);

    // upgrade the value map
    valueMap[countMap[val]].push(val);
}

void FloodFill::fill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor){
    if((sr < rows && sc < cols) && (sr >= 0 && sc >= 0)){
        int curVal = image[sr][sc];

        // Edge case where the new color is equal to the current value 
        if(newColor == curVal) return;

        if(curVal == pxlValue){      
            // Upadte current pixel
            image[sr][sc] = newColor;

            // Fill next neighbors
            fill(image, sr-1, sc, newColor);
            fill(image, sr+1, sc, newColor);
            fill(image, sr, sc-1, newColor);
            fill(image, sr, sc+1, newColor);
        }
    }
}

std::vector<std::vector<int>> FloodFill::floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor){
    // Store image array properties
    pxlValue = image[sr][sc];
    rows = image.size();
    cols = image[0].size();
    
    // BFS Function call
    fill(image, sr, sc, newColor);
    return image;
}

int IslandMaxArea::bfs(int row, int col){
    // Return 0 if already seen this spot our if out of bounds
    if(row >= gRows || col >= gCols || row < 0 || col < 0 || seen[row][col] || island[row][col] == 0) return 0;

    // Update bool map
    seen[row][col] = true;
    
    // Count current spot and move to the next
    return 1 + bfs(row-1, col) + bfs(row+1, col) + bfs(row, col-1) + bfs(row, col+1);
}

int IslandMaxArea::maxAreaOfIsland(std::vector<std::vector<int>>& grid){
    // Store Island Properties
    gRows = grid.size();
    gCols = grid[0].size();
    seen = std::vector<std::vector<bool>> (gRows, std::vector<bool>(gCols));
    island = grid;

    // BFS Algorithm --- Look in each connected structure for the new maximum area
    int ans = 0;
    for(int i = 0; i < gRows; i++){
        for(int j = 0; j < gCols; j++){
            ans = std::max(ans, bfs(i, j));
        }
    }
    return ans;
}

void Populate::dfs (Node* node, Node* next){
    // base case current node is null
    if(node==nullptr) return;

    node->next = next;

    // traverse to the left
    dfs(node->left, node->right);
    
    // traverse to the right with next pointer pointing to 
    // current node next if exist
    dfs(node->right, (node->next != nullptr) ? node->next->left: nullptr);
}

Node* Populate::connect(Node* root){
    dfs(root, nullptr);
    return root;
}