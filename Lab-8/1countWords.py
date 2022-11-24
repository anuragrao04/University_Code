
fName = input("FileName: ")
with open(f"{fName}.txt", "r") as f:
    st = f.read().split()
print(len(st))
