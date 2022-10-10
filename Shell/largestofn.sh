#!/bin/bash

i=0
max=0
read -p "Enter limit : " limit
while [ $i -lt $limit ]
do
	read  j
	if [ $j -gt $max ]; then
	max=$j
	fi
	i=`expr $i + 1`
	
done 
echo "largest number is : $max"
