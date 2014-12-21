
#include <cstdlib>
#include <iostream>
#include "CharStack.h"

using namespace std;

int main(){
   CharStack s;
   s.push('a');
   s.push('b');
   s.push('c');
   s.pop();
   cout << s; 

   cout << "Full test " << s.full() << endl;
  
  
} 
