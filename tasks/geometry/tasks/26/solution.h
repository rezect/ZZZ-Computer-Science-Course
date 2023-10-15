#pragma once

#include <stdio.h>

const int INITIAL_VULUE_I = -10;
const int INITIAL_VULUE_J = -10;
const int INITIAL_VULUE_L = 6;
const double CENTER_COORDINATES_Y = 0.0;
const double CENTER_COORDINATES_X = 20.0;
const double COORDINATES_A_X = 10.0;
const double COORDINATES_B_X = 30.0;
const double COORDINATES_C_Y = 5.0;
const double COORDINATES_D_Y = -5.0;
const int MAX_ITERATIONS = 50;
const int THIRTY = 30;
const int TWENTY_FIVE = 25;
const int TEN = 10;
const int THIRTY_FIVE = 35;

int Mod(int a, int b) {
    if (a % b != 0) {
        return (a > 0) ? a % b : b + (a % b);
    } else {
        return 0;
    }
}

int Abs(int a) {
    return (a >= 0) ? a : -a;
}

int Max(int a, int b) {
    return (a >= b) ? a : b;
}

int Min(int a, int b) {
    return (a >= b) ? b : a;
}

typedef struct {
    int x;
    int y;
} Point;

int CheckZone(Point p) {
    double center_difference_x = (p.x - CENTER_COORDINATES_X) * (p.x - CENTER_COORDINATES_X);
    double center_difference_y = (p.y - CENTER_COORDINATES_Y) * (p.y - CENTER_COORDINATES_Y);
    double square_of_the_x = (CENTER_COORDINATES_X - COORDINATES_A_X) * (CENTER_COORDINATES_X - COORDINATES_A_X);
    double square_of_the_y = (CENTER_COORDINATES_Y - COORDINATES_D_Y) * (CENTER_COORDINATES_Y - COORDINATES_D_Y);
    double equation_x = center_difference_x / square_of_the_x;
    double equation_y = center_difference_y / square_of_the_y;
    double summ_of_coordinates = equation_x + equation_y;
    return (summ_of_coordinates <= 1.0);
}

int Task() {
    int i = INITIAL_VULUE_I;
    int j = INITIAL_VULUE_J;
    int l = INITIAL_VULUE_L;
    Point p;
    p.x = i;
    p.y = j;
    for (int k = 1; k <= MAX_ITERATIONS; ++k) {
        i = Abs(Max(Mod(Min(p.x + p.y, p.x + l), THIRTY), Mod(Max(p.x + l, p.y + k), TWENTY_FIVE)));
        j = Mod(Abs(p.x + k), TEN) + Mod(Abs(p.y + k), TEN) + Mod(Abs(l + k), TEN);
        l = Mod(p.x * p.x * p.x + p.y * p.y * p.y + l * l * l - k, THIRTY_FIVE);
        p.x = i;
        p.y = j;
        if (CheckZone(p)) {
            printf("x = %d, y = %d, l = %d, result = 1, number of iteration = %d\n", p.x, p.y, l, k);
        } else {
            printf("x = %d, y = %d, l = %d, result = 0\n", p.x, p.y, l);
        }
    }
    return 0;
}
