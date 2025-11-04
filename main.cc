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
