#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> st;
        vector<long long > ans;
        ans.resize(n,-1);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};