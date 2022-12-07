#include "shape.h"
#include "pointshape.h"
#include "lineshape.h"
#include "rectshape.h"
#include "elipseshape.h"
#include "linewithelipseshape.h"
#include "cubeshape.h"

Shape::Shape()
{
}

Shape::~Shape()
{
}

void Shape::Set(int x1, int y1, int x2, int y2)
{
    xs1 = x1;
    ys1 = y1;
    xs2 = x2;
    ys2 = y2;
}

int Shape::getXs1() const
{
    return xs1;
}

int Shape::getYs1() const
{
    return ys1;
}

int Shape::getXs2() const
{
    return xs2;
}

int Shape::getYs2() const
{
    return ys2;
}

Shape *Shape::createShape(DrawType type)
{
    switch (type){
    case DrawType::POINT:
        return new PointShape;
        break;
    case DrawType::LINE:
        return new LineShape;
        break;
    case DrawType::RECT:
        return new RectShape;
        break;
    case DrawType::ELIPSE:
        return new ElipseShape;
        break;
    case DrawType::LINEWITHELIPSE:
        return (ElipseShape *)new LineWithElipseShape;
        break;
    case DrawType::CUBE:
        return (LineShape *)new CubeShape;
        break;
    }
}
