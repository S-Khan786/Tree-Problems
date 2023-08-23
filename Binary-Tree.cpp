class BTreeNode {
public:
    int data;
    BTreeNode* left;
    BTreeNode* right;

    BTreeNode(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void print(BTreeNode* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << ":";
    if(root->left != NULL) {
        cout << " L " << root->left->data << ",";
    }
    
    if(root->right != NULL) {
        cout << " R " << root->right->data << ",";
    }
    cout << endl;

    print(root->left);
    print(root->right);
}

void printLevelWise(BTreeNode* root) {
    queue<BTreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        BTreeNode* curr = q.front();
        q.pop();

        cout << curr->data << ":";

        if(curr->left != NULL) {
            cout << " L " << curr->left->data << ",";
            q.push(curr->left);
        }

        if(curr->right != NULL) {
            cout << " R " << curr->right->data;
            q.push(curr->right);
        }
        cout << endl;
    }
}

BTreeNode* takeInput() {
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;

    if(rootData == -1) {
        return NULL;
    }

    BTreeNode* root = new BTreeNode(rootData);
    BTreeNode* leftChild = takeInput();
    BTreeNode* rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

BTreeNode* takeInputLevelWise() {
    int data;
    cout << "Enter Data" << endl;
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    BTreeNode* root = new BTreeNode(data);

    queue<BTreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        BTreeNode* curr = q.front();
        q.pop();

        int leftChild;
        cout << "Left child of " << curr->data << endl;
        cin >> leftChild;

        if(leftChild != -1) {
            BTreeNode* leftP = new BTreeNode(leftChild);
            curr->left = leftP;
            q.push(leftP);
        }

        int rightChild;
        cout << "right child of curr " << curr->data << endl;
        cin >> rightChild;

        if(rightChild != -1) {
            BTreeNode* rightP = new BTreeNode(rightChild);
            curr->right = rightP;
            q.push(rightP);
        }
    }

    return root;
}

void solve1() {
    // BTreeNode* root = new BTreeNode(1);
    // BTreeNode* node1 = new BTreeNode(2);
    // BTreeNode* node2 = new BTreeNode(3);
    // root->left = node1;
    // root->right = node2;

    BTreeNode* root = takeInputLevelWise();

    printLevelWise(root);
}

int32_t main() {

  solve1();

	return 0;
}
