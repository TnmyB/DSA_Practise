// Brute
// TC = O(n*log n)
// SC = O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxCount = 0;
        for(int i = 0; i < nums.size(); i++){
            int count = 0;
            while(i>0 && i < nums.size() && ((nums[i] == nums[i-1]+1) || (nums[i] == nums[i-1]))){
                if(nums[i] == nums[i-1]+1){
                    count++;
                }
                i++;
            }
            maxCount = max(maxCount, count+1);
        }
        return maxCount;
    }
};


// use hashset to store all unique elements
// itereate through the set and find element which has no previous element, look for the next element to it to find the count of consecutive integers
// TC = O(n+2*n)
// SC = O(m)
// the better approach is better if hash set cannot be used
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int> st;
        int longest = 1;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }

        for(auto it: st){
            int count = 1;
            if(st.find(it-1)==st.end()){
                while(st.find(it+1)!=st.end()){
                    count++;
                    it = it + 1;
                }
            }
            longest = max(longest, count);
        }

        return longest;
    }
};
