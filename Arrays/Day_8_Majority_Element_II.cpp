// https://leetcode.com/problems/majority-element-ii/description/
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// Example 1:

// Input: nums = [3,2,3]
// Output: [3]

// Example 2:

// Input: nums = [1]
// Output: [1]

// Example 3:

// Input: nums = [1,2]
// Output: [1,2]

// Constraints:

//     1 <= nums.length <= 5 * 104
//     -109 <= nums[i] <= 109

// Follow up: Could you solve the problem in linear time and in O(1) space?

// My Approach - 
// TC - O(n)+O(distinct) SC - O(distinct)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int limit = nums.size()/3;
        
        for(auto it: mp){
            if(it.second > limit){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};


// My Approach - 
// TC - O(n)+O(distinct) SC - O(distinct)
// Improved by updating ans while populating hash map - stop when you have 2 elements
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int limit = nums.size()/3;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > limit){
              ans.push_back(nums[i]);
            }
            if(ans.size()==2){
              return ans;
            }
        }
        return ans;
    }
};

// Optimal
// Similar to Moore's Voting Algorithm but for 2 elements
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int el1 = INT_MIN, el2 = INT_MIN;
        int cnt1 = 0, cnt2= 0;

        for(int i = 0; i < nums.size(); i++){
            if(cnt1 == 0 && nums[i] != el2){
                el1 = nums[i];
                cnt1++;
            } else if(cnt2 == 0 && nums[i] != el1){
                el2 = nums[i];
                cnt2++;
            } else if(el1 == nums[i]){
                cnt1++;
            } else if(el2 == nums[i]){
                cnt2++;
            } else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==el1){
                cnt1++;
            } 
            if(nums[i]==el2){
                cnt2++;
            }
        }
        int limit = nums.size()/3;
        if(cnt1>limit){
            ans.push_back(el1);
        }
        if(cnt2>limit){
            ans.push_back(el2);
        }

        return ans;
    }
};
