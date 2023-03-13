from collections import deque

cards1 = list(map(lambda x: int(x), input().split()))
cards2 = list(map(lambda x: int(x), input().split()))
dq1 = deque()
dq2 = deque()
len1 = len(cards1)
len2 = len(cards2)
turns = 0
max_turns = 10 ** 6

for i in range(len1):
    dq1.append(cards1[i])
    dq2.append(cards2[i])

while True:
    turns += 1
    elem1 = dq1.popleft()
    elem2 = dq2.popleft()
    if (0 in [elem1, elem2] and 9 in [elem1, elem2]):
        if elem1 == 0:
            dq1.append(elem1)
            dq1.append(elem2)
            len1 += 1
            len2 -= 1
        else:
            dq2.append(elem1)
            dq2.append(elem2)
            len2 += 1
            len1 -= 1
    elif elem1 > elem2:
        dq1.append(elem1)
        dq1.append(elem2)
        len1 += 1
        len2 -= 1
    else:
        dq2.append(elem1)
        dq2.append(elem2)
        len2 += 1
        len1 -= 1
    if len1 == 0:
        print('second', turns, sep = ' ')
        break
    elif len2 == 0:
        print('first', turns, sep = ' ')
        break
    elif turns > max_turns:
        print('botva')
        break