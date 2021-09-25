#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str = "234568671";
    sort(str.begin(), str.end(), greater<int>());
    cout << str; 
    return 0;
}