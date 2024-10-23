//
// Created by 王浩 on 2024/9/19.
//
#include <librdkafka/rdkafkacpp.h> //安装命令  vcpkg install librdkafka
#include <iostream>
#include <string>


#include "kafka_test.h"

void kafka_test::kafka_read_test() {
    std::string brokers = "localhost:9092";
    std::string topic_str = "test";
    std::string errstr;
    RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    conf->set("metadata.broker.list", brokers, errstr);

    RdKafka::Consumer *consumer = RdKafka::Consumer::create(conf, errstr);
    if (!consumer) {
        std::cerr << "Failed to create consumer: " << errstr << std::endl;
        exit(1);
    }

    RdKafka::Topic *topic = RdKafka::Topic::create(consumer, topic_str, conf, errstr);
    if (!topic) {
        std::cerr << "Failed to create topic: " << errstr << std::endl;
        exit(1);
    }

    RdKafka::ErrorCode resp = consumer->start(topic, 0, RdKafka::Topic::OFFSET_BEGINNING);
    if (resp != RdKafka::ERR_NO_ERROR) {
        std::cerr << "Failed to start consumer: " << RdKafka::err2str(resp) << std::endl;
        exit(1);
    }

    while (true) {
        RdKafka::Message *message = consumer->consume(topic, 0, 1000);
        if (!message || message->err() != RdKafka::ERR_NO_ERROR) {
            delete message;
            continue;
        }
        std::cout << "Received message: " << static_cast<const char *>(message->payload()) << std::endl;
        delete message;
    }

    delete topic;
    delete consumer;
}

void kafka_test::kafka_push_test() {
    std::string brokers = "localhost:9092";
    std::string topic_str = "test";
    std::string errstr;
    RdKafka::Conf* conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    conf->set("metadata.broker.list", brokers, errstr);

    RdKafka::Producer* producer = RdKafka::Producer::create(conf, errstr);
    if (!producer) {
        std::cerr << "Failed to create producer: " << errstr << std::endl;
        exit(1);
    }

    RdKafka::Topic* topic = RdKafka::Topic::create(producer, topic_str, conf, errstr);
    if (!topic) {
        std::cerr << "Failed to create topic: " << errstr << std::endl;
        exit(1);
    }

    std::string message_str = "Hello, Kafka!";
    RdKafka::ErrorCode resp = producer->produce(topic, RdKafka::Topic::PARTITION_UA,
                                                RdKafka::Producer::RK_MSG_COPY,
                                                const_cast<char*>(message_str.c_str()),
                                                message_str.size(), NULL, NULL);
    if (resp != RdKafka::ERR_NO_ERROR) {
        std::cerr << "Failed to produce message: " << RdKafka::err2str(resp) << std::endl;
    } else {
        std::cout << "Produced message: " << message_str << std::endl;
    }

    producer->flush(10000); // 等待直到所有未发送的消息都被刷新为止

    delete topic;
    delete producer;
}
