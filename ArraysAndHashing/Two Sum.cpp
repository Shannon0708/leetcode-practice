#include<vector>
#include<unordered_map>
#include<cstdio>

using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> twoSum(std::vector<int>& nums, int target) {
    unordered_map<int, int> nums_map;
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
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    for (int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}