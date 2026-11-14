#include <iostream>
#include <vector>
#include <windows.h>
#include "TriangleClasses.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        std::cout << "=== ЛАБОРАТОРНА РОБОТА №10 (ПОЛІМОРФІЗМ) ===\n\n";

        std::vector<Triangle*> triangles;

        triangles.push_back(new TriangleByVertices({ 0, 0 }, { 4, 0 }, { 0, 3 }));
        triangles.push_back(new TriangleBySides(5, 6, 7));
        triangles.push_back(TriangleBySides::createByMedians(7.5, 6.0, 4.5));
        triangles.push_back(new RightTriangle(3, 4));

        int i = 1;
        for (const auto& t : triangles) {
            std::cout << "--- Трикутник №" << i++ << " ---\n";
            std::cout << "Сторони (a, b, c): " << t->getSideA() << ", "
                << t->getSideB() << ", " << t->getSideC() << "\n";
            std::cout << "Периметр: " << t->getPerimeter() << "\n";
            std::cout << "Площа: " << t->getArea() << "\n";
            std::cout << "Медіана до сторони 'a': " << t->getMedian('a') << "\n";
            std::cout << "Середня лінія, паралельна 'a': " << t->getMidSegment('a') << "\n";

            if (auto rt = dynamic_cast<RightTriangle*>(t)) {
                std::cout << "[Це прямокутний трикутник]\n";
                std::cout << "Радіус вписаного кола: " << rt->getInscribedRadius() << "\n";
                std::cout << "Радіус описаного кола: " << rt->getCircumscribedRadius() << "\n";
            }
            std::cout << "\n";
        }

        for (auto t : triangles) {
            delete t;
        }

    }
    catch (const std::exception& ex) {
        std::cerr << "Помилка: " << ex.what() << "\n";
    }

    return 0;
}