#include<iostream>
#include<algorithm>
using namespace std ; 
//Maximise the minnimum distance between the two cows given that atmost one cow can be placed in each barn_pos
//BinarySearch , Step down function , maximise the mimimum amount
bool check(int* arr ,int n , int mid , int k)
{
    int count = 1 , prev_pos = arr[0];
    for(int i = 1 ; i < n ; i ++ )
    {
        if(arr[i]- prev_pos >= mid)
        {
            prev_pos = arr[i] ;
            count ++ ;
        }
    }
    return (count >= k) ;
}
int solve(int* arr , int n , int k)
{
    sort(arr , arr+n);
    int ans = 1 ;
    int left = arr[0] , right = arr[n-1];
    while(left <= right)
    {
        int mid = (left + right)/2 ;
        
        if(check(arr , n , mid , k))
        {
            cout<<"mid : "<<mid<<endl ;
            left = mid + 1;
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
    int n , k;
    cin >> n >>k;
    int barn_pos[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> barn_pos[i] ;
    }
    cout <<solve(barn_pos , n , k);



}