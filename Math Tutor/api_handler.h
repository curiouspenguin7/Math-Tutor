#ifndef API_HANDLER_H
#define API_HANDLER_H

#include <string>

class ApiHandler {
public:
    std::string getResponse(const std::string& query);
private:
    std::string sendRequest(const std::string& payload);
};

#endif
