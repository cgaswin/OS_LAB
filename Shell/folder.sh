#!/bin/bash

read -p "Enter Folder Name : " DIR

echo -n "Enter File Prefix : "
read File

mkdir $DIR

read -p "enter no of files : " num

for((i=1;i<=$num;i++))
do
	touch "$DIR/$File$i"
done

