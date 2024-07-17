from math import floor
from sortedcontainers import SortedList  

def pre(s1, s2):  
    l, r = s1[0], s2[-1] 
    s1 = s1[1:-1]
    s2 = s2[:-1] 
    L = float('-inf') if s1 == "-inf" else float(s1)  
    R = float('inf') if s2 == "inf" else float(s2)  

    if l == '(' and L != float('-inf'):  
        L += 0.5  
    if r == ')' and R != float('inf'):  
        R -= 0.5  

    return (L, R)  

def main():  
    n = int(input())  
    idset = SortedList()  

    for _ in range(n):  
        s1, s2 = map(str, input().split())  

        it_curr = pre(s1, s2)  
        order = idset.bisect_left(it_curr)  
        size = len(idset)  

        if size < 1:  
            idset.add(it_curr)  
            continue  

        it_next = idset[order] if order < size else None  
        it_prev = idset[order - 1] if order > 0 else None  

        if order == 0:  
            cnt = 0  
            while cnt < size and (it_next[0] <= it_curr[1] or it_next[0] - it_curr[1] == 0.5):  
                cnt += 1  
                it_next = idset[order + cnt] if order + cnt < size else None  

            if cnt == 0:  
                idset.add(it_curr)  
            while cnt > 0:  
                idset.discard(idset[order])  
                cnt -= 1  
            idset.add((it_curr[0], max(it_curr[1], it_next[1] if it_next is not None else float('inf'))))  

        elif order == size:  
            diff = it_curr[0] - it_prev[1]  
            if it_prev[1] >= it_curr[0] or (0 < diff < 1):  
                tmp = it_prev  
                idset.discard(it_prev)  
                idset.add((tmp[0], max(it_curr[1], tmp[1])))  
            else:  
                idset.add(it_curr)  

        else:  
            if it_prev[1] >= it_curr[0] or it_curr[0] - it_prev[1] == 0.5:  
                tmp = it_prev  
                idset.discard(it_prev)  
                idset.add((tmp[0], max(it_curr[1], tmp[1])))  

            cnt = 0  
            while cnt < size and (it_next[0] <= it_curr[1] or it_next[0] - it_curr[1] == 0.5):  
                cnt += 1  
                it_next = idset[order + cnt] if order + cnt < size else None  

            if cnt == 0:  
                idset.add(it_curr)  
            while cnt > 0:  
                idset.discard(idset[order])  
                cnt -= 1  
            idset.add((it_curr[0], max(it_curr[1], it_next[1] if it_next is not None else float('inf'))))  

    print(idset)
    ctr = 0  
    for a, b in idset:  
        if a == float('-inf'):  
            print("(-inf", end='')  
        else:  
            print("(" if int(a) == int(floor(a - 0.5)) else "[", end='')  
            print(int(a) if int(a) != int(floor(a - 0.5)) else int(floor(a - 0.5)), end='')  

        print(", ", end='')  

        if b == float('inf'):  
            print("inf)", end='')  
        else:  
            print(int(floor(b + 0.5)) if int(b) != int(floor(b + 0.5)) else int(b), end='')  
            print("]" if int(b) == int(floor(b + 0.5)) else ")", end='')  

        print(" ", end='')  

        ctr += 1  
        if ctr < len(idset):  
            print("U ", end='')  

    print()  

if __name__ == "__main__":  
    main()