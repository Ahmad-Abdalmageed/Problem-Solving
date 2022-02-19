class Solution {
public:
    string intToRoman(int num) {
        string conversion = "";
        map<int, string, greater<int>> romans = {
            {1000, "M" },
            {900 , "CM"},
            {500 , "D" },
            {400 , "CD"},
            {100 , "C" },
            {90  , "XC"},
            {50  , "L" },
            {40  , "XL"},
            {10  , "X" },
            {9   , "IX"},
            {5   , "V" },
            {4   , "IV"},
            {1   , "I" },
        };
        int remain = num;

        for(auto itr = romans.begin(); itr != romans.end(); ++itr){
            int reps = remain / itr->first ;
            // cout << "reps : " << reps << endl;
            if(reps > 0){
                // cout << "NUM: " << itr->first << endl;
                for(reps; reps > 0; reps--){
                    conversion.append(itr->second);
                }
                remain = remain % (itr->first);
                // cout << "REM : " << remain << endl;
            }
        }
        return conversion;
    }

    
    
};