str = input()
lst = str.split()
stack = []
for elem in lst:
    if elem.isdigit():
        stack.append(int(elem))
    elif elem == '+':
        num1 = stack[-1]
        stack.pop()
        num2 = stack[-1]
        stack.pop()
        stack.append(num1 + num2)
    elif elem == '*':
        num1 = stack[-1]
        stack.pop()
        num2 = stack[-1]
        stack.pop()
        stack.append(num1 * num2)
    elif elem == '-':
        num1 = stack[-1]
        stack.pop()
        num2 = stack[-1]
        stack.pop()
        stack.append(num2 - num1)

print(stack[-1])
