// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return findBadVersion(1, n);
    }
private:
    int findBadVersion(int low, int high){
        int mid = low+(high-low)/2;
        
        bool isCurrentBad = isBadVersion(mid);
        if(isCurrentBad){
            bool isBeforeBad = isBadVersion(mid-1);
            if(!isBeforeBad) return mid;
            else return findBadVersion(low, mid-1);


        } else {
            return findBadVersion(mid+1, high);
        }

    }
};