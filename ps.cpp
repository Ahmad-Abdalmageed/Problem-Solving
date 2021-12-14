// 
// Problem solving Playground File
// 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> reverseArray(vector<int> a);
vector<int> dynamicArray(int n, vector<vector<int>> queries);
vector<int> matchingStrings(vector<string> strings, vector<string> queries);
long arrayManipulation(int n, vector<vector<int>> queries);


int main()
{
    int n = 4;
    vector<vector<int>> q = {{2, 3, 603}, {1, 1, 286}, {4, 4, 882}};
    long res = arrayManipulation(n, q);

    std::cout << res << "\n";
    return 0;
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