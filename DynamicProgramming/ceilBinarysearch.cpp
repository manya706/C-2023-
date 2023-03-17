#include<bits/stdc++.h>
using namespace std;
int ceilBinarySearch(vector<int>& nums, int target){
    int low = 0, high = nums.size()-1;
        if(target < nums[0] || target > nums[high]){ // target doesn't lie in the nums
            return -1;
        }
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return high+1;
}
int main(){
    vector<int> nums = {1,2,3,4,5,6};
    ceilBinarySearch(nums,7);
}