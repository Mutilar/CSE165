#ifndef Point_h
#define Point_h

class Point {

private:
    int x, y;
    
public:
    Point(int x, int y);  
    int getX();
    int getY();	
    void setX(int x);
    void setY(int y);
    void shiftX(int x_adj);
    void shiftY(int y_adj);
};

#endif



