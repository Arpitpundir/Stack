class Solution {
public:
    int evals(int left, int right, string sign){
        if(sign== "+")
                return left+right;
        if(sign=="-")
                return left-right;
        if(sign=="*")
                return left*right;
        return left/right;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(tokens[i] == "+"||tokens[i]=="/"||tokens[i]=="*"||tokens[i]=="-"){
                int right = stoi(st.top());
                st.pop();
                int left = stoi(st.top());
                st.pop();
                st.push(to_string(evals(left,right,tokens[i])));
            }else {
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};