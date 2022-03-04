int Solution::trap(const vector<int> &a) {
    vector<int> left,right;
    int currMax=a[0];
    int n=a.size();
    left.resize(n);
    right.resize(n);
    for(int i=0;i<n;i++){
        if(a[i]>currMax){
            left[i]=a[i];
            currMax=a[i];
        }else{
            left[i]=currMax;
        }
    }
    currMax=a[n-1];
    for(int i=n-1;i>=0;i--){
        if(a[i]>currMax){
            right[i]=a[i];
            currMax=a[i];
        }else{
            right[i]=currMax;
        }
    }
    int ans=0;
// calculate water trapped on top of each bar
    for(int i=0;i<n;i++){
        ans+=(max(left[i],right[i])-a[i]);
    }
    return ans;
}