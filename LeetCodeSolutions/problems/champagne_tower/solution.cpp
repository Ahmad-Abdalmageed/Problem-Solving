class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass){
        // Get the first rows number of glasses 
        vector<double> glasses = {(double)poured};
        if(poured == 0) return 0.0;
        
        for(int row =0; row < query_row; row++){

            vector<double> NEXT_ROW(glasses.size()+1, 0.0);
            
            for(int glass = 0; glass < glasses.size(); glass++){

                double pour = (glasses[glass] - 1.0)/2.0;

                if(pour > 0.0){
                    NEXT_ROW[glass] += pour;
                    NEXT_ROW[glass+1] += pour;
                }
            }
            glasses.swap(NEXT_ROW);
        }
        return min(1.0, glasses[query_glass]);
    }

    void logIntArr(const vector<double> arr){
        for(unsigned int i = 0 ; i < arr.size() ; i++){
            cout << i << " : " << arr[i] << endl;
        }
    }

};