#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"

extern std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

class BakkesSocket: public BakkesMod::Plugin::BakkesModPlugin
{
public:
    virtual void onLoad();
    virtual void onUnLoad();
};