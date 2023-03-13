n = int(input())
nums = list(map(lambda x: int(x), input().split()))
stack = []
max_forward = -1
amount = 0
for elem in nums:
    if max_forward == -1:
        if elem == 1:
            max_forward = 1
            if amount > 0:
                while amount > 0 and stack[-1] == max_forward + 1:
                    max_forward += 1
                    stack.pop()
                    amount -= 1
        else:
            stack.append(elem)
            amount += 1
    else:
        if elem == max_forward + 1:
            max_forward += 1
            if amount > 0:
                while amount > 0 and stack[-1] == max_forward + 1:
                    max_forward += 1
                    stack.pop()
                    amount -= 1
        else:
            stack.append(elem)
            amount += 1

if amount > 0:
    while (amount > 0):
        if stack[-1] == max_forward + 1:
            max_forward += 1
            stack.pop()
            amount -= 1
            if amount == 0:
                print('YES')
        else:
            print('NO')
            break
else:
    print('YES')