#include<vector>
#include<unordered_map>
#include<cstdio>

// Time Complexity: O(n)
// Space Complexity: O(n)
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> nums_map;
    for(int i = 0; i< nums.size(); i++) {
        int complement = target - nums[i];
        if(nums_map.count(complement)) {
            return {nums_map[complement], i};
        }
        nums_map[nums[i]] = i;
    }
    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    for (int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}