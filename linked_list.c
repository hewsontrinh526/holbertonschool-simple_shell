t_dir *create_node(char *dir)
{
	t_dir *node;

	node = malloc(sizeof(t_dir));

	if (node == NULL)
	{
		return (NULL);
	}

	node->directory = strdup(dir);
	node->next = NULL;
	return (node);
}

void add_node_end(t_dir **head, char *dir)
{
	t_dir *new_node;
	t_dir *last;

	new_node = create_node(dir);
	if (new_node == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	last = *head;

	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_node;
}

t_dir *build_path_list(char *path)
{
	t_dir *head;
	char *dir;
	char *path_copy;

	head = NULL;
	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		add_node_end(&head, dir);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (head);
}

void free_list(t_dir *head)
{
	t_dir *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->directory);
		free(temp);
	}
}
