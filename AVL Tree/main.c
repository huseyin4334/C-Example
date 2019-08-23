#include<stdio.h>
#include<stdlib.h>

//AVL Agacini tutacak olan dugum yapisi
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

//Yukseklik bilgisini geri donduren fonksiyon
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

//Verilen 2 degerden hangisi buyukse onu return eden fonksiyon
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Yeni dugum olusturan fonksiyon*/
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // yeni olusturulan dugum yapraktir, yapragin yuksekligi de 1 olur
    return(node);
}

// Saga dondurme fonksiyonu
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // dondurme islemi
    x->right = y;
    y->left = T2;

    // Uyuksekliklerin guncellenmesi
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // yeni root return edilir
    return x;
}

// sola dondurme islemi
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // dondurmeyi gerceklestir
    y->left = x;
    x->right = T2;

    //  yukseklikleri guncelle
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // yeni root'u dondur
    return y;
}

// denge durumunu kontrol edip yukseklik farkini return eden fonksiyon
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// AVL Agacina ekleme yapan fonksiyon
// Bir onceki yazimizda bu fonksiyonu anlattigim icin buranin icinde comment yok.
struct Node* insert(struct Node* node, int key)
{

    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;


    node->height = 1 + max(height(node->left),
                           height(node->right));


    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

/*ikilli arama agacindaki en kucuk degeri tutan fonksiyon, her seferinde arama yapmamak icin */
struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;

    /* Sol alt agacin en solundaki dugumu bulmaya calisiyoruz */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/**** Esas Fonksiyonumuz ****/
/* Recursive olan bu fonksiyonumuz modifiye edilmis alt agaci return ediyor.*/
struct Node* deleteNode(struct Node* root, int key)
{
    // 1. Adim: Standart BST agaci eleman silme islemi

    if (root == NULL)
        return root;

    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    // eger silinmek istenen dugum root ise buraya giriyor
    else
    {
        // Eger yalnizca bir cocugu var ya da hic cocugu yoksa
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;

            // hic cocugu yoksa
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // yalnizca bir cocugu varsa
             *root = *temp; // dugumu kopyaliyoruz
            free(temp);
        }
        else
        {
            // iki cocugu varsa inorder traverse yapiyoruz
            // sag alt agactaki en kucuk dugumu buluyoruz
            struct Node* temp = minValueNode(root->right);

            // sag alt agactaki en kucuk dugumu buraya kopyaliyoruz
            root->key = temp->key;

            // kopyaladigimiz dugumu siliyoruz
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // Eger yalnizca bir dugum varsa
    if (root == NULL)
      return root;

    // 2. Adim: Dugumun yuksekligini guncelliyoruz
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // 3. Adim: Denge durumunu kontrol ediyoruz
    int balance = getBalance(root);

    // Eger dengesizlik durumu varsa 4 durum ortaya cikiyor

    // sol sol durumu
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // sol sag durumu
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // sag sag durumu
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // sag sol durumu
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

//dugumleri preorder sekilde yazdiran fonksiyon
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* main fonksiyonumuzda test yapiyoruz. */
int main()
{
  struct Node *root = NULL;


    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    /* Agac yapimiz
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

    printf("AVL Agacinin ciktisi \n");
    preOrder(root);

    root = deleteNode(root, 10);

    /* 10 dugumu silindikten sonra
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */

    printf("\n10 dugumunu silindikten sonra AVL Agacinin ciktisi \n");
    preOrder(root);

    return 0;
}
