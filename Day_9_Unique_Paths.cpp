// Brute force through recursion - gives TLE for high input as both SC and TC are exponential
// https://leetcode.com/problems/unique-paths/description/
class Solution {
public:
    int iteratePaths(int startM, int startN, int m, int n){
        int path = 0;
        if(startM > m || startN > n){
            return 0;
        }
        if(startM == m && startN == n){
            return path + 1;
        }
        path += iteratePaths(startM + 1, startN, m, n);
        path += iteratePaths(startM, startN + 1, m, n);
        return path;

    }
    int uniquePaths(int m, int n) {
        return iteratePaths(0, 0, m-1, n-1);
    }
};

// Through DP
// Convert recursion into DP
// TC - O(m*n) SC - O(m*n)
class Solution {
public:
    int iteratePaths(int startM, int startN, int m, int n, vector<vector<int>>& dp){
        if(startM > m || startN > n){
            return 0;
        }
        if(startM == m && startN == n){
            return 1;
        }
        if(dp[startM][startN] != -1){
            return dp[startM][startN];
        }
        return dp[startM][startN] = iteratePaths(startM + 1, startN, m, n , dp) + iteratePaths(startM, startN + 1, m, n, dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return iteratePaths(0, 0, m-1, n-1, dp);
    }
};

// Grid Problem P&C solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int totalDir = m + n - 2;
        int smaller = min(m, n) - 1;
        for(int i = 0; i < smaller; i++){
            ans = ans*(totalDir-i);
            ans = ans/(i+1);
        }
        return (int)ans;
    }
};
