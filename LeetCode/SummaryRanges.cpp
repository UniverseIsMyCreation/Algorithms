vector<string> summaryRanges(vector<int>& nums){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> answer;
    int64_t len = nums.size();
    if(len == 0)
        return answer;
    int64_t begin = nums[0];
    int64_t middle = begin;
    for(int i = 1; i<len; ++i){
        if (nums[i] != middle+1){
            if (middle != begin)
                answer.push_back(to_string(begin)+"->"+to_string(middle));
            else
                answer.push_back(to_string(begin));
            begin = nums[i];
            middle = begin;
        }
        else
            middle = nums[i];
    }
    if (middle != begin)
        answer.push_back(to_string(begin)+"->"+to_string(middle));
    else
        answer.push_back(to_string(begin));
    return answer;
}
