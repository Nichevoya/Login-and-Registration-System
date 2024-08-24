/* --------------------------------- Catch2 --------------------------------- */
#include "catch2/catch_all.hpp"

/* --------------------------------- Define --------------------------------- */
#define CATCH_CONFIG_MAIN

#include "registration.hpp"

TEST_CASE("Registration", "[registration]") 
{
    phoenix::input input("registration test, press enter to begin", "[lars.tests]: ");
    lars::registration registration(input);

    const lars::credentials *credentials = registration.submit();
    
    REQUIRE(credentials != nullptr);
    REQUIRE(credentials->name != nullptr);
    REQUIRE(credentials->password != nullptr);
};

TEST_CASE("User Generation", "[registration]") 
{
    const lars::credentials &credentials = { .name = "lars", .password = "0000" };
    lars::user user;

    REQUIRE(user.create(&credentials) == true);
};
