str = input().split()
n, m = int(str[0]), int(str[1])
graph = dict()
points = set()
for i in range(n):
    graph[i + 1] = []
    points.add(i + 1)
for i in range(m):
    str = input().split()
    n1, m1 = int(str[0]), int(str[1])
    if n1 == m1:
        continue
    graph[n1].append(m1)
    graph[m1].append(n1)
visited = []
all_graphs = []
comp = 0
stack = list()
for point in points:
    if not point in visited:
        comp += 1
        one_graph = []
        now = point
        stack.append(now)
        while len(stack) > 0:
            cur_stack = stack.pop()
            if not cur_stack in visited:
                visited.append(cur_stack)
                one_graph.append(cur_stack)
                for point in graph[cur_stack]:
                    if not point in visited:
                        now = point
                        stack.append(now)
        all_graphs.append(one_graph)

print(comp)
for component in all_graphs:
    print(len(component))
    print(*sorted(component))