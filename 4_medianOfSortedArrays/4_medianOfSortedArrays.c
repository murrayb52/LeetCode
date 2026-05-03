#include <stdio.h>
#include <stdbool.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int head1 = 0;
    int head2 = 0;
    double median = 0.0;
    int countToIndex = 0;
    bool countIsEven = false;

    // count numbers to determine if the median is a given number or between two
    int totalNums = nums1Size + nums2Size;
    if (totalNums % 2 == 0) {
        // even - therefore between two numbers
        countIsEven = true;
        countToIndex = totalNums / 2;
    }
    else {
        countToIndex = (totalNums + 1) / 2;
    }

    // min of head1, head2 determines which number is counted next
    int nextSmallest = 0;
    for (int index = 0; index < countToIndex; index++ )    {
        // determine next smaller number
        if (head1 >= nums1Size)  {
            nextSmallest = nums2[head2];
            head2++;
        }
        else if (head2 >= nums2Size) {
            nextSmallest = nums1[head1];
            head1++;
        }
        else {
            if (nums1[head1] <= nums2[head2])   {
                nextSmallest = nums1[head1];
                head1++;
            }
            else {
                nextSmallest = nums2[head2];
                head2++;
            }
        }
    }

    // we've now counted to the median position (or to first of two middle numbers)
    median = (double)nextSmallest;
    if (countIsEven)    {
        // consider second number as well
        if (head1 >= nums1Size) {
            median += (double)nums2[head2];
        }
        else if (head2 >= nums2Size)    {
            median += (double)nums1[head1];
        }
        else {
            if (nums1[head1] <= nums2[head2])   {
                median += (double)nums1[head1];
            }
            else {
                median += (double)nums2[head2];
            }
        }
        median /= 2.0;
    }

    return median;
}

int main(void) {
    int a1[] = {1, 3}, b1[] = {2};
    printf("Input: [1,3] [2]   -> %.5f\n", findMedianSortedArrays(a1, 2, b1, 1));

    int a2[] = {1, 2}, b2[] = {3, 4};
    printf("Input: [1,2] [3,4] -> %.5f\n", findMedianSortedArrays(a2, 2, b2, 2));

    int a3[] = {0}, b3[] = {1};
    printf("Input: [0] [1]     -> %.5f\n", findMedianSortedArrays(a3, 1, b3, 1));
}
