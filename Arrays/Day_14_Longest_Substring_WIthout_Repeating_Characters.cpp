// My Approach - using hashmap
// TC = O(2n)
// SC = O(m)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxCount = 0;
        unordered_map<char, int> st;
        int left = 0;
        int right = 0;
        while(right<n){
            while(left < right && st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st[s[right]] = right; 
            maxCount = max(maxCount, right-left+1);
            right++;
        }
        return maxCount;
    }
};

// Optimal
// TC = O(n)
// SC = O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxCount = 0;
        unordered_map<char, int> st;
        int left = 0;
        int right = 0;
        while(right<n){
            if(st.find(s[right])!=st.end()){
                if(st[s[right]]>=left){
                    left = st[s[right]]+1;
                }
            }
            st[s[right]] = right; 
            maxCount = max(maxCount, right-left+1);
            right++;
        }
        return maxCount;
    }
};
