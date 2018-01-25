zahl = 0

while True:
    d = int(input("Zahl: "))

    if not d == -1:
        zahl = zahl + d
    else:
        break

print(zahl)

