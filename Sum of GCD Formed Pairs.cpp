class Solution {
public:
    long long getGcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int mxi = INT_MIN;
        vector<int>prefixGcd;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mxi = max(mxi,nums[i]);
            prefixGcd.push_back(getGcd(mxi,nums[i]));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        /*int mini = *min_element(prefixGcd.begin(),prefixGcd.end());
        int maxa = *max_element(prefixGcd.begin(),prefixGcd.end());*/
        long long sum =0;
        int i =0;
        int j =prefixGcd.size()-1;
        while(i<j){
            sum+=getGcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
        
    }
};
