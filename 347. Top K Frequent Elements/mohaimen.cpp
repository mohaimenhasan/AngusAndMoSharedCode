// this works


class Solution {
public:
    bool my_function(<pair<int, int> first, <pair<int, int> second){
      return (first.second < second.second);
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map <int, int> my_map;
      for (int i = 0; i < nums.size(); i++){
        auto it = my_map.find(nums[i]);
        if (it == my_map.end()){
          my_map.insert(make_pair(nums[i], 1));
        }
        else{
          int temp = it->second;
          temp ++;
          it->second = temp;
        }
      }
      vector<pair<int, int>> my_vector(my_map.begin(), my_map.end());

      // this sort is not working. use a comparator
      sort(my_vector.rbegin(), my_vector.rend(), my_function);
      vector<int> output;
      for (int i = 0; i<k; i++){
        auto something = my_vector[i];
        output.push_back(something.first);
      }
      return output;
    }
};
