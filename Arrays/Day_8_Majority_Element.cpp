// https://leetcode.com/problems/majority-element/description/
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Example 1:

// Input: nums = [3,2,3]
// Output: 3

// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// TC = O(n) SC = O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = nums[0];
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                el = nums[i];
            }

            if(nums[i] == el){
                cnt++;
            } else{
                cnt--;
            }
        }

        int ansCnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el){
                ansCnt++;
            }
        }

        if(ansCnt >= nums.size()/2){
            return el;
        }
        return -1;
    }
};


// Approach - 2 
// O(n log n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
