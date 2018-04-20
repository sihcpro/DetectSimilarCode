#!/bin/sh

sources="Example"
preProcess="PreProcess"
preCompile="PreCompile"
result="Result"

echo "You had give $#/4 arguments: source file folder, preProcess, preCompile, result"

if [ $# -ge 1 ]
then
	sources=$1
	if [ $# -ge 2 ]
	then
		preProcess=$2
		if [ $# -ge 3 ]
		then
			preCompile=$3
			if [ $# -ge 4 ]
			then
				result=$4
			fi
		fi
	fi
fi

checkFolder () {
	if [ -d $2 ]
	then
		echo "$1 is : ./$2"
	else 
		mkdir "$2"
		echo "$1 is : ./$2 had been created"
	fi
}

checkFolder "Source    " "$sources"
checkFolder "PreProcess" "$preProcess"
checkFolder "PreCompile" "$preCompile"
checkFolder "Result    " "$result"

ls "./Example" > "ls.txt"
exec < "ls.txt"
while read line
do
	echo $line
	./preProcess $line
	# echo "./PreProcess/$line"
	g++ -E "./PreProcess/$line" > "./PreCompile/$line"
	./transfer $line
done
