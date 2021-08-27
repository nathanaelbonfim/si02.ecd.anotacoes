void main(void)
{
	int y, *p, **pp, x;
	x = 99; // x = 99
	y = 7;  // y = 7
	p = &y; // p = &y = 7
	pp = &p; // pp = &p = &y = 7
	printf ("\n*p = %d\n", *p); //  *p = y = 7
	printf ("**pp= %d\n", **pp);// **p = &p = &y = 7 
	printf ("*pp = %d\n", *pp); // *p = &p
	printf ("y = %d\n", y);     // y = 7
	printf ("x = %d\n", x);     // x = 99
}
