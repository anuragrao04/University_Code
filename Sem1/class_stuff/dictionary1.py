d = dict()

while True:
    name = input("Enter Name: ")
    srn = input("Enter SRN: ")
    marks = int(input("Enter Marks: "))
    cont = input("Continue? (y/n) ")
    d[srn] = [name, marks]
    if cont.lower() != 'y': break 


print("\n\nPeople who have scored over 50: ")
for i in d:
    if d[i][1] >= 50: 
        print(d[i][0])

