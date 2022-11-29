#ifndef POINT2D_H
#define POINT2D_H

typedef struct Point2D {
    double x;
    double y;
}

Point2D *newPoint2d(double x, double y);

double get_x_point(Point2D* point);

double get_y_point(Point2D* point);

void set_x_point(Point2D *point, double x);

void set_y_point(Point2D *point, double y);

Point2D *point_sum(Point2D *p1, Point2D *p2);

Point2D *point_diff(Point2D *p1, Point2D *p2);

#endif
