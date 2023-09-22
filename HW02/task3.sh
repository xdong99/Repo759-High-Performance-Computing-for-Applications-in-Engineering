#!/usr/bin/env bash

#SBATCH --partition=instruction
#SBATCH -J task3
#SBATCH -o task3.out -e task3.err

#SBATCH --time=0-00:03:00

g++ task3.cpp matmul.cpp -Wall -O3 -std=c++17 -o task3