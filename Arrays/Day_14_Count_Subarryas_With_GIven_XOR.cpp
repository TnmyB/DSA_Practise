// Brute - O(n^2)

// Optimal
// using unordered_map
// TC = O(n)
// SC = O(n)
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        int curXor = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            curXor = curXor^nums[i];
            count += mp[curXor^k];
            mp[curXor]++;
        }
        return count;
    }
};
