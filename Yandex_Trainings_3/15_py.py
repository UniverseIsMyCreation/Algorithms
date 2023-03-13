n = int(input())
nums = list(map(lambda x: int(x), input().split()))
stack = []
amount = 0
ans = []
for index, elem in enumerate(nums):
    if amount == 0:
        stack.append(elem)
        stack.append(index)
        amount += 1
        ans.append(-1)
    else:
        if elem < stack[-2]:
            while True:
                temp_index = stack[-1]
                stack.pop()
                stack.pop()
                ans[temp_index] = index
                amount -= 1
                if amount == 0:
                    break
                elif elem >= stack[-2]:
                    break
            stack.append(elem)
            stack.append(index)
            amount += 1
            ans.append(-1)
        else:
            stack.append(elem)
            stack.append(index)
            amount += 1
            ans.append(-1)

for elem in ans:
    print(elem, end = ' ')
print()