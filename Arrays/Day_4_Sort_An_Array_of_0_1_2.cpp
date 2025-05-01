// Create 2 pointers for marking end of 1s and start of 2s and fill in
// TC = O(n), SC = O(1)
// Dutch National Flag
// Another approach is to count and create array
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int index = 0;
        while(index <= end){
            if(nums[index] == 0){
                swap(nums[index], nums[start]);
                start++;
                index++;
            } else if(nums[index] == 2){
                swap(nums[index], nums[end]);
                end--;
            } else{
                index++;
            }
        }
    }
};
