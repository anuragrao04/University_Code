authors = ['Rabindranath Tagore',
'Khushwant Singh',
'Vikram Chandra',
'Mulk Raj Anand',
'R K Narayan',
'Jhumpa Lahiri']

def mainFunction(authors):
    # a
    def sortNameLength(): print(sorted(authors, key = lambda x : len(x)))
    # b
    def sortLastName(): print(sorted(authors, key = lambda x : x.split()[-1]))

    return sortNameLength, sortLastName

snl, sln = mainFunction(authors)

snl()
sln()


