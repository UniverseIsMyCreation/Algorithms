n = int(input())
graph = list()
point2dist = dict()
queue = list()
for i in range(n):
    graph.append([])
    lst = list(map(lambda x: int(x), input().split()))
    for idx, j in enumerate(lst):
        if j == 1:
            graph[i].append(idx + 1)
fst, snd = list(map(lambda x: int(x), input().split()))
if fst == snd:
    print(0)
    exit(0)
queue.append(fst)
point2dist[fst] = (0, -1)
length = 1
idx = 0
visited = set()
visited.add(fst)
while length > 0:
    cur = queue[idx]
    idx += 1
    length -= 1
    for elem in graph[cur - 1]:
        if not elem in visited:
            visited.add(elem)
            if point2dist.get(elem, (-1, -1)) == (-1, -1):
                point2dist[elem] = (point2dist[cur][0] + 1, cur)
            else:
                if point2dist[elem][0] > point2dist[cur][0] + 1:
                    point2dist[elem] = (point2dist[cur][0] + 1, cur)
            if elem == snd:
                way = list()
                print(point2dist[elem][0])
                prev = elem
                while True:
                    way.append(prev)
                    prev = point2dist[prev][1]
                    if prev == -1:
                        break
                print(*list(reversed(way)))
                exit(0)
            queue.append(elem)
            length += 1
print(-1)