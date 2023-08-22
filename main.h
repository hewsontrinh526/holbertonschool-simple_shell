#ifndef _MAIN_H_
#define _MAIN_H_

typedef struct s_dir
{
	char *directory;
	struct s_dir *next;
} t_dir;

t_dir *create_node(char *dir);
void add_node_end(t_dir **head, char *dir);
t_dir *build_path_list(char *path);
void free_list(t_dir *head);

#endif
