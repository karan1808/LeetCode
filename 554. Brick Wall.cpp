class Solution {
public:
    int leastBricks(vector<vector<int>>& v) {
        map<int,int>mp;
        int ans=INT_MIN;
        for(int i=0;i<v.size();i++){
            int sum=0;
            for(int j=0;j<v[i].size()-1;j++){
                sum=sum+v[i][j];
                mp[sum]++;
                ans=max(ans,mp[sum]);
            }
        }
        if(ans==INT_MIN) return v.size();
        return v.size()-ans;
    }
};