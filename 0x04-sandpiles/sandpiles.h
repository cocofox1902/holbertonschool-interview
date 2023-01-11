#ifndef SANDPILES_H_
#define SANDPILES_H_

#include <stdlib.h>
#include <stdio.h>

void print_sandpile(int grid[3][3]);
int is_stable(int grid1[3][3], int grid2[3][3]);
void addition(int grid1[3][3], int grid2[3][3]);
void repartitrice(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H_ */
