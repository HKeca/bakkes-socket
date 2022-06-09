#include "BakkesSocket.h"

BAKKESMOD_PLUGIN(BakkesSocket, "Websocket access in bakkesmod", "1.0", PLUGINTYPE_FREEPLAY);

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void BakkesSocket::onLoad()
{
  _globalCvarManager = cvarManager;
  cvarManager->log("Loading WebSocket support for bakkesmod...");
}

void BakkesSocket::onUnLoad()
{
  //
}