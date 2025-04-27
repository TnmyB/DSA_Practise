// Approach - 1: Brute
// O(n^2)

class Solution {
public:
   long long int numberOfInversions(vector<int> nums) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j]<nums[i]){
                    count++;
                }
            }
        }

        return count;
    }
};

// Approach - 2
// Use Divide and Conquer = merge sort breaks it to levels, you just combine and increment the count
// Input Format: N = 5, array[] = {5,3,2,1,4}
// return count of inversions => i < j but arr[i] > arr[j]
// here answer is 7

class Solution {
public:

    int merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int count = 0;
        int start1 = low;
        int start2 = mid+1;

        while(start1 <= mid && start2 <= high){
            if(nums[start1]>nums[start2]){
                count+=mid-start1+1;
                temp.push_back(nums[start2]);
                start2++;
            } else{
                temp.push_back(nums[start1]);
                start1++;
            }
        }
        while(start1<=mid){
            temp.push_back(nums[start1]);
            start1++;
        }
        while(start2<=high){
            temp.push_back(high);
            start2++;
        }
        for(int i = low; i <= high; i++){
            nums[i] = temp[i-low];
        }
        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high){
        int count = 0;
        if(low >= high){
            return count;
        }
        int mid = (high + low)/2;
        
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);
        count += merge(nums, low, mid, high);

        return count;

    }

    long long int numberOfInversions(vector<int> nums) {
        int count = mergeSort(nums, 0, nums.size()-1);

        return count;
    }
};
