#!/bin/sh

answer="y"

while test $answer == "y"
do
    echo "inside loop"
    echo "Do you want to continue [y|n]: "
    read answer
done