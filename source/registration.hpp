#pragma once 

#include "phoenix.hpp"
#include "credentials.hpp"

namespace lars {

    class registration {
        public:
            registration(phoenix::input &input) : _input(input) 
            {
                std::cout << "[lars]: Registration" << std::endl;
            }
            ~registration() = default;
        
            void username(void) & 
            {
                _username = "";
                _input.grab("Please type your username");
                _username = _input.value();
            }

            void password(void) & 
            {
                if (_username.empty()) {
                    std::cerr << "[lars]: Username is invalid" << std::endl;
                    return;
                }

                _password = "";
                _verification = "";

                _input.grab("Please type your password");
                _password = _input.value();

                if (_password.empty()) {
                    std::cerr << "[lars]: Password is invalid" << std::endl;
                    return;
                }
                
                _input.grab("Please type your password again");
                _verification = _input.value();

                if (_verification.empty()) {
                    std::cerr << "[lars]: Password is invalid" << std::endl;
                    return;
                }

                if (!passwords_match()) {
                    std::cerr << "[lars]: Passwords do not match" << std::endl;
                    retry();
                }
            }

            const credentials *submit(void) 
            {
                if (_username.empty() || _password.empty()) {
                    std::cerr << "[lars]: Invalid credentials, aborting" << std::endl;
                    return nullptr;
                }
                
                _credentials.name = _username.c_str();
                _credentials.password = _password.c_str();

                return &_credentials;
            }

        protected:
            bool passwords_match(void) const & 
            {
                return _password == _verification;
            }

            void retry(void) & 
            {
                _input.grab("Do you want to retry ? [y/n/?]");
                if (_input.value() == "yes" || _input.value() == "y") {
                    _username = "";
                    _password = "";
                    _verification = "";
                    username();
                    password();
                } else if (_input.value() == "no" || _input.value() == "n") {
                    return;
                } else {
                    std::cerr << "[lars]: Unknown option, aborting" << std::endl;
                    return;
                }
            }
        
        private:
            phoenix::input &_input;
            credentials _credentials;
            std::string _username, _password, _verification;
    };
    
} // lars

