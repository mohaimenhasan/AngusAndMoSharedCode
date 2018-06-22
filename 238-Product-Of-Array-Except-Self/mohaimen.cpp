/*
Given an array nums of n integers where n > 1,
return an array output such that output[i] is equal to the product of all the
elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity?
(The output array does not count as extra space for the purpose of space complexity analysis.)

*/


/*
here's my idea:>

dumb idea:

try multiplying everything on the same place every time
Time complexity would be out of the roof

trying to outsmart:

get the product once and then divide it by the index LOL 3smart5me
however, what if I try multiplying by the receprocal of the number
so like 2 -> 1/2

basic idea:

need a prcess with O(1) access
so indeed a hash table maybe?

1*2*3*4 = 24
24/2 = 12
24/1 = 24
24/3 = 8
24/4 = 6
1,2,3,4
24,12,8,6



*/





class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector <int> outputArray;
      int product;
      for (int i=0; i <nums.size(); i++){
        product=product*nums[i];
      }
      for (int i=0; i < nums.size(); i++){
        int out=product*1/nums[i];
        outputArray.push(out);
      }
      return outputArray;
    }
};
