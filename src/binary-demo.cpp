#include <iostream>
#include "binary-demo.h"



void binary_demo_hello(){
    std::cout << "binary-demo/0.1.0: Hello World from binary_demo_hello!" << std::endl;    
}

void binary_demo_print_vector(const std::vector<std::string> &strings) {
    for(std::vector<std::string>::const_iterator it = strings.begin(); it != strings.end(); ++it) {
        std::cout << "binary_demo/0.1.0 " << *it << std::endl;
    }
}
