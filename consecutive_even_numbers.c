/* this program inputs an array of integers till it receives a negetaive no.
It returns the sequence of consecutive even numbers.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int processArray(int array[], int len) {
    int count=0;
    int sum=0,i=0;
    while(i<len) {
      int j = i;
      while(j<len && array[j]%2 == 0) {                 //even nos in array 
        j++;
      }
      if(i != j ) {                                     //tracking consecutive even nos 
        sum = sum + j - i; 
        count++;
        i=j;
      }
      else {
        i++;
      } 
    }
    int average = sum/count;
  return average;                                   //returning average of total consecutive length and occurrence of even nos
}

int main() {
  int *array;
  int len = 0, maxsize = 1024, i, input;
  int result;
  array = (int *)malloc(maxsize*sizeof(int));
  while(scanf("%d", &input) == 1) {
    if (input < 0) break; /* Stop when a negative number is entered */
    array[len++] = input;
    if (len == maxsize) { /* array is full. increase size */
      maxsize *= 2;
      array = (int *)realloc(array, maxsize*sizeof(int));
    }
  }
  result = processArray(array, len);
  printf("%d\n", result);
  return 0;
}

