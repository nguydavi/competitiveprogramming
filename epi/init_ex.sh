#!/bin/bash

# Script initializing exercice folder with Makefile and main.cpp

function help {
    echo
    echo "Example of usage:"
    echo "$0 chapter exercice"
    echo
    echo -e "\tchapter\t\twhat chapter is the exercice in, must be valid number greater than 5"
    echo -e "\t\t\t(there are no exercices for chapter 1 to 4)"
    echo -e "\texeercice\texercice number, must be valid number"
    exit 1
}

function is_number {
    if [[ "$1" =~ ^[0-9]+$ ]]; then
        echo 0
    else
        echo 1
    fi
}

function main {
    chapterNumber=$1
    exerciceNumber=$2

    template_path="template"
    dst_path="chapter$1/ex$2"
    mkdir -p $dst_path

    if [ "$(ls -A $dst_path)" ]; then
        echo "Folder $dst_path exists and is non empty, do nothing."
    else
        cp "$template_path/Makefile" "$dst_path"
        cp "$template_path/main.cpp" "$dst_path"
        echo "Initialized \"$dst_path\" done"
    fi
}

# Checking arguments
if [ $# != 2 ]; then
    help
fi
checkArg1=$(is_number "$1")
checkArg2=$(is_number "$2")

if [ $checkArg1 != 0 ] || [ $checkArg2 != 0 ] || [ $1 -lt 5 ]; then
    help
fi

main $1 $2
