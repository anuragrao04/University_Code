n = int(input())

sum = 0

# + pattern
for i in range(1, n+1):
    if i != n: print(i, end = ' + ')
    else: print(i, end = ' ')
    sum += i
print('=', sum)

# * pattern
sum = 1
for i in range(1, n+1):
    if i != n: print(i, end = ' x ')
    else: print(i, end = ' ')
    sum *= i
print('=', sum)