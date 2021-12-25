//
// Created by wat on 2021/12/23.
//

#include "smain.h"

//#include <Windows.h>
//#include <iostream>
#include <string>
#include <direct.h>

//#include <filesystem>
using namespace std;

#define LENTH 255



sMain::sMain() : window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_GLASSY /*| SW_ENABLE_DEBUG - frame sets it manually*/) {

}

int sMain::get_windowHandle() {
    return (int)(intptr_t)get_hwnd();
}


int uimain(std::function<int()> run ) {

    //SciterSetOption(NULL, SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_GLASSY /*| SW_ENABLE_DEBUG - frame sets it manually*/);

    //SciterSetGlobalAsset(new sqlite::SQLite());

    sciter::om::hasset<sMain> pwin = new sMain();
    SciterSetMediaType(pwin->get_hwnd(), WSTR("desktop,sMain"));
    bool loaded = false;
    const std::vector<sciter::string>& argv = sciter::application::argv();

    pwin->load(WSTR("F:/CProject/sciter-js-sdk-main/rapIM/res/server/holle.html"));

    return run();
}