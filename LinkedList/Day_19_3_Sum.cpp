// https://leetcode.com/problems/3sum/description/

// Approach - 1
// Use set to store the elements and keep iterating
// TC = O(log n) * O(n^2)
// SC - O(N) + O(k)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            unordered_set<int> st;
            for(int j = i + 1; j < n; j++){
                int rem = 0 - nums[i] - nums[j];
                if(st.find(rem)!=st.end()){
                    vector<int> temp = {nums[i], nums[j], rem};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                } 
                st.insert(nums[j]);
            }
        }

        vector<vector<int>> ansvec(ans.begin(), ans.end());
        return ansvec;
    }
};


// Approach - 2
// Sort the array
// Use 3 pointers = 1 fixed and other 2 moving to create sum
// TC = O(nlogn) + O(n)
// SC = O(1) [just the answer array]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i>0 && nums[i-1] == nums[i]){
                continue;
            }

            int j = i + 1;
            int k = n - 1;
            while(k>j){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0){
                    j++;
                } else if(sum>0){
                    k--;
                } else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j-1]==nums[j]){
                        j++;
                    }
                    while(j<k && nums[k+1]==nums[k]){
                        k--;
                    }

                }
            }
        }
        return ans;
    }
};
