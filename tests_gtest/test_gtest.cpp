#include <gtest/gtest.h>
#include "../src/math_func.h"

// Базовые случаи
TEST(LinearInterpTest, BasicCases) {
    // Левая точка
    EXPECT_NEAR(linear_interp(0, 0, 10, 100, 0), 0.0, 1e-9);
    
    // Правая точка
    EXPECT_NEAR(linear_interp(0, 0, 10, 100, 10), 100.0, 1e-9);
    
    // Середина
    EXPECT_NEAR(linear_interp(0, 0, 10, 100, 5), 50.0, 1e-9);
}

// Четверти
TEST(LinearInterpTest, Quarters) {
    EXPECT_NEAR(linear_interp(0, 0, 10, 100, 2.5), 25.0, 1e-9);
    EXPECT_NEAR(linear_interp(0, 0, 10, 100, 7.5), 75.0, 1e-9);
}

// Отрицательные значения
TEST(LinearInterpTest, NegativeValues) {
    EXPECT_NEAR(linear_interp(-10, -100, 10, 100, 0), 0.0, 1e-9);
    EXPECT_NEAR(linear_interp(-10, -100, 10, 100, -5), -50.0, 1e-9);
}

// Экстраполяция
TEST(LinearInterpTest, Extrapolation) {
    EXPECT_NEAR(linear_interp(0, 0, 10, 100, 15), 150.0, 1e-9);
    EXPECT_NEAR(linear_interp(0, 0, 10, 100, -5), -50.0, 1e-9);
}

// Проверка ошибки (x0 == x1)
TEST(LinearInterpTest, ThrowsOnVerticalLine) {
    EXPECT_THROW(
        linear_interp(5, 0, 5, 100, 5),
        std::invalid_argument
    );
}