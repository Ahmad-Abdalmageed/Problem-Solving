class Solution {
public:
  bool isValid(string s)
  {
    // for each opening Parentheses add its closing one
    stack<char> parenthesesSequence;
    for (auto const &bracket : s)
    {
      switch (bracket)
      {
      case '{':
        parenthesesSequence.push('}');
        break;
      case '(':
        parenthesesSequence.push(')');
        break;
      case '[':
        parenthesesSequence.push(']');
        break;
      default:
        // When adding a closing bracket without it's openning one 
        // retrun false
        if (parenthesesSequence.empty() || bracket != parenthesesSequence.top())
          return false;
        // when adding closing bracket that match the closing ones added in the
        // stack -> pop the stack
        else
          parenthesesSequence.pop();
      }
    }
    // return true only if stack is empty after operations
    return parenthesesSequence.empty();
  }

};