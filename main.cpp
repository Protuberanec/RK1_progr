#include <QCoreApplication>
#include <QFile>
#include <QList>


struct StudentInfo {
    char* name;
    char* surname;
    int age;
    char* numTicket;
};

struct SubjMark {
    char* subj;
    int id_subj;
    QVector<int> marks_list;
    float averMark;

//homework fill constructors
    SubjMark() {

    }
    SubjMark(const char* _subj) {

    }

    SubjMark(const char* _subj, int _idSubj) {

    }

    ~SubjMark() {
        if (subj != nullptr) {
            delete [] subj;
        }
    }

};


class Student {
private :
    StudentInfo* info;
    QList<SubjMark*> listSubjMark;
//howework вернуть итератор!!!
    int lookForSub(const char* subjName) {
//        for (auto iter = listSubjMark.begin(); iter != listSubjMark.end(); iter++) {}
        for (int i = 0; i < listSubjMark.size(); i++) {
            //homework реализоавть функцию strcmp(....)
            if (strcmp(listSubjMark[i]->subj, subjName) == 0) {
                return i;
            }
        }

        listSubjMark.push_back(new SubjMark(subjName));
        return listSubjMark.size() - 1;
    }

public :

    void addSubject(const char* subjName, int idSubj = 0) {
        listSubjMark.push_back(new SubjMark(subjName, idSubj));
    }

    int addMarkToSubj(const char* subjName /*int _idSubj*/, int mark) {
        int numSubj = lookForSub(subjName);

        listSubjMark[numSubj]->marks_list.push_back(mark);

        return 0;


    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);




    return a.exec();
}
