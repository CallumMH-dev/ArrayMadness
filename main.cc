/* Printing and editing pseudo 2D array by Callum Hartley */
#include <iostream>

const unsigned HEIGHT = 20;
const unsigned WIDTH  = 20;
int array[HEIGHT*WIDTH];

void INIT_ARRAY(int* array, unsigned i = 0){ for(;i < HEIGHT*WIDTH;){ array[i++] = 0; } }

void PRINT_ARRAY(int* array, unsigned counter = 0, unsigned i = 0)
{
 for(;i < HEIGHT*WIDTH;)
 {
  if( array[i++] == 0 ){ std::cout << '.'; } else { std::cout << '#'; }
  if( counter++ == (WIDTH - 1) ){ counter = 0; std::cout << '\n';}
 }
}

bool CHANGE_ELEMENT_VIA_COORDINATES(int* array, unsigned x = 0, unsigned y = 0)
{
 std::cout << "please enter an X followed by a Y coordinate" << std::endl;
 std::cin >> std::ws >> x >> y;
 if( x >= WIDTH || y >= HEIGHT ){ return 1; } else { array[y * WIDTH + x] = 1; }
 return 0;
}

int main()
{
 INIT_ARRAY(array);
 PRINT_ARRAY(array);
 if( !CHANGE_ELEMENT_VIA_COORDINATES(array) ){ PRINT_ARRAY(array); }
 else{ std::cout << "invalid coord, array is " << HEIGHT << " * " << WIDTH << std::endl; }
 return 0;
}

/* NOTES: Thought it would be a good idea to leave a comment for future self incase I ever look over this and get confused.
   The premise behind y * WIDTH + x is relatively simple, first to clear up any confusion HEIGHT is Y is rows and WIDTH is X is cols, in terms of a 2D array( array[HEIGHT][WIDTH] )
   now the formula of y * WIDTH + x can be better explained broken down, first we have y * WIDTH = how many rows down we want to go, i.e. 0*20 = first row, 1 * 20 = second row etc.

   Now if you're lost just remember WIDTH is the cols part of an array, we can assume every row has 19 elements( index 0 ), so when it ticks over we will be at the first element of the
   next row( array[1][0] == 1 * 20 ).

   Next we have + x which is going to traverse the current cols on the row of n * WIDTH.
*/
