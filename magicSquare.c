#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool checkMagicSquare(int square[3][3]);

void printSquareFormat(int square[3][3]);

int main() {
   time_t t;
   int magicSquare[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
   int notMagicSquare[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   int randomMagicSquare[3][3];
   int count = 0, randomNumber = 0;;

   printSquareFormat(magicSquare);
   if (checkMagicSquare(magicSquare))
      printf("This is a magic square.\n\n");
   else 
      printf("This is not a magic square.\n\n");

   printSquareFormat(notMagicSquare);
   if (checkMagicSquare(notMagicSquare))
      printf("This is a magic square.\n\n");
   else 
      printf("This is not a magic square.\n\n");
   
   srand((unsigned) time(&t));
   // loop to populate 2D array with random integers 1-9
   do
   {
      bool numberUsed[10] = {false};
      for (int row = 0; row < 3; row++) {
         for (int col = 0; col < 3; col++) {
            do
            {
               randomNumber = (rand() % 9) + 1;
               // check if random number has already been stored
               // if it has, generate new random number between 1 and 9
            } while (numberUsed[randomNumber] == true);  
            randomMagicSquare[row][col] = randomNumber;
            numberUsed[randomNumber] = true;
         }
      }
      count++;
   } while (checkMagicSquare(randomMagicSquare) == false);

   printf("Total number of squares generated and tested before success: %d\n", count);
   printf("Successful magic square with random numbers 1-9:\n");
   printSquareFormat(randomMagicSquare);
   printf("\n");

   return 0;
}

bool checkMagicSquare(int square[3][3]) {
   // sum of first row to check if equal to remaining rows/columns/diagonals
   int sum = square[0][0] + square[0][1] + square[0][2];

   // check if 2-D array contains numbers 1-9 exactly
   for (int row = 0; row < 3; row++) {
      for (int col = 0; col < 3; col++) {
         if (square[row][col] < 1 || square[row][col] > 9)
            return false;
      }
   }

   // check if sum of each remaining row equals sum of first row
   for (int row = 1; row < 3; row++) {
      if (sum != square[row][0] + square[row][1] + square[row][2])
         return false;
   }

   // check if sum of each column equals sum of first row
   for (int col = 0; col < 3; col++) {
      if (sum != square[0][col] + square[1][col] + square[2][col])
         return false;
   }

   // check if sum of each diagonal equals sum of first row
   if (sum != square[0][0] + square[1][1] + square[2][2]) {
      return false;
   }
   if (sum != square[0][2] + square[1][1] + square[2][0]) {
      return false;
   }

   return true;
}

void printSquareFormat(int square[3][3]) {
   for (int row = 0; row < 3; row++) {
      printf("[");
      for (int col = 0; col < 3; col++) {
         printf("%d", square[row][col]);
         if (col < 2) {
            printf(" ");
         }
      }
      printf("]\n");
   }
}