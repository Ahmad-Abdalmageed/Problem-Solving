class Solution {
private:
    void fill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor);
    std::vector<std::vector<int>> res;
    int pxlValue;
    int rows;
    int cols;

public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor);

};

void Solution::fill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor){
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

std::vector<std::vector<int>> Solution::floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor){
    pxlValue = image[sr][sc];
    rows = image.size();
    cols = image[0].size();
    
    fill(image, sr, sc, newColor);
    return image;
}