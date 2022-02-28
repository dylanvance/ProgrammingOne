/***************************************************************
 * Program Name: Project 2                                     *
 *                                                             *
 * Description: Collects an input from the user which defines  *
 *              how many sets of 6 random numbers they want    *
 *              to be printed.                                 *
 *                                                             *
 * Author: Dylan Vance (n01450847)                             *
 *                                                             *
 * Date: 10/23/2020                                            *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define RANGE r
#define OFFSET o


int InputFun();
void RandFun(int r, int o, int * r1, int* r2, int* r3, int* r4, int* r5, int* r6);


int sets;
int randNum;

/****************************************************************
 * Function Name: InputFun                                      *
 *                                                              *
 * Input Parameters: Nothing.                                   *
 *                                                              *
 * Description: Prompts the user to enter a number and assigns  *
 *              the input to the sets variable. This function   *
 *              gets called at the beginning of the while loop  *
 *              in the  main function.                          *
 *                                                              *
 * Return Value: Nothing.                                       *
 ****************************************************************/
int InputFun() {

  printf("Enter a number ('0' to quit)\n");
  scanf("%d", &sets);

  return 0;
}

/****************************************************************
 * Function Name: RandFun                                       *
 *                                                              *
 * Input Parameters: The Range and Offset for rand() as well as *
 *                   the pointers for r1, r2, r3, r4, r5, & r6. *
 *                                                              *
 * Description: Generates 6 random numbers and assigns them to  *
 *              the pointers for r1, r2, r3, r4, r5, & r6.      *
 *              Also includes a do while loop that prevents the *
 *              generation of more than 1 of the same number.   *
 *                                                              *
 * Return Value: Nothing                                        *
 ****************************************************************/
void RandFun(int r, int o, int * r1, int* r2, int* r3, int* r4, int* r5, int* r6) {
  do {
    *r1  = (rand() % RANGE) + OFFSET;
    *r2  = (rand() % RANGE) + OFFSET;
    *r3  = (rand() % RANGE) + OFFSET;
    *r4  = (rand() % RANGE) + OFFSET;
    *r5  = (rand() % RANGE) + OFFSET;
    *r6  = (rand() % RANGE) + OFFSET;
  } while( (*r1 == *r2) || (*r1 == *r3) || (*r1 == *r4) || (*r1 == *r5) || (*r1 == *r6) || 
           (*r2 == *r3) || (*r2 == *r4) || (*r2 == *r5) || (*r2 == *r6) || 
           (*r3 == *r4) || (*r3 == *r5) || (*r3 == *r6) ||
           (*r4 == *r5) || (*r4 == *r6) || 
           (*r5 == *r6) );  
}


int main(void) {

  int r1, r2, r3, r4, r5, r6 = 0;
  int i, j;
  int counter;

  counter = 1;

  srand(time(NULL));

  while (1 > 0) {
    
    InputFun();

    if (sets <= 0) {						//Quits the while loop if 0 is entered.
      break;
    }

    printf("Sets: %d\n", sets);
      
      for (i = 0; i < sets; i++) {

        if (counter < 10) {
          printf("Set #0%d: ", counter);	//Here I use a counter to keep track of the set #.
        }

        else {
          printf("Set #%d: ", counter);
        }

        counter++;							//Increments the counter.
      
        RandFun(53, 1, &r1, &r2, &r3, &r4, &r5, &r6);

        if (r1 < 10) {						//These if-else statements determine if the value is < 10.
          printf("0%d ", r1);				//If so, a '0' is printed in front of the number; used for neatness.
        }									//I use the same method for the counter above.
        else {
          printf("%d ", r1);
        }
          
        if (r2 < 10) {
          printf("0%d ", r2);
        }
        else {
          printf("%d ", r2);
        }

        if (r3 < 10) {
          printf("0%d ", r3);
        }
        else {
          printf("%d ", r3);
        }

        if (r4 < 10) {
          printf("0%d ", r4);
        }
        else {
          printf("%d ", r4);
        }

        if (r5 < 10) {
          printf("0%d ", r5);
        }
        else {
          printf("%d ", r5);
        }

        if (r6 < 10) {
          printf("0%d ", r6);
        }
        else {
          printf("%d ", r6);
        }
      printf("\n");
      }
    counter = 1;							//Counter reset.
  }
  printf("Program Exited\n");

  return 0;
}