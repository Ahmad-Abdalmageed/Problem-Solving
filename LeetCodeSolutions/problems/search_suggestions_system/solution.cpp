class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        std::sort(products.begin(), products.end());
        vector<vector<string>> res;
        
        int left = 0;
        int rght = products.size() - 1;
        
        for(int c = 0; c < searchWord.size(); c++)
        {
            char curLetter = searchWord[c];
            
            while(left <= rght && (products[left].size() <= c || products[left][c] != curLetter)) left++;
            while(left <= rght && (products[rght].size() <= c || products[rght][c] != curLetter)) rght--;
            
            vector<string> curSearch;
            int validWords = std::min(3, rght - left + 1);
            
            for(int word = 0; word < validWords; word++)
            {
                curSearch.push_back(products[left + word]);
            }
            
            res.push_back(curSearch);
        }
        return res;
    }
};