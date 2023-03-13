stack = []
amount = 0
while True:
    str = input()
    if str.find('push') != -1:
        number = int(str.split()[1])
        stack.append(number)
        amount += 1
        print('ok')
    elif str == 'pop':
        if amount == 0:
            print('error')
        else:
            amount -= 1
            print(stack[-1])
            stack.pop()
    elif str == 'clear':
        amount = 0
        stack.clear()
        print('ok')
    elif str == 'size':
        print(amount)
    elif str == 'exit':
        print('bye')
        break
    elif str == 'back':
        if amount == 0:
            print('error')
        else:
            print(stack[-1])
