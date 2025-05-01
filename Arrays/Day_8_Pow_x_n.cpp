// https://leetcode.com/problems/powx-n/description/
// Edge cases - n < -1
// since n is an integer it lies from -2,147,483,648 to 2,147,483,647

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(x == 1 || x == 0){
            return x;
        }

        if(x == -1){
            return n%2==0 ? 1 : -1;
        }
        if(n > 0){
            for(int i = 0; i < n; i++){
                ans = ans * x;
            }
            return ans;
        } else if(n < 0){
            for(int i = n; i < 0; i++){
                ans = ans * (1/x);
                if(ans == 0){
                    return ans;
                }
            }
            return ans;
        } else {
            return ans;
        }
        return ans;
    }
};


// Approach - O(log N)
// double your base by halving your power
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn < 0 ){
            nn = nn * -1;
        }
        while(nn != 0){
            if(nn % 2){
                ans = ans * x;
                nn--;
            } else{
                x = x * x;
                nn = nn / 2;
            }
        }

        if(n < 0){
            ans = (double) (1.0) / (double) (ans);
        }
        return ans;
    }
};
