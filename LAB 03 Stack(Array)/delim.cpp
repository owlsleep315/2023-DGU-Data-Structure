//20222110879 Á¤Ã¤È²
//--------------------------------------------------------------------
//
//  Laboratory 5 (In-lab 3 shell)                          delim.cs
//
//  Program validates delimiter pairing.
//
//--------------------------------------------------------------------

#include <string>
#include "stackarr.cpp"

//--------------------------------------------------------------------
//
//  Function prototype

bool delimitersOk(const string &expression);

//--------------------------------------------------------------------

int main(void)
{
    string inputLine;            // Input line
    char ch;                     // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while(cin)
    {
        cout << "Enter delimited expression (<EOF> to quit) : ";

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while(cin && ch != '\n')
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }
    
        if(!cin)              // Reached EOF: stop processing
            break;

        if (delimitersOk(inputLine))
            cout << "Valid" << endl << endl;
        else
            cout << "Invalid" << endl << endl;
    }

    return 0;
}


bool delimitersOk(const string& expression)
{
    Stack<char> delimiterStack(100);
    for(char c : expression){
        switch (c) {
        case  '[':
        case '(':
            delimiterStack.push(c);
            break;
        case ']':
            if (delimiterStack.pop() != '[') {
                return false;
            }
            break;
        case ')':
            if (delimiterStack.pop() != '(') {
                return false;
            }
            break;
        default:
            break;
        }
    }
    return delimiterStack.isEmpty();
}
