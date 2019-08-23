#include <stdio.h>
#include <stdlib.h>
 //Aðaç düðüm yapýmýz
struct node
{
    int data;
    struct node *left, *right;
};

// düðüm oluþturan fonksiyon
struct node *yeninode(int data)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


/* Eleman ekleme iþlemini yapan fonksiyon */
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


// inorder fonksiyonu node'u kucukten buyuge sýralar
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


/* Verilen düðümün alt aðacýndaki en küçük düðümü bulan fonksiyon.
   ikili arama agacýnda en kucuk sayi en soldadir.
 */
struct node *enkucuksayi(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

/* silme iþini yapan esas fonksiyonumuz */
struct node* deleteNode(struct node* root, int data)
{
    // kök düðüm NULL ise root'u return ediyor
    if (root == NULL)
        return root;

    // Silinmek istenen elemaný öncelikle bulmamýz gerekiyor.
    // Bu yüzden eðer silmek istediðimiz düðüm root'dan küçükse sol alt aðaca gidiyor.
    if (data < root->data)
        root->left = deleteNode(root->left, data);

    // Eðer silmek istediðimiz düðüm root'dan büyükse sað alt aðaca gidiyor
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    // Yukarýdaki þartlardan hiçbirisi saðlanmýyorsa aradýðýmýz düðümü bulduk demektir.
    else
    {
        // Eðer düðümün solda çocuðu yoksa...
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        // eðer düðümün saðda çocuðu yoksa...
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Ýþin en can alýcý noktasý burasý, þimdi düðümün 2 çocuðu varsa nasýl eleman sileceðiz ona bakýyoruz
        // enkucuksayi sað alt aðaçtaki en küçük deðeri bulur ve temp deðerine atar.
        struct node* temp = enkucuksayi(root->right);

        // Burada atama iþlemi yaptýk
        root->data = temp->data;

        // Burada ise silme iþlemini gerçekleþtiriyoruz
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

//test aþamasý
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
