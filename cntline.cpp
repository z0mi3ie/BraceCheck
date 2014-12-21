/********************************************** 
A simple program for file processing
Input file is read from command line 
Program displays the total number of open/close braces 
and the line numbers.
************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>  
using namespace std;

int main(int argc, char ** argv){
  ifstream f;
  f.open(argv[1] );
  if( !f ){
    cout << "Error opening file. Quitting.\n";
    exit(-1);
  }

  int open_count = 0;
  int close_count = 0;
  int line_count = 0;

  char ch;
  while( f.get( ch ) ){    // fills ch with the next char from file,
                           // returns false if the end of file (EOF) 
                           // is reached
    if( ch == '(' ) 
      open_count++;
    else if( ch == ')' )
      close_count++;
    else if( ch == '\n' )
      line_count++;
  }   
  
  cout << open_count << " of ) " << endl;   
  cout << close_count << " of (  " << endl;
  cout << line_count  << " lines " << endl;
}
