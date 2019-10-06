#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<fstream>
#include <cctype>
#include<vector>
#include"Binary_Tree.h"
#include<iostream>
using namespace std;

class Dictionary
{

private:
    /**
     * @brief tree - (Arvore) Objeto arvore do tipo string com o uso de template
     */
    Binary_Tree tree;
    /**
     * @brief array - Objeto vetor de string para manipulação dos dados do txtx
     */
    vector<string> array;
    /**
     * @brief archive - Objeto de leitura de dados de arquivo txt
     */
    fstream archive;

public:

    void writeArchive(char url[],vector<string>latter)
    {
        this->archive.open(url);

        for(int i=0; i < latter.size();i++){
             archive<<latter[i]<<endl;
        }

        archive.close();
    }

    void readArchive(char url[])
    {

        this->archive.open(url);
        string str;

        if(this->archive.is_open())
        {

            while(getline(this->archive,str))
            {
                int size = str.length();

                for(int i = 0; i < size; i++)
                {
                    str[i] = toupper(str[i]);
                }

                this->array.push_back(str);
            }

            this->archive.close();
            insertBinaryTree();
        }
    }
private:
    /**
     * @brief order - (Ordenar) Método de ordenação do array
     * Metodo baseado no método de ordenação bolha (Bubblesort)
     */
    void order()
    {

        int sizeArray = this->array.size();
        string str;

        for(int i = 0; i < sizeArray; i++)
        {
            str = this->array[i];

            int pos = str.find("\t",0);//pegue o tamanho da string onde encontra o \t
            str = str.substr(0, pos);//traga a string do inicio até o \t

            for(int j = 1; j < sizeArray; j++)
            {

                string next = this->array[j];
                int posNext = next.find("\t",0);
                next = next.substr(0, posNext);

                if(str.compare(next) == 1)//se for igual a 1 o str maior que seu proximo valor realize a troca
                {
                    string aux = array[i];
                    array[i] = array[j];
                    array[j] = aux;
                }
            }
        }
    }

private:
    /**
     * @brief insertBinaryTree - (Inserir na arvore binaria) Método de inserir os dados no padrão para a arvore binaria do arquivo.
     */
    void insertBinaryTree()
    {
        string str;
        string keyEnghish;//chave
        string valuePortuguese;//conteudo

        int sizeArray = this->array.size();

        for(int i = 0; i < sizeArray; i++)
        {

            str = this->array[i];

            int pos, length;
            pos = str.find("\t",0);

            keyEnghish = str.substr(0, pos);

            length = pos+1;
            pos = str.find("\t", pos+1);

            valuePortuguese = str.substr(length,pos-length);

            tree.treeInsert(keyEnghish,valuePortuguese);//Inseri na arvore
        }

        array.clear();//limpa o array após todas as operações.
    }

public:
    /**
     * @brief insertTreeBinary (Inserir na arvore binaria) - Método de inserção de dados na arvore e no arquivo pelo usuário
     * @param key - chave recebida
     * @param value - conteudo recebido
     * @param url - caminho do arquivo
     * @return true/false - verdadeiro se tudo ocorrer bem se não retorna false
     */
    bool insertTreeBinary(string key,string value)
    {
        int sizeKey = key.length();
        int sizeValue = value.length();

        for(int i = 0; i < sizeKey; i++)
        {
            key[i] = toupper(key[i]);
        }

        for(int i = 0; i < sizeValue; i++)
        {
            value[i] = toupper(value[i]);
        }

        if(tree.searchElement(tree.root,key).compare("NULL") == 0) //se for igual a null é porque o elemento não existe na arvore então posso inserir
        {
            tree.treeInsert(key,value);
            return true;
        }

        return false;
    }

    string searchElement(string key)
    {

        int size = key.length();

        for(int i = 0; i < size; i++)
        {
            key[i] = toupper(key[i]);
        }

        string portuguese = tree.searchElement(tree.root,key);

        if(portuguese.compare("NULL") == 0){
            return "( A palvra não existe no dicionario )";
        }

        return portuguese;
    }

    vector<string> searchElementLetter(char latter)
    {
        latter = toupper(latter);
        tree.searchElementLetter(tree.root,latter);
        return tree.getLatterArray();
    }

    void clearArrayTree(){
        tree.clearLatterArray();
    }


    void removeKey(string key){

        int size = key.length();

        for(int i = 0; i < size; i++)
        {
            key[i] = toupper(key[i]);
        }

        tree.treeRemove(tree.root,key);
    }


    /**
     * @brief getDictionary - Método de retorno de todos os dados do dicionario
     */
    void getDictionary()
    {
        this->tree.inOrder(this->tree.root);
    }
};
#endif // DICTIONARY_H
