#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    int n=intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    vector<int> prev=intervals[0];
    for(int i=1; i<n; i++){
        if(intervals[i][0]<prev[1]){
            prev[1]=max(prev[1],intervals[i][1]);
        }
        else{
            merged.push_back(prev);
            prev=intervals[i];
        }
    }
    merged.push_back(prev);
    return merged;
}
