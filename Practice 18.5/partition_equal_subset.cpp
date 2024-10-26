/*
 Author : YEASIN ARAFAT
 DATE : 
 SOURCE : https://leetcode.com/problems/partition-equal-subset-sum/
*/
class Solution {
public:
    int dp[205][20005];
    bool checkPartition(int n , vector<int> &nums , int sum)
    {
        if(n==0)
        {
            if(sum==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(dp[n][sum]!= -1)
        {
            return dp[n][sum];
        }
        if(nums[n-1]<=sum)
        {
             bool op1 = checkPartition(n-1,nums,sum-nums[n-1]);
             bool op2 = checkPartition(n-1,nums,sum);
             return dp[n][sum]= op1||op2;
        }
        else
        {
            bool op2 = checkPartition (n-1,nums,sum);
            return dp[n][sum]=op2;
        }
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int sum = 0;
        for(int child : nums){
            sum+=child;
        }
        if(sum%2 == 1) return false;
      
        return checkPartition(n-1 , nums , sum/2);
    }
};