class Solution {
public:
bool checkInclusion(string s1, string s2){
    // Case s1 > s2
    if(s1.size() > s2.size()) return false; 
    
    //  create an array of frequencies of both strings for 
    // first s1 size chars 
    vector<int> charCountS1(26, 0);
    vector<int> charCountS2(26, 0);
    for(int i = 0; i < s1.size(); i++){
        charCountS1[s1[i] - 'a']++;
        charCountS2[s2[i] - 'a']++; // Contains count of first (s1.size()) elements
    }

    // Sliding window technique ... move the window and calculate current window freq.
    for(int i = 0 ; i < s2.size() - s1.size(); i++){
        // Return if already matches 
        if(match(charCountS1, charCountS2)) return true;

        // Move window to the right by adding and removing characters from the wnidow
        charCountS2[s2[i + s1.size()] - 'a'] ++; // Add next char to window
        charCountS2[s2[i] - 'a'] --; // remove first char from window   
    }

    // may still have not returned so last check
    return match(charCountS1, charCountS2);
}
    
private:
    bool match(vector<int> a, vector<int> b){
        for(int i = 0 ; i < a.size(); i++){
            if(a[i] != b[i]) return false ; 
        }
        return true;
    }
};