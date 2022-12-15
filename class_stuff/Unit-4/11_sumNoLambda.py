import functools
l = [1,2,3,4,5]
print(functools.reduce(int.__add__, l))

# __add__ is the built in method of the int class
# this method is invoked everytime 2 integers are 
# added normally, using the + operator
