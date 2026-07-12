#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h> /* gestion des clés, chiffrement et déchiffrement */
#include <openssl/pem.h> /* Formatage(PEM), écriture et lecture de clés */
#include <openssl/bio.h> /* BIO (Basic Input/Output; système d'entrée et de sortie de OpenSSL */
#include <openssl/err.h> /* gestion des erreurs OpenSSL */

//global variable
#define SIZE 2048

RSA *generate_keys()
{
    RSA *rsa = RSA_new();
    BIGNUM *bn = BN_new();

    BN_set_word(bn, RSA_F4);

    RSA_generate_key_ex(rsa, SIZE, bn, NULL);

    BN_free(bn);

    return rsa;
}

void save_public_key(RSA *rsa)
{
    FILE *fp = fopen("public.pem", "wb");
    PEM_write_RSAPublicKey(fp, rsa);
    fclose(fp);
}

void save_private_key(RSA *rsa)
{
    FILE *fp = fopen("private.pem", "wb");
    PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(fp);
}

RSA *load_public_key()
{
    FILE *fp = fopen("public.pem", "rb");

    RSA *rsa = PEM_read_RSAPublicKey(fp, NULL, NULL, NULL);

    fclose(fp);

    return rsa;
}

RSA *load_private_key()
{
    FILE *fp = fopen("private.pem", "rb");

    RSA *rsa = PEM_read_RSAPrivateKey(fp, NULL, NULL, NULL);

    fclose(fp);

    return rsa;
}


//crypteur du message
void encrypt_message()
{
    char message[256];
    unsigned char encrypted[256];

    printf("Message : ");
    getchar();
    fgets(message, sizeof(message), stdin);

    RSA *rsa = load_public_key();

    int size = RSA_public_encrypt(
        strlen(message),
        (unsigned char *)message,
        encrypted,
        rsa,
        RSA_PKCS1_PADDING
    );

    FILE *fp = fopen("encrypted.bin", "wb");
    fwrite(encrypted, 1, size, fp);
    fclose(fp);

    RSA_free(rsa);

    printf("Message chiffre dans encrypted.bin\n");
}


//décrypteur du message
void decrypt_message()
{
    unsigned char encrypted[256];
    unsigned char decrypted[256];

    FILE *fp = fopen("encrypted.bin", "rb");

    int size = fread(encrypted, 1, sizeof(encrypted), fp);

    fclose(fp);

    RSA *rsa = load_private_key();

    int len = RSA_private_decrypt(
        size,
        encrypted,
        decrypted,
        rsa,
        RSA_PKCS1_PADDING
    );

    decrypted[len] = '\0';

    printf("Message clair : %s\n", decrypted);

    RSA_free(rsa);
}



// Début de la fonction principale
int main()
{
    int choix;

    while(1)
    {
        printf("\n1. Generer les cles\n");
        printf("2. Chiffrer\n");
        printf("3. Dechiffrer\n");
        printf("4. Quitter\n");
        printf("Choix : ");

        scanf("%d", &choix);

        if(choix == 1)
        {
            RSA *rsa = generate_keys();

            save_public_key(rsa);
            save_private_key(rsa);

            RSA_free(rsa);

            printf("Cles generees\n");
        }

        else if(choix == 2)
        {
            encrypt_message();
        }

        else if(choix == 3)
        {
            decrypt_message();
        }

        else if(choix == 4)
        {
            break;
        }
    }

    return 0;
}
