// #include <iostream>
// #include <unistd.h>
// #include <sys/wait.h>
// #include <cstring>
// #include <cstdlib>
// #include <fcntl.h>



// int cgi(char *str[], char **env, int *pip)
// {
//     close(pip[0]);         
//     dup2(pip[1], STDOUT_FILENO);	
//     execve(str[0], str, env);           
//     perror("execve");
//     exit(EXIT_FAILURE);    
// }

// int main(int argc, char **argv, char **env)
// {
//     char buf[5];
//     int len;
//     std::string str;
//     int pip[2];
//     len = 0;
//     pipe(pip);
//     pid_t pid = fork();
//     if(pid == -1)
//     {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }
//     else if(pid == 0)
//     {
//         char * a = strdup("./cgi/php-cgi-mac");
//         char * b = strdup("./php.php");
//         char * str[]= {a, b, NULL};
          
//         cgi(str, env, pip);
//         free(a);
//         free(b);
//     }
//      close (pip[1]);
//      waitpid(pid, NULL, 0);
//      while ((len = read(pip[0], &buf, sizeof(buf) - 1)) > 0)
//      {
//                 buf[len] = '\0';
//                 str += buf;
//      }                   
//      std::cout << str <<std::endl;
//     // else
//     // {
//     //     int status;
//     //     waitpid(pid, &status, 0);
//     //     if (WIFEXITED(status)) {
//     //         std::cout << "Child process exited with status: " << WEXITSTATUS(status) << std::endl;
//     //     } else {
//     //         std::cerr << "Child process did not exit normally" << std::endl;
//     //     }
//     // }    
//     return (0);
// }