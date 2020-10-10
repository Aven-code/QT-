#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QIcon>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    pix.load(":/img/helicopter.png");
    this->setWindowIcon(QIcon(pix));

    this->setAttribute(Qt::WA_TranslucentBackground);

    this->setWindowFlags(Qt::FramelessWindowHint);  //设置窗口的标记

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent * ev )
{
    if(ev->button() == Qt::LeftButton)
    {
         this->point = ev->globalPos() - this->frameGeometry().topLeft();
    }
    if(ev->button() == Qt::RightButton)
        this->close();
}

void Widget::paintEvent(QPaintEvent * ev)
{
    QPainter p(this);
    p.drawPixmap(0,0,pix);
}

void Widget::mouseMoveEvent(QMouseEvent *ev)
{

    this->move(ev->globalPos() - this->point);
}


