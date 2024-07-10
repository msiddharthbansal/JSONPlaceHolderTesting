#include <iostream>
#include <cpprest/http_client.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

int main() {
    http_client client(U("https://jsonplaceholder.typicode.com"));

    client.request(methods::GET, U("/posts")).then([](http_response response) {
        if (response.status_code() == status_codes::OK) {
            return response.extract_json();
        } else {
            throw std::runtime_error("Failed to fetch posts");
        }
    }).then([](json::value json) {
        // Process JSON response here
        if (json.is_array()) {
            for (const auto& post : json.as_array()) {
                if (post.is_object() && post.has_field(U("title"))) {
                    std::cout << "Id: " << post.at(U("id")) << std::endl;
                    std::cout << "Title: " << post.at(U("title")).as_string() << std::endl;
                    std::cout << "Body: " << post.at(U("body")).as_string() << std::endl;
                    std::cout << "\n";
                } else {
                    std::cerr << "Error: Post object doesn't have a 'title' field." << std::endl;
                }
            }
        } else {
            std::cerr << "Error: JSON response is not an array." << std::endl;
        }
    }).wait();

    return 0;
}

