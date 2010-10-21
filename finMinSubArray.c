/* YAHOO CODE WRITE QUESTION :
 * 
 *  Given an array of length N. How wil you find the minimum lenght continues sub_array 
 *  of whose some is S and product is P here S and P will be given to you.
 *
 * Program  : Find minimum sub sequence which matches the given sum and product.
 * Input    : Array, Sum, Product  
 * Output   : minimum lenght of sub-array
 *
*/


//header file 
#include <stdio.h>
#include <malloc.h>

//function prototype
int findMinSubArray(int *array, int S, int P, int size);

//main function
int main() {
 
  //local variables
  int i;
  int size;
  int sum;
  int product;
  int minLength;
  int *array;


  //reading input from user
  printf("\n Enter The Size Of Array : ");
  scanf("%d", &size);
  
  array = (int *)malloc(sizeof(int)*size);
 
  for(i = 0; i < size; i++)
      scanf("%d", &array[i]);
  
  printf("\n Enter the sum(S ) : ");
  scanf("%d", &sum);

  printf("\n Enter the product(S) : ");
  scanf("%d", &product);

  //calling function findMinSubArray
  minLength = findMinSubArray(array, sum, product, size);
 
  //printing the result
  printf("Min Length :  %d ", minLength);

  return 0;
}//main


/* Function  : findMinSubArray(int *array, int sum, int product, int size)
 * Parameter : array, sum, product, size
 * Retrun    : 
 *       minLength : min lenght of sub array
 */
int findMinSubArray(int *array, int S, int P, int size){

  //local variable 
  int start = 0;
  int end = 0;
  int sum = 0;
  int product = 1;
  int minLength = size;

  //while not reach upto end of array
  while(end != size) {
 
    sum += array[end];

    if(product == 0) product = 1;
 
    if(array[end] != 0 || P == 0)
      product = ((product) * (array[end]));

   
    //while sum and product value grater than given S and P  
    while((sum > S || product > P)) {
      sum = sum - array[start];
      if(array[start] != 0)
      product = product / array[start];
      start++; // increament the start point
    }//while

    // if matches then calculate minLenght
    if(sum == S && product == P) {
      if(minLength > (end - start))
	minLength = (end - start);
   }
   
    end++; //increament the end point

  }//while 
  return minLength+1; //return the result;
 }//findMinSubArray
