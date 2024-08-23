#include<bits/stdc++.h>
//this is eco friendly problem , man want  to cut the tree and he only cut what is required atleast
//set the height of blade such that it would cut with minimum height 
using namespace std ; 
bool check(int* arr , int n ,int mid, int k )
{
    int sum = 0 ; 
    for(int i = 0 ; i < n; i ++)
    {
        sum += max(0 , arr[i]-mid);
    }
    return sum >=k;
}
int solve(int* arr , int n , int k )
{
    sort(arr , arr + n );
    int left = arr[0] , right = arr[n-1] ;
    int ans = -1 ;
    while(left <= right)
    {
        int mid = left + (right - left)/2 ;
        if(check(arr ,n , mid , k))
        {
            left = mid +1 ;
            ans = mid ;
        }
        else
        {
            right = mid - 1; 
        }
    }
    return ans ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed ;
    cout<<setprecision(6);
    int n =4 , k=7;
    
    int arr[n] = {20 ,15,10,17} ;
    
    cout << solve(arr , n , k);
}