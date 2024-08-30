#pragma once 

#include "phoenix.hpp"
#include "input_output.hpp"

#include "registration.hpp"
#include "login.hpp"

namespace lars {

    bool parameters(const int ac, const char *const *const av) 
    {
        input_output instance(ac, av);
        return instance.handled();
    }

    int run(const int ac, const char *const *const av) 
    {
        if (!parameters(ac, av)) 
            return -1;

        start:
            phoenix::input input("Main menu, enter help if needed", "[lars]: ");
            phoenix::string in = input.value();

            switch (phoenix::experimental::hash(in.lowercase().value().c_str())) {
                case phoenix::experimental::hash("register"):
                    {
                        registration registration(input);
                        registration.username();
                        registration.password();
                        
                        const credentials *credentials = registration.submit();

                        if (!credentials || 
                            !credentials->name || 
                            !credentials->password) break;

                        user user;
                        
                        if (!user.create(credentials))
                            break;
                    } break;

                case phoenix::experimental::hash("login"):
                    {
                        login login(input);
                        login.username();
                        login.password();

                        const credentials *credentials = login.user();

                        if (!credentials || 
                            !credentials->name || 
                            !credentials->password) break;

                        user user;
                        const auto identity = user.get(credentials);

                        if (std::strcmp(credentials->name, identity.name) != 0 || 
                            std::strcmp(credentials->password, identity.password) != 0) {
                            std::cerr << "[lars]: User not found" << std::endl;
                            break;
                        } else {
                            std::cout << "[lars]: logged in as " << identity.name << std::endl;
                            return 0;
                        }
                    } break;

                case phoenix::experimental::hash("help"): 
                    std::cout << "[lars]: Displaying help" << std::endl << std::endl
                    << "help\t\tdisplay this message" << std::endl
                    << "register\tregister a user with given credentials and create a username.txt file" << std::endl
                    << "login\t\tlogin a user with the registered credentials" << std::endl
                    << "quit\t\texit the application" << std::endl << std::endl;
                    break;

                case phoenix::experimental::hash("quit"): 
                    std::cout << "[lars]: leaving" << std::endl;
                    return 0; 

                default: break;
            }

        goto start;
    }

} // lars

