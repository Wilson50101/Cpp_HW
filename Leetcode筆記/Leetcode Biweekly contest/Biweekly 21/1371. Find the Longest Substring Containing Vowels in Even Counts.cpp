#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheLongestSubstring(string s)
    {
        /*
            cvowel紀錄string s到某個字元為止aeiou分別出現次數
            ex :

            index    -1  0  1  2  3  4  5  6  7
                         l  e  e  t  c  o  d  e
            a         0  0  0  0  0  0  0  0  0
            e         0  0  1  2  2  2  2  2  3
            i         0  0  0  0  0  0  0  0  0
            o         0  0  0  0  0  0  1  1  1
            u         0  0  0  0  0  0  0  0  0

            cvowel vector會由左到右更新當下的<a,e,i,o,u>
            Note:
            1.  實際上會mod2之後再丟進去這邊,因為我們只在乎出現是否偶數次->0代表偶數次,1代表奇數次

                index    -1  0  1  2  3  4  5  6  7
                             l  e  e  t  c  o  d  e
                a         0  0  0  0  0  0  0  0  0
                e         0  0  1  0  0  0  0  0  1
                i         0  0  0  0  0  0  0  0  0
                o         0  0  0  0  0  0  1  1  1
                u         0  0  0  0  0  0  0  0  0

            2.  前面補上index -1原因:
                    以上面例子為例,不補-1的話,<0,0,0,0,0>的case會有問題存在
                    假設我目前traverse到c:其cvowel=<0,0,0,0,0>,index=4
                    在dictionary找到d[<0,0,0,0,0>]=0;
                    所以我們找到長度為4-0=4的可行解
                    解為eetc沒有包含到'l'
                    但是leetc可以更長卻沒有找到
        */
        vector<int>cvowel;
        //resize可以順便初始化成5個0
        cvowel.resize(5);

        /*
            map d作dictionary之用
            功能:紀錄所有第一次出現cvowel pattern的位置
            dict結構:
            以上面例子leetcode為例

                                    key                 value
                                    cvowel              index
                                    <0,1,0,0,0>         1

            代表第一次出現<0,1,0,0,0>這種長相的cvowel的位置是在index=1時
            ....
            以此類推
        */
        map<vector<int>,int>d;

        /*
            因為剛剛有初始化所以會把
            cvowel=<0,0,0,0,0>
            index=-1
            丟進去dictionary
            代表第一次出現<0,0,0,0,0>的地方在-1(字串還沒開始處)
        */
        d[cvowel]=-1;

        //要比較的有aeiou
        char vowel[]={'a','e','i','o','u'};

        //儲存我們最佳解的長度
        int ans=0;

        //traverse字串的所有字元
        for(int i=0;i<s.size();i++)
        {
            //對於每個位置都要統計到目前為止的cvowel(即到該字元aeiou出現奇數or偶數次)
            for(int j=0;j<5;j++)
            {
                //如果這個字元是aeiou其中一種cvowel vector就要更新
                if (s[i]==vowel[j])
                {
                    //對應a or e or i or o or u的個數+1
                    cvowel[j]+=1;
                    //mod 2(如前述)
                    cvowel[j]%=2;
                }
                //否則不用更新(cvowel vector維持不變)
            }

            /*
                當目前cvowel vector的pattern沒有出現在dictionary裡面
                代表有產生了第一次出現的pattern
                就要更新進去dictionary

                寫法:
                    d[cvowel]=i;
                意義:
                    d[新的pattern長相]=這個pattern第一次在哪個index出現
            */
            if(!d.count(cvowel))
                d[cvowel]=i;
            /*
                反之,如果不是第一次出現就要去dictionary裡面抓出來相同pattern第一次出現的index d[cvowel]
                如果i-d[cvowel]>ans則更新
                所以最後跑完,ans就是我們要的最佳解
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
