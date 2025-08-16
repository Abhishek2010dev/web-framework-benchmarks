#include <drogon/drogon.h>
#include <json/json.h> // make sure to include JsonCpp

int main() {
    drogon::app().addListener("0.0.0.0", 8080);

    drogon::app().registerHandler("/ping",
        [](const drogon::HttpRequestPtr &,
           std::function<void (const drogon::HttpResponsePtr &)> &&callback) {

            Json::Value jsonResp;
            jsonResp["message"] = "pong";  // safer way to set JSON
            auto resp = drogon::HttpResponse::newHttpJsonResponse(jsonResp);
            callback(resp);
        },
        {drogon::Get}
    );

    drogon::app().run();
    return 0;
}

