time1 = list(map(lambda x: int(x), input().split(':')))
time2 = list(map(lambda x: int(x), input().split(':')))
time3 = list(map(lambda x: int(x), input().split(':')))

seconds1 = time1[2] + time1[1] * 60 + time1[0] * 3600
seconds2 = time2[2] + time2[1] * 60 + time2[0] * 3600
seconds3 = time3[2] + time3[1] * 60 + time3[0] * 3600

if seconds3 > seconds1:
    diff_seconds = seconds3 - seconds1
else:
    diff_seconds = 24 * 60 * 60 - abs(seconds3 - seconds1)
diff_seconds = diff_seconds // 2 + 1 if diff_seconds % 2 == 1 else diff_seconds // 2

time2[2] += diff_seconds
time2_leave = time2[2] // 60
time2[2] = time2[2] % 60

time2[1] += time2_leave
time2_leave = time2[1] // 60
time2[1] = time2[1] % 60

time2[0] += time2_leave
if time2[0] >= 24:
    time2[0] = time2[0] % 24

if time2[0] < 10:
    print('0', time2[0], end = ':', sep = '')
else:
    print(time2[0], end = ':')

if time2[1] < 10:
    print('0', time2[1], end = ':', sep = '')
else:
    print(time2[1], end = ':')

if time2[2] < 10:
    print('0', time2[2], sep = '')
else:
    print(time2[2])