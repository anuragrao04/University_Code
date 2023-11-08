#!/bin/sh

a=1
b=2

#-a is for AND operation
if test $a -eq 1 -a $b -eq 2
then
    echo "a is 1 and b is 2"
fi

a=2
#-o is for OR operation
if test $a -eq 1 -o $b -eq 2
then
    echo "a is 1 or b is 2"
fi