// 
// Problem solving Playground File
// 

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <limits>
#include <string.h>
using namespace std;

vector<int> reverseArray(vector<int> a);
vector<int> dynamicArray(int n, vector<vector<int>> queries);
vector<int> matchingStrings(vector<string> strings, vector<string> queries);
long arrayManipulation(int n, vector<vector<int>> queries);
vector<int> twoSum(vector<int> & nums, int target);
int removeDuplicates(vector<int>& nums);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2); 
string longestPalindrome(string s);

void logIntArr(vector<int>);
void logString(string s );
int getMax(vector<int> nums, int part);
int getMin(vector<int> nums, int part); 

int main()
{
    string s = "babad";
    string res = longestPalindrome(s);
    cout << res << endl;

}


/*
 * HACKER RANK::Problem Solving.Array
 * 
 */
vector<int> reverseArray(vector<int> a) 
{
    vector<int> revArray;
    // for (int i: a)
    // {
    //     revArray.push_back(i);
    // }
    // reverse(revArray.begin(), revArray.end());
    
    for (auto i = a.end() -1 ; i >= a.begin(); i--)
    {
        revArray.push_back(*i);
    }

    return revArray;

}


/*
 * HACKER RANK::Problem Solving.Dynamic Array
 * 
 */

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    using namespace std;
    vector<vector<int>> arr(n);
    vector<int> answers ;
    int answer = 0;

    for(unsigned int i = 0; i < queries.size() ; ++i){
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = (x ^ answer) % n;

        if (queries[i][0] == 1){
            arr[idx].push_back(y);
        }
        else if (queries[i][0] == 2){
            answer = arr[idx][y % (arr[idx].size())];
            answers.push_back(answer);
            std::cout << answer << std::endl;
        }
    }
    return answers;
}


/*
 * HACKER RANK::Problem Solving.Left Rotation
 * 
 */
vector<int> rotateLeft(int d, vector<int> arr) {
    // Create a buffer array to hold the rotated items 
    vector<int> buffer ; 

    // Insert the Rotated items into the buffer
    buffer.insert(buffer.end(), arr.begin()+d, arr.end());
    // Push back the ramainig elements from the original array
    buffer.insert(buffer.end(), arr.begin(), arr.begin()+d);

    // Return Rotated Buffer
    return buffer;
}

/*
 * HACKER RANK::Problem Solving.Sparse Arrays 
 * 
 */
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int> results(queries.size());
    // Search for each instance from the queries Array in the Strings Array
    int idx = 0;
   
    for(auto& q: queries){
        // std::cout << "Query: "<< q << "\n";
        for(auto& string: strings){       
            if(string == q){
                // std::cout << "Found :" << string << "\n";

                // Increment the query 
                results[idx] = results[idx] + 1;
            }
        }
        std::cout << results[idx] << std::endl;
        // Next Query
        idx++;
    }
    return results;
}

/*
 * HACKER RANK::Problem Solving.Array_Manipulation 
 * 
 */
// long arrayManipulation(int n, vector<vector<int>> queries) {
//     vector<int> res(n);
//     for(auto & op: queries){
//         int k = op[2];
//         // Apply the Operation on the Specified Range from the Query and insert the Result in the res Array
//         std::transform(res.begin()+op[0], res.begin()+op[1]+1, res.begin()+op[0], [k](int i){return i+k;});
//     }
//     // Return the Maximum Number resulted from the operations 
//     return *std::max_element(res.begin(), res.end());

// }

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<int_least32_t> res(n+1);
    long max = 0;

    for(auto & op: queries){
        // Store the Operations paramaters 
        int a = op[0];
        int b = op[1];
        int k = op[2];

        // Apply the Operation on the Specified Range from the Query and insert the Result in the res Array
        res[a] += k;
        res[b+1] -= k; 
    }

    // Calculate the maximum value 
    long prev = 0;
    for(auto & i : res){
        prev = prev + i;
        if (prev > max){
            max = prev;
        }

    }
    return max;

}


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

    for(unsigned int i = 0; i < s.size() ; i++){
        
        // Odd Case .. Center Expansion
        unsigned int left = i;
        unsigned int right = i;

        while(left >= 0 && right <= s.size()){
            if((right - left + 1) > max &&  s[left] == s[right]){
                max = right - left + 1;
                res = s.substr(left, right - left + 1);
                cout << "res : " << res << endl;
            }
            left--;
            right++;
        }

        // Even Case
        left = i;
        right = i+1;
        while(left >= 0 && right <= s.size()){
            if((right - left + 1) > max && s[left] == s[right]){
                max = right - left + 1;
                res = s.substr(left, right - left + 1);
            }
            left--;
            right++;
        }
        cout << max << endl;
    }
    return res;
}


void logIntArr(const vector<int> arr){
    for(unsigned int i = 0 ; i < arr.size() ; i++){
        cout << i << " : " << arr[i] << endl;
    }
}
