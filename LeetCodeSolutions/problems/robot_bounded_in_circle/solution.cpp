class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        
        for(auto const & instruction: instructions)
        {
            if(instruction == 'R') dir = (dir + 1) % 4;
            else if(instruction == 'L') dir = (dir + 3) % 4;
            else{
                x += _directions[dir][0];
                y += _directions[dir][1];
            }
        }
        
        return x == 0 && y == 0 || dir > 0;
    }
private:
    vector<vector<int>> _directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
};