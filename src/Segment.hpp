#pragma once
#include "Point.hpp"
#include "GlobalCalculates.hpp"

using namespace std;

namespace Simulator
{
    void SetLenght();
    
    class Segment
    {
    public:
        Point *points[2];
        float segmentLenght;

        Segment(Point *p1, Point *p2)
        {
            points[0] = p1;
            points[1] = p2;
            SetLenght();
        }

        void SetLenght()
        {
            segmentLenght = Distance(points[0]->position,points[1]->position);
        }
    };
}