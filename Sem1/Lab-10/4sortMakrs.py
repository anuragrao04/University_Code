s=[("890", "ram", (95,78,99)),
("123", "kishan", (90,98,89)),
("567", "arjun", (59,68,100)),
]
def sortName():
    print(sorted(s, key = lambda x : x[1]))
    

def sortPCMDesc():
    print(sorted(s, key = lambda x : sum(x[2]), reverse = True))


def mainFunction(s, func1, func2):
    func1()
    func2()


mainFunction(s, sortName, sortPCMDesc)


