#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str = "23456234566";
    sort(str.begin(), str.end(), greater<int>)
    return 0;
}