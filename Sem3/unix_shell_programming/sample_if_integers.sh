#!/bin/sh

a=1
b=2

#eq stands for equal
if test $a -eq $b
then
    echo "a and b are equal"
fi

#ne stands for not-equal
if test $a -ne $b
then
    echo "a and b are not equal"
fi

#lt stands for less than
if test $a -lt $b
then
    echo "a is less than b"
fi

#gt stands for great than
if test $a -gt $b
then
    echo "a is greater than b"
fi

#le stands for less than or equal to 
if test $a -le $b
then
    echo "a is less than or equal to b"
fi

#gt stands for great than or equal to 
if test $a -ge $b
then
    echo "a is greater than or equal to b"
fi