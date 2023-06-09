//#include "../include/mainwindow.h"
#include "mainwindow.h"
//#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    commNode=new rclcomm();
    //commNode->start();

    connect(commNode,SIGNAL(emitTopicData(QString)),this,SLOT(onRecvData(QString)));

    QImage img;
    img.load("://v2-00ee32c36ff2add684bbd42f0649aa4e.gif");
    ui->label_3->setPixmap(QPixmap::fromImage(img).scaled(ui->label_3->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));

    //初始化场景类
    m_qGraphicScene = new QGraphicsScene();
    m_qGraphicScene->clear();
    //初始化item
    m_roboItem = new roboItem();
    //视图中添加item
    m_qGraphicScene->addItem(m_roboItem);
    //ui中的graphicsView添加场景
    ui->graphicsView->setScene(m_qGraphicScene);
    commNode->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRecvData(QString msg)
{
    ui->label_2->setText(msg);
}

void MainWindow::on_pushButton_clicked()
{
    //commNode->start();
}
//显示图片
void MainWindow::on_pushButton_2_clicked()
{
    QImage img;
    img.load("://v2-00ee32c36ff2add684bbd42f0649aa4e.gif");
    m_roboItem->updateImage(img);
}

void MainWindow::on_pushButton_3_clicked()
{
    QPolygonF point;
    point.push_back(QPointF(0,0));
    point.push_back(QPointF(1,1));
    point.push_back(QPointF(3,3));
    point.push_back(QPointF(5,5));
    m_roboItem->updatePoints(point);
}

void MainWindow::on_pushButton_4_clicked()
{
    QLine line(QPoint(0,0),QPoint(30,30));
    m_roboItem->updateLines(line);
}
