// #include "header_file/rectangle.h"

// void rectangleCtor(RECTANGLE* const RTHIS, int IX, int IY, int IWidth, int IHeight)
// { 
//     shapeCtor(&RTHIS->sp , IX, IY); // Gọi lại hàm khởi tạo có tham số của class cha.

//     RTHIS->IWidth = IWidth;
//     RTHIS->IHeight = IHeight;
// }

// int getW(RECTANGLE* const RTHIS)
// {
//     return RTHIS->IWidth;
// }

// int getH(RECTANGLE* const RTHIS)
// {
//     return RTHIS->IHeight;
// }

#include "header_file/rectangle.h" /* Rectangle class interface */
#include <stdio.h>                 /* for printf() */

/* Rectangle's prototypes of its virtual functions */
/* NOTE: the "me" pointer has the type of the superclass to fit the vtable */
static uint32_t Rectangle_area_(Shape const *const me); // 1
static void Rectangle_draw_(Shape const *const me); // 2

/* constructor */
void Rectangle_ctor(RECTANGLE *const me, int16_t x, int16_t y, uint16_t width, uint16_t height)
{
    // 3
    static struct ShapeVtbl const vtbl = {/* vtbl of the Rectangle class */
    &Rectangle_area_,
    &Rectangle_draw_};

    Shape_ctor(&me->sp, x, y); /* 4 call the superclass' ctor */
    me->sp.vptr = &vtbl;       /* 5 override the vptr */
    me->IWidth = width;
    me->IHeight = height;
}

/* Rectangle's class implementations of its virtual functions... */
static uint32_t Rectangle_area_(Shape const *const me)
{
    RECTANGLE const *const me_ = (RECTANGLE const *)me; /* 6 explicit downcast */
    return (uint32_t)me_->IWidth * (uint32_t)me_->IHeight;
}

static void Rectangle_draw_(Shape const *const me)
{
    RECTANGLE const *const me_ = (RECTANGLE const *)me; /* explicit downcast */
    printf("Rectangle_draw_(x=%d,y=%d,width=%d,height=%d)\n", me_->sp.x, me_->sp.y, me_->IWidth, me_->IHeight);
}
