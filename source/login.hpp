#pragma once 

#include "phoenix.hpp"
#include "credentials.hpp"

namespace lars {
    
    class login {
        public:
            login(phoenix::input &input) : _input(input) 
            {
                std::cout << "[lars]: Login" << std::endl;
            }
            
            ~login() = default;

            const credentials *user(void) const 
            {
                return &_credentials;
            }

            void username(void) 
            {
                _input.grab("Please enter your username");
                _username = _input.value();

                if (_username.empty()) {
                    std::cerr << "[lars]: Username is invalid" << std::endl;
                    return;
                }

                _credentials.name = _username.c_str();
            }

            void password(void) 
            {
                if (_username.empty()) {
                    return;
                }

                _input.grab("Please enter your password");
                _password = _input.value();

                if (_username.empty()) {
                    std::cerr << "[lars]: Password is invalid" << std::endl;
                    return;
                }

                _credentials.password = _password.c_str();
            }

        protected:
        private:
            phoenix::input &_input;
            credentials _credentials;
            std::string _username, _password;
    };


} // lars
