mat1 = eval(input("Enter matrix1 in nested list format: "))
mat2 = eval(input("Enter matrix2 in nested list format: "))

for i in range(len(mat1)):
    for j in range(len(mat1[i])):
        mat1[i][j] += mat2[i][j]

# Printing the matrix
for i in mat1: print(i)
