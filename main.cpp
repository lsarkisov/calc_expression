#include "src/run.cpp"

int main(int argc, char** argv) {
    std::cout << "result: "
      << expcounter::run("./test.txt") << std::endl;
}
