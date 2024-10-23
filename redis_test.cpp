//
// Created by 王浩 on 2024/9/19.
//
#include <iostream>
#include <string>
#include <hiredis/hiredis.h>
#include <sw/redis++/redis++.h>
#include "redis_test.h"  //安装命令  vcpkg install redis-plus-plus
//  redis-plus-plus


void redis_test::redis_get() {
    try {
        // 创建Redis对象时,需要在构造函数中指定redis服务器的地址和端口
        sw::redis::Redis redis("tcp://127.0.0.1:6379");

        // 使用Redis客户端的get函数获取key为test的值
        sw::redis::OptionalString value = redis.get("test");

        // 如果返回结果不为空，则输出获取到的值
        if (value) {
            std::cout << "Get value from Redis: " << value.value() << std::endl;
        } else {
            std::cout << "Cannot find value in Redis." << std::endl;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
}

void redis_test::redis_set() {
    try {
        // 创建Redis对象时,需要在构造函数中指定redis服务器的地址和端口
        sw::redis::Redis redis("tcp://127.0.0.1:6379");

        // 使用Redis客户端的set函数设置key为test的值为Hello World!
        redis.set("test", "Hello World!");

        std::cout << "Set value to Redis: Hello World!" << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

}
