// Copyright [2025] <mbshin>

#ifndef CPP_STUDY_SRC_CORE_CALCULATOR_CALCULATOR_H_
#define CPP_STUDY_SRC_CORE_CALCULATOR_CALCULATOR_H_

class Calculator {
 public:
    int Add(int a, int b) { return a + b; }
    int Subtract(int a, int b) { return a - b; }
    int Multiply(int a, int b) { return a * b; }
    int Divide(int a, int b) {
        if (b == 0) throw std::invalid_argument("Division by zero");
        return a / b;
    }
};

#endif  // CPP_STUDY_SRC_CORE_CALCULATOR_CALCULATOR_H_
