/* Kyle Vickers
   ID: 984418528
   Assignment 5: Bracechecker
   CS515
*/

/* Design: This program reads in a file from the command line to check that all braces
(), [], and {} are properly matched in the program. If they are then the output
states this, and if they are not then the output states what line the first
brace was mismatched at. */
   
#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <stack>
#include <vector>
#include "Stack.h"

using namespace std;

struct Token
{
    char bracket;
    int line;
};

int main(int argc, char ** argv){
    ifstream f;
    f.open( argv[1] );
    if( !f ){
      cout << "Error opening file. Quitting.\n";
      system("PAUSE");
       return EXIT_SUCCESS;
      //exit(-1);
    }

    int line_count = 1;
    
    Stack<Token> brackstack;
    
    Token stackchar;
    char ch;

    while( f.get( ch ) ){   
    //IF YOU FIND A LEFT BRACKET ADD IT TO THE STACK
    if( ch == '(' || ch == '{' || ch == '[')
    {
           Token cur;
           cur.bracket = ch;
           cur.line = line_count;
           brackstack.push(cur);
    }
    //FOUND A RIGHT BRACKET
    else if( ch == ')' || ch == '}' || ch == ']' )
    {
           // IF STACK IS SIZE IS 0 AND YOU FOUND CLOSING BRACKET THERE IS AN ERROR //
           if( brackstack.empty() )
           {
               cout << "mismatched " << ch << " in line " << line_count << endl;
	       return 0;
           }
           stackchar = brackstack.top();
           // IF THE TOP OF THE STACK IS MATCHING LEFT BRACKET FOR THE CURRENT CHARACTER POP THE TOKEN OFF THE STACK
           if(
                (stackchar.bracket == '(' && ch == ')') ||
                (stackchar.bracket == '{' && ch == '}') ||
                (stackchar.bracket == '[' && ch == ']')
             ) {
                  brackstack.pop();
              }
              // IF THE TOP OF THE STACK IS NOT A MATCHING LEFT BRACKET THEN THERE IS AN ERROR ON THE STACK TOKEN LINE
              else
              {            
                  cout << "mismatched " << ch  << " in line " << line_count  << endl;
		  return 0;
              }
    }
    else if( ch == '\n' )
        line_count++;
    }
    if( brackstack.empty() == 0 )
    {
        cout << "mismatched " << brackstack.top().bracket << " in line " << brackstack.top().line << endl;
	return 0;
    }
    cout << "All braces matched." << endl;
    
       system("PAUSE");
       return EXIT_SUCCESS;
    //return 0;
}
