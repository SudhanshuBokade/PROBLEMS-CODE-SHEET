#include<bits/stdc++.h>
using namespace std ; 
bool cmp(pair<int ,int>& a , pair<int ,int>& b)
{
    if(a.second == b.second)
    {
        return a.first < b.first ;
    }
    else
    {
        return a.second < b.second;
    }
}
int main()
{
    int n  ;
    cin >> n ;
    vector<pair<int,int>>intervals ; 
    int start , end ;
    for(int i = 0 ; i < n ; i++ )
    {
        cin >> start >>end ;
        intervals.push_back({start , end});
    }
    sort(intervals.begin() , intervals.end() , cmp);
    int classrooms = 0 ;
    while(!intervals.empty())
    {
        auto it = intervals.begin();
        int prev_end = it->second ;
        it = intervals.erase(it);
        it = intervals.begin();
        while(it != intervals.end())
        {
            if(it->first >= prev_end)
            {
                prev_end = it->second ;
                it = intervals.erase(it);
            
            }
            else
            {
                it++ ;
            }
        } 
        classrooms ++ ;
    }
    cout<<"no. of classrooms required are "<<classrooms<<endl;

}