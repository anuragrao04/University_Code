#include <stdio.h>

void optimal(int ref_str[], int n, int frames) {
  printf("\nRef String\t Page Frames\n");
  int hit = 0;  // Counter for page hits
  int miss = 0; // Counter for page misses

  int frames_arr[frames];

  // Initialize all frames as -1 (not used)
  for (int i = 0; i < frames; i++) {
    frames_arr[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    int flag = 0; // Flag to indicate if page is found in frames

    // Check if page is already present in frames
    for (int j = 0; j < frames; j++) {
      if (ref_str[i] == frames_arr[j]) {
        flag = 1;
        hit++;
        break;
      }
    }

    // If page is not found, replace the page that will not be used for the
    // longest time in the future
    if (flag == 0) {
      int farthest = i;
      int to_replace = 0; // Index of page to be replaced

      // Find the page that will not be used for the longest time in the future
      for (int j = 0; j < frames; j++) {
        int temp = -1;
        for (int k = i + 1; k < n; k++) {
          if (frames_arr[j] == ref_str[k]) {
            if (temp == -1 || k > temp) {
              temp = k;
            }
            break;
          }
        }
        // If a page is never used in the future, replace it immediately
        if (temp == -1) {
          to_replace = j;
          break;
        }
        // Update farthest if a better candidate is found
        if (temp > farthest) {
          farthest = temp;
          to_replace = j;
        }
      }

      // Replace the page
      frames_arr[to_replace] = ref_str[i];
      miss++;
    }

    // Print the reference string and current page frames
    printf("%d\t\t", ref_str[i]);
    for (int j = 0; j < frames; j++) {
      printf("%d ", frames_arr[j]);
    }
    printf("\n");
  }

  printf("\nTotal Hits = %d", hit);
  printf("\nTotal Misses = %d\n", miss);
}

int main() {
  int ref_str[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
  int n = sizeof(ref_str) / sizeof(ref_str[0]);
  int frames = 4; // Number of page frames

  printf("Optimal Page Replacement Algorithm\n");
  optimal(ref_str, n, frames);

  return 0;
}
