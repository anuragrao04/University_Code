#!/bin/sh

function_arguments() {
    echo "All the arguments are $@"
    echo "All the arguments are $*"
    echo "First value is $1"
    echo "Second value is $2"
    echo "Third value is $3"
}

function_arguments 1 2 3