class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool invalid = false;
        unordered_map<char,char> mp;
        mp[')'] = '(', mp['}'] = '{', mp[']'] = '[';
        for(int i=0;i<s.size();i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }else {
                if(st.empty() || st.top() != mp[s[i]]){
                    invalid = true;
                    break;
                }else{
                    st.pop();
                }
            }
        }
        return !invalid && st.empty();
    }
};