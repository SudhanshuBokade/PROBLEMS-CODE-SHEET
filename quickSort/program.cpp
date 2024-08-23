#include<bits/stdc++.h>
using namespace std ;
int partition(int* a , int start , int end)
{
    int pivot = start ;
    int right_element = a[end];   
    for(int i = start ;i < end ; i ++)
    {
        if(a[i] <= right_element)
        {
            swap(a[i] , a[pivot]);
            pivot ++ ;
        }
    }
    swap(a[end] , a[pivot]);
    return pivot ;
}
void quickSort(int* arr ,int start , int end)
{
    if(start == end )
    {
        return ; 
    }
    int idx = partition(arr , start , end);
    quickSort(arr , start , idx -1 );
    quickSort(arr, idx+1 ,end);
}
int main()
{
    int n ; 
    cin >> n ;
    int a[n] ; 
    for (int i = 0 ; i < n; i ++)
    {
        cin >> a[i] ;
    }
    quickSort(a , 0 , n-1);
    for(int i = 0 ; i < n; i ++)
    {
        cout<<a[i]<<" ";
    }

}