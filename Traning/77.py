from math import *
t = int(input())

for _ in range(t):
    arr = list(map(int, input().split()))
    n = arr[0] + 1
    arr.pop(0)
    d = int(input())
    k = int(input())

    a = [0] * 21
    for i in range(1, 21):
        sum = 0
        for j in range(n):
            sum += pow(i, j) * arr[j]
        a[i - 1] = sum

    idx = 0
    sum = 0
    for i in range(d, 1000001 + d, d):
        sum += i
        if (sum >= k):
            print(int(a[idx]))
            break
        idx += 1