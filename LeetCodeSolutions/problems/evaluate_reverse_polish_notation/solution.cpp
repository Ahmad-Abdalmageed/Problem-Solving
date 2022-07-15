class Solution {
public:
  //  LEETCODE: 150. Evaluate Reverse Polish Notation
  int evalRPN(vector<string> &tokens)
  {
    // map operations to functions
    constexpr auto operation = [](char op) -> function<int(int, int)>
    {
      switch (op)
      {
      case '+':
        return std::plus<>();
        break;
      case '-':
        return std::minus<>();
        break;
      case '*':
        return std::multiplies<>();
        break;
      case '/':
        return std::divides<>();
        break;

      default:
        return nullptr;
        break;
      }
    };

    //  Using Stack to store Operands
    std::stack<int> operandStack;
    int operationResult;

    // Get each token
    for (auto const &token : tokens)
    {
      // current char is an operation , pop two elements
      // from stack and calculate the result
      if (token.size() == 1 && operation(token[0]))
      {
        const auto rhs = operandStack.top();
        operandStack.pop();
        const auto lhs = operandStack.top();
        operandStack.pop();

        // Perform the calculation in token[0] == '=,-.*,/'
        // on lhs and rhs
        operandStack.push(operation(token[0])(lhs, rhs));
      }
      else
      {
        operandStack.push(std::stoi(token));
      }
    }
    return operandStack.top();
  }

};