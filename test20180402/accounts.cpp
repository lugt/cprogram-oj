#include <iostream>
#include <sstream>

using namespace std;
class CAccount {

private:
    int bianhao, shouji, dp, yuee;
public:
    int get_num() const;    void setId(int id);
    int getshouji() const;    void setCell(int cell);
    int dpp() const;    void dpe(int dp);
    int getBal() const;    void setBal(int bal);
};


void result(CAccount *sb, CAccount *apm, int n, int i, int k, int j, int q);

CAccount *chazhao(CAccount *zhanghushuzu, int i, int shoujill);


int main() {
    CAccount * zhanghu;
    int zhanghuhaoma, shoujihaoma, _dp, yuee, s, t, r;

    cin >> s;

    zhanghu = new CAccount[s]();
    for (r = 0; r < s; r++) {
        cin >> zhanghuhaoma >> shoujihaoma >> _dp >> yuee;
        zhanghu[r].setId(zhanghuhaoma);
        zhanghu[r].setCell(shoujihaoma);
        zhanghu[r].dpe(_dp);
        zhanghu[r].setBal(yuee);
    }

    cin >> t;
    for (r = 0; r < t; r++) {
        cin >> shoujihaoma;
        cin >> _dp;
        cin >> yuee;
        CAccount *zhizhen = chazhao(zhanghu, s, shoujihaoma);
        if(zhizhen == NULL){
            cout << "手机号不存在" << endl;
            continue;
        }
        if (zhizhen->dpp() == _dp) {
            if (zhizhen->getBal() >= yuee) {
                cout << "卡号" << zhizhen->get_num() << "--余额" << zhizhen->getBal() - yuee << endl;
            } else {
                cout << "卡号" << zhizhen->get_num() << "--余额不足" << endl;
            }
        } else {
            cout << "密码错误" << endl;
        }
    }
    return 0;
}

CAccount *chazhao(CAccount *zhanghushuzu, int total, int shoujill) {
    for(int i = 0; i < total; i++){
        if(zhanghushuzu[i].getshouji() == shoujill){
            return &zhanghushuzu[i];
        };
    }
    return NULL;
}



int CAccount::get_num() const {
    return bianhao;
}

void CAccount::setId(int id) {
    CAccount::bianhao = id;
}

int CAccount::getshouji() const {
    return shouji;
}

void CAccount::setCell(int cell) {
    CAccount::shouji = cell;
}

int CAccount::dpp() const {
    return dp;
}

void CAccount::dpe(int dp) {
    CAccount::dp = dp;
}

int CAccount::getBal() const {
    return yuee;
}

void CAccount::setBal(int bal) {
    CAccount::yuee = bal;
}