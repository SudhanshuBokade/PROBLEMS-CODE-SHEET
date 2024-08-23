#include<iostream>
#include<bits/stdc++.h>
//Given an array B of length N {b1 ,b2 ,b3 , b4 ... bN} and integer L 
//Input constraints 1<=bi , 2<=N  
// to find , minimum(abs(bi+ bj - L))  and count of such pairs(i, j) such that i!= j
using namespace std ; 
int main()
{

    freopen("input.txt","r",stdin);
    int test ; 
    cin >> test ; 
    while(test --)
    {
        int N , L; 
        cin >> N >> L;
        int arr[N] ; 
        for(int i = 0 ; i  < N ; i ++)
        {
            cin >> arr[i] ; 
        }
        sort(arr , arr + N );
        int i = 0 , j  = N -1 ; 
        int minElement = INT_MAX;
        while(i<j )
        {
            if(arr[i] + arr[j] == L )
            {
                minElement = 0 ;
                break ;
            }
            if(minElement > abs(arr[i] + arr[j]- L ))
            {
                minElement = abs(arr[i] + arr[j] - L);
            }
            if(arr[i] + arr[j] > L )
            {
                j -- ;
            }
            else
            {
                i ++;
            }
        }     
        i = 0 , j = N-1; 
        int count =0 ;
        while(i < j)
        {
            if(minElement == abs(arr[i] + arr[j] - L))
            {
                if(arr[i] == arr[j] )
                {
                    count += (j-i+1)*(j-i)/2 ;
                    break ;
                }
                count ++ ; 
                i ++ ;
            }
            else if ( arr[i] + arr[j]- L > minElement )
            {
                j -- ;
            }
            else
            {
                i ++ ;
            }
        }
        cout<<minElement <<" "<< count ; 
        if(test-1 >= 0)
        {
            cout<<",";
        }
    }
}