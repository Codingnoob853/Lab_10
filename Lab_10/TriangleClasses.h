#pragma once
#include <cmath>
#include <stdexcept>

struct Point {
    double x, y;
    Point(double px = 0.0, double py = 0.0) : x(px), y(py) {}
};

class Triangle {
public:
    virtual ~Triangle() = default;

    virtual double getSideA() const = 0;
    virtual double getSideB() const = 0;
    virtual double getSideC() const = 0;

    virtual double getPerimeter() const;
    virtual double getArea() const;

    double getMedian(char sideName) const;
    double getMidSegment(char sideName) const;
};

class TriangleByVertices : public Triangle {
private:
    Point p1, p2, p3;
    double distance(Point a, Point b) const;

public:
    TriangleByVertices(Point pt1, Point pt2, Point pt3);

    double getSideA() const override;
    double getSideB() const override;
    double getSideC() const override;
};

class TriangleBySides : public Triangle {
protected:
    double a, b, c;

public:
    TriangleBySides(double sideA, double sideB, double sideC);

    static TriangleBySides* createByMedians(double ma, double mb, double mc);

    double getSideA() const override { return a; }
    double getSideB() const override { return b; }
    double getSideC() const override { return c; }
};

class RightTriangle : public TriangleBySides {
public:
    RightTriangle(double leg1, double leg2);

    double getInscribedRadius() const;    
    double getCircumscribedRadius() const;
};