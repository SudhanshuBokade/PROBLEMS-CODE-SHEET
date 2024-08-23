#include<bits/stdc++.h>
using namespace std ; 
class Job
{
    public : 
    int start , end , profit ;
};
bool cmp(Job& a , Job& b)
{
    return a.end < b.end ;
}
int binary(vector<Job>& vec ,int ind )
{
    int lo = 0 , high = ind-1;
    while(lo <= high)
    {
        int mid = (lo+high)/2 ;
        if(vec[mid].end <= vec[ind].start)
        {
            if(vec[mid+1].end > vec[ind].start)
            {
                return mid ; 
            }
            else
            {
                lo = mid +1 ;
            }
        }
        else
        {
            high = mid -1 ;
        }
    } 
    return -1 ;
}
int main()
{
    int test ; 
    cin >> test ; 
    while(test --)
    {
        int n ;
        cin>>n ;
        vector<Job>vec(n);
        for(int i = 0 ; i < n; i ++)
        {
            cin >>vec[i].start>>vec[i].end>>vec[i].profit ;
        }
        sort(vec.begin(),vec.end(),cmp);
        int table[n]; 
        table[0] = vec[0].profit;
        for(int i = 1 ;  i < n ; i++)
        {
            int incProfit = vec[i].profit ;
            int greatest_uninterleaved_index = binary(vec , i );
            if(greatest_uninterleaved_index != -1 )
            {
                incProfit += table[greatest_uninterleaved_index]; 
            }
            table[i] = max(incProfit , table[i-1]);
        }
        cout<< table[n-1]<<endl;
    }
}