// https://leetcode.com/problems/4sum/description/
// 

// Brute - with 4 loops = o(n^4)

// Better - use hash set
// TC = O(n^3 * log m)
// SC = O(n) + 2*O(quads)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> tempSet;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                set<long long> hashSet;
                for(int k = j + 1; k < nums.size(); k++){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if(hashSet.find(fourth) != hashSet.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        tempSet.insert(temp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(tempSet.begin(), tempSet.end());
        return ans;
    }
};

// Optimal - using 2 pointer with additional 2 pointers fixed
// TC = O(n^2 * n)
// SC = O(1) (only to return)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j = i+1; j < nums.size(); j++){
                if(j != i+1 && nums[j-1]==nums[j]){
                    continue;
                }
                int k = j + 1;
                int l = nums.size()-1;
                long long sum = nums[i] + nums[j];
                while(k < l){
                    long long tempSum = sum + nums[k] + nums[l];
                    if(tempSum==target){
                        vector<int> tempAns = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(tempAns);
                        k++;
                        l--;
                        while(l > k && nums[k] == nums[k-1]){
                            k++;
                        }
                        while(l > k && nums[l] == nums[l+1]){
                            l--;
                        }
                    } else if(tempSum > target){
                        l--;
                    } else{
                        k++;
                    }
                }

            }
        }
        return ans;
    }
};
