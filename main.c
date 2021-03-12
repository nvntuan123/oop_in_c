// #include <stdio.h>
// #include "header_file/shape.h"
// #include "header_file/rectangle.h"

// int main()
// {
//     // SHAPE sp;
//     // //sp._IX = 1;
//     // //sp._IY = 2;
//     // shapeCtor(&sp, 6, 8);

//     // printf("X = %d\n", shapeGetX(&sp));
//     // printf("Y = %d", shapeGetY(&sp));

//     RECTANGLE r;
//     rectangleCtor(&r, 1, 2, 6, 8); // r, x, y, w, h.
//     printf("X = %d\n", r.sp._IX);
//     printf("Y = %d\n", r.sp._IY);
//     printf("Width = %d\n", getW(&r));
//     printf("Height = %d\n", getH(&r));
// }

#include "header_file/rectangle.h"   /* Rectangle class interface */
//#include "circle.h" /* Circle class interface */
#include <stdio.h>  /* for printf() */

int main()
{
    RECTANGLE r1, r2;        /* multiple instances of Rectangle */
    //Circle c1, c2;           /* multiple instances of Circle */
    Shape const *shapes[] = {/* collection of shapes */
    //&c1.sp,
    &r2.sp,
    //&c2.super,
    &r1.sp
    };

    Shape const *s;

    /* instantiate rectangles... */
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);
    
    /* instantiate circles... */
    // Circle_ctor(&c1, 1, -2, 12);
    // Circle_ctor(&c2, 1, -3, 6);

    s = largestShape(shapes, sizeof(shapes) / sizeof(shapes[0]));
    printf("largetsShape s(x=%d,y=%d)\n", Shape_getX(&s), Shape_getY(&s));
    drawAllShapes(shapes, sizeof(shapes) / sizeof(shapes[0]));
}
