#include <string>
#include <iostream>
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define pb push_back

#define N 1000500
typedef long long int ll;
using namespace std;
int main(void){
	int i;
	string s;
	cin>>s;
	int n=s.length();
	ll dp[n+1][2];
	memset(dp,0,sizeof dp);
	//dp[1][0]=s[0]-'0';
	//dp[1][1]=10-(s[0]-'0');
	dp[0][1]=1;
	for(i=0;i<n;i++){
		int k=s[i]-'0';
  if (k > 5) k = 10-k;
		// dp[i+1][0]=min(dp[i][0]+k,dp[i][1]+10-k);
  // cout << k << endl;
  dp[i+1][0]=min(dp[i][0]+k,dp[i][1]+k);
		// dp[i+1][1]=min(dp[i][0]+k+1,dp[i][1]+10-k-1);
  dp[i+1][1]=min(dp[i][0]+k+1,dp[i][1]+k+1);
	}
	cout<<dp[n][0]<<endl;
}
