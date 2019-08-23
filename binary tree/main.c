#include <stdio.h>
#include <stdlib.h>
 //A�a� d���m yap�m�z
struct node
{
    int data;
    struct node *left, *right;
};

// d���m olu�turan fonksiyon
struct node *yeninode(int data)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


/* Eleman ekleme i�lemini yapan fonksiyon */
struct node* ekle(struct node* node, int data)
{
    if (node == NULL)
        return yeninode(data);

    if (data < node->data)
        node->left  = ekle(node->left, data);
    else
        node->right = ekle(node->right, data);

    return node;
}


// inorder fonksiyonu node'u kucukten buyuge s�ralar
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d ", root->data);
    }
}


/* Verilen d���m�n alt a�ac�ndaki en k���k d���m� bulan fonksiyon.
   ikili arama agac�nda en kucuk sayi en soldadir.
 */
struct node *enkucuksayi(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

/* silme i�ini yapan esas fonksiyonumuz */
struct node* deleteNode(struct node* root, int data)
{
    // k�k d���m NULL ise root'u return ediyor
    if (root == NULL)
        return root;

    // Silinmek istenen eleman� �ncelikle bulmam�z gerekiyor.
    // Bu y�zden e�er silmek istedi�imiz d���m root'dan k���kse sol alt a�aca gidiyor.
    if (data < root->data)
        root->left = deleteNode(root->left, data);

    // E�er silmek istedi�imiz d���m root'dan b�y�kse sa� alt a�aca gidiyor
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    // Yukar�daki �artlardan hi�birisi sa�lanm�yorsa arad���m�z d���m� bulduk demektir.
    else
    {
        // E�er d���m�n solda �ocu�u yoksa...
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        // e�er d���m�n sa�da �ocu�u yoksa...
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // ��in en can al�c� noktas� buras�, �imdi d���m�n 2 �ocu�u varsa nas�l eleman silece�iz ona bak�yoruz
        // enkucuksayi sa� alt a�a�taki en k���k de�eri bulur ve temp de�erine atar.
        struct node* temp = enkucuksayi(root->right);

        // Burada atama i�lemi yapt�k
        root->data = temp->data;

        // Burada ise silme i�lemini ger�ekle�tiriyoruz
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

//test a�amas�
int main()
{
    /*
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = ekle(root, 50);
    root = ekle(root, 30);
    root = ekle(root, 20);
    root = ekle(root, 40);
    root = ekle(root, 70);
    root = ekle(root, 60);
    root = ekle(root, 80);

    printf("\nVerilan agacin preorder Siralamasi\n");
    preorder(root);

    printf("\nVerilan agacin postorder Siralamasi\n");
    postorder(root);

    printf("\nVerilan agacin inorder Siralamasi \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);

    printf("Verilan agacin inorder Siralamasi \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);

    printf("Verilan agacin inorder Siralamasi \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);

    printf("Verilan agacin inorder Siralamasi \n");
    inorder(root);


    return 0;
}
