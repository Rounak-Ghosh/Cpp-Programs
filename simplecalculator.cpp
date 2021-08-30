#include<iostream>
using namespace std;

int main()
{
    int n1, n2;
    cout << "Enter 2 nos : \n";
    cin >> n1 >> n2;

    char op;
    cout << "Enter operand - ";
    cin >> op;
    cout << "\n";

    switch(op)
    {
        case '+':   cout << n1+n2;
                    break;
        case '-':   cout << n1-n2;
                    break;
        case '*':   cout << n1*n2;
                    break;
        case '/':   cout << n1/n2;
                    break;
        case '%':   cout << n1%n2;
                    break;
        default :   cout << "Couldn't recognise operand.";
                    break;            
    }
    return 0;
}