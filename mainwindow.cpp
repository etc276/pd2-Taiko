#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setObjectName("Openmenu");
    setStyleSheet("#Openmenu{border-image:url(:/START)}");
    showFullScreen();

    ui->label_Score->hide();
    ui->label_Time->hide();
    ui->label_D->hide();
    ui->label_J->hide();

    ui->label  ->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();

    ui->pushButton->setGeometry(400,400,150,150);
    ui->pushButton_2->setGeometry(800,400,150,150);

    for (j=0; j<25; ++j)
        card[j]=j;
    for (j=0; j<25; ++j)
    {
        int a=rand()%25, b=rand()%25, temp;
        temp = card[a];
        card[a] = card[b];
        card[b] = temp;
    }
    for (j=0; j<6; ++j)
        x[j] = card[j]*200+2000;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    setStyleSheet("#Openmenu{border-image:url(:/PLAY)}");

    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->label_Score->show();
    ui->label_Time ->show();

    ui->label_D->setStyleSheet("#label_D{border-image:url(:/D)}");
    ui->label_J->setStyleSheet("#label_J{border-image:url(:/J)}");
    ui->label_D->setGeometry(400,400,150,150);
    ui->label_J->setGeometry(800,400,150,150);
    ui->label_D->show();
    ui->label_J->show();

    ui->label  ->setStyleSheet("#label  {border-image:url(:/WHITE)}");
    ui->label_2->setStyleSheet("#label_2{border-image:url(:/WHITE)}");
    ui->label_3->setStyleSheet("#label_3{border-image:url(:/WHITE)}");
    ui->label_4->setStyleSheet("#label_4{border-image:url(:/BLACK)}");
    ui->label_5->setStyleSheet("#label_5{border-image:url(:/BLACK)}");
    ui->label_6->setStyleSheet("#label_6{border-image:url(:/BLACK)}");

    ui->label  ->setGeometry(x[0],180,150,150);
    ui->label_2->setGeometry(x[1],180,150,150);
    ui->label_3->setGeometry(x[2],180,150,150);
    ui->label_4->setGeometry(x[3],180,150,150);
    ui->label_5->setGeometry(x[4],180,150,150);
    ui->label_6->setGeometry(x[5],180,150,150);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(MySlot()));
    timer->start(10);   //每隔10毫秒

    score = 0;          //顯示得分
    playtime = 20;      //遊戲時間
    ever = false;       //顯示重玩
}

void MainWindow::MySlot()
{
    for (i=0; i<6; ++i)
        x[i] = x[i] - 10;

    ui->label  ->setStyleSheet("#label  {border-image:url(:/WHITE)}");
    ui->label_2->setStyleSheet("#label_2{border-image:url(:/WHITE)}");
    ui->label_3->setStyleSheet("#label_3{border-image:url(:/WHITE)}");
    ui->label_4->setStyleSheet("#label_4{border-image:url(:/BLACK)}");
    ui->label_5->setStyleSheet("#label_5{border-image:url(:/BLACK)}");
    ui->label_6->setStyleSheet("#label_6{border-image:url(:/BLACK)}");

    QString Score = "Score:";
    Score += QString::number(score);
    ui->label_Score->setText(Score);

    QString Time = "Time:";
    Time += QString::number(playtime);
    ui->label_Time->setText(Time);

    playtime = playtime-0.01;

    if (playtime<0 && ever==false)
    {
        ever = true;
        QMessageBox::information(NULL, "FINAL~","score:" + QString::number(score)  + "\nPlay again?");
        MainWindow *c = new MainWindow();
        c->show();
        close();
    }

    if (x[0]<300) ui->label  ->setStyleSheet("#label  {border-image:url(:/RED)}");
    if (x[1]<300) ui->label_2->setStyleSheet("#label_2{border-image:url(:/RED)}");
    if (x[2]<300) ui->label_3->setStyleSheet("#label_3{border-image:url(:/RED)}");
    if (x[3]<300) ui->label_4->setStyleSheet("#label_4{border-image:url(:/RED)}");
    if (x[4]<300) ui->label_5->setStyleSheet("#label_5{border-image:url(:/RED)}");
    if (x[5]<300) ui->label_6->setStyleSheet("#label_6{border-image:url(:/RED)}");

    if (x[0]<100) {ui->label  ->setStyleSheet("#label  {border-image:url(:/WHITE)}"); x[0]=card[j++]*200+2000; j%=25;}
    if (x[1]<100) {ui->label_2->setStyleSheet("#label_2{border-image:url(:/WHITE)}"); x[1]=card[j++]*200+2000; j%=25;}
    if (x[2]<100) {ui->label_3->setStyleSheet("#label_3{border-image:url(:/WHITE)}"); x[2]=card[j++]*200+2000; j%=25;}
    if (x[3]<100) {ui->label_4->setStyleSheet("#label_4{border-image:url(:/BLACK)}"); x[3]=card[j++]*200+2000; j%=25;}
    if (x[4]<100) {ui->label_5->setStyleSheet("#label_5{border-image:url(:/BLACK)}"); x[4]=card[j++]*200+2000; j%=25;}
    if (x[5]<100) {ui->label_6->setStyleSheet("#label_6{border-image:url(:/BLACK)}"); x[5]=card[j++]*200+2000; j%=25;}

    ui->label  ->setGeometry(x[0],180,150,150);
    ui->label_2->setGeometry(x[1],180,150,150);
    ui->label_3->setGeometry(x[2],180,150,150);
    ui->label_4->setGeometry(x[3],180,150,150);
    ui->label_5->setGeometry(x[4],180,150,150);
    ui->label_6->setGeometry(x[5],180,150,150);

    ui->label  ->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_D)
    {
        if (x[0]>=280 && x[0]<=430) {score++; x[0]=card[j++]*200+2000; j%=25; ui->label  ->setGeometry(x[0], 200, 150, 100);}
        if (x[1]>=280 && x[1]<=430) {score++; x[1]=card[j++]*200+2000; j%=25; ui->label_2->setGeometry(x[1], 200, 150, 100);}
        if (x[2]>=280 && x[2]<=430) {score++; x[2]=card[j++]*200+2000; j%=25; ui->label_3->setGeometry(x[2], 200, 150, 100);}
    }

    if (event->key() == Qt::Key_J)
    {
        if (x[3]>=280 && x[3]<=430) {score++; x[3]=card[j++]*200+2000; j%=25; ui->label_4->setGeometry(x[3], 200, 150, 100);}
        if (x[4]>=280 && x[4]<=430) {score++; x[4]=card[j++]*200+2000; j%=25; ui->label_5->setGeometry(x[4], 200, 150, 100);}
        if (x[5]>=280 && x[5]<=430) {score++; x[5]=card[j++]*200+2000; j%=25; ui->label_6->setGeometry(x[5], 200, 150, 100);}
    }
}
