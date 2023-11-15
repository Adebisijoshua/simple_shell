#include <stdio.h>

int is_even(int num) {
  return (num % 2) == 0;
}

int main(void) {
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  if (is_even(num))
    printf("%d is even\n", num);
  else
    printf("%d is odd\n", num);

  return 0;
}

