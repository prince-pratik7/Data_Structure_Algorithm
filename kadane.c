#include <stdio.h>

 
int maximumSubArraySum(int arr[], int n)
{
    int max_so_far = 0, max_end = 0;
 
    for (int i = 0; i < n; i++)
    {
        max_end = max_end + arr[i];
        if (max_end <= 0)
            max_end = 0;
        else if (max_so_far < max_end)
            max_so_far = max_end;
   }
   return max_so_far;
}
 
int main()
{
    int arr[] = {-10 , 5 ,-1 , -8 ,12, 15,2 ,-100 , 101 ,-100};
    int size = sizeof(arr) / sizeof(arr[0]);
 
    printf(" The max sum of the subarray is %d", maximumSubArraySum(arr, size));
    
    int arr2[] = { -20, -2, 1 ,4 ,5 ,-3, 7, -25};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("\n The max sum of the subarray is %d", maximumSubArraySum(arr2, size2));
    return 0;
}