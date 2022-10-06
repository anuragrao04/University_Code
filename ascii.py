
st = input("Enter String: ")
# for loop
for i in st: 
    print(i, ord(i))

print('\n\n\n')
# while loop

index = 0
while(index<len(st)):
    print(st[index], ord(st[index]))
    index += 1