// Approach = 1: TC = O(n) SC = O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(uset.find(nums[i]) == uset.end()){
                uset.insert(nums[i]);
            } else{
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};

// Approach - 2 Link List Loop Method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
