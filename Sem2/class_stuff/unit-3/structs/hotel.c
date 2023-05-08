#include <stdio.h>
#include <stdlib.h>
struct number {
  unsigned int mob;
  unsigned int alternate_mob;
};

struct hotel {
  char customer_name[50];
  int no_days;
  struct number num;
};

int main(int argc, char *argv[]) {
  struct hotel amazing_hotel_customer;
  printf("\nWelcome to amazing hotel\n");
  printf("Enter customer name: ");
  fgets(amazing_hotel_customer.customer_name, 50, stdin);
  printf("\nEnter number of days: ");
  scanf("%d", &amazing_hotel_customer.no_days);
  printf("\nEnter mobile number: ");
  scanf("%d", &amazing_hotel_customer.num.mob);
  printf("\nAnd lastly, an altername mobile number: ");
  scanf("%d", &amazing_hotel_customer.num.alternate_mob);

  int total = 2000 * amazing_hotel_customer.no_days;
  total += 0.085 * total; // tax

  printf("\nHere's all the data: \n");
  printf("Customer name: %s", amazing_hotel_customer.customer_name);
  printf("Number of days: %d\n", amazing_hotel_customer.no_days);
  printf("Mobile number: %d\n", amazing_hotel_customer.num.mob);
  printf("Alternate mobile number: %d\n",
         amazing_hotel_customer.num.alternate_mob);
  printf("Total: %d\n", total);

  return EXIT_SUCCESS;
}
