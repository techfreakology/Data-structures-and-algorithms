#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> build_lps(string pat)
{
    ll n = pat.length();
    vector<ll> lps(n);
    lps[0] = 0;
    
    for(ll i=0,j=1;j<n;)
    {
        if(pat[i]==pat[j])
        {
            lps[j] = i+1;
            i++;
            j++;
        }
        else
        {
            lps[j] = i;
            if(i==0)
            {
                j++;
            }
            else
                i = lps[i-1];
        }
    }
    return lps;
}

ll KMP(string s,string pat)
{
    vector<ll> lps = build_lps(pat);
    bool f = false;
    ll i=0,j=0;
    ll cnt = 0;
    for(;i<s.length();)
    {
        if(s[i] == pat[j])
        {
            i++;
            j++;
            if(j==pat.length())
            {
                f = true;
                cnt++;
                j = lps[j-1];
            }
        }
        else
        {
            if(j == 0)
            {
                i++;
            }
            else
                j = lps[j-1];
        }
    }
    
    return cnt;
}

int main()
{
    string s,t;
    s = "abcdfabcdabc";
    t = "abc";
    cout<<KMP(s,t); // count of pattern in string
    return 0;
}
