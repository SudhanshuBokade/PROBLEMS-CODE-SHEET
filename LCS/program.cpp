#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test ; 
    cin >> test ;
    while(test -- )
    {
        string s1 , s2 ;
        cin >>s1 >>s2 ;
        int m = s1.length() , n = s2.length();
        int a[m+1][n+1];
        vector<char>s4 ;
        for(int i = 0 ; i < m+1 ; i ++)
        {
            a[i][0] = 0 ;
        }
        for(int i = 0 ; i < n+1 ; i ++)
        {
            a[0][i] = 0 ;
        }
        for(int i = 1 ; i < m+1 ;i ++)
        {
            for(int j = 1 ; j <n+1 ; j ++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    a[i][j] = a[i-1][j-1] +1 ;
                }
                else
                {
                    a[i][j] = max(a[i][j-1] ,a[i-1][j]); 
                }
            }
        }
        cout<<"Length of longest subsequence of strings "<<s1<<" and "<<s2<<" is "<<a[m][n];
    
    }
        

}