#!/bin/sh

a=15
b=5

#Operators: +,-,/,%
c=`expr $a + $b`
echo "c: $c"

#Operators: *
c=`expr $a \* $b`
echo "c: $c"
