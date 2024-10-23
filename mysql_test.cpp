//
// Created by 王浩 on 2024/9/19.
//

#include "mysql_test.h"
#include <iostream>
#include <mysqlx/xdevapi.h> //安装命令 vcpkg install mysql-connector-cpp
void mysql_test::mysql_x() {
    try {

    }catch (const mysqlx::Error &e){
        std::cerr << "MySQL error: " << e.what() << std::endl;
    }

}
void mysql_test::mysql_input() {
    try {
        mysqlx::Session session("localhost", 3306, "root", "12345678");
        // 指定要使用的数据库
        session.getDefaultSchema().createCollection("test");
        // 执行 SQL 插入操作
        session.sql("INSERT INTO test1 (name, info,other) VALUES ('user3', 'user3info','user3other')").execute();
        session.sql("INSERT INTO test1 (name, info,other) VALUES ('user1', 'user1info','user1other')").execute();

        session.close();
    }catch (const mysqlx::Error &e){
        std::cerr << "MySQL error: " << e.what() << std::endl;
    }

}



void mysql_test::mysql_update() {
    mysqlx::Session session("localhost", 3306, "root", "12345678");
    // 指定要使用的数据库
    session.getDefaultSchema().createCollection("test");
    // 执行 SQL
    session.sql("UPDATE test1 SET info='user3xxx' WHERE name='user3'").execute();


    session.close();
}

void mysql_test::mysql_delect_test() {
    mysqlx::Session session("localhost", 3306, "root", "12345678");
    // 指定要使用的数据库
    session.getDefaultSchema().createCollection("test");

    // 执行 SQL
    session.sql("DELETE FROM test1 WHERE name='user1'").execute();


    session.close();
}

void mysql_test::mysql_select() {
    mysqlx::Session session("localhost", 3306, "root", "12345678");
    // 指定要使用的数据库
    session.getDefaultSchema().createCollection("test");


    // 执行 SQL 查询
    mysqlx::SqlResult r = session.sql("SELECT * FROM test1 ").execute();
    std::vector<mysqlx::Row> rows = r.fetchAll();
    for (const auto& row : rows) {
        std::cout << "name: " << row[0] << ", info: " << row[1] << std::endl;
    }
    session.close();
}


