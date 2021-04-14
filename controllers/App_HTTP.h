//
// Created by Parti on 2021/2/3.
//

#pragma once

#include <drogon/HttpController.h>
#include <services/App_HTTP.h>

namespace tech::api::v1 {
    class App : public drogon::HttpController<App> {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(App::validateAccount, "/register", drogon::Get);
        METHOD_LIST_END

        void validateAccount(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);

    private:
        services::http::App _service;
    };
}