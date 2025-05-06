#include "api_handler.h"
#include <iostream>
#include <curl/curl.h>

std::string ApiHandler::getResponse(const std::string& query) {
    std::string payload = "{ \"prompt\": \"" + query + "\", \"max_tokens\": 100 }";
    return sendRequest(payload);
}

std::string ApiHandler::sendRequest(const std::string& payload) {
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Authorization: Bearer YOUR_API_KEY");

        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/completions");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void* contents, size_t size, size_t nmemb, void* userp) {
            ((std::string*)userp)->append(static_cast<char*>(contents), size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << "\n";
        }

        curl_easy_cleanup(curl);
    }

    return response;
}
