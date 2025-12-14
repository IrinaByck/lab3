#include <iostream>
#include <vector>
#include <memory>
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    std::cout << "Сколько фигур создать? ";
    int count;
    std::cin >> count;
    for (int i = 0; i < count; i++) {
        std::cout << "\nФигура #" << (i + 1) << ":\n";
        std::cout << "Выберите тип (1-Квадрат, 2-Прямоугольник, 3-Трапеция): ";
        int type;
        std::cin >> type;
        if (type == 1) {
            figures.push_back(std::make_unique<Square>());
        } else if (type == 2) {
            figures.push_back(std::make_unique<Rectangle>());
        } else if (type == 3) {
            figures.push_back(std::make_unique<Trapezoid>());
        } else {
            std::cout << "Неверный тип! Пропускаем.\n";
            continue;
        }
        std::cout << "Введите 8 координат через пробел: ";
        std::cin >> *figures.back();
    }
    std::cout << "\n=== ИНФОРМАЦИЯ О ФИГУРАХ ===\n\n";
    double total_area = 0;
    for (size_t i = 0; i < figures.size(); i++) {
        std::cout << "Фигура " << i << ":\n";
        std::cout << "  Вершины: " << *figures[i] << "\n";
        auto center = figures[i]->getCenter();
        std::cout << "  Центр: (" << center.first << ", " << center.second << ")\n";
        double area = static_cast<double>(*figures[i]);
        std::cout << "  Площадь: " << area << "\n\n";
        total_area += area;
    }
    std::cout << "Общая площадь всех фигур: " << total_area << "\n\n";
    if (!figures.empty()) {
        std::cout << "Какую фигуру удалить? Введите индекс (0-" << (figures.size() - 1) << "): ";
        int index;
        std::cin >> index;
        if (index >= 0 && index < (int)figures.size()) {
            figures.erase(figures.begin() + index);
            std::cout << "Фигура " << index << " удалена.\n";
        } else {
            std::cout << "Неверный индекс!\n";
        }
    }
    std::cout << "\nПрограмма завершена.\n";
    return 0;
}
