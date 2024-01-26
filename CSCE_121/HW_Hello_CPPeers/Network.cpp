# include <iostream>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include "Network.h"

using std::string, std::vector;

Network::Network() : users({}), posts({}), tags({}) {}

void Network::loadFromFile(string fileName) {
    // TODO: load user and post information from file
    std::ifstream inputFS;
    inputFS.open(fileName);

    if (!inputFS.is_open()) {
        throw std::invalid_argument("Failed to open <filename>");
    }

    string type;
    string userName;
    unsigned int postID;
    string postText;
    string check;
    while (inputFS >> type) {

        if (type == "User") {
            if (!(inputFS >> userName)) {
                throw std::runtime_error("Not following specified format");
            }
            for (long unsigned int k = 0; k < userName.size(); k++) {
                if (!(isalpha(userName[k]))) {
                    throw std::runtime_error("userName does not have alphabet");
                }
            }
            try{
                addUser(userName);
            }
            catch(std::invalid_argument&) {
                throw std::runtime_error("addUser threw invalid argument");
            }
        }

        else if (type == "Post") {
            if (!(inputFS >> postID)) {
                throw std::runtime_error("Not following specified format");
            }
            if (!(inputFS >> userName)) {
                throw std::runtime_error("Not following specified format");
            }
            for (long unsigned int i = 0; i < userName.size(); i++) {
                if (!(isalpha(userName[i]))) {
                    throw std::runtime_error("userName does not have alphabet");
                }
            }
            if (!(inputFS >> check)) {
                throw std::runtime_error("No postText");
            }
            if (check == "Post" || check == "User") {
                throw std::runtime_error("No postText");
            }
            getline(inputFS, postText);
            postText.insert(0, check);
            try {
                addPost(postID, userName, postText);
            }
            catch(std::invalid_argument&) {
                throw std::runtime_error("addPost threw invalid argument");
            }
        }

        else {
            throw std::runtime_error("Does not match format");
        }
    }
}

void Network::addUser(string userName) {
    // TODO: create user and add it to network
    for (long unsigned int j = 0; j < userName.size(); j++) {
        userName[j] = static_cast<char>(tolower(userName[j]));
    }

    for (long unsigned int k = 0; k < users.size(); k++) {
        if (userName == users.at(k)->getUserName()) {
            throw std::invalid_argument("A user with this name already exists");
        }
    }

    User* addUser = new User(userName);
    users.push_back(addUser);
    std::cout << "Added User "  << userName << std::endl;

}

void Network::addPost(unsigned int postId, string userName, string postText) {
    // TODO: create post and add it to network
    int userExists = 0;
    for (long unsigned int i = 0; i < posts.size(); i++) {
        if (postId == posts.at(i)->getPostId()) {
            throw std::invalid_argument("Post with this ID already exists");
        }
    }

    User* newpost;
    for (long unsigned int p = 0; p < users.size(); p++) {
        if (userName == users.at(p)->getUserName()) {
            userExists = 1;
            newpost = users.at(p);
        }
    }
    if (userExists == 0) {
        throw std::invalid_argument("No user with this name exists");
    }

    Post* addPost = new Post(postId, userName, postText);
    posts.push_back(addPost);
    newpost->addUserPost(addPost);
    vector<string> newTags = addPost->findTags();
    for (long unsigned int k = 0; k < newTags.size(); k++) {
        for (long unsigned int j = 0; j < tags.size(); j++) {
            if (newTags.at(k) == tags.at(j)->getTagName()) {
                tags.at(j)->addTagPost(addPost);
            }
            else {
                try{
                    Tag* addTag = new Tag(newTags.at(k));
                    tags.push_back(addTag);
                    addTag->addTagPost(addPost);
                }
                catch(std::invalid_argument&) {
                    continue;
                }   
            }
        }
    }
    
    std::cout << "Added Post " << postId << " by " << userName << std::endl;
}

vector<Post*> Network::getPostsByUser(string userName) {
    // TODO: return posts created by the given user
    if (userName == "") {
        throw std::invalid_argument("userName is empty");
    }

    int found = 0;
    vector<Post*> PostsByUser;
    for (long unsigned int i = 0; i < users.size(); i++) {
        if (userName == users.at(i)->getUserName()) {
            found = 1;
            PostsByUser = users.at(i)->getUserPosts();
        }
    }
    if (found == 0) {
        throw std::invalid_argument("userName is not found");
    }

    return PostsByUser;
}

vector<Post*> Network::getPostsWithTag(string tagName) {
    // TODO: return posts containing the given tag
    if (tagName == "") {
        throw std::invalid_argument("tagName is empty");
    }

    vector<Post*> PostsWithTags;
    vector<string> tagnames;
    for (long unsigned int i = 0; i < posts.size(); i++) {
        tagnames = posts.at(i)->findTags();
        for (long unsigned int k = 0; k < tagnames.size(); k++) {
            if (tagName == tagnames.at(k)) {
                PostsWithTags.push_back(posts.at(i));
            }
        }
    }

    return PostsWithTags;

}

vector<string> Network::getMostPopularHashtag() {
    // TODO: return the tag occurring in most posts
    vector<string> hashtag;
    vector<string> mostPopular;
    vector<string> tag;
    int max = 0; 
    int current = 0;
    
    for (long unsigned int i = 0; i < posts.size(); i++) {
        tag = posts.at(i)->findTags();
        for (unsigned long j = 0; j < tag.size(); j++) {
            hashtag.push_back(tag.at(j));
        }
    }

    for (long unsigned int k = 0; k < hashtag.size(); k++) {
        current = 0;
        for (long unsigned int l = 0; l < hashtag.size(); l++) {
            if (hashtag.at(k) == hashtag.at(l)) {
                current += 1;
            }
        }
        if (current > max) {
            max = current;
        }
    }

    for (long unsigned int a = 0; a < hashtag.size(); a++) {
        current = 0;
        bool repeat = false;
        for (long unsigned int l = 0; l < hashtag.size(); l++) {
            if (hashtag.at(a) == hashtag.at(l)) {
                current += 1;
            }
        }
        if (current == max) {
            for (long unsigned int o = 0; o < mostPopular.size(); o++) {
                if (mostPopular.at(o) == hashtag.at(a)) {
                    repeat = true;
                }
            }
            if (!repeat) {
                mostPopular.push_back(hashtag.at(a));
            }
        }
    }
    
    return mostPopular;

    
}

Network::~Network() {
    for (unsigned int i = 0; i < users.size(); ++i) {
        delete users.at(i);
    }

    for (unsigned int i = 0; i < tags.size(); ++i) {
        delete tags.at(i);
    }
    
    for (unsigned int i = 0; i < posts.size(); ++i) {
        delete posts.at(i);
    }
}
