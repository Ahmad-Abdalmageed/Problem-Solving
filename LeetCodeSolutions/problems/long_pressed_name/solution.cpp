class Solution {
public:
    // Using Two pointers Approach
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        
        for(int j = 0; j < typed.size(); j++)
        {
            if(typed[j] == name[i] && i < name.size()) i++;
            else if(!j || typed[j] != typed[j - 1]) return false;
        }
        
        return i == name.size();
    }
};