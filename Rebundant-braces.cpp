int Solution::braces(string A) {
    stack<char> s;
    int i=0,n=A.size();
    while(i<n){
        if(A[i]==')'){
            bool isReb=true;
            while(s.top()!='('){
                if(s.top()=='+'||s.top()=='-'||s.top()=='*'||s.top()=='/')
                isReb=false;
                s.pop();
            }
            s.pop();
            if(isReb){
                return 1;
            }
        }else{
            s.push(A[i]);
        }
        i++;
    }
    return 0;
}