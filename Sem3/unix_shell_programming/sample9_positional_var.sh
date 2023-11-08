#!/bin/sh

#Positional Variables

#Run the program as 
#bash sample_positional_var.sh 1 2 3

echo "The argument \$0 is $0"

echo "The first argument is $1"

echo "The second argument is $2"

echo "The third argument is $3"

echo "The fourth argument is $4"	#nothing is printing for the fourth argument

echo "The number of arguments is $#"

echo "The complete list of arguments is $*"

echo "The complete list of arguments is $@" 