// #ifndef SHAPE_H
// #define SHAPE_H

// // Class Shape
// struct Shape {
//     int _IX;
//     int _IY;
// };

// typedef struct Shape SHAPE;

// // Default constructor.
// void shapeCtor(SHAPE* const, int, int);

// int shapeGetX(SHAPE* const);
// int shapeGetY(SHAPE* const);

// #endif

#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>
/* Shape's attributes... */
struct ShapeVtbl; /* forward declaration */

typedef struct {
    // 1
    struct ShapeVtbl const *vptr; /* <== Shape's Virtual Pointer */
    int16_t x; /* x-coordinate of Shape's position */
    int16_t y; /* y-coordinate of Shape's position */
} Shape;

/* Shape's virtual table */
struct ShapeVtbl { // 2
    uint32_t (*area)(Shape const * const me); // 3
    void (*draw)(Shape const * const me); // 4
};

/* Shape's operations (Shape's interface)... */
void Shape_ctor(Shape * const me, int16_t x, int16_t y);
void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy);

static inline uint32_t Shape_area(Shape const * const me) {
    return (*me->vptr->area)(me); // 5
}

static inline void Shape_draw(Shape const * const me) {
    (*me->vptr->draw)(me); // 6
}

/* generic operations on collections of Shapes */
Shape const *largestShape(Shape const *shapes[], uint32_t nShapes); // 7
void drawAllShapes(Shape const *shapes[], uint32_t nShapes); // 8

#endif /* SHAPE_H */
