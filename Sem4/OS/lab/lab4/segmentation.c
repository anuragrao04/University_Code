#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // this defines the max size of the segment table

typedef struct segment_table_entry {
  int segment_number;
  int base_address;
  int segment_limit;
} table_entry_t;

int main(int argc, char *argv[]) {
  int n;
  printf("Enter number of segments to put in the segment table: ");
  scanf("%d", &n);
  table_entry_t segment_table[MAX];
  int segment_number;
  int base_address;
  int segment_limit;

  for (int i = 0; i < n; i++) {
    printf("\nEnter Segment %d Number: ", i + 1);
    scanf("%d", &segment_number);
    printf("\nEnter %d Base Address: ", i + 1);
    scanf("%d", &base_address);
    printf("\nEnter %d Segment Limit: ", i + 1);
    scanf("%d", &segment_limit);
    segment_table[i].segment_number = segment_number;
    segment_table[i].segment_limit = segment_limit;
    segment_table[i].base_address = base_address;
  }

  // We are done building the segment table. Now we access memory

  int offset;
  int choice = 1;
  while (choice) {
    printf("\nEnter 1 to find physical address\nEnter 0 to exit: ");
    scanf("%d", &choice);
    if (!choice) {
      break;
    }

    printf("\nEnter segment number to access: ");
    scanf("%d", &segment_number);
    printf("\nEnter offset (which byte in that segment?): ");
    scanf("%d", &offset);

    // now we search the table to get segment limit and base address from the
    // table
    int found = 0;
    for (int i = 0; i < n; i++) {
      if (segment_table[i].segment_number == segment_number) {
        // found!
        found = 1;
        int base_address = segment_table[i].base_address;
        int segment_limit = segment_table[i].segment_limit;
        if (offset > segment_limit) {
          printf("\nTrap: Addressing Error\n");
          break;
        } else {
          int physical_address = base_address + offset;
          printf("\nComputed physical address: %d", physical_address);
        }
      }
    }
    if (!found) {
      printf("\nSegment Number Not Found In Table\n");
    }
  }

  return EXIT_SUCCESS;
}
