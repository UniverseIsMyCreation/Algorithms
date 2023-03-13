def dfs(graph, now, visited, colored, stack, stack_len):
    visited.add(now)
    stack.append(now)
    colored[now] = 1
    stack_len += 1
    for point in graph[now]:
        if colored[point] == 1:
            cycle_len = stack_len
            for elem in stack:
                if elem == point:
                    if cycle_len % 2 == 1:
                        print('NO')
                        exit(0)
                    else:
                        continue 
                else:
                    cycle_len -= 1
        if not point in visited:
            dfs(graph, point, visited, colored, stack, stack_len)
    stack_len -= 1
    colored[now] = 2
    stack.remove(now)


n, m = list(map(lambda x: int(x), input().split()))
graph = dict()
points = set()
colored = dict()
visited = set()
stack = list()
for i in range(n):
    graph[i + 1] = []
    points.add(i + 1)
    colored[i + 1] = 0
for i in range(m):
    n1, m1 = list(map(lambda x: int(x), input().split()))
    graph[n1].append(m1)
    graph[m1].append(n1)
else:
    stack_len = 0
    for point in points:
        dfs(graph, point, visited, colored, stack, stack_len)
    print("YES")     