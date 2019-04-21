#ifndef Point_h
#define Point_h

class Point {

private:
    float  x, y;
    
public:
    Point(float  x, float  y);  
    float  getX();
    float  getY();	
    void setX(float  x);
    void setY(float  y);
    void shiftX(float  x_adj);
    void shiftY(float  y_adj);
};

#endif



