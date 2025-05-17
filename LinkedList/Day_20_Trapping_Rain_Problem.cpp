// https://leetcode.com/problems/trapping-rain-water/description/


// My Approach:
// TC: O(n^2)
// SC: O(1)
class Solution {
public:

    int returnRightHeight(vector<int>& height, int rightIndex){
        int maxRightHeightIndex = rightIndex;
        for(int i = rightIndex + 1; i < height.size(); i++){
            if(height[maxRightHeightIndex] <= height[i]){
                maxRightHeightIndex = i;
            }
        }
        return maxRightHeightIndex;
    }

    int trap(vector<int>& height) {
        int totalHeight = 0;
        int leftHeightIndex = 0;
        if(height.size()<=2){
            return 0;
        }

        int rightHeightIndex = returnRightHeight(height, 2);

        for(int i = 1; i < height.size()-1; i++){
            if(height[leftHeightIndex]<=height[i]){
                leftHeightIndex = i;
                continue;
            }
            
            if(rightHeightIndex<i){
                rightHeightIndex = returnRightHeight(height, i+1);
            }

            if(height[i]>=height[rightHeightIndex]){
                continue;
            }

            totalHeight += min(height[leftHeightIndex], height[rightHeightIndex]) - height[i];
        }

        return totalHeight;
    }
};

// Approach - 2
// calculate max prefix array
// calculate max suffix array
// calculate the water level
// TC = O(3n)
// SC = O(2n)

// A bit optimization by calculating left as we iterate


// Approach - 3
// traverse both left and right, keeping the track of leftMax and rightMax


class Solution {
public:
    int trap(vector<int>& height) {
        int lMax = 0;
        int rMax = 0;
        int total = 0;
        int left = 0;
        int right = height.size() - 1;

        while(left<right){
            if(height[left]<=height[right]){
                if(lMax > height[left]){
                    total += lMax - height[left];
                } else {
                    lMax = height[left];
                }
                left++;
            } else {
                if(rMax > height[right]){
                    total += rMax - height[right];
                } else{
                    rMax = height[right];
                }
                right--;
            }
        }
        return total;
    }
};
