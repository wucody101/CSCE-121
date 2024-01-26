# include <string>
# include <stdexcept>
# include "Tag.h"

using std::string, std::vector;

Tag::Tag(string tagName) : tagName(tagName)/* TODO: initialize */ {
    // TODO: implement constructor checks
    if (tagName.size() < 2) {
        throw std::invalid_argument("Tag name is too short");
    }

    if (tagName[0] != '#') {
        throw std::invalid_argument("Invalid first character (not #)");
    }

    if (!islower(tagName[1]) || !isalpha(tagName[1])) {
        throw std::invalid_argument("Second character is not from 'a' - 'z'");
    }

    for (long unsigned int i = 0; i < tagName.size(); i++) {
        if (isupper(tagName[i])) {
            throw std::invalid_argument("Contains capital letters");
        }
        if (tagName[i] == '!' || tagName[i] == ',' || tagName[i] == '.' || tagName[i] == '?') {
            throw std::invalid_argument("Contains punctuation");
        }
    }
}

string Tag::getTagName() {
    // TODO: implement getter
    return tagName;
}

vector<Post*>& Tag::getTagPosts() {
    // TODO: implement getter
    return tagPosts;
}

void Tag::addTagPost(Post* post) {
    // TODO: add post to tag posts
    if (post == nullptr) {
        throw std::invalid_argument("Post is nullptr");
    }

    tagPosts.push_back(post);
}
