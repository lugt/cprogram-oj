#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    Student(int v = 0, int v2 = 0)
            : id(v), score(v2) {}
    static void findMax(Student & stu){
        if(stu.score > maxscore){            maxscore = stu.score;            maxid = stu.id;        }
    }
private:
    int id;    //学号
    int score; //成绩

    static int maxscore;    //最高分数
    static int maxid;        //最高分数学生学号

public:

    static int get_max_id(){
        return maxid;
    }
    static int get_max_score(){
        return maxscore;
    }


};

int Student::maxscore = 0, Student::maxid = 0;

int main() {
    int t, id, sc_;
    cin >> t;

    while (t--) {
        cin >> id >> sc_;
        Student::findMax(* new Student(id, sc_));
    }
    cout << Student::get_max_id() << "--" << Student::get_max_score();

}
