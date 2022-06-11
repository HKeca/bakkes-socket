#include "BakkesSocket.h"

BAKKESMOD_PLUGIN(BakkesSocket, "Websocket", "1.0", PLUGINTYPE_FREEPLAY);

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

// The structure of a ticker stat event
struct TickerStruct {
    // person who got a stat
    uintptr_t Receiver;
    // person who is victim of a stat (only exists for demos afaik)
    uintptr_t Victim;
    // wrapper for the stat event
    uintptr_t StatEvent;
};

void BakkesSocket::statEvent(ServerWrapper caller, void* args)
{
  auto tArgs = (TickerStruct*)args;
  auto statEvent = StatEventWrapper(tArgs->StatEvent);
  auto eventString = statEvent.GetEventName();

  if (eventString == "Goal") {
    _globalCvarManager->log("Player scored goal");
  }
}

void BakkesSocket::onLoad()
{
  _globalCvarManager = cvarManager;
  cvarManager->log("Loading WebSocket support for bakkesmod...");

  gameWrapper->HookEventWithCallerPost<ServerWrapper>(
    "Function TAGame.GFxHUD_TA.HandleStatTickerMessage",
    std::bind(&BakkesSocket::statEvent, this,
      std::placeholders::_1, std::placeholders::_2)
  );
}

void BakkesSocket::onUnLoad()
{
  //
}