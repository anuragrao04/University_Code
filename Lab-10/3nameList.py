authors = ['Rabindranath Tagore',
'Khushwant Singh',
'Vikram Chandra',
'Mulk Raj Anand',
'R K Narayan',
'Jhumpa Lahiri']


def sortNameLength(): print(sorted(authors, key = lambda x : len(x)))
def sortLastName(): print(sorted(authors, key = lambda x : x.split()[-1]))

def mainFunction(authors, func1, func2):
    # a
    func1()
    #b
    func2()
    

mainFunction(authors, sortNameLength, sortLastName)






