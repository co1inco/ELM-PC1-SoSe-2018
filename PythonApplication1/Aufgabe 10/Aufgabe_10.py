
array = [10, 5 , 3, 48 , 12]
min = array[0]
max = array[0]
sum = 0

for i in array:
    if i < min:
        min = i
    if i > max:
        max = i
    sum = sum + i

print(min)
print(max)
print(sum)