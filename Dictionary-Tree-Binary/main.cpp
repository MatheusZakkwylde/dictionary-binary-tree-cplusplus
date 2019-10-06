#include"Dictionary.h"
#include"colors.h"
#include<stdlib.h>
int main()
{
    //troque o caminho do arquivo para o caminho de sua maquina
    char urlArchive[] = "/home/linuxlite-anonymous/Downloads/Dictionary/archive.txt";
    char urlLatter[] ="/home/linuxlite-anonymous/Downloads/Dictionary/archiveLatter.txt";

    Dictionary dictionary;

    vector<string> arrayLetter;
    string keyEnglish,wordPortuguese,letter, keyRemove;
    int option;
    char charOption;


    //Inicializando dados no dicionario
    dictionary.readArchive(urlArchive);

    while(option != 6)
    {
        foreground(BLUE);

        cout<<"--------- DICIONARIO INGLES/PORTUGUES------------" <<endl<<endl;

        cout<<" 1 - MOSTRAR DICIONÁRIO; " <<endl;
        cout<<" 2 - INSERIR PALAVRA; " <<endl;
        cout<<" 3 - REMOVER PALAVRA; " <<endl;
        cout<<" 4 - BUSCAR TRADUÇÃO; " <<endl;
        cout<<" 5 - BUSCA PALAVRA POR LETRA; " <<endl;
        cout<<" 6 - SAIR; " << endl<<endl;

        foreground(YELLOW);
        cout<<" Digite sua opção: ";
        cin >> option;
        foreground(BLUE);

        switch(option)
        {

        case 1:
            system("clear");
            foreground(WHITE);
            dictionary.getDictionary();
            foreground(BLUE);
            cout<<endl;
            break;
        case 2:

            system("clear");
            cout<<"Digite a  palavra em Inglês: " <<endl;
            cin>>keyEnglish;
            cout<<"Digite a tradução em Português: " <<endl;
            cin>>wordPortuguese;
            system("clear");

            if(dictionary.insertTreeBinary(keyEnglish,wordPortuguese))
            {
                cout << "Palavra inserida com sucesso!" <<endl<<endl;
            }
            else
            {
                cout << "Esta palavra já existe no Dicionário!" <<endl<<endl;
            }

            break;

        case 3:
            cout << "Digite a chave a ser removida: " <<endl;
            cin >> keyRemove;
            dictionary.removeKey(keyRemove);
            break;
        case 4:
            system("clear");
            cout << "Digite a palavra em Inglês: ";
            cin >> keyEnglish;
            foreground(WHITE);
            system("clear");
            cout<<"Palavra: "<<keyEnglish<<endl;
            cout<<"\n Tradução: " <<dictionary.searchElement(keyEnglish) <<endl<<endl;
            foreground(BLUE);
            break;

        case 5:
            system("clear");
            cout << "Digite a primeira letra da palavra a ser pesquisada: "<<endl;
            cin >> letter;
            system("clear");

            arrayLetter = dictionary.searchElementLetter(letter[0]);
            cout<<endl;
            foreground(WHITE);
            for(int i = 0; i < arrayLetter.size(); i++)
            {
                cout <<arrayLetter[i] << endl;
            }

            cout<<"\nQuantidade de palavras com a letra: "<<letter<<" ( "<<arrayLetter.size()<<" )"<<endl<<endl;
            foreground(BLUE);
            cout<<"Deseja salvar o resultado da pesquisa em um arquivo?(S/N)";
            cin>>charOption;

            if(charOption == 'n' || charOption == 'N')
            {
                system("clear");
                arrayLetter.clear();
                dictionary.clearArrayTree();
            }
            else if(charOption == 'S' || charOption == 's')
            {
                dictionary.writeArchive(urlLatter,arrayLetter);
                system("clear");
                cout<<"\nDados salvo com sucesso no arquivo"<<endl<<endl;
                cout<<"Confira seus dados em: "<<urlLatter<<endl<<endl;
                arrayLetter.clear();
                dictionary.clearArrayTree();

            }
            else
            {
                system("clear");
                foreground(RED);
                cout<<"Erro de digitação. Os dados não foram salvos"<<endl<<endl;
                foreground(BLUE);
            }

            break;

        case 6:
            option = 6;
            break;

        default:
            system("clear");
            foreground(RED);
            cout<<"\nValor incorreto!" <<endl<<endl;
            foreground(RED);
            break;
        }
    }

    return 0;
}


