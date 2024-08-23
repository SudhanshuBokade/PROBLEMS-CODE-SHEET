#include<iostream>
using namespace std ; 
int main()
{
    int n ; 
    cin >> n ;
    int arr[n]  ;
    int xxor = 0 ;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> arr[i-1] ;
        xxor ^= arr[i-1] ;
        xxor ^= i ;
    }
    
    int x = 0 , y = 0;
    int setBit = (xxor &(~(xxor-1))) ;
    for(int i = 0 ; i < n ; i ++)
    {
        if(arr[i] & setBit )
        {
            x ^= arr[i] ;
        }
        else
        {
            y ^= arr[i] ;
        }
    }
    for(int i = 1; i <= n ; i ++)
    {
        if(i & setBit)
        {
            x^= i; 
        }
        else
        {
            y ^= i ;
        }
    }
    cout <<" x = "<<x <<" y = "<<y <<endl;
    for(int i = 0; i < n ; i ++)
    {
        if(arr[i] == y)
        {
            cout<<x<<" is missing number"<<endl;
            break ;
        }
        else if(arr[i] == x)
        {
            cout<<y<< " is missing number "<<endl ;
            break ;
        }
    }
    

}