class Solution {
public:
    double getPower(double x,int n){
        if(n == 0) return 1;
        if(n == 1) return x;
        double t = getPower(x,n/2);
        return n%2 == 0 ? t*t : t*t*x;

    }
    double myPow(double x, int n) {
        double ans = getPower(x,abs(n));
        return n>=0 ? ans : 1/ans;
    }
};