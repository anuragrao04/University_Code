c = [1,2,3,4]

for i in c:
    print("one")

for i in [c]:
    print("two")

for i in (c):
    print("three")

for i in (c, ):
    print("four")