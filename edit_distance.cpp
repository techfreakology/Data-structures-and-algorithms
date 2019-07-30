//EDIT DISTANCE 
//PROBLEM LINK: https://www.spoj.com/problems/EDIST/

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
        long dp[2001][2001]={0},i,j;
        for(i=0;i<=a.length();i++)
        {
            for(j=0;j<=b.length();j++)
            {
                if(i==0 || j==0)    dp[i][j] = max(i,j);
                else
                {
                    if(a[i-1]==b[j-1])  dp[i][j] = dp[i-1][j-1];
                    else
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                }
            }
        }
        cout<<dp[a.length()][b.length()]<<endl;
    }
	return 0;
}
