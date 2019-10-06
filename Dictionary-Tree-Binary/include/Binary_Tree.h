#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class No
{

public:
    /**
     * @brief left - ( Esquerda ) No que aponta para o anterior do No criado ou para o no da esquerda.
     */
    No* left;

    /**
     * @brief right - ( Direita ) No que aponta para proximo o No criado ou para o no da direita.
     */
    No* right;

    /**
     * @brief key - ( chave ) indentificadora e unica para o Objeto No.
     */
    string key;

    /**
     * @brief value - ( conteudo ) armazenado no No.
     */
    string value;

public:
    /**
     * Construtor - Responsável por receber a chave e o conteudo a ser armazenado quando construido o No
     * e inicializar o valor No esquerda e Direita como NULL como segue a regra de uma Arvore Binaria.
     * @brief No - Objeto a ser criado.
     * @param key - chave de indentificação.
     * @param value - conteudo a ser armazenado.
     */
    No (string key,string value)
    {
        this->left = this->right = NULL;
        this->key = key;
        this->value = value;
    }

    // Métodos Gets e Sets

    void setLeft(No* no)
    {
        this->left = no;
    }

    No* getLeft()
    {
        return this->left;
    }

    void setRight(No* no)
    {
        this->right = no;
    }

    No* getRight()
    {
        return this->right;
    }

    void setKey(string key)
    {
        this->key = key;
    }

    string getKey ()
    {
        return this->key;
    }

    void setValue(string value)
    {
        this->value = value;
    }

    string getValue()
    {
        return this->value;
    }
};


/**
 * @brief The Binary_Tree class
 * Arvore Binaria de busca
 * Regras - Tem no maximo dois filhos cada folha. Um a esquerda e um a direita;
 *        - O filho da esquerda sempre é menor do que o da direita.
 */
class Binary_Tree
{

public:
    /**
     * @brief root - (raiz) - No raiz ou no cabeça da arvore.
     */
    No *root;

    vector<string> latters;
public:


    Binary_Tree()
    {
        this->root = NULL;
    }

    /**
     * @brief getRoot - Método de retorno do No raiz da arvore
     * @return No raiz
     */
    No* getRoot()
    {
        return this->root;
    }

    vector <string> getLatterArray()
    {
        return this->latters;
    }

    void clearLatterArray()
    {
        this->latters.clear();
    }

    /**
     * @brief insertTree (Inserir Arvore ) - Método de inserir dados na arvore.
     * @param key - Chave de indentificação do conteudo a ser armazenado.
     * @param value - Conteudo a ser armazenado.
     * @return true / false - Se caso tudo ocorrer bem true, se não false.
     * Description - Se a riaz da arvore for nula, então é criado o novo No e raiz aponta para ele.
     * Se não chama o método leaf (Folha).
     */
    bool treeInsert (string key,string value)
    {
        if(this->root == NULL)
        {
            this->root = new No (key,value);
            return true;
        }
        else
        {
            return leaf(this->root,key,value);
        }
    }

private:

    /**
     * @brief leaf - (Folha) Método verifica folhas da arvore.
     * @param no - No passado por parametro.
     * @param key - Chave indenficadora.
     * @param value - Valor a ser armazenado
     * @return true / false - se tudo ocorrer bem true se não false.
     * Description -
     *             Regras - Primeiro verifica se a chave é menor que a chave do No
     *                      Então verifica se o filho da esquerda do No com a chave
     *                      e NULL. Se sim, ele recebe o novo No porque chegou o fim da arvore,
     *                      se não vai procurando o proximo no da esquerda até que chegue na folha nula.
     *
     *                      Segundo se o caso um não for positivo verifica se a chave é maior que a chave do No.
     *                      Se sim verifica se a folha do no da chave e null, se sim ele recebe o novo no.
     *                      Se não ele ira desse até encontra uma folha nula pela esquerda.
     */
    bool leaf(No *&no,string key,string value)
    {

        if(key.compare(no->getKey()) == -1)
        {

            if(no->left == NULL)
            {

                No* new_No = new No (key,value);
                no->left = new_No;
                return true;

            }
            else
            {
                leaf(no->left,key,value);
            }

        }
        else if(key.compare(no->getKey()) > 0)
        {

            if(no->right == NULL)
            {

                No* new_No = new No(key,value);
                no->right = new_No;
                return true;
            }
            else
            {

                leaf(no->right,key,value);
            }
        }

        return false;
    }

public:

    /**
     * @brief inOrder (emOrdem) - Função de busca em ordem.
     * Regra - percorrer a arvore pela direita até que encontre o no folha e seu proximo seja null
     * quando for null imprime o no folha e seque para direita da mesma forma
     * @param no ponteiro de No
     */
    void inOrder(No *&no)
    {
        if(no != NULL)
        {
            inOrder(no->left);
            cout<<no->getKey()<<"\t"<<no->getValue()<<endl;
            inOrder(no->right);
        }
    }

    void searchElementLetter(No *&no,char value)
    {
        if(no != NULL)
        {
            searchElementLetter(no->left,value);
            string aux = no->getKey();

            if(value == aux[0])
            {
                this->latters.push_back( no->getKey()+"\t"+no->getValue());
            }
            searchElementLetter(no->right,value);
        }
    }

    /**
        * @brief searchElement - (Pesquisa Elemento) - Método de pesquisa de elemento existente na arvore.
        * @param no - recebe um no raiz da arvore para verificação do elemento.
        * @param key - Elemento chave a ser verificado.
        * @return No - elemento encontrado ou No NULL caso não exista.
        */
    string searchElement(No* &no,string key)
    {

        if(no == NULL)
        {

            return "NULL";
        }

        if(no->getKey().compare(key) == 0)
        {
            return no->getValue();
        }

        if(no->getKey().compare(key) > 0)
        {
            return searchElement(no->left,key);
        }
        else if (no->getKey().compare(key) < 0)
        {
            return searchElement(no->right,key);
        }
    }

    No* searchMin(No*& no)
    {

        if(no->right != NULL)
        {
            return no->right;
        }
        else
        {
            return no;
        }

    }

    void treeRemove (No *& no,string key)
    {
        No *temp = NULL;

        if(no == NULL)
            return;
        if(key.compare(no->getKey()) == 0)
        {
            temp = no;

            if(no->left == NULL)
                no = no->right;
            else if(no->right == NULL)
                no = no->left;
            else
            {
                //temp = bigger(no->left);
                no->setKey(temp->getKey());
            }

            delete temp;
            return;
        }
        else if(key.compare(no->getKey()) < 0)
            treeRemove(no->left,key);
        else
            treeRemove(no->right,key);


    }


/**
 * @brief clearTree - ( Limpar Arvore) Método de limpeza dos dados da arvore
 * Segue o mesmo conceito do método em ordem pecorrer toda a arvore e apaga todos os Nos.
 * @param no  - Recebe o No raiz da arvore
 */
void clearTree(No *no)
{
    if(no != NULL)
    {
        clearTree(no->getLeft());
        clearTree(no->getRight());
        delete no;
    }
}
};
#endif // BINARY_TREE_H
