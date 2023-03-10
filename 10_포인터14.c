// 10_포인터14.c

#include <stdio.h>

#if 1
int main(void)
{
  const int n = 10;
  int x = 100;

  int *p = &n;
  *p = 100; /* 미정의 동작 */

  return 0;
}
#endif

#if 1
// > 포인터 변수에 대한 const는

//   const int *p1; - *
//   int const *p2;
//  > 포인터 변수가 가르키는 대상체를 수정하지 않겠다.
//  p  ----> <n>

//  int *const p3;
//  > 포인터 변수를 다른 주소로 변경할 수 없습니다.
// <p> ---->  n

// const int *const p4;
// int const *const p5;
// <p> ----> <n>
int main(void)
{
  int n = 100;
  int x = 100;

  const int *p1 = &n;
  int const *p2 = &n;
  // *p1 = 200; /* 에러 */
  // *p2 = 200; /* 에러 */
  p1 = &x; /* OK */
  p2 = &x; /* OK */

  int *const p3 = &n;
  *p3 = 10000; /* OK */
  // p3 = &x;     /* 에러 */

  const int *const p4;
  int const *const p5;

  return 0;
}
#endif

#if 0
int main(void)
{
  const int n = 100;
  int *p = &n;

  *p = 42; /* 미정의 동작 */

  const int *pc = &n;
  // *pc = 42; /* 컴파일 오류 */

  printf("%d\n", n);

  return 0;
}
#endif

#if 0
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void)
{
  int a = 10;
  int b = 20;
  swap(&a, &b);

  printf("%d %d\n", a, b); // ?

  return 0;
}
#endif

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 포인터 변수를 다른 함수에서 다른 주소로 변경하기 위함이다.
#if 1
void pswap(int **a, int **b)
{
  int *temp = *a;
  *a = *b;
  *b = temp;
}

int main(void)
{
  int a = 10;
  int b = 20;

  int *pa = &a;
  int *pb = &b;
  printf("%d %d\n", *pa, *pb);

  pswap(&pa, &pb);
  printf("%d %d\n", *pa, *pb);

  return 0;
}
#endif

typedef int error_t;

//          out parameter
#if 0
error_t foo(int *result)
{
  int n = 10;
  *result = n; /* 인자를 통해 결과를 전달합니다. */

  return 0;
}

int main(void)
{
  int result;
  error_t error = foo(&result);
  if (error == 0)
  {
    printf("result: %d\n", result);
  }

  return 0;
}
#endif

#if 0
error_t foo(int **result)
{
  static int n = 10;
  *result = &n;

  return 0;
}

int main(void)
{
  int *result;
  error_t error = foo(&result);
  if (error == 0)
  {
    printf("result: %d\n", *result);
  }

  return 0;
}
#endif

// ppa ----> pa ----> a
int main(void)
{
  int a = 100;

  int *pa = &a;
  int **ppa = &pa;

  printf("%d\n", **ppa);
  **ppa = 42;
  printf("%d\n", a);

  return 0;
}
