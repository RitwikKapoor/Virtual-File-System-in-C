#!/bin/sh

if [ -z $CC ] 
then 
	CC=gcc
fi
$CC ffuse.c `pkg-config fuse --libs --cflags`

