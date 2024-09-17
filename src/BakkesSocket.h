#pragma once

#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "BroadcastServer.h"

class BakkesSocket: public BakkesMod::Plugin::BakkesModPlugin
{
public:
    virtual void onLoad() override;
    virtual void onUnload() override;

    void statEvent(ServerWrapper caller, void* args);

private:
    BroadcastServer* wsServer;
};