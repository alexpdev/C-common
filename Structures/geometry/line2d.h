#ifndef LINE2D_H
#define LINE2D_H

#include <math.h>
#include "point2d.h"

typedef struct Line2D {
    Point2D *start;
    Point2D *end;
} Line2D;


Point2D *get_start(Line2D *line);

Point2D *get_end(Line2D *line);

double get_length(*line2d);

#endif
