#!/bin/bash

var=$(./push_swap 1 2 3 4 5 | ./checker 1 2 3 4 5)

echo 'lolleroo'

echo $var
if [ "$var" == "OK" ]; then
echo "TEST PASSED."
fi

entries=($(gshuf -i 0-149 -n 15))
echo "$entries"
echo "${entries[@]}"
