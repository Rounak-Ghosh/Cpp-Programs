#include<iostream>
using namespace std;

int main()
{

    char ch;
    int isLowercaseVowel, isUppercaseVowel;
    
    cout << "Enter an alphabet - ";
    cin >> ch;

    isLowercaseVowel = (ch=='a' || ch=='e' || ch=='i' || ch=='o' ||ch=='u');
    isUppercaseVowel = (ch=='A' || ch=='E' || ch=='I' || ch=='O' ||ch=='U');

    if(isUppercaseVowel || isLowercaseVowel)
    {
        cout << "\n" << ch << " is a vowel.";
    }
    else
    {
        cout << "\n" << ch << " is a consonant.";
    }

    return 0;

}