#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char company[50];
  char model[50];
  int year;
} CAR;

void read_cars(CAR *cars, int n);
void display_cars(const CAR *cars, int n);
void display_specific_year(const CAR *cars, int n, int year);

int main(int argc, char *argv[]) {
  int n;
  printf("Enter number of cars: ");
  scanf("%d", &n);
  CAR cars[n];

  read_cars(cars, n);
  printf("\nCar details: \n");
  display_cars(cars, n);
  int year;
  printf("\n\nEnter year you want cars from: ");
  scanf("%d", &year);

  display_specific_year(cars, n, year);
  return EXIT_SUCCESS;
}

void read_cars(CAR *cars, int n) {
  for (int i = 0; i < n; i++) {
    printf("\nCar %d", i + 1);
    printf("\nEnter company name: ");
    getchar();
    fgets(cars[i].company, 50, stdin);
    printf("\nEnter model: ");
    fgets(cars[i].model, 50, stdin);
    printf("\nEnter year: ");
    scanf("%d", &cars[i].year);
  }
  printf("\n\nDone\n\n");
}

void display_cars(const CAR *cars, int n) {
  for (int i = 0; i < n; i++) {
    printf("\n\nCar %d\n", i + 1);
    printf("Company: %s", cars[i].company);
    printf("Model: %s", cars[i].model);
    printf("Year: %d", cars[i].year);
  }
}

void display_specific_year(const CAR *cars, int n, int year) {
  printf("\n Cars from the year %d are: \n", year);
  for (int i = 0; i < n; i++) {
    if (cars[i].year == year) {
      printf("Company: %s", cars[i].company);
      printf("Model: %s", cars[i].model);
    }
  }
}
