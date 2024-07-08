#include <dirent.h> 

int scandir(const char *dirp, struct dirent *** namelist);

int main(void)
{
    char* dir_path = "path to some dir"; 
    struct dirent** pp_dirent = NULL; 
    int i; 

    scandir(dir_path, &pp_dirent); 

    for(i = 0; pp_dirent[i] != NULL; ++i)
    {
        pp_dirent[i]-> = ;
    }


    for(i = 0; pp_dirent[i] != NULL; ++i)
        free(pp_dirent[i]); 

    free(pp_dirent); 
    pp_dirent = NULL; 
}