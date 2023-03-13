n = int(input())
dp = list()
dp.append(2)
dp.append(4)
dp.append(7)
for i in range(3, n):
    dp.append(dp[i - 1] + dp[i - 2] + dp[i - 3])
if n == 1:
    print(dp[0])
elif n == 2:
    print(dp[1])
elif n == 3:
    print(dp[2])
else:    
    print(dp[-1])