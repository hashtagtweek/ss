#include <stdio.h>

int main() {
int p, r;
printf("Enter the number of processes: ");
scanf("%d", &p);
printf("Enter the number of resources: ");
scanf("%d", &r);

int allocated[p][r];
int max[p][r];
int need[p][r];
int avail[r];
int completed[p];
int safeSequence[p];
int count = 0;

printf("Enter the allocation matrix:\n");
for (int i = 0; i < p; i++) {
for (int j = 0; j < r; j++) {
scanf("%d", &allocated[i][j]);
}
completed[i] = 0;
}

printf("Enter the maximum matrix:\n");
for (int i = 0; i < p; i++) {
for (int j = 0; j < r; j++) {
scanf("%d", &max[i][j]);
need[i][j] = max[i][j] - allocated[i][j];
}
}


printf("Enter the available resources:\n");
for (int i = 0; i < r; i++) {
scanf("%d", &avail[i]);
}

int process = -1;
do {
process = -1;
for (int i = 0; i < p; i++) {
if (completed[i] == 0) {
int isProcessSafe = 1;
for (int j = 0; j < r; j++) {
if (avail[j] < need[i][j]) {
isProcessSafe = 0;
break;
}
}
if (isProcessSafe == 1) {
process = i;
break;
}
}
}
if (process != -1) {
printf("\nProcess %d runs to completion!", process + 1);
safeSequence[count] = process + 1;
count++;
for (int j = 0; j < r; j++) {
avail[j] += allocated[process][j];
allocated[process][j] = 0;
max[process][j] = 0;
completed[process] = 1;
}
}
} while (count != p && process != -1);

if (count == p) {
printf("\nThe system is in a safe state!!\n");
printf("Safe Sequence: < ");
for (int i = 0; i < p; i++) {
printf("%d ", safeSequence[i]);
}
printf(">\n");
} else {
printf("\nThe system is in an unsafe state!\n");
}

return 0;
}
