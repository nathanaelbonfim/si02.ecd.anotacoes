void main(void)
{
  int y, *p, x;
  y = 10; // y = 0
  p = &y; // p = endereço de y
  x = *p; // x = 10 -> conteudo de p -> aponta para y = 10
  x = 2;  // x = 2
  (*p)++; // y = 11 /// aumenta o conteudo de p (que aponta para y)
  x--;    // x = 1
  (*p) += x; // y = 12 (x = 1 + *p = y = 11)
  printf ("y = %d\n", y); // y = 12
  printf ("x = %d\n", x); // x = 1
}
