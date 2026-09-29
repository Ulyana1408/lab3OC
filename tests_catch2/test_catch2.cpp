#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/math_func.h"

TEST_CASE("Линейная интерполяция: базовые случаи") {
    // Левая точка
    REQUIRE(linear_interp(0, 0, 10, 100, 0) == Approx(0.0));
    
    // Правая точка
    REQUIRE(linear_interp(0, 0, 10, 100, 10) == Approx(100.0));
    
    // Середина
    REQUIRE(linear_interp(0, 0, 10, 100, 5) == Approx(50.0));
}

TEST_CASE("Линейная интерполяция: четверти") {
    REQUIRE(linear_interp(0, 0, 10, 100, 2.5) == Approx(25.0));
    REQUIRE(linear_interp(0, 0, 10, 100, 7.5) == Approx(75.0));
}

TEST_CASE("Линейная интерполяция: отрицательные значения") {
    REQUIRE(linear_interp(-10, -100, 10, 100, 0) == Approx(0.0));
    REQUIRE(linear_interp(-10, -100, 10, 100, -5) == Approx(-50.0));
}

TEST_CASE("Линейная интерполяция: экстраполяция") {
    // x выходит за пределы [x0, x1] — это тоже работает
    REQUIRE(linear_interp(0, 0, 10, 100, 15) == Approx(150.0));
    REQUIRE(linear_interp(0, 0, 10, 100, -5) == Approx(-50.0));
}

TEST_CASE("Линейная интерполяция: ошибка при x0 == x1") {
    // Ожидаем, что функция выбросит исключение
    REQUIRE_THROWS_AS(
        linear_interp(5, 0, 5, 100, 5),
        std::invalid_argument
    );
}