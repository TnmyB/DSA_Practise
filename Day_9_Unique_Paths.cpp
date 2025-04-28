// Grid Problem in P&C
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
