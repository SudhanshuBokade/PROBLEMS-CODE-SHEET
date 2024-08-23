#include<bits/stdc++.h>
using namespace std ; 
bool cmp(pair<int ,int>& a , pair<int ,int>& b)
{
    if(a.second == b.second)
    {
        return a.first < b.first; 
    }
    else{
        return a.second > b.second ;
    }
}
int main()
{
    int N ,K  ; 
    cin >>N >> K ; 
    int weight , value ;
    vector<pair<int ,int>>items(N);
    for(int i = 0 ;  i < N ; i++)
    {
        cin >> weight >> value;
        items[i] = {weight , value};
    }
    vector<int>bags(K) ;
    for(int i = 0 ; i < K ; i ++)
    {
        cin >> bags[i] ;
    }
    multiset<int>ms ; 
    for(int i = 0 ; i < K ; i ++)
    {
        ms.insert(bags[i]);
    }
    int result = 0  ; 
    sort(items.begin() , items.end() , cmp );
    sort(bags.begin() , bags.end());
    for(int i = 0 ; i < N ; i ++)
    {
        auto it = ms.lower_bound(items[i].first);
        if(it != ms.end())
        {
            result += items[i].second ;

            
            ms.erase(it);
        } 
    }
    cout<<result ;

}