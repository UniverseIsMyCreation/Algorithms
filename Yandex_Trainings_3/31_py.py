def dfs(graph, now, visited, points):
    if not now in visited:
        visited.append(now)
        points.append(now)
        for point in graph[now]:
            if not point in visited:
                now = point
                dfs(graph, now, visited, points)



n, m = list(map(lambda x: int(x), input().split()))
graph = dict()
for i in range(n):
    graph[i + 1] = []
for i in range(m):
    n1, m1 = list(map(lambda x: int(x), input().split()))
    if n1 == m1:
        continue
    graph[n1].append(m1)
    graph[m1].append(n1)
visited = []
points = []
now = 1
dfs(graph, now, visited, points)
print(len(points))
print(*sorted(points))