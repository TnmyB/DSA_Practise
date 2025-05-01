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


// Print all recursions

void recurPermute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, int freq[]){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}

vector<vectotr<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()-1] = {0};

    recurPermute(ds, nums, ans, freq);
    return ans;
}
