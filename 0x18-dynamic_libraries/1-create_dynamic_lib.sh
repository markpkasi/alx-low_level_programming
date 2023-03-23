#!/bin/bash
gcc -FPIC -c *.c
gcc *.o -shared -o liball.so
