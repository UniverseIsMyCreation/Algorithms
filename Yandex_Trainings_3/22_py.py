n, k = list(map(lambda x: int(x), input().split()))
dp = list()
dp.append(1)
for index in range(1, n - 1):
    if index < k:
        index_rev = index - 1
        res_sum_jump = 1
        while index_rev >= 0:
            res_sum_jump += dp[index_rev]
            index_rev -= 1
    else:
        index_rev = index - 1
        res_sum_jump = 0
        steps = 0
        while steps < k:
            res_sum_jump += dp[index_rev]
            index_rev -= 1
            steps += 1
    dp.append(res_sum_jump)
print(dp[-1])