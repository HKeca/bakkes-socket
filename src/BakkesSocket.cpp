#include "BakkesSocket.h"

BAKKESMOD_PLUGIN(BakkesSocket, "BakkesSocket", "1.0.0.0", PLUGINTYPE_THREADED);

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
  auto receiver = PriWrapper(tArgs->Receiver);
  auto victim = PriWrapper(tArgs->Victim);
  auto statEvent = StatEventWrapper(tArgs->StatEvent);
  std::string eventString = statEvent.GetEventName();

  wsServer->sendMessage(eventString);
  wsServer->sendMessage(std::format("score {}", receiver.GetMatchScore()));
}

void BakkesSocket::onLoad()
{
  _globalCvarManager = cvarManager;

  gameWrapper->HookEventWithCallerPost<ServerWrapper>(
    "Function TAGame.GFxHUD_TA.HandleStatTickerMessage",
    std::bind(&BakkesSocket::statEvent, this,
      std::placeholders::_1, std::placeholders::_2)
  );

  cvarManager->log("Starting broadcast server");
  wsServer = new BroadcastServer();
  wsServer->run(9002);
}


void BakkesSocket::onUnload()
{
  cvarManager->log("Stopping broadcast server and unhooking events");

  if (wsServer) {
    wsServer->stop();
    delete wsServer;
  }

  gameWrapper->UnhookEvent("Function TAGame.GFxHUD_TA.HandleStatTickerMessage");
}