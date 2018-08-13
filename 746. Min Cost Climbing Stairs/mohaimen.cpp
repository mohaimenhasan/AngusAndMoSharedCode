class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      if (cost.size() == 2)
        return min(cost[0], cost[1]);

      int something = INT_MAX;
      for (int i = cost.size()-1; i >= 0; i++){
        int temp = cost[i];
        cost.pop_back();
        something = min(something, temp + minCostClimbingStairs(cost));
      }
      return something;
    }
};
