//
// Created by lugt on 2018/4/23.
//

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Student {

private:
    int id;    //学号
    int score; //成绩

    static int maxscore;    //最高分数
    static int maxid;        //最高分数学生学号

    static list<Student> group;

public:

    Student(int ti = 0, int ts = 0)
            : id(ti), score(ts) {}

    static void findMax(Student & stu){

        group.push_back(stu);

        maxscore = 0;

        for(list<Student>::iterator it = group.begin(); it != group.end(); it++){
            if(it == group.begin() || it->score > maxscore){
                maxscore = it->score;
                maxid = it->id;
            }
        }
    }

    static int getMaxScore(){
        return maxscore;
    }
    static int getMaxID(){
        return maxid;
    }

};

int Student::maxscore = 0, Student::maxid = 0;
list<Student> Student::group;

int main() {
    int t, id, score, maxscore;
    cin >> t;

    while (t--) {
        cin >> id >> score;
        Student::findMax(* new Student(id, score));
    }
    cout << Student::getMaxID() << "--" << Student::getMaxScore();

}
