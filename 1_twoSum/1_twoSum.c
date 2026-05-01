#include "stdbool.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    for (int iCompare = 0; iCompare < (numsSize - 1); iCompare++ )   {
        for (int iAdd = iCompare + 1; iAdd < (numsSize); iAdd++ )   {
            if (nums[iAdd] + nums[iCompare] == target) {
                *returnSize = 2;
                int *returnArrayPtr = (int *)malloc(*returnSize * UINT8_MAX);
                returnArrayPtr[0] = iCompare;
                returnArrayPtr[1] = iAdd;
                
                return returnArrayPtr;
            }
        }
    }

    returnSize = 0;
    return NULL;
}

int main(void) {
    int returnSize = 2;

    int nums1[] = {2, 7, 11, 15};
    int* r1 = twoSum(nums1, 4, 9, &returnSize);
    printf("Input: [2,7,11,15] target=9  -> indexes [%d, %d]\n", r1[0], r1[1]);
    free(r1);

    int nums2[] = {3, 2, 4};
    int* r2 = twoSum(nums2, 3, 6, &returnSize);
    printf("Input: [3,2,4] target=6      -> indexes [%d, %d]\n", r2[0], r2[1]);
    free(r2);

    int nums3[] = {3, 3};
    int* r3 = twoSum(nums3, 2, 6, &returnSize);
    printf("Input: [3,3] target=6        -> indexes [%d, %d]\n", r3[0], r3[1]);
    free(r3);

    return 0;
}
