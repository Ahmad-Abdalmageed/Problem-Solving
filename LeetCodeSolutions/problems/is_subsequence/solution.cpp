class Solution {
public:
bool isSubsequence(string s, string t) {
    // Using two pointer technique
    int i = 0;
    int j = 0;

    // bool IS_SUBSEQUENCE ;
    // if(s.empty() && t.empty()) return true;

    while(i < s.size() && j < t.size()){
        cout << s[i] << " == " << t[j] << " ? " << endl;
        cout << i << " " << j << endl;
        if(s[i] == t[j]) i++;
        j++;
    }
    if(i == s.size()) return true;
    else return false;
}
};