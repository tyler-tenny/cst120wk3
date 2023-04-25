#include <stdio.h>

//define pi
#define PI 3.14
//define macros for area and circumference
#define area(radius) radius*radius*PI
#define circumference(radius) 2*PI*radius

int main() {
  float radius = 0;
  //continue loop
  char userCont = 'y';
  while (userCont == 'y' || userCont == 'Y') {
    printf("Please enter a radius in meters: ");
    scanf(" %f", &radius);
    //print results of macros
    printf("Circle radius = %f\n", radius);
    printf("Circumference = %f\n", circumference(radius));
    printf("Area = %f\n", area(radius));
    //check continue loop
    printf("Press y to continue: ");
    scanf(" %c", &userCont);
  }
}

