#include<iostream>
using namespace std ; 
int main()
{
    int arr[10] = {0 ,1, 2, 2,3, 3, 2, 2,1, 1} ;
    int p0 = 0  , p1 = 0 , current = 0 , p3 = 9 ; 
    while(current < p3)
    {
        if(arr[current] == 0 )
        {
            swap(arr[p0] , arr[current]);
            current ++ , p0 ++ , p1 ++ ;
        }
        else if( arr[current] == 1)
        {
            swap(arr[current] , arr[p1]);
            p1 ++ ,current ++ ;
            
        }
        else if(arr[current] == 2)
        {
            current ++ ;
        }
        else
        {
            swap(arr[current] , arr[p3]);
            p3 -- ;
        }
    } 
    for(int i = 0 ; i < 10; i ++)
    {
        cout<<arr[i]<<" ";
    }
    return 0 ;
}