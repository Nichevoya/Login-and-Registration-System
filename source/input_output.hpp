#pragma once 

#include <iostream>
#include <cxxopts.hpp>

namespace lars {
    
    class input_output {
        public:
            enum class options {
                none,
                help,
                registration,
                login
            };
            
            input_output(const int ac, const char *const *const av) : 
                _ac(ac), _av(av), _options(meta::name, meta::description), _result(entry_point()) {}

            bool handled(void) { return parameters(); }

            std::map<options, std::string> &found(void) & { return _found; }
            const std::map<options, std::string> &found(void) const & { return _found; }

        protected:
            const cxxopts::ParseResult &result(void) const & { return _result; }
            const cxxopts::ParseResult entry_point(void)
            {
                _options.add_options()  //NOTE - Parameters are first added into this list via (param, description, value) synthax
                    ("h,help", "Print usage and display available options");

                return _options.parse(_ac, _av);
            }

            bool parameters(void) //NOTE - Parameters are then handled here
            {
                //NOTE - Whether help is needed or not 
                if (result().count("help")) {
                    std::cout << _options.help() << std::endl;
                    return false;
                }

                return true;
            }

        private:
            struct meta {
                static constexpr const char *const &name = "lars";
                static constexpr const char *const &description = "Description:\n  User credentials like usernames and passwords are asked from the user.\n  If the registration of the user is successful then with the given credentials a file will be created of a particular user in the database.";
            };

            const int _ac;
            const char *const *const _av;
            cxxopts::Options _options;
            cxxopts::ParseResult _result;
            std::map<options, std::string> _found;
    };

} // lars

