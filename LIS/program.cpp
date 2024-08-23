#include<iostream>
using namespace std ;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test ;
    cin >> test ;
    while(test -- )
    {
        string s ;
        cin >> s; 
        int len = s.length();
        int a[len+1];
        a[0] = 0 ;
        for(int i = 1 ; i < len+1 ; i ++)
        {
            a[i] = 1 ;
        }
        int max_target = 0 ;
        for(int i = 1 ; i < len+1 ; i ++)
        {
            cout<<s.substr(0,i)<<" ";
            int maxi  = 1;
            for(int j = 1 ; j <= i-1 ; j ++)
            {
                if(s[i-1] > s[j-1])
                {
                    maxi = max( maxi ,a[j]+1);
                }
            }
            a[i] = maxi ;
            max_target = max(a[i],max_target);
            cout<<a[i]<<endl;
        }
        cout<<max_target<<endl;
    }
    
     fclose(stdin);
     fclose(stdout);
}