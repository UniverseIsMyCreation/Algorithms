n = int(input())
customers = list()
for i in range(n):
    customers.append(list(map(lambda x: int(x), input().split())))
dp = list()
dp.append(customers[0][0])
if n >= 2:
    dp.append(min(customers[1][0] + dp[0], customers[0][1]))
if n >= 3:
    dp.append(min(customers[2][0] + dp[1], dp[0] + customers[1][1], customers[0][2]))
for i in range(3, n):
    dp.append(min(customers[i][0] + dp[i-1], dp[i-2] + customers[i-1][1], customers[i-2][2] + dp[i-3]))
if n == 1:
    print(dp[0])
elif n == 2:
    print(dp[1])
elif n == 3:
    print(dp[2])
else:
    print(dp[-1])