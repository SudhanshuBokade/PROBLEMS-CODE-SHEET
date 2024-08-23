#include<iostream>

using namespace std ;
int maxi(int a , int b)
{
    return (a>b)?a:b ;
}
int main()
{
   
    int n ; 
    cin >> n ; 
    int arr[n];
    cout<<"Enter the elements  i.e. length of each walls : ";
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> arr[i] ;
    }
    int max_left = 0 , max_right = 0 ;
    int left = 0 , right = n-1 ; 
    int result = 0 ;
    while(left <= right )
    {
        if(max_right <= max_left)
        {
            result += maxi(0 , max_right - arr[right]);
            max_right  = maxi(max_right , arr[right]);
            right -- ;
        }
        else
        {
            result += maxi(0 , max_left - arr[left]);
            max_left = maxi(max_left , arr[left]);
            left ++ ;
        }
    }
    cout<<result ;
    return  0 ;
    
}