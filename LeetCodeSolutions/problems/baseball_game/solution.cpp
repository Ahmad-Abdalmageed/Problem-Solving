class Solution {
public:
    int calPoints(vector<string>& ops){
        // Create Score Stack
        std::stack<int> score;
        int res = 0;

        // Loop the Given Operations and operate on stack
        for(auto op: ops){
            // Operations 
            if(op == "D") score.push(score.top() * 2);
            else if(op == "C") score.pop();
            else if(op == "+") {
                int last_score = score.top();
                score.pop();
                int prev_score = score.top();
                score.push(last_score);
                score.push(last_score + prev_score);
            }

            // Score Extraction
            else {
                score.push(std::stoi(op));
            }
        }

        while(!score.empty()){
            res+= score.top();
            score.pop();
        }
        return res;
    }

};