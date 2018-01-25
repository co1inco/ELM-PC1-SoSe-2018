
s = "Programmierkurs"

pos = s.find("i")

s = s[:pos] + "\0" + s[pos+1:]

print(s)