#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calculateSpan(vector<int> price, int n)
{
    vector<int> span;
    stack<pair<int,int>> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
            span.push_back(-1);
    
        if (st.size() > 0 && st.top().first > price[i])
            span.push_back(st.top().second);

        else if (st.size() > 0 && st.top().first < price[i])
        {
            while (st.size() > 0 && st.top().first < price[i])
                st.pop();
            span.push_back(st.top().second);
        }
        st.push({price[i],i});
    }

    for(int i=0; i<span.size(); i++)
        span[i] = i - span[i];
        
    return span;
}
int main()
{
    vector<int> stockPrice = {100,80,60,70,60,75,85};
    vector<int> span = calculateSpan(stockPrice, 7);
    for (int i : span)
    {
        cout << i << " ";
    }
    return 0;
}