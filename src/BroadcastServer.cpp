#include "BroadcastServer.h"

BroadcastServer::BroadcastServer()
{
    m_server.init_asio();

    m_server.set_open_handler(std::bind(&BroadcastServer::handleOpen, this, std::placeholders::_1));
    m_server.set_close_handler(std::bind(&BroadcastServer::handleClose, this, std::placeholders::_1));
}

void BroadcastServer::stop()
{
    m_server.stop();
    m_server.stop_listening();
}

void BroadcastServer::handleOpen(websocketpp::connection_hdl hdl)
{
    m_connections.insert(hdl);
}

void BroadcastServer::handleClose(websocketpp::connection_hdl hdl)
{
    m_connections.erase(hdl);
}

void BroadcastServer::sendMessage(std::string& message)
{
    for (auto it : m_connections) {
        m_server.send(it, message, websocketpp::frame::opcode::text);
    }
}

void BroadcastServer::run(uint16_t port)
{
    m_server.listen(port);
    m_server.start_accept();
    m_server.run();
}