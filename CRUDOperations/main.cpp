#include <iostream>
#include "create_post.h"
#include "fetch_post.h"
#include "update_post.h"
#include "delete_post.h"
#include <string>

using namespace std;

int main() {

    cout << "Hello User, I hope you are in the best of your health :) !!!" << endl;
    cout << "We provide the CRUD Operations service to the post in JSON Placeholder API.\n" << endl;
    string str = "";
    while (str != "q" && str != "quit" && str != "Q" && str != "Quit") {
        cout << "Please provide the first letter as key to the operation you want to perform: ('q' or 'quit' to exit)" << endl;
        cin >> str;

        if (str == "c" || str == "C") {
            string title, postBody;
            cin.ignore(); // to clear the newline character left by cin
            cout << "Please enter the title of your post: ";
            getline(cin, title);
            cout << "Please enter the content of the post: ";
            getline(cin, postBody);

            createPost(title, postBody);
            cout << "\n";
        }
        else if (str == "r" || str == "R" || str == "f" || str == "F") {
            cout << "Here is the list of all posts: \n";
            fetchPosts();
            cout << "\n";
        }
        else if (str == "u" || str == "U") {
            int postId;
            string newTitle, newPostBody, response;
            cout << "Please enter the postId: ";
            cin >> postId;

            cout << "Update Title (t), postBody (p) or Both (b): ";
            cin >> response;

            cin.ignore(); // to clear the newline character left by cin
            if (response == "t" || response == "T") {
                cout << "Enter the new title: ";
                getline(cin, newTitle);
                updatePost(postId, newTitle, "");
                cout << "\n";
            }
            else if (response == "p" || response == "P") {
                cout << "Enter the new post body: ";
                getline(cin, newPostBody);
                updatePost(postId, "", newPostBody);
                cout << "\n";
            }
            else if (response == "b" || response == "B") {
                cout << "Enter the new title: ";
                getline(cin, newTitle);
                cout << "Enter the new post body: ";
                getline(cin, newPostBody);
                updatePost(postId, newTitle, newPostBody);
                cout << "\n";
            } else {
                cout << "Invalid Response.\n";
            }
        }
        else if (str == "d" || str == "D") {
            int postId;
            string response;
            cout << "Please enter the postId: ";
            cin >> postId;

            cout << "Are you sure you want to delete the post with id " << postId << " ? (y/n) ";
            cin >> response;

            if (response == "y" || response == "Y") {
                deletePost(postId);
            }
            cout << "\n";
        }
        else if (str != "q" && str != "quit" && str != "Q" && str != "Quit") {
            cout << "Invalid Response.\n";
        }
    }
    cout << "Thank You for using this operational software. *!* " << endl;
    return 0;
}

