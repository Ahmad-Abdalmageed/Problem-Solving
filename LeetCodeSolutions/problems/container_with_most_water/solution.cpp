class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int current;
        int i = 0 ;
        int j = height.size()-1;

        while(j > i){
            current = min(height[i], height[j]) * (j - i);
            area = max(current, area);
            if(height[i] < height[j]){
                i++;
            } else {
                j--;
            }
        }
        return area ;
    }
};