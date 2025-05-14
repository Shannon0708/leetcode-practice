#include<vector>
#include<unordered_map>
#include<cstdio>

// The difference is that -1000 < numbers < 1000 contains minus numbers,
// the numbers are sorted in ascending order, and the return result is "position"(start from 1) but "index(start from 0)".


// The time complexity is O(n) and the space complexity is O(1).

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& numbers, int target) {
            std::unordered_map<int, int> map;
            int complement = 0;
            for(int i=0 ; i<numbers.size() ; i++) {
                complement = target - numbers[i];
    
                if (map.count(complement)) {
                    return {map[complement] + 1, i + 1};
                } 
                else {
                    map[numbers[i]] = i;
                }
            }
            return{};
        }
    };