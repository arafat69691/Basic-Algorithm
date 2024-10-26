/*
 Author : YEASIN ARAFAT
 DATE : 
 SOURCE : https://leetcode.com/problems/target-sum/
*/

class Solution {
public:
    int dp[1005][1005];
    int findTarget(int n , vector<int>& nums, int sum)
    {
        if(n==0)
        {
            if(sum==0) return 1;
            else return 0;
        }
        if(dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        if(nums[n-1] <= sum)
        {
            int op1 = findTarget(n-1,nums,sum-nums[n-1]);
            int op2 = findTarget(n-1,nums, sum);
           return dp[n][sum]= op1 +op2;
        }
        else
        {
            int op2 = findTarget(n-1,nums,sum);
           return dp[n][sum] = op2;
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int sum = 0; 
        for(int child : nums)
        {
            sum+=child;
        }
        memset(dp,-1,sizeof(dp));

        int s1 = (target+sum) /2;
        if(s1<0) return 0;
        if(target>sum || (target+sum)%2==1) return 0;
        return findTarget(n,nums,s1);
    }
};