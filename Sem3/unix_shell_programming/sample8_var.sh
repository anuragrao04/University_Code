#!/bin/sh

#Creating variables
a=5
b="string1"
c='string2'
#d = 5          #error: Having spaces are illegal in assignment statement
#e= 5           #error: Having spaces are illegal in assignment statement
#f =5           #error: Having spaces are illegal in assignment statement

#Print the variables
echo $a
echo "$b"
#echo '$c'       #does not print the value of the variable c
echo "The value of c is $c"

echo    #print new line

#Assign to another variable
g=$a
echo $g

#Readonly variable
g=10
echo $g
readonly g
#g=15   #after making a variable readonly, its value cannot be changed
echo $g

