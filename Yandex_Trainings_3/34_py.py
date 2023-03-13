n, m = list(map(lambda x: int(x), input().split()))
graph = dict()
points = set()
colored = dict()
stack = list()
for i in range(n):
    graph[i + 1] = []
    colored[i + 1] = 0
    points.add(i + 1)
for i in range(m):
    n1, m1 = list(map(lambda x: int(x), input().split()))
    graph[n1].append(m1)
visited = set()
topological_sort = []
for point in points:
    if not point in visited:
        stack.append(point)
        stack_len = 1
        while stack_len > 0:
            break_cycle = False
            cur_stack = stack.pop()
            colored[cur_stack] = 1
            stack.append(cur_stack)
            for point in graph[cur_stack]:
                if colored[point] == 1:
                    print(-1)
                    exit(0)
                if not point in visited:
                    stack.append(point)
                    stack_len += 1
                    break_cycle = True
                    break
            if not break_cycle:
                topological_sort.append(cur_stack)
                stack.pop()
                stack_len -= 1
                colored[cur_stack] = 2
                visited.add(cur_stack)
                
print(*reversed(topological_sort))