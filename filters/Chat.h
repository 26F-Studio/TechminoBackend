//
// Created by Particle_G on 2021/2/23.
//

#pragma once

#include <drogon/HttpFilter.h>

using namespace drogon;
namespace tech::filters {
    class Chat : public HttpFilter<Chat> {
    public:
        Chat() {}

        void doFilter(
                const HttpRequestPtr &req,
                FilterCallback &&filterCallback,
                FilterChainCallback &&filterChainCallback
        ) override;
    };
}
