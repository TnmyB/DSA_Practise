
// Approach 1 
// With Extra Vector to store the rows/col to be made 0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> col;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for(int i = 0; i < row.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[row[i]][j] = 0;
            }
        }

        for(int j = 0; j < col.size(); j++){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][col[j]] = 0;
            }
        }
    }
};

// Approach 2
// Use extra variables firstCol and firstRow to mark if the 1st row or 1st col needs to be marked to 0
// and reuse the 1st row and 1st col to determine if any row or col is needed to be marked to 0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstCol=0;
        int firstRow=0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if(i==0){
                        firstRow = 1;
                    }
                    if(j==0){
                        firstCol = 1;
                    }
                }
            }
        }

        for(int j = 1; j < matrix[0].size(); j++){
            if(matrix[0][j]==0){
                for(int i = 1; i < matrix.size(); i++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < matrix.size(); i++){
            if(matrix[i][0]==0){
                for(int j = 1; j< matrix[i].size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }


        if(firstCol == 1){
            cout<<firstCol;
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }

        if(firstRow == 1){
            cout<<firstRow;
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        }

    }
};
