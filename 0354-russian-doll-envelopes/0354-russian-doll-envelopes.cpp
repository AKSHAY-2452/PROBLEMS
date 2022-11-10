class Solution {
    
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> arr;
       for(auto it: envelopes){
           int idx = lower_bound(arr.begin(),arr.end(),it[1]) - arr.begin();
           if(idx >= arr.size()) arr.push_back(it[1]);
           else{
               arr[idx] = it[1];
           }
       }
        return arr.size();
    }
};