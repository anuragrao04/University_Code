import time

with open('test.txt', 'r') as f:
    line = f.readline()
    while(line):
        print(line)
        line = f.readline()


