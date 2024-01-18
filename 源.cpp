#include<iostream>
#include<vector>
#include<initializer_list>
#include<map>
#include<algorithm>
#include "tou_text.h"


using namespace std;

extern const int size;//tou_text.h

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* headf = nullptr;
    ListNode* front = nullptr;
    vector<int> LNarr;
    //auto arrt = LNarr.begin();
    int i = 0;
    while (head->next != nullptr) {
        if (head->val != (head->next)->val) {
            if (i == 0) headf = head;
            ++i;
            if (front != nullptr) front->next = head;
            front = head;
        }
        else {
            do {
                if ((head->next)->next != nullptr) head = head->next;
                else {
                    if (headf != nullptr) front->next = nullptr;
                    head = headf;
                    return head;
                }
            } while (head->val == (head->next)->val);
        }
        head = head->next;
    }
    if (i == 0) headf = head;
    if (front != nullptr) front->next = head;
    head = headf;
    return head;
}

string repeatLimitedString(string s, int repeatLimit) {
    if (s.empty()) return "";
    map<char, int> sp;
    auto st = s.begin() + 1;
    string sd;  //������¼�ַ�������
    {sd.push_back(s[0]);
    sp[s[0]] = 1; }//Ԥ����
    while (st != s.end()) {  //Ԥ�����ַ�����ͳ�����������
        if (sp.find(*st) != sp.end()) {
            ++sp[*st];
        }
        else {
            if (*st > sd[0]) { sd.insert(sd.begin(), *st); }
            else {
                auto sdft = sd.begin();
                auto sdet = sd.end();
                while (sdft + 1 != sdet) {
                    auto temp = sdft + (sdet - sdft) / 2;
                    if (*temp > *st) {
                        sdft = temp;
                    }
                    else if (*temp < *st) {
                        sdet = temp;
                    }
                }
                sd.insert(sdet, *st);
            }
            sp[*st] = 1;
        }
        ++st;
    }
    //cout << sd << endl;

    //----�������Ŀ���ַ���
    st = sd.begin();
    auto stn = st + 1;
    string target;
    while (1) {
        int i = 0;
        if (sp[*st] >= repeatLimit) {
            if (target.empty() || *(target.end() - 1) != *st) i = repeatLimit;
            else i = repeatLimit - 1;
        }
        else {
            i = sp[*st];
        }
        target.insert(target.end(), i, *st);
        sp[*st] -= i;
        if (stn != sd.end()) {
            target.insert(target.end(), 1, *stn);
            sp[*stn] -= 1;
        }
        else break;
        if (sp[*st] <= 0) {
            st = stn;
            stn = stn + 1;
        }
        else if (sp[*stn] <= 0) {
            stn = stn + 1;
        }
    }
    return target;
}

int countSeniors(const vector<string>& details) {//ͳ���ַ����ϵ�12��13λ��ɵ�����ֵ�Ƿ����60�ĸ���
    int count = 0;
    for (string str : details) {
        int i = (int)(str[11] - '0') * 10 + (int)(str[12] - '0');
        if (i > 60) count++;
    }
    return count;
}

int unknow_argv_f(initializer_list<int> ch, char i) {
    cout << i << endl;
    return 0;
};

long long minimumRemoval(vector<int>& beans) {
    long long total = 0;
    for (int i : beans) { total += (long long)i; }
    sort(beans.begin(), beans.end());
    long long res = total;
    for (int i = 0; i < beans.size(); i++) {
        long long j = (total - (long long)beans[i] * (beans.size() - i));
        res = min(res, j);
    }
    return res;
}

int main() {
    //--------------1.18
    vector<int> beans{ 4,1,6,5 };
    cout << minimumRemoval(beans);
    /*--------------1.17
    Salas_data Sd;
    cout << Sd.tri() << endl;
    cout << Salas_data::i;
    /*--------------1.15
    int arr[7] = { 1, 2, 3, 3, 4, 4, 5 };
    ListNode head = ListNode(arr[6]);
    int i;
    //cout << i << endl; //�ᱨ����ʾʹ��δ��ʼ���ľֲ�����
    i = 5;
    ListNode temp[7];
    temp[6] = head;
    while (i >= 0) {
        temp[i] = ListNode(arr[i], &temp[i + 1]);
        --i;
    }
    ListNode *headp = &temp[0];
    ListNode* target = deleteDuplicates(headp);
    while (target != nullptr) {
        cout << target->val << ' ';
        target = target->next;
    }

    /*--------------1.13
    string s = "aababab";
    //auto st = s.end();
    //s.insert(st , 'n');
    if ('c' > 'z') {
        cout << "c > z";
    }
    else cout << "c < z"  ;
    cout << repeatLimitedString(s, 2);
    /*--------------1.11
    int i11 = 0;
    cout << i11 << ' ' << ++i11 << endl;
    unknow_argv_f({2, 3, 4, 53, 5, 5}, 'c');
    //--------------
    vector<string> de{ "7868190130M7522","5303914400F9211","9273338290F4010" };
    cout << countSeniors(de) << endl;
    cout << ::size << endl;
    int i = 42, * p = &i, & r = i;
    decltype((i)) d = i;
    cout << typeid(decltype(d)).name() << endl;

    int ia[3][4] = {
        {0 ,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    for (auto &row : ia)
        for (auto col : row) {
            cout << col << ',';
        }

    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    // �ڵ�����λ�ò���Ԫ��6
    auto it = vec.begin() + 2;
    vec.insert(it, 6);

    // ���������Ԫ��
    for (auto num : vec) {
        std::cout << num << " ";
    }
    */
}