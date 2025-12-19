/*
You are given an integer array nums, an integer k, and an integer multiplier.
You need to perform k operations on nums. In each operation:
Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.
*/


// my apporach ----   tc- O(N*K)

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k>0){
            int mini=INT_MAX;
            int ind=-1;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<mini){
                    mini=nums[i];
                    ind=i;
                }
            }
            nums[ind]=nums[ind]*multiplier;
            k--;
        }

        return nums;
    }

 // HEAP -----   tc- O(N + k*logn) 

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pair<int, int>> heap;
        for (int i = 0; i < nums.size(); i++) {
            heap.push_back({nums[i], i});
        }

        make_heap(heap.begin(), heap.end(), greater<>());

        while (k--) {
            pop_heap(heap.begin(), heap.end(), greater<>());
            auto [value, i] = heap.back();
            heap.pop_back();

            nums[i] *= multiplier;
            heap.push_back({nums[i], i});
            push_heap(heap.begin(), heap.end(), greater<>());
        }

        return nums;
    }
 