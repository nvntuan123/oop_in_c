/*
class Rectangle : public Shape -> Kế thừa trong C++
*/
#ifndef RECT_H
#define RECT_H

#include "shape.h"

struct Rectangle {
    Shape sp; // Sử dụng struct lồng nhau để thể hiện tính kế thừa.

    int IWidth;
    int IHeight;
};

typedef struct Rectangle RECTANGLE;

void rectangleCtor(RECTANGLE* const, int, int, int, int);
int getW(RECTANGLE* const);
int getH(RECTANGLE* const);

#endif
