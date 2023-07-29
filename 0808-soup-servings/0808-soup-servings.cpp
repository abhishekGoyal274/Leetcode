class Solution {
public:
    double helper(int typeA,int typeB, int n,vector<vector<double>> &dp){
        if(typeA<=0 || typeB<=0){
            if(typeA<=0 && typeB<=0) return pow(0.25,n)/2;
            else if(typeA<=0) return pow(0.25,n);
            else return 0;
        }
        
        if(dp[typeA][typeB] != -1) return dp[typeA][typeB];
        
        double a = helper(typeA-100,typeB,n+1,dp);
        double b = helper(typeA-75,typeB-25,n+1,dp);
        double c = helper(typeA-50,typeB-50,n+1,dp);
        double d = helper(typeA-25,typeB-75,n+1,dp);    
        dp[typeA][typeB] = a+b+c+d;
        
        return dp[typeA][typeB];
    }
    double soupServings(int n) {
        if(n > 4800) return 1;
        vector<vector<double>> dp(n+1, vector<double>(n+1,-1));
        return helper(n,n,0,dp);
    }
};
