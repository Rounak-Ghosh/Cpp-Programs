#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    int n;
    cout << "Size of array = ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter array elements:" << endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    unordered_map<int, int> freq;
    for(int i=0; i<n; i++)
    {
        freq[arr[i]]++;
    }

    cout << endl;
    unordered_map<int, int> :: iterator it;
    for(it = freq.begin(); it!=freq.end(); it++)
        cout << it->first << " " << it->second << endl;


    cout << endl;
    for(auto x : freq)
        cout << x.first << " " << x.second << endl;
    return 0;
}