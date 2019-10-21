/*
This code has been written by Manas Ranjan Swain (https://github.com/Manas173)

Description: To find the maximum sum of the contiguous subarray and to print the value.
For Example:

In array having elements as:
-10  5 -1 -8 12 15 2 -100 101 -100

The answer would be 101 as this would be the maximum sum of a contiguous subarray (only one element in this case).
    
INPUT:
First line will contain the number of elements i.e, the size of the array
Next N lines will contain N array elements.

OUTPUT:
A single line output that contains the maximum sum of the contigous subarray

TESTCASE:

8                                                                                                                                                                                     
Enter 8 elements 2 -1 10 -12 -1 5 2 -3                                                                                                                                                 
The max sum of the subarray is 11

EXPLANATION: The maximum sum contiguous subarray is from 1st element to 3rd element
*/

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
    int size;
    scanf("%d",&size);
    printf("Enter %d elements ",size);
    int arr[size];
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);

    printf("The max sum of the subarray is %d", maximumSubArraySum(arr, size));
    return 0;
}