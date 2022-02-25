/*
 * LEET CODE Problems Solution
 * LIST : Algorithms 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits>
#include <string.h>
using namespace std;

// Definition for singly-linked list by LEET CODE.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



vector<int> twoSum(vector<int> & nums, int target);
int removeDuplicates(vector<int>& nums);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2); 
string longestPalindrome(string s);
string convert(string s, int numRows);
int reverse(int x);
int myAtoi(string s);
bool isPalindrome(int x) ;
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
bool isMatch(string s, string p);
bool find (int i, int j, string s, string p);
int maxArea(vector<int>& height);
string intToRoman(int num);
int romanToInt(string s);
string longestCommonPrefix(vector<string>& strs);
vector<vector<int>> threeSum(vector<int>& nums);
int threeSumClosest(vector<int>& nums, int target);
int majorityElement(vector<int>& nums);
vector<string> letterCombinations(string digits);
int compareVersion(string version1, string version2);

void logIntArr(vector<int>);
void logString(string s );
int getMax(vector<int> nums, int part);
int getMin(vector<int> nums, int part); 



/* Main Programm 
 * Usage: Unit Tests and Code Checks 
 */ 

int main(int argc, const char** argv) {
    string v1 = "1.01";
    string v2 = "1.001";
    cout << compareVersion(v1, v2) << endl;
}

/*
 * LEET CODE: Compare Version Numbers
 */ 
int compareVersion(string version1, string version2)
{
    int v1 = 0, v2 = 0;
    int i = 0, j = 0;

    while(i < version1.size() || j < version2.size())
    {
        cout << i << j << endl;
        // Excluding any leading zeros
        while(i < version1.size() && version1[i] != '.')
        {
            cout << "V1 : " << version1[i] << endl;
            v1 = v1*10 + (version1[i] - '0');
            i++;
        }
        while(j < version2.size() && version2[j] != '.')
        {

            cout << "V2 : " << version2[j] << endl;

            v2 = v2*10 + (version2[j] - '0');
            j++;
        }

        // check both versions
        if(v1 < v2){
            return -1;
        } else if(v1 > v2){
            return 1;
        }

        // Reset revisions and increment counters 
        // after ther dot operator
        v1 = 0;
        v2 = 0;
        i++;
        j++;
    }
    return 0;
}

/*
 * LEET CODE: Letter Combinations of a phone number
 */
class Solution{
    public:
        void backtrack(int curI, string curStr){
            if(curStr.size() == input.size()){
                cout << curStr << endl;
                res.push_back(curStr);
                return;
            }
            for(auto c : phone[input[curI]]){
                backtrack(curI+1, curStr + c);
            }
        }

        vector<string> letterCombinations(string digits) {
            input = digits;
            if(digits != ""){
                backtrack(0, "");
            }
            return res;
        }
    private:
        string input;
        vector<string> res = {};
        map<char, string> phone = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

};


/*
 * LEET CODE : Majority Number
 */
// int majorityElement(vector<int>& nums) {
//     map<int, int> table;
//     for(auto num: nums){
//         if(table.find(num) != table.end()){
//             table[num] = table[num] + 1;
//         }else {
//             table[num] = 1;
//         }
//         cout << "num : " << num << " : " << table[num] << endl;
//     }
//     int count = 0;
//     int res;
//     auto itr = table.begin();
//     while(itr != table.end()){
//         if(itr->second > count){
//             count = itr->second;
//             res = itr->first;
//         }
//         itr++;
//     }
//     return res;
// }
// Randomization Solution
int majorityElement(vector<int>& nums) {
    int res;
    while(true){
        int count = 0;
        int idx = rand() % nums.size();
        for(auto num: nums){
            if(num == nums[idx]) count++;
        }
        if(count > nums.size()/2){
            return nums[idx];
        }

    }
}


/*
 * LEET CODE : 3SUM
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    // Sort the Input Array to skip duplicates
    sort(nums.begin(), nums.end());
    logIntArr(nums);
    vector<vector<int>> res;
    // Fix the first two numbers  
    // Search for the third number which equals to
    // z = -( x + y ) and append to the result
    for(int i = 0; i < nums.size(); i++){
        int lptr = i+1;
        int rptr = nums.size() - 1;
        
        // check for duplicate .. Exit loop and skip to the next 
        if( i > 0 && nums[i] == nums[i-1]){

        }else {
            while(lptr < rptr){
                int summation = nums[i] + nums[lptr] + nums[rptr];                
                if(summation < 0){
                    lptr++;
                }
                else if(summation > 0){
                    rptr--;
                }
                else{
                    res.push_back({nums[i], nums[rptr], nums[lptr]});
                    cout << "ADDING : " << lptr << " " << rptr << " " << i << endl;
                    lptr++;
                    while(lptr < rptr && nums[lptr-1] == nums[lptr]){
                        lptr++;
                    }
                }   
            }
        }
    }
        
    return res;
}

/*
 * LEET CODE: Longest Common Prefix
 */
string longestCommonPrefix(vector<string>& strs){    
    string pfx = "";

    // Take the first String as an arbitrary point
    for(int iPfx = 0; iPfx < strs[0].size(); iPfx++){
        // Loop each character and check if it is a common prefix among other strings
        for(auto str : strs){
            if(iPfx == str.size() || str[iPfx] != strs[0][iPfx]) return pfx;
        }
        // Append the character to the pfx holder
        pfx.push_back(strs[0][iPfx]);
    }
    return pfx;
}

/*
 * LEET CODE: Roman to Integer
 */ 
int romanToInt(string s) {
    int res = 0; 
    int i = 0;
    map<char, int> romans = {
        { 'M' , 1000},
        { 'D' , 500 },
        { 'C' , 100 },
        { 'L' , 50  },
        { 'X' , 10  },
        { 'V' , 5   },
        { 'I' , 1   },
    };

    while(i < s.size()){
        if(i+1 < s.size() && romans[s[i+1]] > romans[s[i]]){
            res = res + (romans[s[i+1]] - romans[s[i]]);
            i = i + 2;
         } else{
            res = res + romans[s[i]];
            i++;

        }
    }
    return res;
}



/*
 * LEET CODE: Integers to Roman
 */
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
        // Calculate the Number of Repeatitons
        int reps = remain / itr->first ;

        // Append to the Conversion String repeated times
        if(reps > 0){
            for(reps; reps > 0; reps--){
                conversion.append(itr->second);
            }
            remain = remain % (itr->first);
        }
    }
    return conversion;
}

/*
 *
 * LEET CODE: Container with most Water
 */
int maxArea(vector<int>& height) {
    int area = 0;
    int current;
    int i = 0 ;
    int j = height.size()-1;
    
    while(j > i){
        current = min(height[i], height[j]) * (j - i);
        area = max(current, area);
        if(height[i] < height[j]){
            i++;
        } else {
            j--;
        }
    }
    return area ;
}

/*
 * LEET CODE: Regular Expression Matching
 */
bool isMatch(string s, string p) {
    // Call the Finder Function
    return find(0, 0, s, p);
}

// Top Down DP Solution
bool find (int i, int j, string s, string p){
    bool match;

    // Match is found when both pointers reach the end
    if(i >= s.size() && j >= p.size()) return true;

    // Match is not found when Pattern pointer reaches the end
    if(j >= p.size()) return false;
    
    // Find the Match
    match = ((s[i] == p[j]) || (p[j] == '.')) && i < s.size();

    // Case: Next element is *
    if(j+1 < p.size() && p[j+1] == '*'){
        // Choose whether to use the star or not
        return ((find(i+1, j, s, p) && match) || (find(i, j+2, s, p)));
    }

    if(match){
        return find(i+1, j+1, s, p);
    }

    // No match found return false
    return false;
}
/*
 * LEET CODE: Add Two Numbers 
 */ 
// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
// }


/*
 * LEECODE: TWO SUM
 * 
 * 
 */
// vector<int> twoSum(vector<int> & nums, int target){
//     vector<int> res;
//     for(unsigned int i = 0; i < nums.size(); i++){
//         for(unsigned int j =  i + 1; j < nums.size(); j++){
//             if(nums[i] + nums[j] == target){
//                 res.push_back(i);
//                 res.push_back(j);
//             }
//         }
//     }

//     return res;
// }

// Using Maps
vector<int> twoSum(vector<int> & nums, int target)
{
    vector<int> res; 
    map<int, int> table;

    for(unsigned int i = 0; i < nums.size(); i++)
    {
        int comp = target - nums[i];

        if( table.find(comp) != table.end())
        {
            res.push_back(i);
            res.push_back(table[comp]);
        }


        table.insert({nums[i], i});
    }

    return res;
}

/*
 * LEET CODE: Remove Duplicates from Sorted Array
 *
 */

// int removeDuplicates(vector<int>& nums)
// {
//     // Define the parsing pointers for the first two elements 
//     int i = 0;
//     for(int j = 1; j < nums.size(); j++){
//         if(nums[i] != nums[j]){
//             i = i + 1;
//             nums[i] = nums[j];
//         }
//     }
//     return i+1;
// }

int removeDuplicates(vector<int>& nums)
{
    vector<int>::iterator res = unique(nums.begin(), nums.end());
    nums.erase(res, nums.end());
    return nums.size();
}

/*
 * LEET CODE: Median of Two Sorted Arrays 
 *
 */

// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     // Calculated the size of both arrays combined 
//     unsigned int size = (nums1.size() + nums2.size());
//     vector<int> resArr;
//     int i = 0;
//     int j = 0;
//     int count;
//     double res;

//     for(count = 0; count <= (int)(size/2); count++){               
//         if(nums1[i] <= nums2[j] && i < nums1.size()){
//             resArr.push_back(nums1[i]);
//             i++;
//         }
//         if (nums1[i] > nums2[j] && j < nums2.size()){
//             resArr.push_back(nums2[j]);
//             j++;
//         }
//     }
//     // Even Case 
//     if(size % 2 == 0){
//         if(i >= nums1.size()){
//             resArr.push_back(nums2[j]);
//         } else if(j >= nums2.size()){
//             resArr.push_back(nums1[i]);
//         }
//         res = (*(resArr.end()-1) + *(resArr.end() - 2)) / 2.0 ;
//     } else {
//         res = *(resArr.end()-1);
//     }

//     return res;
// }

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //  Swapping Arrays to search the smaller array always 
    if(nums2.size() < nums1.size()){
        vector<int> temp = nums2;
        nums2 = nums1;
        nums1 = temp;
    }

    int lo = 0;
    int hi = nums1.size();
    int totSize = nums1.size() + nums2.size();

    while(lo <= hi){
        int partX = (lo + hi) / 2 ;
        int partY = ((totSize + 1) / 2) - partX;


        // Calculate Left and Right Partitions (Elements) of both arrays 
        int lX = getMax(nums1, partX);
        int rX = getMin(nums1, partX);

        int lY = getMax(nums2, partY);
        int rY = getMin(nums2, partY);

        // Check Median Condition == LeftX <= Righty and Lefty <= RightX
        if((lX <= rY) && (lY <= rX)){
            //  Even Case Return Average
            if(totSize %2 == 0){
                return (max(lX, lY) + min(rX, rY)) / 2.0;
            } else {
                return max(lX, lY);
            }
        }

        //  Shifting the partitioning Point
        if(lX > rY){
            hi = partX -1;
        } else {
            lo = partX +1;
        }
    }
    // Not Sorted Case, Search Failed
    return -1;

}

int getMax(vector<int> nums, int part){
    if(part == 0){
        return numeric_limits<int>::min();
    } else {
        return nums[part-1];
    }
}
int getMin(vector<int> nums, int part){
    if(part == nums.size()){
        return numeric_limits<int>::max();
    } else {
        return nums[part];
    }
}




/*
 *
 * LEET CODE: Longest Palindromic Substring 
 * 
 */
// string longestPalindrome(string s){
//     int max = 0;
//     string res;
//     if (s.size() == 1){
//         return s ;
//     }
//     for(unsigned int i = 0; i < s.size(); i++){
//         for(unsigned int j = i+1; j < s.size(); j++){
//                 string subs = s.substr(i, j - i);
//                 string sRev(subs);
//                 reverse(sRev.begin(), sRev.end());
//                 if(!(subs.compare(sRev)) && (subs.size() > max)){
//                     max = subs.size();
//                     res = subs;
//                 }
//         }
//     }
//     if (res.size() == 0){
//         return string(1, s[0]);
//     }
//     return res;
// }

string longestPalindrome(string s){
    int max = 0;
    string res;
    if(s.size() == 1){
        return s;
    }
    for(unsigned int i = 0; i < s.size() ; i++){
        
        // Odd Case .. Center Expansion
        int left = i; // Do not Use Unsigned Int
        int right = i;

        while(left >= 0 && right < s.size()  &&  s[left] == s[right]){
            if((right - left + 1) > max){
                max = right - left + 1;
                res = s.substr(left, right - left + 1);
            }
            left--;
            right++;
        }

        // Even Case
        left = i;
        right = i+1;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            if((right - left + 1) > max ){
                max = right - left + 1;
                res = s.substr(left, right - left + 1);
                cout << res << endl;

            }
            left--;
            right++;
        }
    }
    return res;
}

/*
 *
 * LEET CODE: Zigzag Conversion 
 */
// string convert(string s, int numRows){
//     string res;
//     int row;
//     int element;
//     for(row = 0; row <= numRows; row++){
//         // Redefine the Next Element Finder
//         element = 0;

//         // Add the First Element in the Row
//         res.push_back(s[row]);

//         while(element <= s.size() - 1){
//             //  Calculate the Next Element in the Zigzag    
//             element = row + element + (numRows-1)*2;

//             // Check element bounds 
//             if( element > s.size()) break ; 

//             //  Add the Elements in the Middle Zigzag
//             if(row>0 && row < numRows){
//                 cout << "mid : " << element - 2 *row << endl;
//                 res.push_back(s[element - 2*row]);
//             }
//             res.push_back(s[element]);
//             cout << element << endl;
//         }
//     }
//     return res;

// }
string convert(string s, int numRows){
    string res; 
    int element;

    // Edge Case, numRows == 1
    if (numRows == 1) return s ;

    // Element incrementing and Zigzag Formation
    for(int r = 0; r <= numRows - 1; r++){
        element = 2* (numRows - 1);
        for(int i = r; i < s.size() ; i = i + element){
            res.push_back(s[i]);

            // Case : Middle Rows Elements 
            if( (r > 0) && (r < numRows - 1) && (i + element - 2*r < s.size()) ){
                res.push_back(s[i + element - 2*r]);
            }
        }
    }

    return res;
}

/*
 * LEET CODE: Reverse Integer
 *
 * 
 */
int reverse(int x) {
    int digit;
    int res = 0;
    int MAX = 2147483647;
    int MIN = -MAX;

    while(x != 0){
        //  Check Result out of bounds
        if(res > MAX / 10 || (res == MAX / 10 && digit >= MAX%10 )) return 0;
        if(res < MIN / 10 || (res == MIN / 10 && digit <= MIN%10 )) return 0;

        // Extract each digit from X and Reverse 
        digit = x % 10 ;
        x = x / 10;
        res = (res * 10) + digit;
    }

    return res;
}


/*
 * LEET CODE : String to Integer (ATOI)
 */
int myAtoi(string s){
    int res = 0;
    int digit;
    int sign = 1;
    int MAX = INT32_MAX;
    int MIN = INT32_MIN;
    int c = 0;
    
    // Increment untill first non-white space is found and ignore + sign
    while((int)s[c] == 32) c++;

    // Check Char for sign
    if((int)s[c] == 45 || (int)s[c] == 43){
            sign= s[c]=='-' ? -1 : 1;
        c++;
    }
    // Only convert characters in range of digits
    // 0 - 9 --> 48 - 57
    while((int)s[c] >= 48 && (int)s[c] <= 57){
        // Convert Current Digit
        digit = (s[c] - '0') *sign;
        // Check for Bounds

        if(res > MAX / 10 || (res == MAX / 10 && digit > MAX%10 )) return MAX;
        if(res < MIN / 10 || (res == MIN / 10 && digit < MIN%10 )) return MIN;

        // Shft the result left by one
        //  Add the converted digit
        res = res * 10 + digit ;

        // Increment
        c++;
    } 

    return res;
}

/*
 * LEET CODE: Palindrom Number
 */

bool isPalindrome(int x) {
    int xRev = 0;
    int digit ;
    int MAX = INT32_MAX;
    int MIN = INT32_MIN;

    // Return False if Negative Number
    if(x < 0 || x%10 == 0) return 0;
    
    // Reverse the Input and Compare to Original
    while(x > xRev){
        xRev = xRev * 10 + x % 10;
        x = x / 10;
    }
    if (xRev == x || xRev/10 == x) return true;
    else return false;
}



void logIntArr(const vector<int> arr){
    for(unsigned int i = 0 ; i < arr.size() ; i++){
        cout << i << " : " << arr[i] << endl;
    }
}
