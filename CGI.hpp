#ifndef CGI_HPP
#define CGI_HPP

#include <map>
#include <string>

class CGI {
    public:
        CGI();
        CGI(const CGI& other);
        CGI& operator=(const CGI& other);
        ~CGI();

    private:
        static std::map<std::string, std::string> m_env;
        std::map<std::string, std::string> m_args;
    public:
        void initEnv();
        char** envToDoublePointerChar(std::map<std::string, std::string> env);
        void executeCGI();
        void printEnv();
};

#endif