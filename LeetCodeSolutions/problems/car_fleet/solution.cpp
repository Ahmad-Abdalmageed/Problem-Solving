class Solution {
public:
  // LEETCODE: 853. Car Fleet
  int carFleet(int target, vector<int> &position, vector<int> &speed)
  {
    int numberOfCars = position.size();
    std::vector<std::pair<int, double>> positionTimeStack;
    // Create pairs of position and speeds 
    for(int currentCar = 0; currentCar < numberOfCars; currentCar++){
      double timeToTarget = (double) (target - position[currentCar]) / speed[currentCar];
      positionTimeStack.push_back({position[currentCar], timeToTarget});
    }

    // Sort the Pairs according to the Postion ascendingly
    std::sort(positionTimeStack.begin(), positionTimeStack.end());

    int carFleets = 0;
    double fastestCar = 0.0;
    for(auto carIterator = positionTimeStack.rbegin(); carIterator != positionTimeStack.rend(); carIterator++){
      if(carIterator->second > fastestCar){
        fastestCar = carIterator->second;
        carFleets++;
      }
    }
    return carFleets;
  }

};