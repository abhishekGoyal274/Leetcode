class Solution {
public:
    int findDuplicate(vector<int>& nums) {
int n = nums.size();
        // if(n==1) return 
        int i = 0;
       while(i<n){
           if(nums[i]<n && nums[i]!=nums[nums[i]]){
               swap(nums[i],nums[nums[i]]);
           }
            else{
                i++;
            }
        }
       
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return nums[i];
            // cout<<nums[i]<<" ";
        }
        return 0;
    }
};