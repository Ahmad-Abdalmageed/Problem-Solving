class TrieNode {
public: 
    TrieNode* children[26];
    bool endOfWord;
    
    TrieNode() : endOfWord(false) {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};


class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {

        // Insert every character in the root children
        TrieNode* node = root;
        int curChild = 0;
        
        // loop word characters --- the Character is its positon in the children array
        for(int i = 0; i < word.size(); i++) {
            curChild = word[i] - 'a';
            if(node->children[curChild] == nullptr) {
                node->children[curChild] = new TrieNode();
            }
            
            // Move to the Next node
            node = node->children[curChild];
        }
        
        // at the last character mark end of word
        node->endOfWord = true;
        
        return; // Null
    }
    
    bool search(string word) {
        TrieNode* node= root;
        return dfs(word, 0, node);
    }

        
private: 
    TrieNode* root;
    
    bool dfs(string &word, int startIndex, TrieNode * node) {
        // Base Case --- No Children
        if( node == nullptr ) 
            return false;
        
        // Reached end of Word
        if( startIndex == word.size()) 
            return node->endOfWord;
        
        // Current Child/Character is not a wild card
        if( word[startIndex] != '.') {
            return dfs(word, startIndex+1, node->children[word[startIndex] - 'a']);            
        }
        
        // Wild Card
        for(int i = 0; i < 26; i++) {
            // found one match 
            if(dfs(word, startIndex + 1, node->children[i])) 
                return true;
        }
        
        // found no match
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */