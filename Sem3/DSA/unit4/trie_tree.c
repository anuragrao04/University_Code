

node *delete(node *root, char word[], int depth) {
  if (root == NULL) {
    return root;
  }

  if (depth == strlen(word)) {
    if (root->endofword) {
      endofword = 0;
    }

    if (nochildren(root)) {
      free(root);
      root = NULL;
    }

    return root;
  }

  int index = root->children[depth] - 'a';
  root->children[index] = delete (root->children[index], word, ++depth);

  if (nochildren(root) && root->endofword == 0) {
    free(root);
    root = NULL;
  }

  return root;
}

void insert(node *root, char word[]) {

  int length = strlen(word);
  int index;

  node *current = root;

  for (int i = 0; i < length; i++) {
    index = word[i] - 'a';

    if (current->children[index] == NULL) {
      current->children[index] = getnode();
    }

    current = current->children[index];
  }

  current->endofword = 1;
}
