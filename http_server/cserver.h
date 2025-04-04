#ifndef CSERVER_H
#define CSERVER_H
#include <boost/beast/http.hpp>
#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <memory>
#include<iostream>
namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

class CServer:public std::enable_shared_from_this<CServer>
{
public:
    CServer(boost::asio::io_context& ioc, unsigned short& port);
    void Start();
private:
    tcp::acceptor  _acceptor;
    net::io_context& _ioc;
    boost::asio::ip::tcp::socket   _socket;
};

#endif