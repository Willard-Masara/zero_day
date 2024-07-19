#ifndef MAIN_H
#define MAIN_H



void prompt(void);
void handle_arguments(const char *command, char *const arguments[]);
void execute_command(const char* command, char *const args[]);
char *find_executable(const char *command);
void handle_env(void);
void handle_exit(void);
#endif
