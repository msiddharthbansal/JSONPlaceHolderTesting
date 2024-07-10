#include <iostream>
#include <cpprest/http_client.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

void deletePost(int postId) {
    http_client client(U("https://jsonplaceholder.typicode.com"));

    client.request(methods::DEL, U("/posts/") + utility::conversions::to_string_t(std::to_string(postId))).then([](http_response response) {
        if (response.status_code() == status_codes::NoContent) {
            std::cout << "Post deleted successfully!" << std::endl;
        } else {
            std::cout << "Failed to delete post. Status code: " << response.status_code() << std::endl;
        }
    }).wait();
}

