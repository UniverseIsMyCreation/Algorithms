n = int(input())
dct = dict()
train = list()
train_length = 0
index = 0
for i in range(n):
    str = input().split()
    if str[0] == 'add':
        number = int(str[1])
        if number == 0:
            continue
        what = str[2]
        train_length += number
        train.append(number)
        train.append(what)
        index += 2
        if dct.get(what, -1) == -1:
            dct[what] = number
        else:
            dct[what] += number
    elif str[0] == 'get':
        if dct.get(str[1], -1) == -1:
            print(0)
        else:
            print(dct[str[1]])
    elif str[0] == 'delete':
        number = int(str[1])
        if number >= train_length:
            train_length = 0
            train.clear()
            index = 0
            dct = dict()
        else:
            del_sum = 0
            while True and number > 0:
                del_sum += train[index - 2]
                what = train[index - 1]
                if del_sum > number:
                    dct[what] -= (number - del_sum + train[index - 2])
                    train_length -= (number - del_sum + train[index - 2])
                    train[index - 2] -= (number - del_sum + train[index - 2])
                    break
                dct[what] -= train[index - 2]
                train_length -= train[index - 2]
                index -= 2
                train.pop()
                train.pop()