#include <iostream>

/* class hello_world
*
* members:
* construcor
* hello()
*/

class hello_world
{
public:
   hello_world() // constructor
   {
     year = 2019; // default value for variable
   }

   int set_year(int newyear)
   {
     year = newyear;
   }

   int hello()
   {
     std::cout << "Hello in the year: " << year << std::endl;
   }

   int year;
};

int main()
{
  hello_world hw1;
  hello_world hw2;

  hw1.set_year(2019);
  hw1.hello();
  hw2.set_year(2022);
  hw2.hello();

  return 0;
}
