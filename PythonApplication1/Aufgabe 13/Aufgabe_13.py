
a = [61, 32, -5, 31, 20, -50, 20, 15, 68,  3, 84]


for i, j in enumerate(a):
    min = a[i]
    min_pos = i

    for k in range(i+1, 10):
        if a[k] < min:
            min = a[k]
            min_pos = k
    a[min_pos] = a[i]
    a[i] = min

print(a)