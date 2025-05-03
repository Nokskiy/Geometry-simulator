#pragma once
#include "Point.hpp"

using namespace std;

namespace Simulator
{
    class Segment
    {
    private:
        /* data */
    public:
        Point* points[2];

        Segment(Point *p1,Point *p2)
        {
            points[0] = p1;
            points[1] = p2;
        }
    };
}