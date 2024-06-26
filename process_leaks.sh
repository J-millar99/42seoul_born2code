#!/bin/bash

echo "Enter the starting pid (or 'q' to quit): "
read x

if [ "$x" = "q" ]; then
    exit 0
fi

echo "Enter the ending pid: "
read y

f="$x"
while true; do
	x="$f"
    while [ "$x" -le "$y" ]; do
        leaks "$x"
        ((x++))
        sleep 0.5
    done
done