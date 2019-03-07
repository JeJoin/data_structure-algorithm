#ifndef __BST_H__
#define __BST_H__

#include <common.h>
#include <queue>

template <typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node * left;
        Node * right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            left = right = NULL;
        }

        Node(Node* node) {
            key = node->key;
            value = node->value;
            left = node->left;
            right = node->right;
        }
    };

    Node * m_root;
    int m_count;

public:
    BST() {
        m_root = NULL;
        m_count = 0;
    }

    ~BST() {
        destroy(m_root);
    }

    bool isEmpty() {
        return m_count == 0;
    }

    int size() {
        return m_count;
    }

    void insert(Key key, Value value) {
#if 1
        insertNonRecursion(key, value);
#else
        m_root = insert(m_root, key, value);
#endif
    }

    bool contain(Key key) {
#if 1
        return containNonRecursion(key);
#else
        return contain(m_root, key);
#endif
    }

    Value* search(Key key) {
#if 1
        return searchNonRecursion(key);
#else
        return search(m_root, key);
#endif
    }

    Key maximun() {
        assert(!isEmpty());

        Node* root = m_root;
        while (root->right != NULL) {
            root = root->right;
        }

        return root->key;
    }

    Key minimun() {
        assert(!isEmpty());

        Node* root = m_root;
        while (root->left != NULL) {
            root = root->left;
        }

        return root->key;
    }

    void removeMin() {
        assert(!isEmpty());
        m_root = removeMin(m_root);
    }

    void removeMax() {
        assert(!isEmpty());
        m_root = removeMax(m_root);
    }

    void remove(Key key) {
        assert(!isEmpty());
        m_root = remove(m_root, key);
    }

    // 前序遍历
    void preOrder() {
        preOrder(m_root);
    }

    // 中序遍历
    void inOrder() {
        inOrder(m_root);
    }

    // 后序遍历
    void postOrder() {
        postOrder(m_root);
    }

    // 层序遍历
    void levelOrder() {
        levelOrder(m_root);
    }

private:
    // 向以node为根的二叉搜索树中,插入节点(key, value)
    // 返回插入新节点后的二叉搜索树的根
    Node* insert(Node* node, Key key, Value value) {
        if (node == NULL) {
            m_count++;
            return new Node(key, value);
        }

        if (node->key == key) {
            node->value = value;
        } else if (node->key > key) {
            node->left = insert(node->left, key, value);
        } else {
            node->right = insert(node->right, key, value);
        }

        return node;
    }

    void insertNonRecursion(Key key, Value value) {

        if (m_root == NULL) {
            m_root = new Node(key, value);
            return;
        }
        Node *root = m_root;

        while (root != NULL) {
            if (root->key == key) {
                root->value = value;
                m_count++;
                return;
            } else if (root->key < key) {
                if (root->right == NULL) {
                    root->right = new Node(key, value);
                } else {
                    root = root->right;
                }
            } else { // root->key > key
                if (root->left == NULL) {
                    root->left = new Node(key, value);
                } else {
                    root = root->left;
                }
            }
        }
    }

    bool contain(Node* node, Key key) {
        if (node == NULL) {
            return false;
        }
        if (node->key == key) {
            return true;
        } else if (node->key > key) {
            return contain(node->left, key);
        } else {
            return contain(node->right, key);
        }
    }

    bool containNonRecursion(Key key) {

        Node *root = m_root;
        while (root != NULL) {
            if (root->key == key) {
                return true;
            } else if (root->key < key) {
                root = root->right;
            } else { // root->key > key
                root = root->left;
            }
        }
        return false;
    }

    Value* search(Node* node, Key key) {
        if (node == NULL) {
            return NULL;
        }

        if (node->key == key) {
            return &node->value;
        } else if (node->key > key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    Value* searchNonRecursion(Key key) {
        Node *root = m_root;
        while (root != NULL) {
            if (root->key == key) {
                return &root->value;
            } else if (root->key < key) {
                root = root->right;
            } else { // root->key > key
                root = root->left;
            }
        }
        return NULL;
    }

    // 返回以node为根的子树最小的节点
    Node* minimun(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        if (node->left == NULL) {
            return node;
        }

        return minimun(node->left);
    }

    // 移除以node为根的子树最小节点
    // 返回移除最小节点后的根
    Node* removeMin(Node* node) {
        if (node == NULL) {
            return node;
        }

        if (node->left != NULL) {
            node->left = removeMin(node->left);
            return node;
        }

        Node* r = node->right;
        delete node;
        m_count--;
        return r;
    }

    // 移除以node为根的子树最大节点
    // 返回移除最大节点后的根
    Node* removeMax(Node* node) {
        if (node == NULL) {
            return node;
        }

        if (node->right != NULL) {
            node->right = removeMax(node->right);
            return node;
        }

        Node* r = node->left;
        delete node;
        m_count--;
        return r;
    }

    // 移除以node为根的子树键值为key的节点
    // 返回移除该节点之后子树的根
    Node* remove(Node* node, Key key) {
        if (node == NULL) {
            return NULL;
        }

        if (node->key > key) {
            node->left = remove(node->left, key);
            return node;
        } else if (node->key < key) {
            node->right = remove(node->right, key);
            return node;
        } else { // node->key == key
            if (node->left == NULL) {
                Node* r = node->right;
                delete node;
                m_count--;
                return r;
            } 

            if (node->right == NULL) {
                Node* l = node->left;
                delete node;
                m_count--;
                return l;
            }

            // node->right != NULL && node->left != NULL
            Node* successor = new Node(minimun(node->right));
            m_count++;
            Node* rightNode = removeMin(node->right);
            successor->left = node->left;
            successor->right = rightNode;
            delete node;
            m_count--;
            return successor;
        }
    }

    // 本质就是后序遍历
    void destroy(Node* node) {
        if (node != NULL) {
            destroy(node->left);
            destroy(node->right);

            delete node;
            m_count--;
        }
    }

    void preOrder(Node* node) {
        if (node != NULL) {
            cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node* node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->key << " ";
            inOrder(node->right);
        }
    }

    void postOrder(Node* node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << " ";
        }
    }

    void levelOrder(Node* node) {

        if (node != NULL) {
            queue<Node*> q;
            q.push(node);
            while (!q.empty()) {
                Node* p = (Node*)q.front();
                q.pop();
                cout << p->key << " ";
                if (p->left != NULL) {
                    q.push(p->left);
                }

                if (p->right != NULL) {
                    q.push(p->right);
                }
            }
        }
    }

};

#endif // !__BST_H__

