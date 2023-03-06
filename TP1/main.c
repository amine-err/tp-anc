#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct FLOT
{
  int s;   // chiffres apres virgule
  float m; // mantisse
  int e;   // exposant
};

struct FLOT FLOTTANT(float nb, int s)
{
  if (s > 0)
  {
    struct FLOT nbfl = {s, 0, 0};

    while ((int)(nb) != 0)
    {
      nb = nb / 10;
      nbfl.e++;
    }
    while (nb != 0 && (int)(nb * 10) == 0)
    {
      nb = nb * 10;
      nbfl.e--;
    }
    nbfl.m = (int)(nb * (int)pow(10, s)) / pow(10, s);
    // nbfl.m = (int)(nb*(int)pow(10, s));
    return nbfl;
  }
  else
  {
    printf("Nombre des chiffres doit etre positif\n");
    exit(EXIT_FAILURE);
  }
}

struct FLOT
SOMMEFL(struct FLOT a, struct FLOT b)
{
  // a.m = a.m/pow(10, a.s); b.m = b.m/pow(10, b.s);
  if (b.e < a.e)
  {
    struct FLOT temp = a;
    a = b;
    b = temp;
  }
  a.m = a.m * pow(10, a.e) / pow(10, b.e);
  float somme = (b.m + a.m) * pow(10, b.e);
  if (b.s > a.s)
  {
    a.s = b.s;
  }
  struct FLOT sommefl = FLOTTANT(somme, a.s);
  return sommefl;
}

struct FLOT
DIFFL(struct FLOT a, struct FLOT b)
{
  b.m = -b.m;
  struct FLOT diffl = SOMMEFL(a, b);
  return diffl;
}

struct FLOT
MULFL(struct FLOT a, struct FLOT b)
{
  if (b.s > a.s)
  {
    a.s = b.s;
  }
  struct FLOT mulfl = FLOTTANT(a.m * b.m, a.s);
  mulfl.e = mulfl.e + a.e + b.e;
  return mulfl;
}

struct FLOT
DIVFL(struct FLOT a, struct FLOT b)
{
  b.m = 1 / b.m;
  b.e = -b.e;
  struct FLOT divfl = MULFL(a, b);
  return divfl;
}

int
main()
{
  char operation;
  float n1, n2;
  int n1s, n2s;

  printf("Entrer un operateur (+, -, *, /): ");
  scanf("%c", &operation);
  printf("Enter un nombre reel et sa precision: ");
  scanf("%f %d", &n1, &n1s);
  printf("Enter un autre nombre reel et sa precision: ");
  scanf("%f %d", &n2, &n2s);

  struct FLOT a = FLOTTANT(n1, n1s);
  struct FLOT b = FLOTTANT(n2, n2s);

  printf("flottant 1: s=%d m=%f e=%d\n", a.s, a.m, a.e);
  printf("flottant 2: s=%d m=%f e=%d\n", b.s, b.m, b.e);

  switch (operation)
  {
  case '+':
    struct FLOT somme = SOMMEFL(a, b);
    printf("somme: s=%d : %f * 10^%d\n", somme.s, somme.m, somme.e);
    break;

  case '-':
    struct FLOT diff = DIFFL(a, b);
    printf("difference: s=%d : %f * 10^%d\n", diff.s, diff.m, diff.e);
    break;

  case '*':
    struct FLOT multi = MULFL(a, b);
    printf("multiplication: s=%d : %f * 10^%d\n", multi.s, multi.m, multi.e);
    break;

  case '/':
  {
    if (b.m == 0)
    {
      printf("Division par Zero impossible\n");
      exit(EXIT_FAILURE);
    }
    else
    {
      struct FLOT div = DIVFL(a, b);
      printf("division: s=%d : %f * 10^%d\n", div.s, div.m, div.e);
      break;
    }
  }
  default:
    printf("Operateur est incorrect");
    exit(EXIT_FAILURE);
  }
  return 0;
}