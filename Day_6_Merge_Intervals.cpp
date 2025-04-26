class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i< intervals.size(); i++){
            if(ans.size()==0){
                ans.push_back(intervals[i]);
                continue;
            }
            
            if(ans[ans.size()-1][1] >= intervals[i][0]){
                ans[ans.size()-1][1] = max(intervals[i][1], ans[ans.size()-1][1]);
            } else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
