class Solution {
public:
int longestSubstring(string s, int k) {
      unordered_map<char, int> counter;
        // populate the map in O(N)
      for (int i = 0; i < s.length(); i++){
          auto it = counter.find(s[i]);
          if (it == counter.end()){
            int temp=1;
            counter.insert(make_pair(s[i], 1));
          }
          else{
            int temp = it->second;
            temp ++;
            it->second = temp;
          }
      }

      int largest = 0;
      int temp_count = 0;
      unordered_map<char, int> temp_map;
        // second map and second iteration
      for (int i = 0; i < s.length(); i++){
        auto it = counter.find(s[i]);
        if (it->second < k){
          if (temp_count > largest){
            largest = temp_count;
          }
          temp_map.clear();
          temp_count = 0;
        }

        it = temp_map.find(s[i]);
        if (it == temp_map.end()){
          temp_map.insert(make_pair(s[i], 1));
        }

        else{
            int temp = it->second;
            temp ++;
            it->second = temp;
            if (it->second >= k){
                temp_count += temp;
            }
        }
      }
      return largest;
    }
};
