str = input()
pointer = 0
length = len(str)
stack = []
good_seq = True
amount = 0
while pointer < length:
    symbol = str[pointer]
    if symbol == '(':
        stack.append(symbol)
        amount += 1
    elif symbol == '[':
        stack.append(symbol)
        amount += 1
    elif symbol == '{':
        stack.append(symbol)
        amount += 1
    elif symbol == ')':
        if amount == 0:
            good_seq = False
            break
        elif stack[-1] == '(':
            stack.pop()
            amount -= 1
        else:
            good_seq = False
            break
    elif symbol == ']':
        if amount == 0:
            good_seq = False
            break
        elif stack[-1] == '[':
            stack.pop()
            amount -= 1
        else:
            good_seq = False
            break
    elif symbol == '}':
        if amount == 0:
            good_seq = False
            break
        elif stack[-1] == '{':
            stack.pop()
            amount -= 1
        else:
            good_seq = False
            break
    pointer += 1

if amount != 0:
    good_seq = False

if good_seq:
    print('yes')
else:
    print('no')