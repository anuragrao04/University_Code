#!/bin/sh

echo "Type 1 to list the current directory, Type 2 for process list, Type 3 for date"
read var

case $var in
1)
    ls
    ;;
2)
    ps -ef
    ;;
3)
    date
    ;;
*)
    echo "Invalid command"
esac