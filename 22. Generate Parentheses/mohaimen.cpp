//doesn't work 

class Solution {
public:
    vector<string> output;
    vector<string> generateParenthesis(int n) {
      if (n == 0)
        return output;
      recurs(n);
      return output;
    }
    string recurs(int n){
      string str_;
      for(auto i=0; i < n; n++){
        str_ = str_ + "(";
      }
      for(auto i=0; i < n; n++){
        str_ = str_ + ")";
      }
      output.push_back(str_);
      if (n == 1)
        return str_;
      string temp = "()"+recurs(n-1);
      output.push_back(temp);
      temp = recurs(n-1) + "()";
      output.push_back(temp);
      return str_;
    }
};
