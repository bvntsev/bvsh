#include <asm-generic/errno-base.h>
#include <linux/limits.h>
#include <stdint.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "../include/tools.h"

char *sys_command[] = {
    "cd",
    "exit"
};

int user_exec(char **);
int user_cd(char **);
int user_exit(char **);


int (*sys_functions[])(char **) = {
    &user_cd,
    &user_exit
};

int pid_launch(char **arg);


int file_exist(char *path){
    FILE *fstream  = fopen(path, "r");
    if (fstream == NULL)
        return -1;
    fclose(fstream);
    return 0;
}

int input_processing(char **input, const u32 *len) {
    // printf("%s\n", "========INPUT_PROCESSING=========");
    u32 sys_command_len = sizeof(sys_command)/sizeof(char *);
    for (u32 iter = 0; iter < sys_command_len; ++iter) {
        if (strcmp(sys_command[iter], input[0]) == 0) {
            printf("matched\n");
            return sys_functions[iter](input);
        }
    }

    return pid_launch(input);
} 

int pid_launch(char **arg) {

    pid_t pid ;
    
    pid = fork();

    int output_code;
    int status;

    switch (pid) {
        case -1: {
            fprintf(stderr, "fork");
            exit(EXIT_FAILURE);
        }
        case 0: {
            output_code = user_exec(arg);
            return 0;
        }
        default: {
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (WIFSIGNALED(status) && !WIFEXITED(status));
        }
    }

    return output_code;
}

int user_exec(char **arg) {

    printf("%s\n", "========USER_EXECVP=========");
    int exec_code = execvp(arg[0], arg);
    printf("\nexec_code - %d\n", exec_code);
    return exec_code;
}

int user_cd(char **arg){ //TODO: man 2 chdir
    int cd_output = chdir(arg[1]);
    char *current_directory = (char *)malloc(sizeof(char) * PATH_MAX);

    if (cd_output == -1) {

        fprintf(stderr, "bvsh_cd error\n");
        free(current_directory);
        return -1;
    }

    getcwd(current_directory, PATH_MAX);
    // printf("curr_dir - %s\n", current_directory);

    free(current_directory);

    return cd_output;

}

int user_exit(char ** str){
    // TODO: kill pid
    exit(0);
}
