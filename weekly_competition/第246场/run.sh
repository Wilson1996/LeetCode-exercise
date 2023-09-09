#!/bin/bash
if [ ! -n "$1" ]
then
    echo "[WARNING: please enter your file name(no extended name)]"
    exit
fi
_file=${1}.cpp
if [ -a ${_file} ]
then
    echo "[compiling ${_file} ...]"
    g++ ${_file} -D TW_LOCAL -o ${1} -std=c++17
else
    echo "[WARNING: not find file ${_file}]"
    exit
fi

if [ -a in.txt ]
then
   ./${1} <in.txt
else
   echo "[WARNING: no file in.txt, please provide]"
fi

