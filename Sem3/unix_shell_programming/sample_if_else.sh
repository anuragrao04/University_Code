#!/bin/sh

a=1
b=2

#eq stands for equal
if test $a -eq $b
then
    echo "a and b are equal"
else
    echo "a and b are not equal"
fi