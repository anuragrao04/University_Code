#include <stdio.h>

int main() {
  int i, n, time, remaining, flag = 0, time_quantum;
  int wt = 0, tat = 0, at[10], bt[10], rt[10];
  char pn[10][10];

  printf("Enter Total Process:\t ");
  scanf("%d", &n);

  remaining = n;
  for (i = 0; i < n; i++) {
    printf("Enter Process Name, Arrival Time and Burst Time for Process Number "
           "%d :",
           i + 1);
    scanf("%s", pn[i]);
    scanf("%d", &at[i]);
    scanf("%d", &bt[i]);
    rt[i] = bt[i];
  }

  printf("Enter Time Quantum:\t");
  scanf("%d", &time_quantum);

  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for (time = 0, i = 0; remaining != 0;) {
    if (rt[i] <= time_quantum && rt[i] > 0) {
      time += rt[i];
      rt[i] = 0;
      flag = 1;
    } else if (rt[i] > 0) {
      rt[i] -= time_quantum;
      time += time_quantum;
    }

    if (rt[i] == 0 && flag == 1) {
      remaining--;
      printf("P[%s]\t|\t%d\t|\t%d\n", pn[i], time - at[i],
             time - at[i] - bt[i]);
      wt += time - at[i] - bt[i];
      tat += time - at[i];
      flag = 0;
    }

    if (i == n - 1) {
      i = 0;
    } else if (at[i + 1] <= time) {
      i++;
    } else {
      i = 0;
    }
  }

  printf("\nAverage Waiting Time= %f\n", wt * 1.0 / n);
  printf("Avg Turnaround Time = %f", tat * 1.0 / n);

  return 0;
}
