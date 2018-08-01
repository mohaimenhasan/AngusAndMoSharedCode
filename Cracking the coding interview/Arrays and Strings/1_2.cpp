//  Write code to reverse a C-Style String
// (C-String means that “abcd” is represented as five characters, including the null character )


// using a vector

class Solution{
public:
  string reverseString(string given){
      list<char>stack_;
      for (int i = 0; i < given.length(); i++){
        stack_.push_back(given[i]);
      }
      stack_.push_back('\0');
      for (int i = 0; i < given.length(); i++){
        given[i] = stack_.back();
        stack_.pop_back();
      }
      return given;
    }
};

// reduce memory with o(n) this doesn't work GG

class Solution{
public:
  string reverseString(char str[]){
    size = 0;
    while (str[size] != '\0'){
      size++;
    }
    char* ptr[size];
    int i = 0;
    for (i = 0; i <= size; i++){
      ptr[i] = &str[i];
    }

    int begin = 0;
    int end = size;
    bool done = false;

    while(!done){

      reverseVal(ptr[begin], ptr[end]);
      begin ++;
      end --;
      if (begin >= end)
        done = true;
      else
        done = false;

    }
  }
  void reverseVal(char* ptr1, char* ptr2){
    int temp = &ptr1;
    &ptr1 = &ptr2;
    &ptr2 = temp;
  }
};
