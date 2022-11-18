#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>

void plural_words_function(char a[1000]);
void number_of_words_function(char a[1000]);
void number_of_sentences_function(char a[1000]);
void number_of_letters_function(char a[1000]);
char *word_search = "word search";
char *labial_and_palatal_harmony = "labial and palatal harmony";
char *connexion = "connexion";
char *strong_and_soft_vowels = "strong and soft consonants";
char *number_of_words = "number of words";
char *number_of_sentences = "number of sentences";
char *number_of_letters = "number of letters";
char *plural_words = "plural words";
int a = 100, b = 100, c = 100, d = 100, e = 100, f = 100, g = 100, i, h=100;
int temp_of_words = 0;
int number_of_bold_vowel = 0, number_of_thin_vowel = 0, strong_consonants = 0, soft_consonants = 0,number_of_unrounded_vowel=0,number_of_rounded_vowel=0;
char rule[100];
char text[10000],text2[10000];
int wordtemp1 = 0,wordtemp2=0, connexion_temp = 0, temp_of_letters = 0;
char *vowels = "aeioöuAEIOUÖ";
char *unrounded_vowels = "aeýiAEIÝ";
char *consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
char *firstword, *secondword, *firstword2,*firstword3;
char endofword[] = " ,!?.;:"; //de�i�kenleri atad�m

int main()
{

    SetConsoleCP(1254);
    SetConsoleOutputCP(1254);
    setlocale(LC_ALL, "Turkish_turkish.1254"); //t�rk�e karakterler i�in uyumluluk
    printf("Please enter the text:");
    gets(text); //girdi al�m�
    strcpy(text2,text);
    printf("I'm checking for:\nconnexion,\nlabial and palatal harmony,\nstrong and soft consonants,\nnumber of words,\nnumber of sentences,\nnumber of letters,\nplural words,\nword search\n");
    printf("Is there any rule which you want checked?\n:"); //men� ba�lang���
    gets(rule);

    a = strcmp(connexion, rule); //girilen girdi ile fonksiyonun isminin kar��la�t�r�lmas�
    b = strcmp(labial_and_palatal_harmony, rule);
    c = strcmp(strong_and_soft_vowels, rule);
    d = strcmp(number_of_words, rule);
    e = strcmp(number_of_sentences, rule);
    f = strcmp(number_of_letters, rule);
    g = strcmp(plural_words, rule);
    h = strcmp(word_search,rule);

    if (a == 1)
    {
        abort;
    }
    else if (a == 0)
    {
        connexion_function(text);   //kar��la�t�rma do�ruysa fonksiyonun �al��t�r�lmas�
        print_connexion_function(text);
    }

    if (b == 1)
    {
        abort;
    }
    else if (b == 0)
    {
        labial_and_palatal_harmony_function(text);
    }

    if (c == 1)
    {
        abort;
    }
    else if (c == 0)
    {
        strong_and_soft_vowels_function(text);
    }

    if (d == 1)
    {
        abort;
    }
    else if (d == 0)
    {
        number_of_words_function(text);
    }

    if (e == 1)
    {
        abort;
    }
    else if (e == 0)
    {
        number_of_sentences_function(text);
    }
    if (f == 1)
    {
        abort;
    }
    else if (f == 0)
    {
        number_of_letters_function(text);
    }
    if (g == 1)
    {
        abort;
    }
    else if (g == 0)
    {
        plural_words_function(text);
    }
    if (h == 1)
    {
        abort;
    }
    else if (h == 0)
    {
        word_search_function(text);
    }//men� biti�i
    return 0;
}

void connexion_function(char a[1000])   //ulama say�s�n� yazd�rmak i�in fonksiyon
{
    int j = 0;

    while (text[j + 2] != '\0')
    {
        if ((strchr(consonants, text[j]) != NULL) && (text[j + 1] == ' ') && (strchr(vowels, text[j + 2]) != NULL))//ilk kelimenin son harfinin �ns�z, aras�nda bo�luk, ve ikinci kelimenin de �nl� olmas� halinde ulama say�s�n� g�steren sayac� artt�r�r.
            connexion_temp++;
        j++;
    }
    printf("There are %d connexion in this text", connexion_temp);
}

void print_connexion_function(char text[])  //ulamalar� yazd�rmak i�in fonksiyon
{

    char *part_of_text = strtok(text, endofword);//endofword de�i�kenindeki elemanlardan birine ula�ana kadar olan karakterleri atama
    firstword = part_of_text;

    while (part_of_text != NULL)
    {
        secondword = strtok(NULL, endofword);

        if ((strchr(consonants, (int)firstword[strlen(part_of_text) - 1]) != NULL) && (strchr(vowels, (int)secondword[0]) != NULL))//ilgili kelimeleri yazd�rma
        {
            printf("\n%s %s ,", firstword, secondword);
        }
        firstword = secondword;
    }
}

void labial_and_palatal_harmony_function(char text[])   //b�y�k ve k���k �nl� uyumu fonksiyonu
{

    int k=0;

    char *part_of_text2 = strtok(text, endofword);
    firstword2 = part_of_text2;

     printf("\nThese are obey the rule of palatal harmony:\n");//b�y�k �nl� uyumu sorgulama

    while (firstword2 != NULL)
    {
        for(int i=0;firstword2[i]!=NULL;i++)

        {



        if (firstword2[i] == 'a' || firstword2[i] == '�' || firstword2[i] == 'o' || firstword2[i] == 'u' || firstword2[i] == 'A' || firstword2[i] == 'I' || firstword2[i] == 'U' || firstword2[i] == 'O' )
        {
            number_of_bold_vowel++;
        }
         if (firstword2[i] == 'e' || firstword2[i] == 'i' || firstword2[i] == '�' || firstword2[i] == '�' || firstword2[i] == 'E' || firstword2[i] == '�' || firstword2[i] == '�' || firstword2[i] == '�')
        {
            number_of_thin_vowel++;
        }

        }// sert ve yumu�ak �ns�z say�lar� bulma





        if (number_of_bold_vowel > 0 && number_of_thin_vowel > 0)
        {
            abort;
        }
        else if(number_of_bold_vowel==0 && number_of_thin_vowel==0)
        {
            abort;
        }
        else
        {
            printf("%s,\n", firstword2);
        }
        number_of_bold_vowel=0;
        number_of_thin_vowel=0;

        firstword2 = strtok(NULL, endofword);//sonraki kelime i�in gerekli olan atama
    }



     printf("\nThese are obey the rule of labial harmony:\n");//k���k �nl� uyumu sorgulama
    int temp1=0,temp2=0;
    char *part_of_text3 = strtok(text2, endofword);
    firstword3 = part_of_text3;

     while (firstword3 != NULL)
    {
        for(int i=0;firstword3[i]!=NULL;i++)

        {

            if (firstword3[i] == 'a' || firstword3[i] == 'e' || firstword3[i] == '�' || firstword3[i] == 'i' || firstword3[i] == 'A' || firstword3[i] == 'E' || firstword3[i] == 'I' || firstword3[i] == '�' )
        {
            number_of_unrounded_vowel++;
        }


            if (firstword3[i] == 'o' || firstword3[i] == 'ö' || firstword3[i] == 'u' || firstword3[i] == 'ü' || firstword3[i] == 'O' || firstword3[i] == 'Ö' || firstword3[i] == 'U' || firstword3[i] == 'Ü' )
        {
            number_of_rounded_vowel++;
        }

        }
            if(firstword3[i]=='o'||firstword3[i]=='ö'||firstword3[i]=='u'||firstword3[i]=='ü')
            {
            k=i+1;
        for(k;firstword3[k]!=NULL;k++){
            if(firstword3[k]=='a'||firstword3[k]=='e'||firstword3[k]=='u'||firstword3[k]=='ü')
            {
            temp1++;
            }
            else if(firstword3[k]=='o'||firstword3[k]=='ö'||firstword3[k]=='ı'||firstword3[k]=='i')
            {
                temp2++;
            }
            }
        break;
        }
    }


        if (number_of_unrounded_vowel>0 && number_of_rounded_vowel==0)
        {
            printf("%s,\n", firstword3);
        }

      else if(temp1>0&&temp2==0)
      {
          printf("%s,\n",firstword3);
      }



        number_of_unrounded_vowel=0;
        number_of_rounded_vowel=0;

        firstword3 = strtok(NULL, endofword);
    }









void strong_and_soft_vowels_function(char a[1000])//sert ve yumu�ak �ns�z fonksiyonu
{
    for (int n = 0; n < strlen(text); n++)
    {

        if (text[n] >= 'a' && text[n] <= 'z')
            text[n] = text[n] - 32;

        if (text[n] == '�' || text[n] == 'F' || text[n] == 'H' || text[n] == 'K' || text[n] == 'P' || text[n] == 'T' || text[n] == 'S' || text[n] == '�' || text[n] == '�' || text[n] == '�')
            wordtemp1++;


        if (text[n] == 'B' || text[n] == 'C' || text[n] == 'D' || text[n] == 'G' || text[n] == 'J' || text[n] == 'L' || text[n] == 'M' || text[n] == 'N' || text[n] == 'R' || text[n] == 'V' || text[n] == 'Y' || text[n] == 'Z')
            wordtemp2++;
    }

    printf("There are %d strong consonants\n", wordtemp1);
    printf("There are %d soft consonants\n", wordtemp2);


}

void number_of_words_function(char a[1000]) // kelime say�s� bulma
{
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' || text[i] == '.' || text[i] == '?' || text[i] == ',' || text[i] == '!')
        {
            temp_of_words++;
        }
    }

    printf("%d", temp_of_words);
}

void number_of_sentences_function(char a[1000])//c�mle say�s� bulma
{

    int amount_of_sentences = 0;

    while (text[i] != '\0')
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i] == ':')
        {
            amount_of_sentences++;
        }
        i++;
    }
    printf("%d", amount_of_sentences);
}

void number_of_letters_function(char text[]) //harf sayisi bulma
{

    temp_of_letters = strlen(text);

    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' || text[i] == '!' || text[i] == '.' || text[i] == '-' || text[i] == '?' || text[i] == '$' || text[i] == '%' || text[i] == '*' || text[i] == '_' || text[i] == '(' || text[i] == ')' || text[i] == '/' || text[i] == '&' || text[i] == ',')
        {
            temp_of_letters--;
        }
    }

    printf("%d", temp_of_letters);
}
void plural_words_function(char a[1000])//�o�ul kelimeleri bulma ve yazd�rma
{
    int plurals = 0;
    char *word;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 'l' && (text[i + 1] == 'a' || text[i + 1] == 'e') && text[i + 2] == 'r')
        {
            plurals++;
        }
    }
    printf("There are %d plural words.\n", plurals);

    word = strtok(text, endofword);

     for(int j=0;j<strlen(word);j++){
        if (word[j] == 'l' && (word[j+1] == 'e' || word[j+1] == 'a') && word[j+2] == 'r')
        {
            printf("%s,\n", word);
        }
      }


    while (word != NULL)
    {
        word = strtok(NULL, endofword);
      for(int j=0;j<strlen(word);j++){
        if (word[j] == 'l' && (word[j+1] == 'e' || word[j+1] == 'a') && word[j+2] == 'r')
        {
            printf("%s,\n", word);
        }
      }

    }
}

void word_search_function(char a[1000])//istenilen kelimeyi metinde olup olmad���n�n sorgulanmas�
{
    char word1[22];


    printf("Type the word which you want search it:\n");
    gets(word1);

    char *control;

    control=strstr(text,word1);

    if(control==NULL)
    {
        printf("Word didnt found.");
    }
    else
    {
        printf("Word found in this text.");
    }

}
