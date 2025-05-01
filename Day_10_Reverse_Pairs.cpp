// https://leetcode.com/problems/reverse-pairs/description/

// Brute 
// O(n^2)

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if((double)nums[i]>(double)2*nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};


// Optimal
// Using Merge Sort
// Intuition counting while merging 2 sorted arrays is easier
// TC = O(log n * (n1+n2)) = O(2nlog(n))
// SC = O(n) (we distort the array)
class Solution {
public:

    int merge(vector<int>& nums, int low, int mid, int high){
        int i = low;
        int j = mid + 1;
        int count = 0;
        vector<int> temp;

        // cleaner approach to separate out this to a new method
        // added in Optimal - 2
        int curCount = 0;
        int k = low;
        int l = mid+1;
        while(k <= mid){
            while((l <= high) && (long long)nums[k] > (long long)2*nums[l]){
                curCount++;
                l++;
            }
            k++;
            count+=curCount;
        }
        
        while(i <= mid && j <= high){
            if(nums[i]>nums[j]){
                temp.push_back(nums[j]);
                j++;
            } else{
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i-low];
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int low, int high){
        int count = 0;
        if(low>=high){
            return count;
        }
        int mid = (low+high)/2;
        count += mergeSort(nums, low, mid) + mergeSort(nums, mid+1, high);
        count += merge(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};


// Optimal - cleaner
class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high){
        int i = low;
        int j = mid + 1;
        vector<int> temp;

        while(i <= mid && j <= high){
            if(nums[i]>nums[j]){
                temp.push_back(nums[j]);
                j++;
            } else{
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i-low];
        }
        return;
    }

    int countReversePairs(vector<int>& nums, int low, int mid, int high){
        int count = 0;
        int j = mid+1;
        for(int i = low; i<=mid; i++){
            while( j <= high && (long long)nums[i] > (long long)2*nums[j]){
                j++;
            }
            count += j-mid-1;
        }
        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high){
        int count = 0;
        if(low>=high){
            return count;
        }
        int mid = (low+high)/2;
        count += mergeSort(nums, low, mid) + mergeSort(nums, mid+1, high);
        count += countReversePairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
