#!/bin/sh

if test "string1" = "string1"
then
    echo "Test3: a and b are equal"
fi

a="string1"
b="string1"

if test $a = $b
then
    echo "Test1: a and b are equal"
fi

if test "$a" = "$b"
then
    echo "Test2: a and b are equal"
fi