#include <iostream>

/*
  Assignment: complete this program by putting your code in all the locations
    that say -- your code here --

  Make sure that the program compiles and builds and check the output
    after every change.

  Tip: before you look at the output, always think ahead what you expect to
    see and then check if your assumption was correct.
 */

int main()
{
char letter = 97; // find this in the ASCII table (type 'man ascii')
char *letterpointer;

  std::cout << "Contents of the variable letter: "<< std::endl;
  std::cout << "a"<< std::endl;

  letterpointer = &letter;
  std::cout << "Contents of letterpointer: "<< std::endl;
  std::cout << letterpointer << std::endl;

  std::cout << "Contents of what letterpointer points to: " << std::endl;
  std::cout << *letterpointer << std::endl;

  *letterpointer = 'b';
  std::cout << "The variabele letter has gotten a new value through letterpointer."<< std::endl;
  std::cout << "Contents of what letterpointer points to: "<< std::endl;
  std::cout << *letterpointer << std::endl;

  std::cout << "Contents of the variable letter: "<< std::endl;
  std::cout << letter << std::endl;

  /*
   * Create the necessary pointer(s) and use them
   */

  unsigned short year = 2019;
  std::cout << "Contents of the variabele year: "<< std::endl;
  std::cout << year << std::endl;
  unsigned short* yearpointer;

  yearpointer = &year;
  std::cout << "Contents of yearpointer: "<< std::endl;
  std::cout << yearpointer << std::endl;

  std::cout << "Contents of what yearpointer points to: "<< std::endl;
  std::cout << *yearpointer << std::endl;

  *yearpointer = 2020;

  std::cout << "Contents of the variabele year: "<< std::endl;
  std::cout << year << std::endl;

  unsigned short* anotheryearpointer;
  anotheryearpointer = &year;

  std::cout << "Contents of anotheryearpointer: "<< std::endl;
  std::cout << anotheryearpointer << std::endl;

  std::cout << "Contents of what anotheryearpointer points to: "<< std::endl;
  std::cout << *anotheryearpointer << std::endl;

  *anotheryearpointer = 2021;

  std::cout << "Contents of year: "<< std::endl;
  std::cout << year << std::endl;

  std::cout << "Contents of what anotheryearpointer points to: "<< std::endl;
  std::cout << *anotheryearpointer << std::endl;

  anotheryearpointer++;

  std::cout << "Contents of anotheryearpointer after ++: "<< std::endl;
  std::cout << *anotheryearpointer << std::endl;
}
