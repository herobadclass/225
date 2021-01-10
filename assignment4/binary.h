//301330473 jzfeng Jeffrey Feng
//Binary Search Tree implementation

//Create node
struct node
{
  int key_value;
  node *left;
  node *right;
};

class btree
{
    public:
        btree();

        void insert(int key);
        node *search(int key);

    private:
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        
        node *root;
};

//Initialize
btree::btree()
{
  root=NULL;
}

//Insert values into a bst (public)
void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
  }
}

//Insert value into a bst
void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;
      leaf->left->right=NULL;
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL; 
      leaf->right->right=NULL; 
    }
  }
}

//Search bst for a specific element (public)
node *btree::search(int key)
{
  return search(key, root);
}

//Search bst for a specific element
node *btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key_value)
      return leaf;
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

