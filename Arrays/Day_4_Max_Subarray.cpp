// Brute Force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxSum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            long long sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                if(sum > maxSum){
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }
};

// Kadane's algo - Do not carry negatives into your future
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxSum = INT_MIN;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > maxSum){
                maxSum = sum;
            }
            if(sum < 0){
                sum = 0;
            }

        }
        return maxSum;
    }
};
