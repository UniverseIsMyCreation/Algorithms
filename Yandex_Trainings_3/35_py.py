n = int(input())
graph = dict()
points = set()
colored = dict()
stack = list()
visited = set()
for i in range(n):
    graph[i + 1] = set()
    points.add(i + 1)
    colored[i + 1] = 0
for i in range(n):
    lst = list(map(lambda x: int(x), input().split()))
    for idx, j in enumerate(lst):
        if j == 1:
            graph[i + 1].add(idx + 1)
            graph[idx + 1].add(i + 1)
for point in points:
    if not point in visited:
        stack.append(point)
        stack_len = 1
        while stack_len > 0:
            break_cycle = False
            cur_stack = stack.pop()
            stack.append(cur_stack)
            visited.add(cur_stack)
            colored[cur_stack] = 1
            for point in graph[cur_stack]:
                if colored[point] == 1:
                    for idx, elem in enumerate(stack):
                        if elem == point:
                            rec = stack[idx:]
                            length = len(rec)
                            if length <= 2:
                                break
                            print('YES')
                            print(length)
                            print(*rec)
                            exit(0)
                if not point in visited:
                    stack.append(point)
                    stack_len += 1
                    break_cycle = True
                    break
            if not break_cycle:
                colored[cur_stack] = 2
                stack.pop()
                stack_len -= 1
print('NO')