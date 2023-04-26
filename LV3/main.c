#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 100

int x1 = 0;
int x2 = 0;
int stog1[N];
int stog2[N];
int brojac1 = 0;
int brojac2 = 0;



int povrh(int a, int b)
{
	if (a == b || b == 0)
	{
		return 1;
	}
	else
	{
		return povrh(a - 1, b - 1) + povrh(a - 1, b);
	}
}

void push1(int x)
{
	if (brojac1 == N)
	{
		printf("Stack overflow!");
	}
	else
	{
		brojac1++;
		stog1[brojac1] = x;
	}
}

void push2(int x)
{
	if (brojac2 == N)
	{
		printf("Stack overflow!");
	}
	else
	{
		brojac2++;
		stog2[brojac2] = x;
	}
}

int pop1() {
	if (brojac1 == 0) {
		printf("Stack Underflow!");
	}
	else
	{
		x1 = stog1[brojac1];
		brojac1--;
		return x1;
	}
}

int pop2() {
	if (brojac2 == 0) {
		printf("Stack Underflow!");
	}
	else
	{
		x2 = stog2[brojac2];
		brojac2--;
		return x2;
	}
}

void povrh_stog(int a, int b)
{
	push1(a);
	push2(b);
	int povrh = 0;

	while (brojac1 != 0)
	{
		a = pop1();
		b = pop2();

		if (a == b || b == 0)
		{
			povrh++;
		}
		else
		{
			push1(a - 1);
			push2(b - 1);
			push1(a - 1);
			push2(b);
		}
	}
	printf("%d \n \n", povrh);
}

int main()
{
	int t1, t2, t3, t4 = 0;
	t1 = clock();
	printf("Povrh rekurzije:\n%d\n", povrh(26, 13));
	t2 = clock();



	t3 = clock();
	printf("Povrh stoga:\n");
	povrh_stog(26, 13);
	t4 = clock();
	printf("Vrijeme rekurzije: %dms\nVrijeme stoga: %dms\n\n", t2 - t1, t4 - t3);
	system("pause");

	return 0;
}
