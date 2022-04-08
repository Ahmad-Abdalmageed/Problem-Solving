class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums);
    int add(int val);
private: 
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int k;
};


KthLargest::KthLargest(int k, std::vector<int>& nums){
    // Initialize the Min Heap 
    this->k = k;
    this->minHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>(nums.begin(), nums.end());

    while (this->minHeap.size() > this->k){
        // Removing Smaller Elements 
        this->minHeap.pop();
    }
}

int KthLargest::add(int val){
    this->minHeap.push(val);
    
    if(this->minHeap.size() > this->k) this->minHeap.pop();
    return this->minHeap.top();
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */