#!/bin/bash
#FILE: Test.sh
#************************************************************************************
# SHELL SCRIPT: Combine.sh

# Script combines the calendar text files and cats them into a single input.txt file
# Complete this after you can get one file working
#************************************************************************************
for i in `seq 1 1 10`; do
    echo Testing parallel version...
    _startTime=$(date +%s)
    ./thread --parallel 5000000 2000 12000000 --verbose
    _finishTime=$(date +%s)
    _deltaTime=$[ $_finishTime - $_startTime + 1 ]
    echo $_deltaTime seconds.
    echo Testing serial version...
    _startTime=$(date +%s)
    ./thread --serial 5000000 2000 12000000 --verbose
    _finishTime=$(date +%s)
    _deltaTime=$[ $_finishTime - $_startTime + 1 ]
    echo $_deltaTime seconds.
done
_deltaTime=
_finishTime=
_startTime=