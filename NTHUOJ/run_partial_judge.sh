#!/bin/zsh
cp $1 function.h
gcc main.c && ./a.out
