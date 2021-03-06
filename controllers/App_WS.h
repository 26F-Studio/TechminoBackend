//
// Created by Parti on 2021/2/16.
//

#pragma once

#include <controllers/Base_WS.h>
#include <services/App_WS.h>

namespace tech::socket::v1 {
    class App : public Base<App, tech::services::websocket::App> {
    public:
        WS_PATH_LIST_BEGIN
            WS_PATH_ADD("/tech/socket/v1/app", "tech::filters::App")
        WS_PATH_LIST_END

        App();
    };
}
