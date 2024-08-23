#include<bits/stdc++.h>
using namespace std; 
bool cmp(pair<int ,int>& a , pair<int ,int>& b)
{
    return a.first < b.first ;
}

int main()
{
    int n ; 
    vector<pair<int , int>>intervals(n);
    sort(intervals.begin() , intervals.end() ,cmp);
    priority_queue<int , vector<int> , greater<int>> pq ;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >>intervals[i].first >> intervals[i].second ;
    }
    sort(intervals.begin(),  intervals.end() ,cmp);
    vector<int>start(n) , end(n);
    priority_queue<int , vector<int> , greater<int>>endTimes;
    for(const auto& interval : intervals)
    {
        if(!endTimes.empty() && endTimes.top() <= interval.first)
        {
            endTimes.pop();
        }
        endTimes.push(interval.second);
    }
    cout<<"no of classrooms rewuired is "<<endTimes.size();


}