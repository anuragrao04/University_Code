class Matrix:
    def __init__(self, dimensions):
        self.dimensions = dimensions
        self.i, self.j = self.dimensions
        self.matrix = [
            [0 for x in range(self.j)] for y in range(self.i)
        ]

    def display(self):
        print(self.matrix)

    def populate(self, populatedMatrix):
        self.matrix = populatedMatrix


    def add(self, a):
        mat1 = self.matrix
        mat2 = a.matrix
        resultant = []
        resultant = [
            [val1 + val2 for val1, val2 in zip(row1, row2)] 
            for row1, row2 in zip(mat1, mat2)
        ]
        return resultant


matrix1 = Matrix([2,2])
matrix2 = Matrix([2,2])

matrix1.populate([[1,2], [3,4]])
matrix2.populate([[5,6], [7,8]])

matrix1.display()
matrix2.display()

print(matrix1.add(matrix2))

