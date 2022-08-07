#!/bin/bash

highest=0

small_test() {
	variables=$(gshuf -i 0-100000 -n 5)
	var=$(./push_swap $variables | ./checker $variables)
	if [ $var != OK ]; then
		echo "Failed by $var"
		echo $variables
		let "fails=fails+1"
	fi
	wc=$(./push_swap $variables | wc -l)
	if [ $wc -gt $highest ]; then
		let "highest=wc"
	fi
	let "total=total+wc"
}

for (( i=0; i<500; i++))
do
	small_test
done
let "passes=i-fails"
echo Test results of 5 integers:
let "total=total/$i"
echo Tests passed:$passes of $i tests ran.
echo Highest amount of instructions: $highest
echo Average instructions: $total

middle_test() {
	variables=$(gshuf -i 0-100000 -n 100)
	var=$(./push_swap $variables | ./checker $variables)
	if [ $var != OK ]; then
		echo "Failed by $var"
		echo $variables
		let "fails=fails+1"
	fi
	wc=$(./push_swap $variables | wc -l)
	if [ $wc -gt $highest ]; then
		let "highest=wc"
	fi
	let "total=total+wc"
}

for (( i=0; i<500; i++))
do
	middle_test
done
let "passes=i-fails"
echo Test results of 100 integers:
let "total=total/$i"
echo Tests passed:$passes of $i tests ran.
echo Highest amount of instructions: $highest
echo Average instructions: $total

high_test() {
	variables=$(gshuf -i 0-100000 -n 500)
	var=$(./push_swap $variables | ./checker $variables)
	if [ $var != OK ]; then
		echo "Failed by $var"
		echo $variables
		let "fails=fails+1"
	fi
	wc=$(./push_swap $variables | wc -l)
	if [ $wc -gt $highest ]; then
		let "highest=wc"
	fi
	let "total=total+wc"
}

for (( i=0; i<500; i++))
do
	high_test
done
let "passes=i-fails"
echo Test results of 500 integers:
let "total=total/$i"
echo Tests passed:$passes of $i tests ran.
echo Highest amount of instructions: $highest
echo Average instructions: $total