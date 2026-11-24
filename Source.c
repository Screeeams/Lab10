#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
double task_one_func1(double x);
double task_one_func2(double x);
double asin_n(double x, int N);
double asin_eps(double x, double eps);
int area(int x, int y);
int definition();
int draw(char symbol, int side, int angle);

int homework();
int main() {
	setlocale(LC_ALL, "RUS");
	double x;
	puts("TASK ONE-------------------------------------------------------------------------------------");
	puts("Введите число: ");
	scanf_s("%lf", &x);
	printf("Значение функции равно: %lf\n", task_one_func1(x));
	printf("Значение второй функции равно: %lf\n", task_one_func2(x));

	double x2, eps;
	int N;
	puts("TASK TWO-------------------------------------------------------------------------------------");
	puts("Введите x (от -1 до 1): ");
	scanf_s("%lf", &x2);
	puts("Введите N: ");
	scanf_s("%d", &N);
	puts("Введите eps: ");
	scanf_s("%lf", &eps);

	double etalon = asin(x2);
	double res1 = asin_n(x2, N);
	double res2 = asin_eps(x2, eps);

	printf("\nСтандартный asin(x): %lf\n", etalon);
	printf("Через N шагов: %lf (отклонение: %lf)\n", res1, fabs(etalon - res1));
	printf("С точностью eps: %lf (отклонение: %lf)\n", res2, fabs(etalon - res2));

	puts("HOMEWORK-------------------------------------------------------------------------------------");
	homework();
	
}
double task_one_func1(double x) {
	double y;
	if (x <= 3) {
		y = pow(x, 2.0) - (3.0 * x) + 9.0;
	}
	if (x > 3) {
		y = 1.0 / (pow(x, 3.0) + 3.0);
	}
	return y;
}
double task_one_func2(double x) {
	double y;
	y = x * exp(sin(pow(x, 2)));
	return y;
}
double asin_n(double x, int N) {
	double term = x;
	double sum = x;
	for (int n = 1; n < N; n++) {
		term = term * (2.0 * n - 1.0) * (2.0 * n - 1.0) * x * x / (2.0 * n * (2.0 * n + 1.0));
		sum += term;
	}
	return sum;
}
double asin_eps(double x, double eps) {
	double term = x;
	double sum = x;
	double etalon = asin(x);
	int n = 1;
	printf("\n N |   asin_N   | отклонение\n");
	printf("-------------------------------\n");
	printf("%2d | %10.6lf | %+.4e\n", n, sum, sum - etalon);
	while (fabs(term) > eps) {
		term = term * (2.0 * n - 1.0) * (2.0 * n - 1.0) * x * x / (2.0 * n * (2.0 * n + 1.0));
		sum += term;
		n++;
		printf("%2d | %10.6lf | %+.4e\n", n, sum, sum - etalon);
	}
	return sum;
}
int area(int x, int y) {
	int res = x * y;
	printf("Площадь фигуры равняется: %d", res);
}
int definition() {
	puts("Прямоугольник — четырёхугольник, у которого все углы прямые(равны 90°).Слово «прямоугольник» является переводом лат.rectangulus, которое, в свою очередь, представляет собой комбинацию лат.«rectus»(прямой, правильный) и лат.«angulus»(угол). В евклидовой геометрии для того, чтобы четырёхугольник был прямоугольником, достаточно, чтобы хотя бы три его угла были прямые, тогда четвёртый угол в силу теоремы о сумме углов многоугольника также будет равен 90°.)");
}
int draw(char symbol, int side, int angle) {
int  shift, spaces;
	
	shift = angle;


	for (int row = 0; row < side; row++) {
		spaces = row * shift;
		for (int i = 0; i < spaces; i++) {
			printf(" ");
		}
		for (int col = 0; col < side; col++) {
			if (row == 0 || row == side - 1 || col == 0 || col == side - 1) {
				printf("%c ", symbol);
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}

}
int homework() {
	int a;
	int x, y;
	char symbol;
	int side, angle, shift, spaces;
	puts("Введите 1 чтобы посчитать площадь, 2 чтобы вывести определение фигуры, 3 чтобы нарисовать фигуру");
	scanf_s("%d", &a);
	puts("Введите длину и ширину фигуры: ");
	scanf_s("%d %d", &x, &y);
	if (a == 1) {
		area(x, y);
	}
	if (a == 2) {
		definition();
	}
	if (a == 3) {
		printf("Введите символ для построения фигуры: ");
		scanf_s(" %c", &symbol, 1);
		printf("Введите количество символов фигуры в длину и в ширину: ");
		scanf_s("%d", &side);
		printf("Введите сдвиг фигуры (1, 2, 3, 4): ");
		scanf_s("%d", &angle);
		draw(symbol, side, angle);

	}
}
