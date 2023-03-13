n = int(input())
st = set()
arr = list()
for elem in input().split():
    elem = int(elem)
    if not elem in st:
        arr.append(elem)
        st.add(elem)

arr = sorted(arr)

k = int(input())
arr_len = len(arr)
lst_knums = input().split()
for knum in lst_knums:
    knum = int(knum)
    b, e = -1, arr_len
    while (e > b + 1):
        m = (e + b) // 2
        if arr[m] >= knum:
            e = m
        else:
            b = m
    if e == arr_len:
        print(arr_len)
    elif b == -1:
        print(0)
    elif arr[e] < knum:
        print(e + 1)
    else:
        print(b + 1)