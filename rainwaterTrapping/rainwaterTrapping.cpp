#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cout<<"enter the length of arr of walls :";
    cin >> n ; 
    int arr[n] ; 
    cout<<"Enter the length of each wall in order :";
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> arr[i];
    }
    int num_blocks = 0 ; 
    int max_height = -1 ;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i ++)
    {
        num_blocks += arr[i] ; 
        max_height = (max_height > arr[i]) ?max_height:arr[i];
    }
    int left = 0 , right = n-1;
    for (int i = 1 ; i < max_height + 1 ; i ++)
    {
        while(arr[left]< i)
        {
            left ++;
        }
        while(arr[right]<i)
        {
            right -- ;
        }
        ans += (right - left + 1);

    }
    ans -= num_blocks;
    cout<<ans ;


}