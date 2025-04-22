// Link - https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int revIndex = -1;
      for(int i = nums.size()-1; i >0 ; i--){
        if(nums[i] > nums[i-1]) {
          revIndex = i;
          break;
        }
      }

      if(revIndex == -1){
        reverse(nums.begin(), nums.end());
        return;
      }

      for(int i = nums.size()-1; i > 0; i--){
        if(nums[i]>nums[revIndex-1]){
          swap(nums[i], nums[revIndex-1]);
          break;
        }
      }

      reverse(nums.begin()+revIndex, nums.end());
    }
};
