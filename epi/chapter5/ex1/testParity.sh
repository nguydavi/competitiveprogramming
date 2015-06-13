#!/bin/bash

# Script counting the number of one from the binary output and test if the
# parity from program main is correct

make

result=$(make run arg=$1)
echo -e "Program output:\n$result"

binaryOutput=$(echo -n "$result" | xargs | awk '{print $1;}')
parityOutput=$(echo -n "$result" | xargs | awk '{print $2;}')

echo -e "\nNumber of 1 bits:"
numberOfOnes=$(echo -n "$binaryOutput" |  grep -o "1" | wc -l)
# another way: 
# echo -n "$binaryOutput" | sed -ne 's/0//gp' | tr -d '\n' | wc -c
echo "$numberOfOnes"

# Testing if the output of parity is correct according to the number of 1's
# bits
if [[ $(($numberOfOnes % 2)) -eq 0 && $parityOutput -eq 0 ]] ||
    [[ $(($numberOfOnes % 2)) -eq 1 && $parityOutput -eq 1 ]]; then
    echo "$(tput setaf 2)TEST PASSED"
else
    echo "$(tput setaf 1)TEST FAILED"
fi
