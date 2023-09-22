#!/usr/bin/env bash

#SBATCH --partition=instruction
#SBATCH -J task2
#SBATCH -o task2.out -e task2.err

#SBATCH --time=0-00:03:00

g++ convolution.cpp task2.cpp -Wall -O3 -std=c++17 -o task2