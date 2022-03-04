class Solution {
public:
    vector<int> NSR(vector<int> arr){
        int n = arr.size();
        vector<int> ans;
        ans.resize(n,-1);
        stack<pair<int,int> > st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top().second;
            }
            st.push({arr[i],i});
        }
        return ans;
    }
    
    vector<int> NSL(vector<int> arr){
        int n=arr.size();
        vector<int> ans; ans.resize(n,-1);
        stack<pair<int, int> > st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top().second;
            }
            st.push({arr[i], i});
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl=NSL(heights), nsr=NSR(heights);
        vector<int> width;
        
        for(int i=0;i<n;i++){
            if(nsl[i]==-1 && nsr[i]==-1){
                width.push_back(n);
            }else if(nsl[i]==-1){
                width.push_back(nsr[i]);
            }else if(nsr[i]==-1){
                width.push_back(n-nsl[i]-1);
            }else{
                width.push_back(nsr[i]-nsl[i]-1);
            }
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int currArea = heights[i]*width[i];
            ans = max(currArea, ans);
        }
        return ans;
    }