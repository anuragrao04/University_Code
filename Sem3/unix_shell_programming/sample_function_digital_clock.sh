#!/bin/sh

function_clock() {
    clear
    while test 1
    do
        date "+%T"
        sleep 1
        clear
    done
}

function_clock