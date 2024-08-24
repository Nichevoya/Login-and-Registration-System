/* --------------------------------- Catch2 --------------------------------- */
#include "catch2/catch_all.hpp"

/* --------------------------------- Define --------------------------------- */
#define CATCH_CONFIG_MAIN

#include "../source/lars.hpp"

TEST_CASE("Unknown Parameters", "[integrity]")
{
    const char *av[] = {
        "lars",
        "--nullptr"
    };

    REQUIRE_THROWS(lars::parameters(2, av));
};
