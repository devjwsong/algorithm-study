#include <iostream>
#include <vector>

using namespace std;

int mat_size = 2;

vector<vector<long long>> matMul(vector<vector<long long>>& A, vector<vector<long long>>& B) {
  vector<vector<long long>> answer(mat_size, vector<long long>(mat_size));

  for (int i=0; i<mat_size; ++i) {
    for (int j=0; j<mat_size; ++j) {
      for (int k=0; k<mat_size; ++k) {
        answer[i][j] += A[i][k]*B[k][j];
      }
      answer[i][j] %= 1000000;
    }
  }

  return answer;
}

long long fibonacci(long long n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }

  vector<vector<long long>> mat = {{1, 1}, {1, 0}};
  vector<vector<long long>> answer = {{1, 0}, {0, 1}};
  
  long long input = n;
  while(1) {

    if (input % 2 == 1) {
      answer = matMul(mat, answer);
    }

    input /= 2;

    if (input == 0) {
      break;
    }

    mat = matMul(mat, mat);
    
  }

  return answer[1][0];
}

int main() {

  long long n;
  scanf("%lld", &n);

  printf("%lld\n", fibonacci(n));

  return 0;
}