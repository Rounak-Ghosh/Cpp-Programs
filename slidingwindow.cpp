#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void slidingWindow(vector<int> &arr, int k, int n)
{
    deque<int> dq;
    vector<int> ans;
    for(int i=0; i<k; i++)  // push first k elements in deque
    {
        while(!dq.empty() && arr[dq.back()] < arr[i])   // deleting all elements less than arr[i] - left side of queue
            dq.pop_back();
        dq.push_back(i);
    }    
    ans.push_back(arr[dq.front()]);     // first element in deque is the max element
    for(int i=k; i<n; i++)  // rest of elements on the right side of arr[i] 
    {
        if(dq.front() == i-k)   // eliminate index that was max and now is outside sliding window
            dq.pop_front();
        while(!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }
    for(auto &i : ans)
        cout << i << " ";
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i : a) 
        cin >> i;
    slidingWindow(a, k, n);
    return 0;
}