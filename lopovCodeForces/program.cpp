#include<bits/stdc++.h>
#include<iostream>
using namespace std ;
//there are N jewellery which having certain value and  weight to it ,Also there is a thief whith K bags each with holding capacity of Ci and can carry atmost one item
class Jewellery
{
    public :
    int weight ,value;
};

bool cmp(Jewellery& a , Jewellery& b)
{
    if(a.value == b.value)
    {
        return a.weight < b.weight ;
    }
    else
    {
        return a.value > b.value ;
    }
}
void solve()
{
    int N , K ; 
    cin >> N>>K ; 
    vector<Jewellery>jewel(N);
    for(int i  = 0 ; i < N; i ++)
    {
        cin >> jewel[i].weight >> jewel[i].value;
    }
    vector<int>bags(K);
    for(int i =  0 ; i < K ; i ++)
    {
        cin >> bags[i] ;
    }
    int filled[K] ;
    for(int i = 0 ; i < K ;i ++)
    {
        filled[i] = 0 ;
    }
    sort(jewel.begin() , jewel.end(),cmp);
    sort(bags.begin(),bags.end());
    int result = 0 ;
    for(int i = 0 ; i < N ; i ++)
    {
        int idx = lower_bound(bags.begin(),bags.end(),jewel[i].weight) - bags.begin();
        if ( idx != K )
        {
           
                while(idx < K  && filled[idx] != 0)
                {
                    idx++ ;
                }
                if(idx < K)
                {
                    filled[idx] = 1 ;
                    result += jewel[idx].value ;
                }
                
        }
    }
    cout<<result ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed;
    cout<<setprecision(6);
    solve();
}