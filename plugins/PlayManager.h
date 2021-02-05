//
// Created by Parti on 2021/2/4.
//

#pragma once

#include <drogon/plugins/Plugin.h>
#include <.unused/communication_manager.h>
#include <services/RoomManager.h>
#include <services/Room.h>
#include <utils/Utils.h>

using namespace drogon;
using namespace trantor;

namespace tech::plugin {
    class PlayManager : public drogon::Plugin<PlayManager> {
    public:
        PlayManager() {}

        virtual void initAndStart(const Json::Value &config) override;

        virtual void shutdown() override;

        Json::Value createRoom(const std::string &roomID, const std::string &name, const std::string &password,
                               const std::string &roomType);

        SubscriberID
        subscribe(const std::string &roomID, const tech::utils::RoomManager::MessageHandler &handler);

        void unsubscribe(const std::string &roomID, const SubscriberID &playerID);

        bool checkPassword(const std::string &roomID, const std::string &password);

        void publish(const std::string &roomID, const std::string &message);

        void publish(const std::string &roomID, const std::string &message, const SubscriberID &excludedID) const;

        void tell(const std::string &roomID, const std::string &message, const SubscriberID &targetID) const;

        [[maybe_unused]] size_t size();

        Json::Value getRoomList();

        Json::Value getRoomList(const std::string &roomType);

    private:
        std::unordered_map<std::string, uint64_t> _roomTypes;
        tech::utils::RoomManager _roomManager;
        mutable std::shared_mutex _sharedMutex;
    };
}