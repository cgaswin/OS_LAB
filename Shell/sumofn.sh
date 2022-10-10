#!/bin/bash

i=1
sum=0
read -p "enter the limit : " limit

while [ $i -le $limit ] 
do
	read j
	sum=`expr $j + $sum`
	i=`expr $i + 1 `
done
echo "The sum of numbers is : $sum"
