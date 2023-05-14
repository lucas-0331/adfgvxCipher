/* Lucas Costa - 04/25/2023 to 05/08/2023 */
/* AED III - Professor Tiago Gonçalves Botelho */
/* Project - Para os algoritmos de Criptografia, o programa deverá receber uma frase e apresentá-la
criptografada de acordo com o algoritmo implementado. */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int menu();
void text();
void text_adfgvx(int);
int key();
int key_validation();
int key_ordenation();
void filter();
int compare(const void *a, const void *b);
int print_matrix();
int final_crypto(int);

int num_array[8] = {0,1,2,3,4,5,7};
char adfgvx[6] = {'A','D','F','G','V','X'};
char adfgvx_square[6][6] = {{'4','w','a','q','f','8'},
                            {'b','g','2','o','d','y'},
                            {'0','x','c','n','h','1'},
                            {'9','r','7','l','e','t'},
                            {'j','z','p','5','v','k'},
                            {'u','6','s','3','m','i'}};
char matrix[8][8];
char void_char[2] = "";
char input_text[32], input_adfgvx[64], output_adfgvx[64];
char input_key[8], output_key[8];

int main()
{
    int option, success = -1, line;
    do
    {
        option = menu();
        switch(option)
        {
            case 0:
                printf("\nBye bye!\n\n");
                return 0;
            break;
            case 1:
                text();
            break;
            case 2:
                for(int i = 0; i < 8; i++)
                {
                    num_array[i] = i;
                }
                line = key();
            break;
            case 3:
                final_crypto(line);
            break;
            default:
                printf("\nOption not available.\n\n");
            break;
        }
    }
    while(option != 0);
}

int menu()
{
    int option;
    printf("\n======================================\n");
    printf("|                                    |\n");
    printf("|     This a menu crypto ADFGVX      |\n");
    printf("|  [1] - add text                    |\n");
    printf("|  [2] - add key(dont repeat chars)  |\n");
    printf("|  [3] - result                      |\n");
    printf("|  [0] - exit                        |\n");
    printf("|                                    |\n");
    printf("======================================\n");
    printf("\nSelect your option: ");
    scanf("%d", &option);
    return option;
}

void text()
{
    strcpy(input_adfgvx, void_char);
    strcpy(input_key, void_char);
    strcpy(output_adfgvx, void_char);
    printf("\nInput your text: ");
    scanf(" %[^\n]", input_text);
    int len_input_text = strlen(input_text);
    for(int i = 0; i < len_input_text; i++)
    {
        input_text[i] = tolower(input_text[i]);
    }
    text_adfgvx(len_input_text);
}

void text_adfgvx(int len_text_adfgvx)
{
    int aux_cont = 0;
    char aux_char;
    do 
    {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) 
            {
                //Se forem iguais, atribua o indice ADFGVX para uma nova string de entrada criptografada
                if (input_text[aux_cont] == adfgvx_square[i][j])
                {
                    aux_char = adfgvx[i];
                    strcat(input_adfgvx, &aux_char);
                    aux_char = adfgvx[j];
                    strcat(input_adfgvx, &aux_char);
                }
            }
        }
        aux_cont++;
    }
    while(input_text[aux_cont] != '\0');
    filter();
    printf("\nFirst string generated in the array: %s\n", input_adfgvx);
}

int key()
{
    strcpy(input_key, void_char);
    int success = -1;
    printf("\nInput your key: ");
    scanf(" %[^\n]", input_key);
    success = key_validation();
    if(success == 1)
    {
        printf("\nKey valid!\n\n");
    }
    else
    {
        printf("\nKey not valid!\n");
        printf("\n( ͡° ͜ʖ ͡°)\n\n");
        return 0;
    }
    success = -1;
    success = print_matrix();
    if(success > 0)
    {
        printf("\nMatrix ADFGVX\n");
    }
    key_ordenation();
    return success;
}

int key_validation()
{
    int len_input_key = strlen(input_key);
    //Se a chave possuir caracteres repetidos, então ela é inválida
    for(int i = 0; i < len_input_key; i++)
    {
        for(int j = i + 1; j < len_input_key; j++)
        {
            if(input_key[i] == input_key[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int print_matrix()
{
    int len_adfgvx = strlen(input_adfgvx);
    int len_key = strlen(input_key);
    if(len_adfgvx  == 0)
    {
        printf("\nYou need to input text!\n\n");
        return 0;
    }

    int rows = len_adfgvx / len_key;
    if(len_adfgvx % len_key != 0)
    {
        rows++;
    }
    matrix[rows][len_key];
    int cont = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < len_key; j++)
        {
            if(cont < len_adfgvx)
            {
                matrix[i][j] = input_adfgvx[cont];
                cont++;
            }
            else
            {
                matrix[i][j] = '_';
            }
            printf("| %c |", matrix[i][j]);
        }
        printf("\n");
    }
    return rows;
}

int final_crypto(int lines)
{
    strcpy(output_adfgvx, void_char);
    int len_adfgvx = strlen(input_adfgvx);
    int len_key = strlen(input_key);
    char aux_char;
    if(len_adfgvx  == 0)
    {
        printf("\nYou need to input text!\n\n");
        return 0;
    }
    if(len_key  == 0)
    {
        printf("\nYou need to input key!\n\n");
        return 0;
    }
    int cont = 0, aux_number;
    printf("\n");
    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < len_key; j++)
        {
            aux_number = num_array[j];
            printf("| %c |", matrix[i][aux_number]);
            if(matrix[i][aux_number]!= '_')
            {
                aux_char = matrix[i][aux_number];
                strcat(output_adfgvx, &aux_char);
            }
        }
        printf("\n");
    }
    printf("\nMatrix ordened ADFGVX\n");
    printf("\nFinal crypto: %s\n", output_adfgvx);
}

int key_ordenation()
{
    int i, j, len;

    len = strlen(input_key);

    strcpy(output_key, input_key);

    qsort(output_key, len, sizeof(char), compare);

    int temp_array[8];
    for (i = 0; i < len; i++) {
        temp_array[i] = num_array[i];
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (input_key[j] == output_key[i]) {
                num_array[i] = temp_array[j];
                temp_array[j] = -1;  //marca o valor como processado
                break;
            }
        }
    }

    printf("\nKey ordened: %s\n\n", output_key);
    return 0;
}

int compare(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

void filter()
{
    char *src = input_adfgvx;
    char *dest = input_adfgvx;
    while(*src)
    {
        if(isalpha(*src))
        {
            *dest++ = *src;
        }
        src++;
    }
    *dest = '\0';
}
