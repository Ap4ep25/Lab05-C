#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    double mas[100];
    double a, x, d, xmin, xmax, maxv, minv;
    int c, s, i, counter=0;
    char s_s[10], xmin_s[10], xmax_s[10], st[200]={0}, l[100], tmp[100], *key;

    do {

        printf("Для выхода из программы, введите 0\n");
        printf("Формула 1: Рассчет G, введите 1\n");
        printf("Формула 2: Рассчет F, введите 2\n");
        printf("Формула 3: Рассчет Y, введите 3\n");
        scanf("%d", &c);

        if (c == 0) {
            printf("До свидания!");
            break;
        }


        if ((c < 0) || (c > 3)) {
            printf("Неверно введено значение, введите его заново!\n");
            scanf("%d", &c);
        } else
            printf("Введите минимальное значение х: ");
        scanf("%s", &xmin_s);
        printf("Введите максимальное значение x: ");
        scanf("%s", &xmax_s);
        fflush(stdin);
        xmin = atof(xmin_s);
        xmax = atof(xmax_s);

        printf("Введите а: ");
        scanf("%lf", &a);

        if (xmin_s >= xmax_s) {
            printf("Максимальное значение х должно быть больше минимального\n");
            printf("Введите еще раз х: ");
            scanf("%s", &xmax_s);
            fflush(stdin);
            xmax = atof(xmax_s);
        }
        printf("Введите колличество шагов: ");
        scanf("%s", &s_s);
        fflush(stdin);
        s = atoi(s_s);

        if (s <= 0) {
            printf("Число шагов не может быть меньше или равно 0\n");
            printf("Введите число шагов еще раз: ");
            scanf("%s", &s_s);
            fflush(stdin);


        }
        if (s > 100) {
            printf("Допустимое кол-во шагов не должно превышать 100! Введите другое значение.");
            break;
        }


        switch (c) {
            case 1: {
                for (x = xmin, i = 0;
                     x <= xmax & i <= s; x += (xmax - xmin) / (s - 1), i++) {
                    d = (10 * pow(a, 2) + 11 * a * x + 3 * pow(x, 2));
                    if (d == (10e-6)) {
                        printf("Введите другие значения \n");
                        break;
                    }
                    mas[i] = (5 * (-2 * pow(a, 2) + a * x + 3 * pow(x, 2))/d);
                    printf("x = %lf\t", x);
                    printf("G=%lf\n", mas[i]);
                }
                break;
                case 2: {
                    for (x = xmin, i = 0; x <= xmax; x += (xmax - xmin) / (s - 1), i++) {
                        mas[i] = sin(10 * pow(a, 2) - 7 * a * x + pow(x ,2));
                        printf("x = %0.18lf\t", x);
                        printf("F= %0.18lf\n", mas[i]);
                    }
                    break;
                    case 3: {
                        for (x = xmin, i = 0; x <= xmax; x += (xmax - xmin) / (s - 1), i++) {
                            mas[i] = atan(45 * pow(a, 2) + 79 * a * x + 30 * pow(x, 2));
                            printf("x = %lf\t", x);
                            printf("Y= %lf\n", mas[i]);
                        }
                        break;

                    }
                }
            }
        }
        for(i = 0;i <= s;i++) {
            sprintf(l, "%lf", mas[i]);
            strcat(st, l);
        }
        printf("Result =  %s\n", st);

        for (i = 0, minv = mas[0], maxv = mas[0]; i < s; i++) {
            if (mas[i] > maxv)
                maxv = mas[i];
            if (mas[i] < minv)
                minv = mas[i];
        }
        printf("Макс. значение: %0.18lf\n", maxv);
        printf("Мин. значение: %0.18lf\n", minv);
        printf("Введите шаблон: \n");
        scanf("%s", &tmp);
        key = strstr(st, tmp);

        while(key) {
            sprintf(st, key +1);
            counter++;
            key = strstr(st, tmp);
        }
        printf("%d\n", counter);

    } while (c != 0);
    return 0;
}