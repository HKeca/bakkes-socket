#pragma once

#include <set>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

typedef websocketpp::server<websocketpp::config::asio> server;

class BroadcastServer
{
public:
    BroadcastServer();

    void handleOpen(websocketpp::connection_hdl hdl);
    void handleClose(websocketpp::connection_hdl hdl);
    void sendMessage(std::string& message);

    void run(uint16_t port);
    void stop();

private:
    typedef std::set<websocketpp::connection_hdl,std::owner_less<websocketpp::connection_hdl>> con_list;

    server m_server;
    con_list m_connections;
};
