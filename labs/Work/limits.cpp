// This program helps to check limits for orders.
#include <cstdio>

int main() {
  using namespace std;
  printf("I'll help you with limits.\n");
  unsigned int side = 0;
  float factor = 1.0, volume = 0.0, price = 0.0;
  printf("Insert side (1 for buy, 2 for sell), factor, volume and price: ");
  scanf("%u %f %f %f", &side, &factor, &volume, &price);

  float OVal = volume * price * factor;

  printf("\nBriefly:\n");
  if (side==1)
    printf("Long volume per instrument: %.0f\nLong value per instrument: %.0f\n", volume, OVal);
  else if (side == 2)
    printf("Short volume per instrument: %.0f\nShort value per instrument: %.0f\n", volume, OVal);
  else
    printf("Wrong side.\n");
  // printf("L Vol pI\tS Vol pI\tL Vol pU\tS Vol pU\tL Val pI\tS Val pI\tL Val pU\tS Val pU\t");
  // printf("NV\tN Vol pI\tN vol pU\tGV\tO Vol\tO Val\n");
  return 0;

}
