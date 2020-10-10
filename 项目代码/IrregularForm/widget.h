#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPoint>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    //鼠标事件
    void mousePressEvent(QMouseEvent * ev);

    //绘画事件
    void paintEvent(QPaintEvent * ev);


    //鼠标滑动
     void mouseMoveEvent(QMouseEvent *ev);

private:
    Ui::Widget *ui;
    QPixmap pix;
    QPoint point;       //这个对应的是差值
};

#endif // WIDGET_H
