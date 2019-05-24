# Selinie Wang (jw6qe@virginia.edu)
# October 23, 2018
# averagetime.sh

#!/bin/bash

# first version: enter from keyboard
# echo -n "enter P value: "
# read P

# second version: pass as shell script argument
# P=$1

echo -n "Dictionary File: "
read dictFile

echo -n "Grid File: "
read gridFile

RUNNING_TIME1=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME2=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME3=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME4=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME5=`./a.out $dictFile $gridFile | tail -1`

#get average of five
average1 = $(((RUNNING_TIME1 + RUNNING_TIME2 + RUNNING_TIME3 + RUNNING_TIME4 + RUNNING_TIME5) / 5))
echo "Average in milliseconds: "
echo $average1