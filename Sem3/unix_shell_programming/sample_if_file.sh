#!/bin/sh

#-f checks if the file is a regular file
if test -f $1
then
    echo "$1 is a regular file"
fi