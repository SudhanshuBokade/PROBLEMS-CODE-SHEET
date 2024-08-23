#include<iostream>
using namespace std ; 
int lower_bound(int* arr ,int n , int k)
{
    int left = 0 , right = n-1 ;
    while(left< right)
    {
        int mid = left + (right - left)/2  ;
        if(arr[mid] >= k ) right = mid ;
        else
            left = mid + 1;
    }
    if(left < n && arr[left] < k)
    {
        left ++ ;
    }
    return left ;

}

int upper_bound(int* arr , int n, int k)
{
    int left = 0 , right = n-1;
    while(left < right)
    {
        int mid = left + (right - left)/2 ;
        if(k >= arr[mid])left = mid + 1 ;
        else
        {
            right = mid;
        }
    }
    if(left < n && arr[left] <= k)
    {
        left ++  ;
    }
    return left ; 
}


int main()
{
    int n = 10 ; 
   
    int arr[n] = {1 ,2 , 6 , 6, 10 , 18 , 67 ,121 , 129 , 234} ;
    cout<<lower_bound(arr , n , 6);
    
}