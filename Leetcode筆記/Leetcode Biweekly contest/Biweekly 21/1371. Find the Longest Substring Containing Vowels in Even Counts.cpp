#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheLongestSubstring(string s)
    {
        /*
            cvowel����string s��Y�Ӧr������aeiou���O�X�{����
            ex :

            index    -1  0  1  2  3  4  5  6  7
                         l  e  e  t  c  o  d  e
            a         0  0  0  0  0  0  0  0  0
            e         0  0  1  2  2  2  2  2  3
            i         0  0  0  0  0  0  0  0  0
            o         0  0  0  0  0  0  1  1  1
            u         0  0  0  0  0  0  0  0  0

            cvowel vector�|�ѥ���k��s��U��<a,e,i,o,u>
            Note:
            1.  ��ڤW�|mod2����A��i�h�o��,�]���ڭ̥u�b�G�X�{�O�_���Ʀ�->0�N���Ʀ�,1�N��_�Ʀ�

                index    -1  0  1  2  3  4  5  6  7
                             l  e  e  t  c  o  d  e
                a         0  0  0  0  0  0  0  0  0
                e         0  0  1  0  0  0  0  0  1
                i         0  0  0  0  0  0  0  0  0
                o         0  0  0  0  0  0  1  1  1
                u         0  0  0  0  0  0  0  0  0

            2.  �e���ɤWindex -1��]:
                    �H�W���Ҥl����,����-1����,<0,0,0,0,0>��case�|�����D�s�b
                    ���]�ڥثetraverse��c:��cvowel=<0,0,0,0,0>,index=4
                    �bdictionary���d[<0,0,0,0,0>]=0;
                    �ҥH�ڭ̧����׬�4-0=4���i���
                    �Ѭ�eetc�S���]�t��'l'
                    ���Oleetc�i�H����o�S�����
        */
        vector<int>cvowel;
        //resize�i�H���K��l�Ʀ�5��0
        cvowel.resize(5);

        /*
            map d�@dictionary����
            �\��:�����Ҧ��Ĥ@���X�{cvowel pattern����m
            dict���c:
            �H�W���Ҥlleetcode����

                                    key                 value
                                    cvowel              index
                                    <0,1,0,0,0>         1

            �N��Ĥ@���X�{<0,1,0,0,0>�o�ت��۪�cvowel����m�O�bindex=1��
            ....
            �H������
        */
        map<vector<int>,int>d;

        /*
            �]����観��l�ƩҥH�|��
            cvowel=<0,0,0,0,0>
            index=-1
            ��i�hdictionary
            �N��Ĥ@���X�{<0,0,0,0,0>���a��b-1(�r���٨S�}�l�B)
        */
        d[cvowel]=-1;

        //�n�������aeiou
        char vowel[]={'a','e','i','o','u'};

        //�x�s�ڭ̨̳θѪ�����
        int ans=0;

        //traverse�r�ꪺ�Ҧ��r��
        for(int i=0;i<s.size();i++)
        {
            //���C�Ӧ�m���n�έp��ثe���cvowel(�Y��Ӧr��aeiou�X�{�_��or���Ʀ�)
            for(int j=0;j<5;j++)
            {
                //�p�G�o�Ӧr���Oaeiou�䤤�@��cvowel vector�N�n��s
                if (s[i]==vowel[j])
                {
                    //����a or e or i or o or u���Ӽ�+1
                    cvowel[j]+=1;
                    //mod 2(�p�e�z)
                    cvowel[j]%=2;
                }
                //�_�h���Χ�s(cvowel vector��������)
            }

            /*
                ��ثecvowel vector��pattern�S���X�{�bdictionary�̭�
                �N�����ͤF�Ĥ@���X�{��pattern
                �N�n��s�i�hdictionary

                �g�k:
                    d[cvowel]=i;
                �N�q:
                    d[�s��pattern����]=�o��pattern�Ĥ@���b����index�X�{
            */
            if(!d.count(cvowel))
                d[cvowel]=i;
            /*
                �Ϥ�,�p�G���O�Ĥ@���X�{�N�n�hdictionary�̭���X�ӬۦPpattern�Ĥ@���X�{��index d[cvowel]
                �p�Gi-d[cvowel]>ans�h��s
                �ҥH�̫�]��,ans�N�O�ڭ̭n���̨θ�
            */
            else
            {
                if(ans<i-d[cvowel])
                    ans=i-d[cvowel];
            }
        }
        return ans;
    }
};
int main()
{
    string s;
    cin>>s;
    Solution solve;
    cout<<solve.findTheLongestSubstring(s);
    return 0;
}
