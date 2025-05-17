// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int i = 0;
        int prev = i;

        while(i < nums.size()){
            while(i < nums.size()-1 && nums[i]==nums[i+1]){
                i++;
            }
            count++;
            nums[prev] = nums[i];
            i++;
            prev++;

        }

        return count;
    }
};

// Approach - simple
// TC = O(n)
// SC = O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }

        return i+1;
    }
};
