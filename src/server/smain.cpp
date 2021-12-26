//
// Created by wat on 2021/12/23.
//

#include "smain.h"
#include <iostream>

#include <string>
#include <direct.h>



sMain::sMain() : window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_GLASSY /*| SW_ENABLE_DEBUG - frame sets it manually*/) {

}

int sMain::get_windowHandle() {
    return (int)(intptr_t)get_hwnd();
}


int uimain(std::function<int()> run ) {

#ifdef _DEBUG
    std::cout << getcwd(NULL , 0) << std::endl;
#endif

    //SciterSetGlobalAsset(new sqlite::SQLite());

    sciter::om::hasset<sMain> pwin = new sMain();
    SciterSetMediaType(pwin->get_hwnd(), WSTR("desktop,sMain"));
    bool loaded = false;
    const std::vector<sciter::string>& argv = sciter::application::argv();

    pwin->load(WSTR("./res/server/holle.html"));
    pwin->expand();
    return run();
}

