#include <QCoreApplication>
#include <QFile>
#include <QList>


QByteArray fileData;

void ReadFromFile(const char* fileName) {
    QFile f(fileName);
    f.open(QIODevice::ReadOnly);

    fileData = f.readAll();

    f.close();
}

void WriteToFile(const int* ar, int size) {

}

void task1() {
    ReadFromFile("test");

    int ar[256];
    memset(&ar[0], 0x00, sizeof(int) * 256);

    for (int i = 0; i < fileData.size(); i++) {
        ar[fileData[i]]++;
    }

    WriteToFile(&ar[0], 256);
}


char binNumb[32];
void perevod(int numDecimal) {
    memset(binNumb, 0x00, 32 * sizeof(int));

    for (int i = 0; i < 32; i++) {
        binNumb[i] = ((numDecimal & 1 << i)) ? 0x31 : 0x30;
//        binNumb[i] = ((numDecimal & (1 << i)) >> i) + 0x30;
    }
}

void task2() {
    perevod(39);
    qDebug() << binNumb;

    perevod(1);
    qDebug() << binNumb;

    perevod(0xFFFFFFFF);
    qDebug() << binNumb;
}

void tempT() {

    for (int i = 0; i < 256; i++) {
        qDebug() << (int)i << "\t" << (char)i;
    }

}


//std::list<float> getAverStr(int* ar, int N, int M) {

//}

QList<float> getAverStr(int* ar, int N, int M) {
    QList<float> averStr;

    for (int i = 0; i < N; i++) {
        float averStr_temp = 0;
        for (int j = 0; j < M; j++) {
            averStr_temp += ar[i*N + j] / (float)M;
        }

        averStr.push_back(averStr_temp);
        averStr.append(averStr_temp);
    }


    return averStr;
}

void task5() {

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char temp[100][100];
    tempF(&temp[0][0]);

//    task1();
    task2();

    tempT();



    return a.exec();
}
