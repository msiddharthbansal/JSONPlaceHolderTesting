#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

void updatePost(int postId, const std::string& newTitle, const std::string& newPostBody) {
    http_client client(U("https://jsonplaceholder.typicode.com"));

    json::value updatedData;
    if (!newTitle.empty()) {
        updatedData[U("title")] = json::value::string(utility::conversions::to_string_t(newTitle));
    }
    if (!newPostBody.empty()) {
        updatedData[U("body")] = json::value::string(utility::conversions::to_string_t(newPostBody));
    }

    client.request(
        methods::PUT,
        U("/posts/") + utility::conversions::to_string_t(std::to_string(postId)),
        updatedData.serialize(),
        U("application/json")
    ).then([](http_response response) {
        if (response.status_code() == status_codes::OK) {
            std::cout << "Post updated successfully!" << std::endl;
        } else {
            std::cout << "Failed to update post. Status code: " << response.status_code() << std::endl;
        }
    }).wait();
}

