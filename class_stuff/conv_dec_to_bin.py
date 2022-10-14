n = int(input())
res = ""
while n != 0:
    rem = n%2
    n = n//2
    res = str(rem) + res
print(res)