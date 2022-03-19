class FreqStack {
public:
    FreqStack();
    void push(int val);
    int pop();

private:
    std::map<int, std::stack<int>> valueMap;
    std::map<int, int> countMap;
    int maxCount = 0;
};

// Class Conctructor
FreqStack::FreqStack() : valueMap({}), countMap({}), maxCount(0){}

// Pop the most Frequent Element
int FreqStack::pop(){
    // get current maximum frequency value
    int res = valueMap[maxCount].top();
    // Update count value stack
    valueMap[maxCount].pop();
    
    // Update current maximum count value and count map
    countMap[res]--;

    // only upgrade if there are no other elements with the same count
    if(valueMap[maxCount].empty())
        maxCount--;

    return res;
}

// Push a value into the stack
void FreqStack::push(int val){
    // upgrade the count map or add a new value 
    countMap[val]++;

    // Upgrade current max count 
    maxCount = std::max(maxCount, countMap[val]);

    // upgrade the value map
    valueMap[countMap[val]].push(val);
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */