class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if(numRows == 0){
            return ans;
        }
        vector<int> prev = {1};
        ans.push_back(prev);

        for(int i = 2; i<=numRows; i++){
            vector<int> cur;
            for(int j = 0; j < i; j++){
                if(j == 0){
                    cur.push_back(prev[j]);
                } else if(j == i-1){
                    cur.push_back(prev[j-1]);
                } else{
                    cur.push_back(prev[j]+prev[j-1]);
                }
            }
            ans.push_back(cur);
            prev = cur;
        }

        return ans;
    }
};

// Approach - 2 use nCr and get each row
// Example - each row constitutes of nCr
// Now how will you calculate nCr. Simple it is just: [n*(n-1)*(n-2)...]/[1*2*3...] OR [n/1]*[n-1/2]*[n-2/3]*...
// row 5th has these elements = 1 4 6 4 1 which is 4C0 4C1 4C2 4C1 4C0

class Solution {
public:

    vector<int> generateRow(int row){
        vector<int> rowResult;
        int ans = 1;
        rowResult.push_back(ans);
        for(int i = 1; i < row; i++){
            ans = ans * (row - i);
            ans = ans / i;
            rowResult.push_back(ans);
        }
        return rowResult;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 1; i <= numRows; i++){
            result.push_back(generateRow(i));
        }
        return result;
    }
};
