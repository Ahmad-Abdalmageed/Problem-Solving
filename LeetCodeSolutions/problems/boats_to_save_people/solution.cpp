class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // First Sort the people's weights 
        std::sort(people.begin(), people.end());
        int boatCount = 0;
        int i = 0;
        int j = people.size()-1;

        // as Long as the Heaviest person can share a boat with the lightest person
        // then do so , if they can't then they get their own boat
            while(i <= j){
                // The Heavier person gets his own boat unless he can share
                boatCount++;

                if(people[i] + people[j] <= limit) i++;
                j--;
            }
            return boatCount;
    }
};