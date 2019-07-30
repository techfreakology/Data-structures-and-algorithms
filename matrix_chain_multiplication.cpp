#include <iostream>
using namespace std;

int main()
{
	int n,i,j,k;
	cin>>n;
	int p[n+1];
	for(i=0;i<=n;i++)
	{
		cin>>p[i];
	}

	ll c[n+1][n+1],b[n+1][n+1];

	for(i=1;i<=n;i++)
	{
		c[i][i] = 0;
	}

	for(i=1;i<n;i++)
	{
		for(j=1;j+i<=n;j++)
		{
			c[j][j+i] = LONG_MAX, b[j][j+i] = j;
			for(k=j;k<j+i;k++)
			{
				if(c[j][j+i] < c[j][k]+c[k+1][j+i]+p[j-1]*p[k]*p[j+i])
				{
					c[j][j+i] = c[j][k]+c[k+1][j+i]+p[j-1]*p[k]*p[j+i];
				}
			}
		}
	}

	

	return 0;
}