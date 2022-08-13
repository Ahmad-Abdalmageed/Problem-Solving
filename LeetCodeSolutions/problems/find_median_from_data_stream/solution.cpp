class MedianFinder
{
public:
  MedianFinder() {};
  void addNum(int num);
  double findMedian();

private:
  std::priority_queue<int> lowerHeap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> higherHeap;
};


void MedianFinder::addNum(int num)
{
  // Always add to the lower Heap
  if (lowerHeap.empty())
  {
    lowerHeap.push(num);
    return;
  }

  // Heaps have same size or difference 1 element
  if (lowerHeap.size() > higherHeap.size())
  {
    // LowerSize >  HigherSize --- shift to Higher
    if (lowerHeap.top() > num)
    {
      higherHeap.push(lowerHeap.top());
      lowerHeap.pop();
      lowerHeap.push(num);
    }
    else
    {
      higherHeap.push(num);
    }
  }
  else
  {
    if (higherHeap.top() < num)
    {
      lowerHeap.push(higherHeap.top());
      higherHeap.pop();
      higherHeap.push(num);
    }
    else
    {
      lowerHeap.push(num);
    }
  }
}

double MedianFinder::findMedian()
{
  double median = 0.0;

  if (lowerHeap.size() == higherHeap.size())
  {
    median = lowerHeap.top() + ((higherHeap.top() - lowerHeap.top()) / 2.0);
  }
  else
  {
    if (lowerHeap.size() > higherHeap.size())
      median = lowerHeap.top();

    else
      median = higherHeap.top();
  }
  return median;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */