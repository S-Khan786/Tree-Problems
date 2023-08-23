class TreeNode {
public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int data) {
        this->data = data;
    }
};

void print1(TreeNode* root) {
    cout << root->data << endl;

    for(int i=0; i<root->children.size(); i++) {
        print1(root->children[i]);
    }
}

void print2(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    
    cout << root->data << ":";

    for(int i=0; i<root->children.size(); i++) {
        cout << root->children[i]->data << ",";
    }

    cout << endl;
    for(int i=0; i<root->children.size(); i++) {
        print2(root->children[i]);
    }
}

void printLevelWise(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        
        cout << curr->data << ":";

        for(int i=0; i<curr->children.size(); i++) {
            cout << curr->children[i]->data << ",";
            q.push(curr->children[i]);
        }
        cout << endl;
    }
}

TreeNode* takeInput() {
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;

    TreeNode* root = new TreeNode(rootData);

    int numChildren;
    cout << "Enter num of children" << endl;
    cin >> numChildren;

    for(int i=0; i<numChildren; i++) {
        TreeNode* child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

TreeNode* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    TreeNode* root = new TreeNode(rootData);
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        
        int numChildren;
        cout << "No of children of " << curr->data << endl;
        cin >> numChildren;

        for(int i=0; i<numChildren; i++) {
            int node;
            cout << i << " child of the " << curr->data << endl;
            cin >> node;

            TreeNode* child = new TreeNode(node);
            curr->children.push_back(child);
            q.push(child);
        }
    }

    return root;
}

void solve1() {
    // TreeNode* root = new TreeNode(1);
    // TreeNode* node1 = new TreeNode(2);
    // TreeNode* node2 = new TreeNode(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);


    TreeNode* root = takeInputLevelWise();

    printLevelWise(root);
}

int32_t main() {

	solve1();

	return 0;
}
