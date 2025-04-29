// https://leetcode.com/problems/reverse-pairs/description/

// Brute 
// O(n^2)

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if((double)nums[i]>(double)2*nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
