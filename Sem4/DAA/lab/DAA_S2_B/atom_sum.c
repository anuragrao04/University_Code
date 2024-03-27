#include <stdio.h>
typedef struct stackelement {
  int num;          // current count
  char parentheses; // open and closed parentheses
} SE;

int atoms_sum(char formula[]) {
  SE stack[20];
  int stkptr = -1;
  int res = 0;

  for (int i = 0; formula[i] != '\0'; i++) {

    if (formula[i] >= 'A' && formula[i] <= 'Z') { // capital letter
      int atom_no = 1;
      if (formula[i + 1] >= '2' &&
          formula[i + 1] <= '9') { // see if there's a number as a multiplier
        atom_no = formula[i + 1] - '0';
        i++;
      }
      if (formula[i + 1] >= 'a' && formula[i + 1] <= 'z') { // lowercase letter
        i++;
        if (formula[i + 1] >= '2' && formula[i + 1] <= '9') {
          atom_no = formula[i + 1] - '0';
          i++;
        }
      }
      res += atom_no;
    } else if (formula[i] == '(') { // push in case of (
      stkptr++;
      stack[stkptr].num = res;
      stack[stkptr].parentheses = '(';
      res = 0;
    } else if (formula[i] == ')') {
      int atom_no = res;
      if (formula[i + 1] >= '2' && formula[i + 1] <= '9') {
        atom_no *= (formula[i + 1] - '0');
        i++;
      }
      res = stack[stkptr].num + atom_no;
      stkptr--;
    }
  }
  return res;
}

int main() {
  char formula[21];
  scanf("%s", formula);
  printf("%d", atoms_sum(formula));
  return 0;
}
