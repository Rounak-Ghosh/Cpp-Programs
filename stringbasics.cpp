#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;             // Rounak   // Rounak Ghosh
    cout << str << endl;    // Rounak   // Rounak
    
    string str1(5, 'R');
    cout << str1 << endl;   // RRRRR

    string str2 = "RounakGhosh";
    cout << str2 << endl;   // RounakGhosh

    string str3;
    getline(cin, str3);     // Rounak is a peaceful soul
    cout << str3 << endl;    // Rounak is a peaceful soul

    string st1 = "fam";
    string st2 = "ily";
    st1.append(st2);    
    cout << st1 << endl;    // family,  st1 = family, st2 = ily
    cout << st1 + st2 << endl;  // family,   st1 = fam, st2 = ily
    
    cout << st1[2] << endl; // m

    string abc = "jhvfihsgd fsgga asgsg";
    abc.clear();
    cout << abc << endl;    // no output

    st1 = "abc", st2 = "xyz";
    cout << st2.compare(st1) << endl;   // 1

    st1 = "abc", st2 = "abc";
    cout << st2.compare(st1) << endl;   // 0

    st1 = "abc", st2 = "xyz";
    cout << st1.compare(st2) << endl;   // -1

    if(!st1.empty())
        cout << "Not Empty" << endl;

    st1 = "nincompoop";     // foolish person
    st1.erase(3, 3);
    cout << st1 << endl; // ninpoop

    st1.insert(3, "com");
    cout << st1 << endl;

    cout << st1.find("com") << endl;    // 3 - return index & first occurence only

    cout << st1.length() << endl;   // 10
    cout << st1.size() << endl;     // 10

    for(int i=0; i<st1.length(); i++)
        cout << st1[i] << endl;             // all chars

    cout << st1.substr(6, 4) << endl;   // poop

    string st = "786";
    int x = stoi(st);       // string to int
    cout << x << endl; 
    
    cout << to_string(x) + "haha" << endl;      // int to string

    st = "hklsne";
    sort(st.begin(), st.end());     // sorting a string
    cout << st << endl;


    return 0;
}