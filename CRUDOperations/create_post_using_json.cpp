#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

void createPost(const std::string& title, const std::string& postBody) {
    http_client client(U("https://jsonplaceholder.typicode.com"));

    // Fetch existing posts to determine the highest id
    client.request(methods::GET, U("/posts")).then([=](http_response response) {
        if (response.status_code() == status_codes::OK) {
            return response.extract_json();
        } else {
            throw std::runtime_error("Failed to fetch posts");
        }
    }).then([=](json::value json) mutable {
        int highestId = 0;
        for (const auto& post : json.as_array()) {
            int postId = post.at(U("id")).as_integer();
            if (postId > highestId) {
                highestId = postId;
            }
        }
        
        int newPostId = highestId + 1;

        json::value newPost;
        newPost[U("id")] = json::value::number(newPostId);
        newPost[U("title")] = json::value::string(utility::conversions::to_string_t(title));
        newPost[U("body")] = json::value::string(utility::conversions::to_string_t(postBody));
        newPost[U("userId")] = json::value::number(2210); // dummy id for a user, can be put up as an attribute

        return client.request(methods::POST, U("/posts"), newPost.serialize(), U("application/json"));
    }).then([](http_response response) {
        if (response.status_code() == status_codes::Created) {
            std::cout << "Post created successfully!" << std::endl;
        } else {
            std::cout << "Failed to create post. Status code: " << response.status_code() << std::endl;
        }
    }).wait();
}

