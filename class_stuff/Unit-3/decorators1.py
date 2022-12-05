def getMarks():
    marksList = eval(input("Enter marks in the form of list: "))
    avg = getAvg(marksList)
    print(avg)



def getAvg(marksList):
    return sum(marksList)/len(marksList)


getMarks()
