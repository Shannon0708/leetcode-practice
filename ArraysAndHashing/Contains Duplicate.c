#include<stdio.h>
#include<stdbool.h>
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))


bool containsDuplicate(int* nums, int numsSize) {
    // O(n) solution Hash Table - This is not a good solution for 10^-9 < nums[i] < 10^9
    // int hashTable[100000] = {0}; // Assuming nums[i] is in the range [0, 10^5]

    // for (int i = 0; i < numsSize; i++) {
    //     if (hashTable[nums[i]] == 0) {
    //         hashTable[nums[i]] = 1;
    //     }
    //     else {
    //         return 1;
    //     }
    // }
    // return 0;

    // O(n^2) solution: This is Time Exceed Limit for large inputs
    int i, j;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if(nums[i] == nums[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int numsSize = ARRAY_SIZE(nums);
    // containsDuplicate(nums, numsSize);
    printf("%s\n", containsDuplicate(nums, numsSize) ? "true" : "false");
    
}