// https://leetcode.com/problems/car-fleet/description/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double> > carStPosn_iniTime;
        for(int i=0;i<n;i++){
            carStPosn_iniTime.push_back({position[i], (double)(target-position[i])
            /speed[i]});
        }
        // sort by starting position
        sort(carStPosn_iniTime.begin(), carStPosn_iniTime.end());
        int ans = 1;
        double lastCarTime = carStPosn_iniTime[n-1].second;
        for(int i=n-2;i>=0;i--){
          /* 
          * if the car is faster than the last car, it will catch up and will be a part of the same fleet
          * if the car is slower than the last car, it will not catch up and will be a part of a new fleet
          */
            if(carStPosn_iniTime[i].second > lastCarTime){
                ans++;
                lastCarTime = carStPosn_iniTime[i].second;
            }
        }
        return ans;
    }
};