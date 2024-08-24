/* --------------------------------- Catch2 --------------------------------- */
#include "catch2/catch_all.hpp"

/* --------------------------------- Define --------------------------------- */
#define CATCH_CONFIG_MAIN

#include "login.hpp"

TEST_CASE("Successful login", "[login]") 
{
    phoenix::input input("login test, press enter to begin", "[lars.tests]: ");
    lars::login login(input);
    login.username();
    login.password();
    
    const lars::credentials *credentials = login.user();

    REQUIRE(credentials != nullptr);
    REQUIRE(credentials->name != nullptr);
    REQUIRE(credentials->password != nullptr);
};

TEST_CASE("Get User Credentials", "[login]") 
{
    const lars::credentials &credentials = { .name = "lars", .password = "0000" };

    lars::user user;
    const auto identity = user.get(&credentials);

    REQUIRE(credentials.name == identity.name);
    REQUIRE(credentials.password == identity.password);
};

