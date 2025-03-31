#include <jwt-cpp/jwt.h>
#include <iostream>

int main() {
    auto token = jwt::create()
        .set_issuer("auth0")
        .set_type("JWS")
        .sign(jwt::algorithm::hs256{"secret"});
    std::cout << "Token: " << token << std::endl;
    return 0;
}