n = int(input())
m = int(input())
station2lines = list()
points = dict()
line2stations = list()
for i in range(n):
    station2lines.append([])
    points[i] = (-1, -1)
for i in range(m):
    line = list(map(lambda x: int(x), input().split()))[1:]
    line2stations.append(line)
    for elem in line:
        station2lines[elem - 1].append(i)
fst, snd = list(map(lambda x: int(x), input().split()))
fst, snd = fst-1, snd-1
index = 0
length = 1
queue = list()
queue.append(fst)
points[fst] = (0, -1)
while length > 0:
    cur_st = queue[index]
    index += 1
    length -= 1
    cur_dist, cur_line = points[cur_st]
    for line in station2lines[cur_st]:
        for station in line2stations[line]:
            if points[station - 1][0] == -1:
                if cur_line != -1 and line != cur_line:
                    points[station - 1] = (cur_dist + 1, line)
                else:
                    points[station - 1] = (cur_dist, line)
                length += 1
                queue.append(station - 1)
print(points[snd][0])