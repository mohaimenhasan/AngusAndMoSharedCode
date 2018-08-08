class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map <char, int> my_map;
      int largest = 0;
      int prev_it = 0;
      int current_it = 0;
      if (s.length() <= 1)
        return s.length();
      while(current_it < s.length()){
        auto it = my_map.find(s[current_it]);
        if (it == my_map.end()){
          auto my_pair = make_pair(s[current_it], current_it);
          my_map.insert(my_pair);
          current_it ++;
        }
        else{
          int count = current_it - prev_it;
          if (count > largest)
            largest = count;
          prev_it = it->second + 1;
          if (s[current_it] == s[current_it -1]){
            my_map.clear();
            prev_it = current_it;
          }
          else
            my_map.erase(s[current_it]);
        }
      }
      int count = current_it - prev_it;
      if (count > largest)
        largest = count;
      return largest;
    }
};
