class Solution {
public:
    vector<string> generateParenthesis(int n){
        pSize = n;
        backTrackParens("", 0, 0);
        return res;

    }

    void backTrackParens(string s, int nClosed, int nOpen){
        cout << s << endl;
        // Base Case appen result
        if(nClosed==nOpen && nOpen==pSize){
            res.push_back(s);
            return;
        }

        // Add an open Parentheses 
        if(nOpen < pSize){
            s.push_back('(');
            backTrackParens(s, nClosed, nOpen+1);
            s.pop_back();
        }

        // Closed Parentheses 
        if(nClosed < nOpen){
            s.push_back(')');
            backTrackParens(s, nClosed+1, nOpen);
            s.pop_back();
        }
    }

private:
    int pSize;
    vector<string> res;
};