def getHighestMarks(marks, names):
    m = max(marks)
    i = marks.index(m)
    mName = names[i]
    return m, mName


marks = [90, 70, 95, 60]
names = ['Raj', 'Sita', 'Ram', 'Ganga']

print(getHighestMarks(marks, names))
