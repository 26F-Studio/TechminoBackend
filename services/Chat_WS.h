//
// Created by Parti on 2021/2/5.
//

#pragma once

#include <services/Base_WS.h>
#include <structures/Chat.h>
#include <utils/authorizer.h>

namespace tech::services::websocket {
    class Chat : public Base {
    public:
        Chat();

        void establish(
                const drogon::WebSocketConnectionPtr &wsConnPtr,
                const drogon::AttributesPtr &attributes
        ) override;

        void close(
                const drogon::WebSocketConnectionPtr &wsConnPtr
        ) override;
    };
}