# Selinie Wang (jw6qe@virginia.edu)
# November 1, 2018
# averagetime.sh
# Lab Section 101

#!/bin/bash

# TAKE IN A SINGLE INPUT VALUE
echo "enter the exponent for counter.cpp: "
read input

result=0
# IF INPUT IS QUIT, SCRIPT SHOULD EXIT
if [ $input == "quit" ]
	then exit 0
	fi 

# EXECUTE PROGRAM FIVE TIMES
iterations=5 # FIVE ITERATIONS
for (( x = 1; x <= iterations; x++ ))
do
	RUNNING_TIME=`./a.out ${input}`
	result+=`expr $RUNNING_TIME`
	echo "Running iteration ${x}..."
	echo "time taken: ${RUNNING_TIME} ms"
done 

echo "${size} iterations took ${result} ms" 
echo "Average time was " `expr $result / $iterations` "ms"