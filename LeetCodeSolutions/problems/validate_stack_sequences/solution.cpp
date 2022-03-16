class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
        stack<int> s;
        int iPushed = 0;
        int iPopped = 0;

        // Push and pop the stack according to the sequence
        while(iPushed < pushed.size()){
            s.push(pushed[iPushed]);
            
            // check stack top and first element in popped
            while(!s.empty() && popped[iPopped] == s.top()){
                s.pop();
                iPopped++;
                cout<< "POP : " <<iPopped<<endl;
            }
            iPushed++;
            cout<< "Push : " <<iPushed<<endl;
        }

        if(s.empty()) return true;
        else return false;
    }
};