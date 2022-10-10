#!/bin/bash

i=2
read -p "enter the number : " num

if [ $num -le 1 ]; then
echo "The number is not prime nor composite"
else
flag=0
while [ $i -le `expr $num / 2` ]
do 
	if [ $(expr $num % $i) -eq 0 ]; then
	flag=1
	break
	fi
	i=`expr $i + 1`
done
if [ $flag -eq 1 ]; then
echo "The number is composite"
else
echo "The number is prime"
fi
fi
