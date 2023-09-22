#!/usr/bin/env bash

#SBATCH --partition=instruction
#SBATCH -J task1
#SBATCH -o task1.out -e task1.err

#SBATCH --time=0-00:03:00


g++ scan.cpp task1.cpp -Wall -O3 -o task1

for i in {10..30}; do
  n=$((2 ** i))
  echo "Running with n = 2^$i = $n"
  ./task1 $n
  echo
done