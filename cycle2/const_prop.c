#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct production {
  char lhs;
  char rhs[10];
} production;

int num_productions;
production productions[10];

void replace_constants() {
  for (int i = 0; i < num_productions; i++) {
    if (strlen(productions[i].rhs) == 1 && isdigit(productions[i].rhs[0])) {
      for (int j = 0; j < num_productions; j++) {
        for (int k = 0; k < strlen(productions[j].rhs); k++) {
          if (productions[j].rhs[k] == productions[i].lhs) {
            productions[j].rhs[k] = productions[i].rhs[0];
          }
        }
      }
    }
  }
}

int main() {
  printf("Enter the number of productions: ");
  scanf("%d", &num_productions);
  printf("Enter the productions%d\n", num_productions);
  for (int i = 0; i < num_productions; i++) {
    scanf(" %c=%s", &productions[i].lhs, &productions[i].rhs);
  }
  replace_constants();
  for (int i = 0; i < num_productions; i++) {
    printf("%c=%s\n", productions[i].lhs, productions[i].rhs);
  }
  return 0;
}
