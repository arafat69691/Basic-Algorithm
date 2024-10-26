/*
 Author : YEASIN ARAFAT
 DATE : 
 SOURCE : https://www.naukri.com/code360/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
    int dp[k+1];
    memset(dp,0,sizeof(dp);
    dp[0]=1;
    for(int i = 0 ; i<=n ; i++)
    {
        for(int j = k ; j<arr[i] ; j--)
        {
            dp[j] = (dp[j] + dp[j-arr[i]]) %MOD;
        }
    }
    return dp[k];
}
