
def getAvg(func):
    def inner(marksList):
        print("average:", sum(marksList)/len(marksList))
        func(marksList)
    return inner

marksList = eval(input("Enter marks in the form of list: "))

@getAvg
def giveMarks(marksList):
    print("done")

    

giveMarks(marksList)
