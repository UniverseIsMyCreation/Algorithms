queue_links = []
amount = 0
std_size = 3
head = 0
tail = 0
while True:
    command = input()
    if command == 'exit':
        print('bye')
        break
    elif command.find('push') != -1:
        number = int(command.split()[1])
        if tail % std_size == 0:
            queue_links.append([number])
        else:
            queue_links[tail // std_size].append(number)
        amount += 1
        tail += 1
        print('ok')
    elif command == 'clear':
        amount = 0
        tail = 0
        head = 0
        queue_links.clear()
        print('ok')
    elif command == 'size':
        print(amount)
    elif command == 'front':
        if amount == 0:
            print('error')
        else:
            print(queue_links[head // std_size][head % std_size])
    elif command == 'pop':
        if amount == 0:
            print('error')
        else:
            print(queue_links[head // std_size][head % std_size])
            amount -= 1
            head += 1
            if head % std_size == 0:
                head -= std_size
                tail -= std_size
                queue_links.pop(0)

