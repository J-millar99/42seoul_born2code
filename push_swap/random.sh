#!/bin/sh

export ARG=$(seq 1 500 | sort -R)
./push_swap $ARG | ./checker $ARG