/// GOT MAJOR HELP  DIDN'T DO IT MYSELF

// LAD 

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      int count = 0;
      unordered_map<int, int> my_map;
      for(int i = 0; i < A.size(); i++){
        for(int j=0; j < B.size(); j++){
          int sum = A[i] + B[j];
          my_map[sum]++;
        }
       }
       for(int i = 0; i < C.size(); i++){
         for(int j=0; j < D.size(); j++){
           int sum = -(C[i] + D[j]);
           if (my_map.find(sum) != my_map.end())
                count += my_map[sum];
            }
        }
      return count;
    }
};
