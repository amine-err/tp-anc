#include <stdio.h>
#include <string.h>

// Create a function
void myFunction1(char name[], int age)
{
  printf("Hello %s. You are %d years old.\n", name, age);
}

// array param
void myFunction2(int myNumbers[5])
{
  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", myNumbers[i]);
  }
}

// structures
struct myStructure {
  int myNum;
  char myLetter;
  char myString[30]; // String
};

int main()
{
  myFunction1("Liam", 3);
  myFunction1("Jenny", 14);
  myFunction1("Anja", 30);

  int myNumbers[5] = {10, 20, 30, 40, 50};
  myFunction2(myNumbers);

  // Create different struct variables
  struct myStructure s1;
  struct myStructure s2;

  // Assign values to different struct variables
  s1.myNum = 13;
  s1.myLetter = 'B';

  s2.myNum = 20;
  s2.myLetter = 'C';

  // Assign a value to the string using the strcpy function
  strcpy(s1.myString, "Some text");

  // Create a structure variable and assign values to it
  struct myStructure s3 = {13, 'B', "Some text"};

  return 0;
}
