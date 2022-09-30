#include <filesystem>
#include <fstream>
#include "json2hpp.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) return -1;

    std::string name = argv[1];
    std::filesystem::path input = argv[2];
    std::filesystem::path output = argv[3];
    
    input = std::filesystem::absolute(input);
    output = std::filesystem::absolute(output);

    std::ifstream in{ input };
    std::ofstream out{ output };

    std::string json{ std::istreambuf_iterator<char>{ in }, std::istreambuf_iterator<char>{} };

    auto res = kaixo::json::parse(json);
    if (res) out << kaixo::json2hpp::generate(name, res.value());
    return 0;
}