#include "CGI.hpp"
#include <cstring>
#include <iostream>

std::map<std::string, std::string> CGI::m_env;

CGI::CGI() {
    initEnv();
}

CGI::CGI(const CGI& other) {}

CGI& CGI::operator=(const CGI& other) {
    return (*this);
}

void CGI::initEnv() {
    m_env["AUTH_TYPE"] = "Basic";
    m_env["CONTENT_LENGTH"] = "75"; //hardcoded
    m_env["CONTENT_TYPE"] = "image/jpg"; //hardcoded
    m_env["GATEWAY_INTERFACE"] = "CGI/1.1";
    m_env["PATH_INFO"];
    m_env["PATH_TRANSLATED"];
    m_env["QUERY_STRING"];
    m_env["REMOTE_ADDR"];
    m_env["REMOTE_HOST"];
    m_env["REMOTE_IDENT"];
    m_env["REMOTE_USER"];
    m_env["REQUEST_METHOD"];
    m_env["SCRIPT_NAME"];
    m_env["SERVER_NAME"];
    m_env["SERVER_PORT"];
    m_env["SERVER_PROTOCOL"];
    m_env["SERVER_SOFTWARE"];
}

char** CGI::envToDoublePointerChar(std::map<std::string, std::string> env) {
    char** new_env = new char* [env.size() + 1];
    std::map<std::string, std::string>::iterator it;
    std::string var;
    int i = 0;
    for (it = env.begin(); it != env.end(); it++) {
        var = (*it).first + " = " + (*it).second;
        strcpy(new_env[i], var.c_str());
        i++;
    }
    new_env[i] = NULL;
    return (new_env);
}

void CGI::printEnv() {
    char** env = envToDoublePointerChar(m_env);
    for (int i = 0; i < m_env.size(); i++) {
            std::cout << env[i] << std::endl;
    }
    // std::map<std::string, std::string>::iterator it;
    // for (it = m_env.begin(); it != m_env.end(); it++) 
    //     std::cout << (*it).first + " = " << (*it).second << std::endl;
}

void CGI::executeCGI() {

}

CGI::~CGI() {}