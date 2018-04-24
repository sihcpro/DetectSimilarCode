#!/bin/sh

sources="Example"
process="Process"
compile="Compile"
transfer="Transfer"
result="Result"

echo "You can give 5 arguments: folder sources, process, compile, transfer, result"

# case $# in
# 1*)
# 	echo "You gived no arguments!"
# *)
# 3*)
	
# 2*)
# 	sources=$1
# 	;;

if [ $# -ge 1 ]
then
	sources=$1
	if [ $# -ge 2 ]
	then
		process=$2
		if [ $# -ge 3 ]
		then
			compile=$3
			if [ $# -ge 4 ]
			then
				transfer=$4
				if [ $# -ge 5 ]
				then
					result=$5
				fi
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

checkFolder "Source  : " "$sources"
checkFolder "Process : " "$process"
checkFolder "Compile : " "$compile"
checkFolder "Result  : " "$result"

ls $sources > "ls.txt"
exec < "ls.txt"
while read line
do
	echo $line
	./process $line $sources $process
	# echo "./PreProcess/$line"
	g++ -E "./$process/$line" > "./$compile/$line"
	./transfer $line $compile $transfer
	# python3.6 hashing.py 10 $line
done

# python3.6 checkHash.py "ls.txt" $result
