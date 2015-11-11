#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Tokenizer
{
  private:


    istream &in;
    ifstream tokensList;
    string currentToken;


  public:
        Tokenizer (istream& _in, char *fname):in(_in)
        {
            tokensList.open (fname);
        }

        bool getNextToken ()
        {

            return in >> currentToken;
        }

        int tokenId ()
        {
            //currentToken? tokensList

            tokensList.clear();
            tokensList.seekg(0);

            string tmp;
            int count = 0;
            while (tokensList >> tmp)
            {

                if (tmp == currentToken)
                    return count;

                count++;

            }

            return -1;
        }

        string tokenString ()
        {
            return currentToken;

        }

        bool duplicates ()
        {
            //�������� ���� ��� �����
            //� �������� ��� ����������
            return false;
        }

        void ingnoreDuplicates (bool ingrone = true)
        {
            //��� ���������� �� ������
            //ingnoreDuplicates ������������� ��
            //�������� ������ ���� ������� �������
            //�� ����������� ������. �������� � ������� ������
            //aa
            //bb
            //cc
            //bb
            //dd
            //�������, �� ������� bb ��� ������ 1,
            //� dd ��� ������ 3

        }

};

int main()
{


    Tokenizer t (cin, "tokens.txt");

    while (t.getNextToken())
    {

        cout << t.tokenString ()
             << "("
             << t.tokenId()
             << ")";
    }


}
