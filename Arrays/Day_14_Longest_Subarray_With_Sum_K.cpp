// Using hashing
// iterate array, keep adding each element to the sum and store it into map
// look in the map for the current sum and k's difference
// this is optimal in case the array might have negative elements as well
// TC = O(n) worst O(n^2)
// SC = O(n)
class Solution {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxCount = INT_MIN;
        int curSum = 0;
        for(int i = 0; i < nums.size(); i++){
            curSum += nums[i];
            if(curSum == k){
                maxCount = max(maxCount, i+1);
            }
            int leftSum = k - curSum;
            if(mp.find(leftSum)!=mp.end()){
                int count = i - mp[leftSum];
                maxCount = max(maxCount, count);
            } else{
                mp[curSum] = i;
            }
        }

        return maxSum;
    }
};

// Optimal
// But only when all elements are positive
// TC = O(2n)
// SC = O(1)
class Solution {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        int maxLen = 0;
        int sum = nums[0];
        int left = 0;
        int right = 0;
        while(right<nums.size()){
            while(left<=right && sum>k){
                sum-=nums[left];
                left++;
            }

            if(sum==k){
                maxLen = max(maxLen, right-left+1);
            }
            right++;
            if(right<nums.size()){
                sum+=right;
            }
        }
    }
};
