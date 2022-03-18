class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> letterToIdx;

        // Add the Latest Index of every character in S
        for(int i = 0; i<s.size(); i++){
            letterToIdx[s[i]] = i;
        }

        // Structures which will monitor the string
        string sequence = "";
        set<char> seen;

        // Loop s and always add the smallest ordered character if it is already 
        // present latter in the string
        for(int i = 0; i<s.size(); i++){
            // If already seen coninue looping
            if(seen.find(s[i]) != seen.end()) continue;

            // while current character is less than top of stack and stack top is 
            // present later in the string --- remove stack
            while(!sequence.empty() && sequence.back() > s[i] && letterToIdx[sequence.back()] > i){
                seen.erase(sequence.back());
                sequence.pop_back();
            }

            // Otherwise add current character
            seen.insert(s[i]);
            sequence.push_back(s[i]);
        }

        // Return Stack as a String
        return sequence;
    }

};