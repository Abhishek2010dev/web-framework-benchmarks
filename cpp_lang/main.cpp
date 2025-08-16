#include <drogon/drogon.h>

int main() {
    // Create HTTP listener on port 8080
    drogon::app().registerHandler("/ping",
        [](const drogon::HttpRequestPtr &req,
           std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
            auto resp = drogon::HttpResponse::newHttpJsonResponse(
                {{"message", "pong"}}
            );
            callback(resp);
        });

    drogon::app().addListener("0.0.0.0", 8080);
    drogon::app().run();
    return 0;
}
