#include "TriangleClasses.h"

double Triangle::getPerimeter() const {
    return getSideA() + getSideB() + getSideC();
}

double Triangle::getArea() const {
    double p = getPerimeter() / 2.0;
    double a = getSideA(), b = getSideB(), c = getSideC();
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::getMedian(char sideName) const {
    double a = getSideA(), b = getSideB(), c = getSideC();
    if (sideName == 'a' || sideName == 'A')
        return 0.5 * std::sqrt(2 * b * b + 2 * c * c - a * a);
    if (sideName == 'b' || sideName == 'B')
        return 0.5 * std::sqrt(2 * a * a + 2 * c * c - b * b);
    if (sideName == 'c' || sideName == 'C')
        return 0.5 * std::sqrt(2 * a * a + 2 * b * b - c * c);
    return 0.0;
}

double Triangle::getMidSegment(char sideName) const {
    if (sideName == 'a' || sideName == 'A') return getSideA() / 2.0;
    if (sideName == 'b' || sideName == 'B') return getSideB() / 2.0;
    if (sideName == 'c' || sideName == 'C') return getSideC() / 2.0;
    return 0.0;
}

double TriangleByVertices::distance(Point a, Point b) const {
    return std::sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

TriangleByVertices::TriangleByVertices(Point pt1, Point pt2, Point pt3) : p1(pt1), p2(pt2), p3(pt3) {
    double a = distance(p2, p3);
    double b = distance(p1, p3);
    double c = distance(p1, p2);
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::invalid_argument("Трикутник з такими вершинами не існує!");
    }
}

double TriangleByVertices::getSideA() const { return distance(p2, p3); }
double TriangleByVertices::getSideB() const { return distance(p1, p3); }
double TriangleByVertices::getSideC() const { return distance(p1, p2); }

TriangleBySides::TriangleBySides(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        throw std::invalid_argument("Некоректні довжини сторін трикутника!");
    }
}

TriangleBySides* TriangleBySides::createByMedians(double ma, double mb, double mc) {
    if (ma <= 0 || mb <= 0 || mc <= 0) {
        throw std::invalid_argument("Медіани мають бути додатними числами!");
    }
    double sideA = (2.0 / 3.0) * std::sqrt(2 * mb * mb + 2 * mc * mc - ma * ma);
    double sideB = (2.0 / 3.0) * std::sqrt(2 * ma * ma + 2 * mc * mc - mb * mb);
    double sideC = (2.0 / 3.0) * std::sqrt(2 * ma * ma + 2 * mb * mb - mc * mc);
    return new TriangleBySides(sideA, sideB, sideC);
}

RightTriangle::RightTriangle(double leg1, double leg2)
    : TriangleBySides(leg1, leg2, std::sqrt(leg1* leg1 + leg2 * leg2)) {
    if (leg1 <= 0 || leg2 <= 0) {
        throw std::invalid_argument("Катети прямокутного трикутника мають бути додатними!");
    }
}

double RightTriangle::getInscribedRadius() const {
    return (a + b - c) / 2.0;
}

double RightTriangle::getCircumscribedRadius() const {
    return c / 2.0;
}