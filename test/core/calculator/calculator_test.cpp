// Copyright [2025] <mbshin>

#include <gtest/gtest.h>
#include "core/calculator/calculator.h"

// Test fixture class
class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc; // Common setup for all tests
};

// Test addition
TEST_F(CalculatorTest, TestAdd) {
    EXPECT_EQ(calc.Add(2, 3), 5);
    EXPECT_EQ(calc.Add(-1, 1), 0);
    EXPECT_EQ(calc.Add(0, 0), 0);
}

// Test subtraction
TEST_F(CalculatorTest, TestSubtract) {
    EXPECT_EQ(calc.Subtract(5, 3), 2);
    EXPECT_EQ(calc.Subtract(0, 1), -1);
}

// Test multiplication
TEST_F(CalculatorTest, TestMultiply) {
    EXPECT_EQ(calc.Multiply(4, 3), 12);
    EXPECT_EQ(calc.Multiply(-2, 3), -6);
    EXPECT_EQ(calc.Multiply(0, 5), 0);
}

// Test division
TEST_F(CalculatorTest, TestDivide) {
    EXPECT_EQ(calc.Divide(6, 3), 2);
    EXPECT_THROW(calc.Divide(1, 0), std::invalid_argument); // Exception test
}

// Main function for running all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
