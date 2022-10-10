#!/bin/sh

echo "Enter number: "
read n

for(( i=2; i<n; i++ ))
do
    ans=$(( n%i ));
    if [ $ans == 0 ]
    then
        echo "$n is not prime."
        exit 0
    fi
done

echo "$n is prime."