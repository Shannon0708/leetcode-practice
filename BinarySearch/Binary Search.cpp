#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int left, right, middle
        // if(nums[size / 2]> target)
        int left = 0;
        int right = nums.size() - 1;
        int m = (right - left) / 2;
        //left = 10, right = 11, m = 10 + (11-10)/2 = 10
        // left = 10, right = 12, m = 10+ (12-10)/2 = 11
        while(left <= right) {
            //if nums[m] < target
            //update m
            if(nums[m] < target) {
                left = m + 1;
            }
            else if(nums[m] > target){
                right = m - 1;
            }
            else {
                return m;
            }

            m = left + (right - left) / 2;
        }
        
        return -1; // Cannot find
    }
};
