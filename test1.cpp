
#include "Stack.h"

int main(){
   Stack<int> s;
   s.push(5);
   s.push(6);
   s.push(100);
   s.pop();
   cout << s; 

   cout << "Full test " << s.full() << endl;
   //bool fullcheck = s.full();
   
   Stack<char> s1;
   s1.push(56);
   s1.push(59);
   cout << s1;
  
} 
