class Solution {
public:
    int waviness(int val){
        int ans{0}, temp = val;
        if(val < 100) return 0;
        int right = val%10; val/=10;
        int mid = val%10; val/=10;
        int left = val%10; val/=10;
        if((mid > right && mid > left) || (mid < right && mid < left)) ans++;
        
        while(val > 0){
            right = mid; mid = left; 
            left = val%10; val/=10;
            if((mid > right && mid > left) || (mid < right && mid < left)) ans++;
        }
        cout << temp << " " << ans << endl;
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans{0};
        for(int i=num1; i<=num2; i++) ans += waviness(i);
        return ans; 
    }
}; 