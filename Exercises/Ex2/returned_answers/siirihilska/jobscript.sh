#!/bin/bash

n=10

parallel -j "$n" './hello {} > bashoutput_{}.txt' ::: $(seq 1 $n)
