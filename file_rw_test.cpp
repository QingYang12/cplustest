//
// Created by 王浩 on 2024/9/19.
//
#include <fstream>
#include <iostream>
#include "file_rw_test.h"

void file_rw_test::read_file_test() {
    // 读取文件
    std::ifstream in("input.txt");
    if (in.is_open()) {
        std::string line;
        while (std::getline(in, line)) {
            std::cout << line << '\n';
        }
        in.close();
    } else {
        std::cerr << "Failed to open input file\n";
    }
}

void file_rw_test::write_file_test() {
    // 写入文件
    std::ofstream out("output.txt"); //或   "/path/to/directory/output.txt"
    if (out.is_open()) {
        out << "Hello, world!\n";
        out.close();
    } else {
        std::cerr << "Failed to open output file\n";
    }
}
