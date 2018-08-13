class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
      sort(num.begin(), num.end());
      vector<vector<int>> output;
      int my_arr[num.size()];
      for(int i = 0; i < num.size(); i++){
          my_arr[i] = num[i];
      }
      do{
        vector<int> boy;
        for (int i =0; i < num.size(); i++){
          boy.push_back(my_arr[i]);
        }
        output.push_back(boy);
      }
        while (next_permutation(my_arr, my_arr+num.size()));
    return output;
  }
};
