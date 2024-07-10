#include "fetch_post.h"
#include <cpprest/http_client.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

void fetchPosts() {
    http_client client(U("https://jsonplaceholder.typicode.com"));

    client.request(methods::GET, U("/posts")).then([](http_response response) {
        if (response.status_code() == status_codes::OK) {
            return response.extract_json();
        } else {
            throw std::runtime_error("Failed to fetch posts.");
        }
    }).then([](json::value json) {
        for (const auto& post : json.as_array()) {
            std::cout << "Title: " << post.at(U("title")).as_string() << std::endl;
            std::cout << "Body: " << post.at(U("body")).as_string() << std::endl;
            std::cout << std::endl;
        }
    }).wait();
}

