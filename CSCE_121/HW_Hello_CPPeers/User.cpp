# include <string>
# include <stdexcept>
# include "User.h"

using std::string, std::vector;

User::User(string userName) : userName(userName) /* TODO: initialize */ {
    // TODO: implement constructor checks
    if (userName == "" || (!islower(userName[0]) || !isalpha(userName[0]))) {
        throw std::invalid_argument("Invalid conditions");
    }

    for (long unsigned int i = 0; i < userName.size(); i++) {
        if (isupper(userName[i])) {
            throw std::invalid_argument("Contains capital letters");
        }
    }
}

string User::getUserName() {
    // TODO: implement getter
    return userName;
}

vector<Post*>& User::getUserPosts() {
    // TODO: implement getter
    return userPosts;
}

void User::addUserPost(Post* post) {
    // TODO: add post to user posts
    if (post == nullptr) {
        throw std::invalid_argument("Post is nullptr");
    }

    userPosts.push_back(post);
}
