#!/bin/sh

function_scope() {
    x=4
    echo "Inside the function (x): $x"
}

x=5
echo "Outside the function (x): $x"
function_scope
echo "Outside the function - after calling function_scope (x): $x"