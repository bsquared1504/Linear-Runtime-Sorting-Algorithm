//Author: Brady Brown
//Date: 4/6/24
//Class: Algorithms & Data Structures
//Assignment: Counter Sort Algorithm
/*Description: This program implements the counter sort algorithm that was taught in class. 
This algorithm takes an array, increments the value of another array at the index of that value
and assigns them back into the array in the order of the values placed in the second array */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Algorithm for Counter Sort
int CounterSort(int *data, int length){

  //integer to store biggest number in array
  int max = 0;

  //for loop to iterate through array and find the largest value
  for(int i = 0; i < length; i++){
    //if the current value of the array is bigger than the max, update the max to the value
    if (data[i] > max){
      max = data[i];
    }
  }
  
  //Increase the max by one, as it is used to create the size of the array in the next part
  //Otherwise, we will run into index out of bounds errors
  max++;

  //Variable type is a pointer to an integer
  //It then uses the malloc method to dynamically allocate the the amount of memory needed
  //It uses an int pointer for the cast type...
  //and then it allocates the size of an integer in memory * max variable
  //This gives us an a pointer that acts like a dynamically allocated integer array...
  //with the size of the biggest integer found in the previous for loop
  int *sorter = (int*)malloc(max * sizeof(int));
  
  //This for loop initializes every index of the sorter array to 0
  //This is done to set up the counter sorting loop done next
  for(int i = 0; i < max; i++){
    sorter[i] = 0;
  }

  //This for loop goes through the initial data array and increases...
  //the sorter value at the index of the data value at the index of the loop
  //This essentially counts the amount of each number that are in the array
  for(int i = 0; i < length; i++){
    sorter[data[i]]++;
  }

  //There are essentially 3 counters here
  //The first for loop goes through the entire sorter array
  //The second for loop goes from 0 to the value of the sorter at i (first for loop)
  //This for loop is there to check what the value is at each index in the sorter array
  //If it is 0, it skips it
  //But if it is more than 0, it sets the data array at the index of the counter variable to i
  //Then the counter variable increases
  //If the sorter value at i is higher than 1, it will put another value of i into the array
  //Otherwise, it moves on to the next index in the sorter array
  int counter = 0;
  for(int i = 0; i < max; i++){
    for(int j = 0; j < sorter[i]; j++){
      data[counter] = i;
      counter++;
    }
  }

  //This frees the sorter array allocation, as the data array is sorted and this array is no longer needed
  free(sorter);
  return 0;
}

//Main function that tests the algorithm
int main(int argc, char* argv[]){

  //This checks that there is only 1 integer value as a command line argument
  if (argc == 2){

    //Takes the argument and stores it as a char
    char input = *argv[1];

    //This converts the char into an int for easier math later in the function
    int loops = input - '0';

    //This sets the random seed to the current time value
    //This ensures that everything is 100% random every time the program is run
    srand(time(NULL));

    //This runs the amount of loops specified in the command line argument
    for(int i = 0; i < loops; i++){

      //Prints the loop the function is currently on
      printf("\n\nLoop %d:", i + 1);
      //Gives a random value from 1-20
      int size = rand() % 20 + 1;

      //Variable type is a pointer to an integer
      //It then uses the malloc method to dynamically allocate the the amount of memory needed
      //It uses an int pointer for the cast type...
      //and then it allocates the size of an integer in memory * size variable
      //This gives us an a pointer that acts like a dynamically allocated integer array...
      //with the size of the randomly generated size variable
      int *nums = (int*)malloc(size * sizeof(int));

      //This sets the value for each index in the array to a different random number from 1-20
      for(int j = 0; j < size; j++){
        nums[j] = rand() % 20 + 1;
      }
      
      //This prints out the values of each index of the initial array
      printf("\ninitial array: ");
      for(int j = 0; j < size; j++){
        printf("%d ", nums[i]);
      }

      //This runs the sorting algorithm
      CounterSort(nums, size);

      //This prints out the supposedly sorted array
      printf("\nsorted array: ");
      for(int j = 0; j < size; j++){
        printf("%d ", nums[i]);
      }

      //This checks to make sure that each value in the array is greater than the previous numbers in the array
      //Otherwise, it will have an error
      for(int j = 0; j < size - 1; j++){
        if (nums[j] > nums[j+1]){
          printf("Something went wrong");
          return 1;
        }
      }
      
      //This frees the allocation of the dynamically created nums array
      //This is no longer needed, as the program will allocate a different amount of space if more loops are done
      free(nums);
    }
  //This happens in case no arguments or too many arguments are passed
  }else{
    printf("Improper amount of arguments passed\nPlease enter one argument");
    return 1;
  }
  return 0;
}