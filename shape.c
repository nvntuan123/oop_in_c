// #include "header_file/shape.h"

// void shapeCtor(SHAPE* const THIS, int IX, int IY)
// {
//     THIS->_IX = IX;
//     THIS->_IY = IY;
// }

// int shapeGetX(SHAPE* const THIS)
// {
//     return THIS->_IX;
// }

// int shapeGetY(SHAPE* const THIS)
// {
//     return THIS->_IY;
// }

#include "header_file/shape.h"
#include <assert.h>

/* Shape's prototypes of its virtual functions - Nguyên mẫu của Shape về các chức năng ảo của nó*/
static uint32_t Shape_area_(Shape const *const me); // 1
static void Shape_draw_(Shape const *const me); // 2

/* constructor */
void Shape_ctor(Shape *const me, int16_t x, int16_t y)
{
    // 3
    static struct ShapeVtbl const vtbl = {/* vtbl of the Shape class - vtbl của lớp Hình dạng */
    &Shape_area_,
    &Shape_draw_};

    // 4
    me->vptr = &vtbl; /* "hook" the vptr to the vtbl - "nối" vptr vào vtbl */
    me->x = x;
    me->y = y;
}

/* move-by operation - hoạt động di chuyển */
void Shape_moveBy(Shape *const me, int16_t dx, int16_t dy)
{
    me->x += dx;
    me->y += dy;
}

/* Shape class implementations of its virtual functions... - Định dạng triển khai lớp của các chức năng ảo của nó ... */
static uint32_t Shape_area_(Shape const *const me)
{
    // 5
    assert(0); /* purely-virtual function should never be called - hàm thuần-ảo không bao giờ được gọi */
    return 0U; /* to avoid compiler warnings - để tránh cảnh báo trình biên dịch */
}

static void Shape_draw_(Shape const *const me)
{
    // 6
    assert(0); /* purely-virtual function should never be called - hàm thuần-ảo không bao giờ được gọi */
}

/* the following code finds the largest-area shape in the collection - đoạn mã sau tìm hình dạng có diện tích lớn nhất trong bộ sưu tập */
Shape const *largestShape(Shape const *shapes[], uint32_t nShapes)
{
    Shape const *s = (Shape *)0;
    uint32_t max = 0U;
    uint32_t i;
    for (i = 0U; i < nShapes; ++i)
    {
        // 7
        uint32_t area = Shape_area(shapes[i]); /* virtual call - cuộc gọi ảo */
        if (area > max)
        {
            max = area;
            s = shapes[i];
        }
    }
    return s; /* the largest shape in the array shapes[] - hình dạng lớn nhất trong các mảng shapes[] */
}

/* The following code will draw all Shapes on the screen - Đoạn mã sau sẽ vẽ tất cả các Hình dạng trên màn hình */
void drawAllShapes(Shape const *shapes[], uint32_t nShapes)
{
    uint32_t i;
    for (i = 0U; i < nShapes; ++i)
    {
        // 8
        Shape_draw(shapes[i]); /* virtual call - cuộc gọi ảo */
    }
}
