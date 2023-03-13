n = int(input())
coords = list(map(lambda x: int(x), input().split()))
coords = sorted(coords)
dp = list()
dp.append(coords[1] - coords[0])
if n >= 2:
    pass
if n >= 3:
    dp.append(dp[0] + coords[2] - coords[1])
if n >= 4:
    dp.append(dp[0] + coords[3] - coords[2])
if n >= 5:
    for i in range(4, n):
        dp.append(min(dp[i-2] + (coords[i] - coords[i-1]), dp[i-3] + (coords[i] - coords[i-1])))
print(dp[-1])