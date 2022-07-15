class MinStack
{
public:
  void push(int val);
  void pop();
  int top();
  int getMin();

private:
  // using two stack, one that is used 
  // for regular stacking and the other
  // for retrieving the minimum elements
  std::stack<int> normallStack;
  std::stack<int> monotonicDecreaseStack;
};

void MinStack::push(int val)
{
  //  Normall Push
  this->normallStack.push(val);

  // Monotonically Decreasing Push
  if(this->monotonicDecreaseStack.empty() || val <= this->getMin())
    this->monotonicDecreaseStack.push(val);
}
void MinStack::pop()
{
  //  Remove from both stacks in case of minimum element
  if(this->normallStack.top() == this->getMin()){
    this->monotonicDecreaseStack.pop();
  }

  this->normallStack.pop();
}
int MinStack::top()
{
  return this->normallStack.top();
}
int MinStack::getMin()
{
  return this->monotonicDecreaseStack.top();
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */