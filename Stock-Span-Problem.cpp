class StockSpanner {
public:
    int index;
    stack<pair<int, int> > st;
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        int ans = 1;
        index++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        if(!st.empty()){
            ans = index - st.top().second;
        }else{
            ans = index;
        }
        st.push({price,index});
        return ans;
    }
};