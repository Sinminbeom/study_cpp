#include <iostream>

#pragma region IN_OUT_DEFINITIONS

#define OUT

void Compute(const int* input_data, OUT int* output_result) {
    if (input_data && output_result) {
        *output_result = (*input_data) * 2;
    }
}

void Update(OUT int* value) {
    if (value) {
        *value += 10;
    }
}

#define DTO struct

DTO UserDTO {
    std::string name_;
    int age_;

    UserDTO(const std::string& name, int age) : name_(name), age_(age) {}
};

void ProcessUser(const std::shared_ptr<UserDTO>& user) {
    user->name_ = "ShinMinBeom";
    user->age_ += 1;
}

#pragma endregion

/*
int main() {
    int input = 5;
    int result = 0;

    Compute(&input, &result);
    std::cout << "Compute result: " << result << std::endl;

    Update(&result);
    std::cout << "Updated result: " << result << std::endl;

    return 0;
}
*/