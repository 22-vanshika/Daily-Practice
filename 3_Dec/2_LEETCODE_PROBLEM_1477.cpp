class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> left(n,INT_MAX);

        int sum=0;
        int leftMin=INT_MAX;
        int start=0;
        for(int end=0;end<n;end++){
            sum+=arr[end];
            while(sum>target) sum-=arr[start++];
            if(sum==target) leftMin=min(leftMin,end-start+1);
            left[end]=leftMin; 
        }

        sum=0;
        int rightMin=INT_MAX;
        start=n-1;
        int result=INT_MAX;
        for(int end=n-1;end>=0;end--){
            sum+=arr[end];
            while(sum>target) sum-=arr[start--];
            if(sum==target){
                rightMin=min(rightMin,start-end+1);
                if(end && left[end-1]<INT_MAX) 
                    result = min(result,rightMin + left[end-1]);
            }
        }

        if(result==INT_MAX) return -1;
        return result;
    }
};


// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
// You are given an array of integers arr and an integer target.

// You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.

// Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.

