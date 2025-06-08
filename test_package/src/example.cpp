#include "binary-demo.h"
#include <vector>
#include <string>

int main() {
    binary_demo();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    binary_demo_print_vector(vec);
}
