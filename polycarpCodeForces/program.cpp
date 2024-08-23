#include<bits/stdc++.h>
using namespace std ;

//there is n which represents no. of segments of type [Li ,Ri] , and we have to find the subset
// such that there is one node which can interleave with all other segments , ([1 3],[2,4],[4,5]) here [2,4] can 
//interleave with both [1,3] and [4,5] CodeForces Rating 1800
int solve(vector<pair<int ,int>>& segments , int n)
{
    vector<int>l(n) ;
    vector<int> r(n) ;
    for(int i = 0 ; i < n ; i ++)
    {
        l[i] = segments[i].first ;
        r[i] = segments[i].second; 
    }
    sort(l.begin() , l.end());
    sort(r.begin() , r.end()); 
    int ans = n - 1 ;
    for(int i = 0 ; i < n ; i++)
    {
        int right_half = lower_bound(l.begin() , l.end() ,segments[i].second + 1) - l.begin() ;
        int left_half = lower_bound(r.begin() ,r.end(),segments[i].first) - r.begin();
        ans = min(ans  ,n - right_half + left_half);
    }

    return ans ;
    
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed;
    cout<<setprecision(6);
    int n ; 
    cin >> n ;
    vector<pair<int , int>>segments(n) ;
    int left , right ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> segments[i].first >> segments[i].second ;
    } 
    cout<<solve(segments , n) ;

}