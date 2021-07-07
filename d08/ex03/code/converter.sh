#!/bin/sh

cat $1 | tr "><+-.,[]" "fuckthis" > $1"_converted"
