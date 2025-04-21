#include<stdio.h>
#include<stdbool.h>

bool containsDuplicate(int* nums, int numsSize) {
    int i, j;
    for (i = 0, i < numsSize; i++;) {
        for (j = i + 1; j < numsSize+1; j++) {
            if(nums[i] == nums[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums);
    containsDuplicate(nums, numsSize);
}