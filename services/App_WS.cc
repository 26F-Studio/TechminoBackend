//
// Created by Parti on 2021/2/16.
//

#include <plugins/AppManager.h>
#include <services/App_WS.h>

using namespace tech::plugins;
using namespace drogon;
using namespace std;

tech::services::websocket::App::App() : Base(tech::strategies::actions::Prefix::app) {}

void tech::services::websocket::App::establish(
        const WebSocketConnectionPtr &wsConnPtr,
        const AttributesPtr &attributes
) {
    auto data = attributes->get<Json::Value>("data");
    wsConnPtr->setContext(make_shared<structures::App>());

    auto initMessage = data["content"];
    initMessage["type"] = "Connect";

    tech::utils::websocket::initPing(wsConnPtr, initMessage, chrono::seconds(10));

    app().getPlugin<AppManager>()->subscribe(wsConnPtr);
}

void tech::services::websocket::App::close(const WebSocketConnectionPtr &wsConnPtr) {
    app().getPlugin<AppManager>()->unsubscribe(wsConnPtr);
}
