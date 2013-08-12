#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LENGTH 15

using namespace std;
int d1,d2,ft = 0;
int p1,p2 = 0;
void Bresenham(int,int,int const,int const);
void carterToBipolar(int, int);

int main()
{
    Bresenham(3,4,8,7);

    return 0;
}

void carterToBipolar(int x, int y)
{
    int l1,l2;
    l1 = abs(sqrt(x*x+y*y));
    l2 = abs(sqrt(pow(LENGTH-x,2)+y*y));

        d1= p1-l1; //diferencia 1
        d2= p2-l2; //diferencia 2
        p1= l1;    //pasos 1
        p2= l2;    //pasos 2


    printf("cart(%d,%d)\tbipol(%d,%d)\t D(%d,%d) \n",x,y,l1,l2,d1,d2);

}

void Bresenham(int x1,int y1,int const x2,int const y2)
{
    int delta_x(x2 - x1);
    // if x1 == x2, then it does not matter what we set here
    signed char const ix((delta_x > 0) - (delta_x < 0));
    delta_x = abs(delta_x) << 1;

    int delta_y(y2 - y1);
    // if y1 == y2, then it does not matter what we set here
    signed char const iy((delta_y > 0) - (delta_y < 0));
    delta_y = abs(delta_y) << 1;

    carterToBipolar(x1,y1);

    if (delta_x >= delta_y)
    {
        // error may go below zero
        int error(delta_y - (delta_x >> 1));

        while (x1 != x2)
        {
            if ((error >= 0) && (error || (ix > 0)))
            {
                error -= delta_x;
                y1 += iy;
            }
            // else do nothing

            error += delta_y;
            x1 += ix;
            carterToBipolar(x1,y1);
        }
    }
    else
    {
        // error may go below zero
        int error(delta_x - (delta_y >> 1));

        while (y1 != y2)
        {
            if ((error >= 0) && (error || (iy > 0)))
            {
                error -= delta_y;
                x1 += ix;
            }
            // else do nothing
            error += delta_x;
            y1 += iy;
            carterToBipolar(x1,y1);
        }
    }
}
