
def doArray(numbers):
    min = numbers[0]
    max = numbers[0]
    sum = 0
    for i in numbers:
        if i < min:
            min = i
        if i > max:
            max = i
        sum = sum + i
    return min, max, sum

def do2dArray(numbers):
    min = numbers[0][0]
    max = numbers[0][0]
    sum = 0

    for i in numbers:
        tmpMin, tmpMax, tmpSum = doArray(i)

        if tmpMin < min:
            min = tmpMin
        if tmpMax > max:
            max = tmpMax
        sum = sum + tmpSum

    return min, max, sum

numbers  = [[ 5, 16, 34, 97],
            [34, 26,  3, 70],
            [12, -8,  6, 40]]

print(do2dArray(numbers))
