#include<iostream>
#include"cserver.h"
#include<json/json.h>
#include<json/value.h>
#include <json/reader.h>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <csignal>

namespace net = boost::asio; // 定义别名
int main()
{
    try
    {
        unsigned short port = static_cast<unsigned short>(8010);
        net::io_context ioc{ 1 };
        boost::asio::signal_set signals(ioc, SIGINT, SIGTERM);
        signals.async_wait([&ioc](const boost::system::error_code& error, int signal_number) {

            if (error) {
                return;
            }
            ioc.stop();
            });
        std::make_shared<CServer>(ioc, port)->Start();
        ioc.run();
    }
    catch (std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}