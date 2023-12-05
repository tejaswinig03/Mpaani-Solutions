#include <stdio.h>
#include <stdlib.h>

int* majorityElements(int* nums, int numsSize, int* returnsize)
{
    int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 0;

    for (int i = 0; i < numsSize; i++) 
    {
        if (candidate1 == nums[i])
        {
            count1++;
        }
        else if (candidate2 == nums[i])
        {
            count2++;
        } 
        else if (count1 == 0) 
        {
            candidate1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0) 
        {
            candidate2 = nums[i];
            count2 = 1;
        }
        else 
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[i] == candidate1)
        {
            count1++;
        } 
        else if (nums[i] == candidate2) 
        {
            count2++;
        }
    }

    int* result = (int*)malloc(sizeof(int) * 2);
    int index = 0;
    if (count1 > numsSize / 3) 
    {
        result[index++] = candidate1;
    }
    if (count2 > numsSize / 3)
    {
        result[index++] = candidate2;
    }

    *returnsize = index;
    return result;
}

int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(sizeof(int) * n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int returnsize;
    int* result = majorityElements(nums, n, &returnsize);
    printf("Output: [");
    for (int i = 0; i < returnsize; i++)
    {
        printf("%d", result[i]);
        if (i < returnsize - 1) 
        {
            printf(", ");
        }
    }
    printf("]\n");
    free(nums);
    free(result);

    return 0;
}
