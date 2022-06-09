#include "BakkesSocket.h"

BAKKESMOD_PLUGIN(BakkesSocket, "Websocket access in bakkesmod", "1.0", PERMISSION_ALL);

void BakkesSocket::onLoad()
{
  cvarManager->log("Loading WebSocket support for bakkesmod...");
}

void BakkesSocket::onUnLoad()
{
  //
}