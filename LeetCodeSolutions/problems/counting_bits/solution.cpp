class Solution {
public:

vector<int> countBits(int n){
    vector<int> ONES(n+1, 0);
    int offset = 1;
    for(int nBins = 1; nBins<=n; nBins++){
        if(offset*2 == nBins){
            offset = nBins;
        }
        ONES[nBins] = 1+ONES[nBins-offset];
    }
    return ONES;
}

};