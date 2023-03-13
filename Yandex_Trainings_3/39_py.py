n = int(input())
points = dict()
str = input()
cave = list()
for i in range(n):
    lst = list()
    for j in range(n):
        str = input()
        for idx, pos in enumerate(str):
            if pos == 'S':
                fst = (i, j, idx)
                points[fst] = 0
            else:
                points[(i, j, idx)] = -1
        lst.append(str)
    cave.append(lst)
    if i == n - 1:
        break
    str = input()
queue = list()
queue.append(fst)
length = 1
index = 0
while length > 0:
    cur_pos = queue[index]
    block, x, y = cur_pos
    index += 1
    length -= 1
    if block == 0:
        print(points[(block, x, y)])
        exit(0)
    if block - 1 >= 0 and cave[block - 1][x][y] == '.':
        if points[(block - 1, x, y)] == -1:
            queue.append((block - 1, x, y))
            length += 1
            points[(block - 1, x, y)] = points[(block, x, y)] + 1
    if block + 1 < n and cave[block + 1][x][y] == '.':
        if points[(block + 1, x, y)] == -1:
            queue.append((block + 1, x, y))
            length += 1
            points[(block + 1, x, y)] = points[(block, x, y)] + 1
    if x - 1 >= 0 and cave[block][x - 1][y] == '.':
        if points[(block, x - 1, y)] == -1:
            queue.append((block, x - 1, y))
            length += 1
            points[(block, x - 1, y)] = points[(block, x, y)] + 1
    if x + 1 < n and cave[block][x + 1][y] == '.':
        if points[(block, x + 1, y)] == -1:
            queue.append((block, x + 1, y))
            length += 1
            points[(block, x + 1, y)] = points[(block, x, y)] + 1
    if y - 1 >= 0 and cave[block][x][y - 1] == '.':
        if points[(block, x, y - 1)] == -1:
            queue.append((block, x, y - 1))
            length += 1
            points[(block, x, y - 1)] = points[(block, x, y)] + 1
    if y + 1 < n and cave[block][x][y + 1] == '.':
        if points[(block, x, y + 1)] == -1:
            queue.append((block, x, y + 1))
            length += 1
            points[(block, x, y + 1)] = points[(block, x, y)] + 1
