with open('test.txt', 'r') as f:
    lines = f.readlines()
    counter = 0
    searchTerm = 'python'
    for i in lines:
        counter += i.count(searchTerm)

print("Frequency: ", counter)
