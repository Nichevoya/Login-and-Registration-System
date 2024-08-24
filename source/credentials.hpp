#pragma once 

#include <filesystem>

namespace lars {
    
    struct credentials {
        const char *name = nullptr;
        const char *password = nullptr;
    };

    class user {
        public:
            bool create(const credentials *credentials) 
            {
                assert(credentials != nullptr && "Invalid credentials, aborting.");

                std::filesystem::path directory = "users";
                std::filesystem::path file = directory / phoenix::string(credentials->name, ".txt").value();
        
                if (!std::filesystem::exists(directory))
                    std::filesystem::create_directory("users");

                if (std::filesystem::exists(file)) {
                    std::cerr << "[lars]: user already exists" << std::endl;
                    return false;
                }

                std::ofstream ofs(file);

                if (!ofs) {
                    std::cerr << "[lars]: Failed to open file: " << file << std::endl;
                    return false;
                }

                ofs << phoenix::string(credentials->name, " | ", credentials->password);
                std::cout << "[lars]: User successfully created, data written to: " << file << std::endl;

                return true;
            }

            const credentials get(const credentials *identity) 
            {
                assert(identity != nullptr && "Invalid identity, aborting.");
                
                std::filesystem::path directory = "users";
                std::filesystem::path file = directory / phoenix::string(identity->name, ".txt").value();

                std::ifstream ifs(file);

                if (!ifs) {
                    std::cerr << "[lars]: Failed to open file: " << file << std::endl;
                    return credentials{};
                }

                credentials credentials;

                std::string line;
                while (std::getline(ifs, line)) {
                    credentials.name = line.substr(0, line.find_first_of(' ')).c_str();
                    credentials.password = line.substr(line.find_last_of(' ') + 1, line.length() - 1).c_str();
                }

                ifs.close();
                
                return credentials;
            }

        protected:
        private:
    };

} // lars

