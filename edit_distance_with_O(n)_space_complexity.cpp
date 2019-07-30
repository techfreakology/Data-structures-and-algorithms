#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        long dp[2][2001]={0},i,j;
        for(i=0;i<=a.length();i++)
        {
            for(j=0;j<=b.length();j++)
            {
                if(i==0 || j==0)    dp[1][j] = max(i,j);
                else
                {
                    if(a[i-1]==b[j-1])  dp[1][j] = dp[0][j-1];
                    else
                    dp[1][j] = 1+min(dp[0][j-1],min(dp[0][j],dp[1][j-1]));
                }
            }
            
            for(j=0;j<=b.length();j++)
            {
                dp[0][j] = dp[1][j];
            }
        }
        cout<<dp[1][b.length()]<<endl;
    }
	return 0;
}