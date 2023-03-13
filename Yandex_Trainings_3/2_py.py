k = int(input())
str = input()
left, right = 0, 0
pairs = dict()
sum_changes = 0
pairs[str[left]] = 1
max_result = -1
cur_length = 1
input_length = len(str)
max_num_of_char = 1
max_char = str[left]
flag = True

while left < input_length - 1 and right < input_length - 1:
    # print(left, right, sum_changes, max_char, max_num_of_char)
    if sum_changes <= k and right < input_length - 1 and flag:
        right += 1
        cur_length += 1
        if pairs.get(str[right], -1) == -1:
            if sum_changes == k:
                right -= 1
                cur_length -= 1
                flag = False
                continue
            pairs[str[right]] = 1
            sum_changes += 1
        else:
            pairs[str[right]] += 1
            if str[right] != max_char:
                if pairs[str[right]] > max_num_of_char:
                    max_char = str[right]
                    max_num_of_char = pairs[max_char]
                else:
                    if sum_changes == k:
                        flag = False
                        pairs[str[right]] -= 1
                        cur_length -= 1
                        right -= 1
                        continue
                    sum_changes += 1
            else:
                max_num_of_char += 1
    else:
        flag = True
        if max_result == -1:
            max_result = cur_length
        elif cur_length > max_result:
            max_result = cur_length
        pairs[str[left]] -= 1
        if str[left] != max_char:
            sum_changes -= 1
        else:
            max_num_of_char -= 1
            for m, v in pairs.items():
                if v > max_num_of_char:
                    sum_changes -= 1
                    max_char = m
                    max_num_of_char = v
                    break
        cur_length -= 1
        left += 1

print(max_result)