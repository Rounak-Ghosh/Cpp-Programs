#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool ispowerof2(int n)
{
    //return !(n & n-1);    -> except n=0, cuz -1 will come
    return (n && !(n & n-1));   // to avoid corner case, -> n=0 
}

int main()
{
    int n;
    cin >> n;
    cout << ispowerof2(n) << endl;

    if(ceil(log2(n)) == floor(log2(n)))     // Alternative approach
        cout << "True " << endl;
    else
        cout << "False " << endl;

    return 0;
}