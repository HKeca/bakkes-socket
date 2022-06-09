#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"

#pragma comment( lib, "pluginsdk.lib" )

class BakkesSocket: public BakkesMod::Plugin::BakkesModPlugin
{
public:
    virtual void onLoad();
    virtual void onUnLoad();
};