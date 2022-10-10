#!/bin/bash

echo -n 'enter number of fib number to find : '
read num


A=0
B=1
Next=0
echo -n "$A"

for  ((i=1; i<$num; i++))
do
	echo -n " $B "
	Next=`expr $A + $B`
	A=$B
	B=$Next
done

	
echo
