#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "lib.h"


int main() {

        char str1[] = "hello world";
        std::cout << str1 << std::endl;

        std::string str = "hello world";
        std::cout << str << std::endl;

        bool flag=true;
        std::cout<<flag<<std::endl;
        std::cout<<"test cout "<<flag<<std::endl;

        int a=0;
        //std::cout<<"请输入"<<std::endl;
        //std::cin>>a;
        //std::cout<<"输出为"<<a<<std::endl;


        int x=1;

        if(x==1){
            std::cout<<1;
        }else{
            std::cout<<2;
        }





        //1、指针的定义
        int aa = 10; //定义整型变量a

        //指针定义语法： 数据类型 * 变量名 ;
        int * p;

        //指针变量赋值
        p = &aa; //指针指向变量a的地址
        std::cout << &aa<< std::endl; //打印数据a的地址
        std::cout << p << std::endl;  //打印指针变量p

        //2、指针的使用
        //通过*操作指针变量指向的内存，*p表示解引用，找到指针指向的内存中的数据
        std::cout << "*p = " << *p << std::endl;

        *p = 100;
        std::cout << "a = " << aa << std::endl; //100
        std::cout << "*p = " << *p << std::endl; //100

        std::cout << *p << std::endl; //* 解引用
        std::cout << sizeof(p) << std::endl;
        std::cout << sizeof(char *) << std::endl;
        std::cout << sizeof(float *) << std::endl;
        std::cout << sizeof(double *) << std::endl;

        //测试 调另一个cpp中的方法
        int aatest=1;
        int bbtest=1;
        int cctest= add(aatest,bbtest);
        std::cout<<"add cout "<<cctest;

        // 初始化控制台日志器
        spdlog::info("Welcome to spdlog!");
        spdlog::error("This is an error message");
        spdlog::warn("Warning message");
        spdlog::debug("Debug message"); // 默认情况下，debug和trace消息不会显


        // 打印到文件中
        auto file_logger = spdlog::basic_logger_mt("file_logger", "/Users/wanghao/Documents/tools/temp/logs.txt");
        spdlog::set_default_logger(file_logger);

        spdlog::info("Saved to logs.txt");
        return 0;
}
