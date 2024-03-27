#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char pn[10][10], t[10];
  int arr[10], bur[10], star[10], finish[10], tat[10], wt[10], i, j, n, temp;
  int totwt = 0, tottat = 0;
  // tf are these variable names
  printf("Enter the number of processes to schedule: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter the process name, arrival time and the brust time of the "
           "processes: ");
    scanf("%s %d %d", pn[i], &arr[i], &bur[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (arr[i] < arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        temp = bur[i];
        bur[i] = bur[j];
        bur[j] = temp;
        strcpy(t, pn[i]);
        strcpy(pn[i], pn[j]);
        strcpy(pn[j], t);
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (i == 0)
      star[i] = arr[i];
    else
      star[i] = finish[i - 1];
    wt[i] = star[i] - arr[i];
    finish[i] = star[i] + bur[i];
    tat[i] = finish[i] - arr[i];
  }

  printf("\nProcessName\tArrivalTime\tBurstTime\tWaitTime\tStart\tTurnAroundTim"
         "e\t\tFinish");
  printf("\n");
  for (i = 0; i < n; i++) {
    printf("\n%s\t\t%3d\t\t%3d\t\t%3d\t\t%3d\t\t%6d\t\t%6d", pn[i], arr[i],
           bur[i], wt[i], star[i], tat[i], finish[i]);
    totwt += wt[i];
    tottat += tat[i];
  }

  printf("\n\nAverage Waiting Time: %f", (float)totwt / n);
  printf("\nAverate Turn Around Time: %f\n", (float)tottat / n);
  return EXIT_SUCCESS;
}
