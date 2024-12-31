class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int cRight = xCenter + radius;
        int cLeft = xCenter - radius;
        int cTop = yCenter + radius;
        int cBottom = yCenter - radius;

        int rRight = x2;
        int rLeft = x1;
        int rTop = y2;
        int rBottom = y1;

        bool circleWithinRectX = (xCenter >= rLeft && xCenter <= rRight);
        bool circleWithinRectY = (yCenter >= rBottom && yCenter <= rTop);

        bool cornerInsideCircle = 
        (pow(x1 - xCenter, 2) + pow(y1 - yCenter, 2) <= pow(radius, 2)) ||
        (pow(x1 - xCenter, 2) + pow(y2 - yCenter, 2) <= pow(radius, 2)) ||
        (pow(x2 - xCenter, 2) + pow(y1 - yCenter, 2) <= pow(radius, 2)) ||
        (pow(x2 - xCenter, 2) + pow(y2 - yCenter, 2) <= pow(radius, 2));

        bool rectContainsCircle = 
        (xCenter >= rLeft && xCenter <= rRight && yCenter >= rBottom && yCenter <= rTop);

        bool sideOverlap = 
        (circleWithinRectX && (yCenter >= rBottom - radius && yCenter <= rTop + radius)) ||
        (circleWithinRectY && (xCenter >= rLeft - radius && xCenter <= rRight + radius));

        return cornerInsideCircle || rectContainsCircle || sideOverlap;
    }
};
