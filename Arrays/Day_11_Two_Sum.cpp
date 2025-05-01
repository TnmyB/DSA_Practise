// Brute - O(n^2) with 2 loops

// Better - using hashing
// TC = O(n)
// SC = O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int otherPair = target - nums[i];
            if(umap.find(otherPair) != umap.end()){
                ans.push_back(umap[otherPair]);
                ans.push_back(i);
                return ans;
            }
            umap[nums[i]] = i;
        }

        return ans;
    }
};

// No Optimal
// Use 2 pointer = create an array of array of num & element, sort, use start & end, move points greedily and look for sum
// Does not help in reducing the space complexity but in case if asked that if there are any 2 sum pairs, then yes it is better(TC = O(n)+O(nlogn) SC = distorted array)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>> storeNums;
        for(int i = 0; i < nums.size(); i++){
            vector<int> temp = {nums[i], i};
            storeNums.push_back(temp);
        }
        sort(storeNums.begin(), storeNums.end());
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            if(storeNums[start][0] + storeNums[end][0] == target){
                return {storeNums[start][1], storeNums[end][1]};
            } else if (storeNums[start][0] + storeNums[end][0] < target){
                start++;
            } else{
                end--;
            }
        }
        return {-1, -1};
    }
};
