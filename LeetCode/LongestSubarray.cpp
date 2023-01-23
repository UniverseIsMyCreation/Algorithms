int longestSubarray(vector<int>& nums) {
        int64_t sum_part = 0;
        int64_t saved_sum_part = 0;
        bool found_first_zero = false;
        int64_t answer = -1;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 0){
                if (found_first_zero){
                    if (saved_sum_part + sum_part > answer){
                        answer = saved_sum_part + sum_part;
                    }
                }
                saved_sum_part = sum_part;
                sum_part = 0;
                found_first_zero = true;
            }
            else{
                sum_part++;
            }
        }
        if (!found_first_zero){
            return nums.size()-1;
        }
        else{
            if (saved_sum_part + sum_part > answer){
                answer = saved_sum_part + sum_part;
            }
            return answer;
        }
    }

https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
