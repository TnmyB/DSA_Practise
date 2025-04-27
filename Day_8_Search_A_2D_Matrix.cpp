// My Approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int len = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0]<=target && matrix[i][len-1]>=target){
                row = i;
            }
        }

        for(int i = 0; i < len; i++){
            if(matrix[row][i]==target){
                return true;
            }
        }

        return false;
    }
};

// Optimize
// use binary search
// TC = O(n) + O(log m)


// Optimize
// flatten the array
// consider as a flat array, convert the index to row and col by dividing by n
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n * m - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col]==target){
                return true;
            } else if(matrix[row][col]>target){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return false;
        
    }
};
