vector<int> Solution::prevSmaller(vector<int> &a) {
    
    stack<int> st;
    vector<int> ans;
    int n = a.size();
    
    if(a.size() == 0){
        
        return ans;
    }
    ans.push_back(-1);
    st.push(a[0]);
    
    for(int i = 1;i < n;i++){
        
        while(!st.empty() && st.top() >= a[i]){
            
            st.pop();
        }
        
        if(st.empty()){
            
            ans.push_back(-1);
        }else{
            
            ans.push_back(st.top());
        }
        
        st.push(a[i]);
    }
    
    return ans;
}