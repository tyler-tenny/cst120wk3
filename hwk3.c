#include <stdio.h>
#include <stdbool.h>

//function to collect an input
int enterInt() {
  bool isValid = false;
  int userInt = 0;
  //check if a number is valid loop
  while (isValid == false) {
    printf("Please enter an integer between -1000000 and +1000000: ");
    scanf(" %d", &userInt);
    if (userInt > 1000000 || userInt < -1000000) {
      isValid = false;
    } else {
      isValid = true;
    }
  }
  printf("You have entered %d.\n", userInt);
  return userInt;
}

//check if a number is positive or negative with inequality operators
void isPosNeg() {
  int userInt = enterInt();
  if (userInt < 0) {
    printf("%d is a negative number. \n", userInt);
  }
  else if (userInt > 0) {
    printf("%d is a positive number. \n", userInt);
  }
  else if (userInt == 0) {
    printf("%d is zero.\n", userInt);
  }
}

//check if a number is odd or even through modulo operator
void isOddEven() {
  int userInt = enterInt();
  if (userInt % 2 > 0) {
    printf("%d is an odd number.\n", userInt);
  }
  else {
    printf("%d is an even number.\n", userInt);
  }
}

//calculate the number of digits with a for loop
int returnDigits() {
  int userInt = enterInt();
  int temp = userInt;
  int digits = 0;
  for (; temp != 0; digits++) {
    temp /= 10;
  }
  printf("%d contains %d digit(s).\n", userInt, digits);
  return digits;
}

//same as return digits, but without printing and with parameter so that I can use it for the table.
int returnDigitsNoPrint(int val) {
  int temp = val;
  int digits = 0;
  for (; temp != 0; digits++) {
    temp /= 10;
  }
  return digits;
}

//display a table full of values with proper formatting
void displayAddTable() {
  int column = 0;
  int row = 0;
  //top left corner
  printf("---- ");
  //title row
  for(; column < 10; ++column) {
    printf("%d    ", column);
  }
  printf("\n");
  column = 0;
  //printing of each value, one row at a time, before moving to next column
  for (; row < 10; ++row) {
    printf("%d    ", row);
    for (column = 0; column < 10; ++column) {
      //includes check to make sure proper spacing is used for the table
      if (returnDigitsNoPrint(column + row) > 1) {
        printf("%d   ", (column + row));
      } else {
        printf("%d    ", (column + row));
      }
    }
    printf("\n");
  }
}

//same logic and syntax as add table, but with multiplying instead of addition
void displayMultTable() {
  int column = 0;
  int row = 0;
  printf("---- ");
  for(; column < 10; ++column) {
    printf("%d    ", column);
  }
  printf("\n");
  column = 0;
  for (; row < 10; ++row) {
    printf("%d    ", row);
    for (column = 0; column < 10; ++column) {
      if (returnDigitsNoPrint(column * row) > 1) {
        printf("%d   ", (column * row));
      }
      else {
        printf("%d    ", (column * row));
      }
    }
    printf("\n");
  }
}

//menu function that loops, collects choice, and calls the appropriate function.
void mainMenu() {
  int menuChoice = 0;
  char userCont = 'y';
  //continue loop
  while (userCont == 'y') {
   //printing menu and gather choice
   printf("\nWelcome!\nPlease select a choice from the menu below.\n");
   printf("1. Enter integer\n2. Is positive or negative?\n3. Is odd or even?\n4. Display digits\n");
   printf("5. Display addition table\n6. Display multiplication table\n7. Exit\n");
   scanf(" %d", &menuChoice);
   //switch statement to control menu selection
   switch (menuChoice) {
  
     case 1 :
      //enter an integer
      enterInt();
      break;
     case 2 :
      //is positive or negative
      isPosNeg();
      break;
     case 3 :
      //is odd or even
      isOddEven();
      break;
     case 4 :
      //display number of digits
      returnDigits();
      break;
     case 5 :
      //display add table
      displayAddTable();
      break;
     case 6 :
      //display mult table
      displayMultTable();
      break;
     case 7 :
      //exit
      userCont = 'n';
      break;
     //check if no valid value is entered.
     default :
       printf("Please enter a valid choice, from 1 to 7.\n");
    }
  }
}

//main function just calls main menu and it does everything.
int main() {
  mainMenu();
}
    
