// Task:
// sum of elements with odd indices
// sum of elements bw the first and the next negative elements
// zip it by removing elements with abs < 1

#include <iostream>
#include <math.h>

double sum_odds(double arr[], int n);
double sum_bw_neg(double *arr, int n);
void zip(double *arr, int n);

int main() {
  const int n = 20;
  double arr[] = { 12.4, 64.6, 0.53, -0.004, 0.5,   7.12, -8.3, 9.027, 0.61, 20.51, \
                  0.314, 78.19, 7,   0,     30.195, 8.06, 5.08, 6.2, 19.024, 72  };
  std::cout << "Sum of the odd elements: " << sum_odds(arr, n) << std::endl;
  std::cout << "Computing the sum bw negative elements:\n" << sum_bw_neg(arr, n) << std::endl;
  std::cout << "Zipping:\n";
  zip(arr,n);
  for (int k = 0; k<n; k++) std::cout << arr[k] << ' ';
  std::cout << "\n";
  return 0;
}

double sum_odds(double arr[], int n) {
  double result = 0;
  for (int i = 1; i < n; i+=2) {
    result += arr[i];
  }
  return result;
}

double sum_bw_neg(double *arr, int n) {
  int beg = -1, end = -1;
  int i = 0;
  while(i < n) {
    if (arr[i] < 0) { beg = i; i++; break; }
    i++;
  }
  if (beg<0) {std::cout << "Error: there's no negative elements in the array.\n"; return -1;}
  double result = 0;
  while (i < n) {
    if (arr[i] >= 0) { result+=arr[i]; i++; }
    else { end = i; break; }
  }
  if(end<0) { std::cout << "Error: there's only one negative element in the array.\nReturning the sum of elements after the first.\n";}
  return result;
}

void zip(double *arr, int n) {
  // проще всего - напихать в новый массив и переписать старый по-новому
  // но можно пропустить пару шагов и сделать один обход вместо двух
  int j = 0; // счетчик для отслеживания новых элементов
  for (int i = 0; i < n; i++) {
    if (abs(arr[i]) >= 1) {
      arr[j] = arr[i];
      j++;
    }
  }
  while (j < n) {
     arr[j] = 0;
     j++;
   }
}
