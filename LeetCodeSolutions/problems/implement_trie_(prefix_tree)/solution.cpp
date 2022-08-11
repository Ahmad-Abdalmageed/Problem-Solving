class TrieNode {
public: 
    TrieNode* children[26];
    bool endOfWord;
    
    
    TrieNode() : children{}, endOfWord(false) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
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
        // Insert every character in the root children
        TrieNode* node = root;
        int curChild = 0;
        
        // loop word characters --- the Character is its positon in the children array
        for(int i = 0; i < word.size(); i++) {
            curChild = word[i] - 'a';
            if(node->children[curChild] == nullptr) {
                // Character not found 
                return false;
            }
            
            // Move to the Next node
            node = node->children[curChild];
        }
            
        return node->endOfWord; // IF word exists
    }
    
    bool startsWith(string prefix) {
        // Insert every character in the root children
        TrieNode* node = root;
        int curChild = 0;
        
        // loop word characters --- the Character is its positon in the children array
        for(int i = 0; i < prefix.size(); i++) {
            curChild = prefix[i] - 'a';
            if(node->children[curChild] == nullptr) {
                return false;
            }
            
            // Move to the Next node
            node = node->children[curChild];
        }
        
        return true; // Reached end of prefix without returning
    }
    
    
private: 
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */