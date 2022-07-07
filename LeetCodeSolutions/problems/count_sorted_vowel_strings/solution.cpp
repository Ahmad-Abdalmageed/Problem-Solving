class Solution {
public:
  int countVowelStrings(int n);

private:
  std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  int combRes = 0;
  void backtrack(int combSize, char lastVowel);
};


int Solution::countVowelStrings(int n) {
  // Call the Back Tracking Algorithm
  this->backtrack(n, ' ');
  return this->combRes;
}

void Solution::backtrack(int combSize, char lastVowel) {
  // BASE CASE: Combsize == 0
  if(combSize == 0){
    this->combRes++;
    return;
  } else {
    for(auto curVowel: this->vowels){
      if(curVowel >= lastVowel){
        this->backtrack(combSize-1, curVowel);
      }
    }
  }
}





// SLOWER SOLUTION
// int Solution::countVowelStrings(int n) {
//   // Call the backtracking algorithm for every vowel existing
//   for (int vowel = 0; vowel < this->vowels.size(); vowel++) {
//     this->backtrack("", vowel, n);
//   }
//   return this->combRes;
// }

// void Solution::backtrack(std::string curComb, int vowel,
//                                   int combSize) {
//   // Base Case: Reached the Maximum Allowed Combination size
//   if (curComb.size() == combSize) {
//     this->combRes++;
//     return;
//   }

//   if (curComb.size() < combSize) {
//     // Try All Possibilties using backtracking
//     curComb.push_back(this->vowels[vowel]);
//     this->backtrack(curComb, vowel + 1, combSize);
//     curComb.pop_back();
//   }
// }
