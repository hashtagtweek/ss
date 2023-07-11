
#include <stdio.h>

int at[10];
int bt[10];
int rt[10];

int i, j, smallest, count = 0;
int n;
int time;
int remain;
int flag = 0;
int time_quantum;
int wait_time = 0;
double wt = 0, tat = 0, end;

void srjf() {
for (time = 0; count != n; time++) {
smallest = 9;
for (i = 0; i < n; i++) {
if (at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
smallest = i;
}
bt[smallest]--;
if (bt[smallest] == 0) {
count++;
end = time + 1;
tat += end - at[smallest];
wt += end - at[smallest] - rt[smallest];
}
}
printf("\n\nAverage waiting time = %lf\n", wt / n);
printf("Average Turnaround time = %lf", tat / n);
}

void rr() {
printf("Enter Time Quantum:\t");
scanf("%d", &time_quantum);
printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
for (time = 0, count = 0; remain != 0;) {
if (rt[count] <= time_quantum && rt[count] > 0) {
time += rt[count];
rt[count] = 0;
flag = 1;
} else if (rt[count] > 0) {
rt[count] -= time_quantum;
time += time_quantum;
}
if (rt[count] == 0 && flag == 1) {
remain--;
printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
tat += time - at[count];
wait_time += time - at[count] - bt[count];
flag = 0;
}
if (count == n - 1)
count = 0;
else if (at[count + 1] <= time)
count++;
else
count = 0;
}
printf("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n);
printf("Avg Turnaround Time = %f", tat * 1.0 / n);
}

int main() {
int ch;
printf("Enter the number of Processes (less than 9):\n");
scanf("%d", &n);
printf("Enter arrival time:\n");
for (i = 0; i < n; i++)
scanf("%d", &at[i]);
printf("Enter burst time:\n");
for (i = 0; i < n; i++)
scanf("%d", &bt[i]);
for (i = 0; i < n; i++)
rt[i] = bt[i];

printf("\n1) Shortest Remaining Job First (SRJF)\n2) Round Robin (RR)\nEnter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
bt[9] = 9999;
srjf();
break;
case 2:
remain = n;
rr();
break;
default:
printf("Enter correct choice!");
}
return 0;
}
