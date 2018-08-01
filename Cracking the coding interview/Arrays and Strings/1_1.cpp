// Implement an algorithm to determine if a string has all unique
// characters What if you can not use additional data structures?


// O(n) solution

class Solution {
  bool isUnique(string given_){
      int size_ = given_.length();
      unordered_set <char> my_set;
      for (int i = 0; i < size_; i++){
        auto it = my_set.find(given_[i]);
        if (it == my_set.end()){
          my_set.insert(given_[i]);
        }
        else
          return false;
      }
      return true;
    }
};

// O(n^2) solution

class solution {
public:
  bool isUnique2(string given_){

    for (int i = 0; i < given_.length(); i++){
        for (int j = 0; j < given_.length(); j++){
          if (i != j){
            if (given_[i] == given_[j])
              return false;
          }
        }
    }
    return true;
  }
}
