#!/bin/bash

echo 'Menu:'
echo '1.Addition'
echo '2.Subtraction'
echo '3.Division'
echo '4.Multiplication'
echo '5.Modulus'

echo -n 'enter a choice : '
read C

echo -n 'Enter first number : '
read A

echo -n 'Enter Second number : '
read B



case $C in 
    1) echo $((A + B));;
    2) echo `expr $A - $B`;;
    3) echo `expr $A /  $B`;;
    4) echo `expr $A \* $B`;;
    5) echo `expr $A % $B`;;
    *)echo 'invalid case';;
esac 

