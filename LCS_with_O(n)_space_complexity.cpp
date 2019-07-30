#include <bits/stdc++.h>
using namespace std;

long LCS(string a,string b)
{
    long dp[2][6101],i,j;
    for(i=0;i<=a.length();i++)
    {
        for(j=0;j<=b.length();j++)
        {
            if(i==0 || j==0)    dp[1][j]=0;
            else
            {
                if(a[i-1]==b[j-1])  
                {
                    dp[1][j] = dp[0][j-1]+1;
                }
                else    dp[1][j] = max(dp[0][j],dp[1][j-1]);
            }
        }
        for(j=0;j<=b.length();j++)   dp[0][j] = dp[1][j];
    }
    return dp[1][b.length()];
}



int main()
{
    string s,t;
    cin>>s>>t;
    cout<<LCS(s,t);
	return 0;
}