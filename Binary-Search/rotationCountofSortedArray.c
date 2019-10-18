/*
Given an array of integers, find the minimum number of rotations performed on some sorted array to create this given array.

Input

First line of input will contain a number T = number of test cases. Each test case will contain 2 lines. First line will contain a number N = number of elements in the array (1 <= N <= 50).

Next line will contain N space separated integers.

Complete the function int rotationCount(int array[], int size) which will receive array and size of the array as input and return how many times the sorted array is rotated. Function should return -1 if the array is not rotated.

Output

Print one line of output for each test case with the minimum number of rotations for given array.
*/
int rotationCount(int a[], int size)
{
  int i,c=0;
  for(i=0;i<size;i++)
  {
    if(a[i]>a[size-1])
      c++;
    else
      break;
  }
  if(c)
    return c;
  else
    return -1;
}