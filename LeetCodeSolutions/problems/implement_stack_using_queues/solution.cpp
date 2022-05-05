class MyStack {
public:
  MyStack();
  void push(int x);
  int pop();
  int top();
  bool empty();
private:
  std::queue<int> qStack;
  int qStackTop;
};


MyStack::MyStack() {}
void MyStack::push(int x) {
  // Add Input to Object Queue
  this->qStack.push(x);
  int ctr = this->qStack.size();
  while (ctr > 1) {
    int temp = this->qStack.front();
    this->qStack.pop();
    this->qStack.push(temp);
    ctr--;
  }
}

int MyStack::pop() { 
  int temp = this->qStack.front();
  this->qStack.pop();
  return temp;
}
int MyStack::top() { return this->qStack.front(); }
bool MyStack::empty() { return this->qStack.empty(); }

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */