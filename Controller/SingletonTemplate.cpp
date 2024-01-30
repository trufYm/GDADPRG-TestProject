#include "SingletonTemplate.hpp"

using namespace controllers;

void Template::test() {
    std::cout << "Yes" << std::endl;
}

Template* Template::P_SHARED_INSTANCE = NULL;

Template::Template() {}
Template::Template(const Template&) {}

Template* Template::getInstance() {
    if(P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new Template();
    }

    return P_SHARED_INSTANCE;
}