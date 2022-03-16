class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int rght = s.size() - 1;

        while(left<rght){
            char temp = s[left];
            s[left] = s[rght];
            s[rght] = temp;
            left++;
            rght--;
        }
    }

};