#ifndef NOBORDERMAIN_H
#define NOBORDERMAIN_H

#include <QDialog>
#include <QPoint>
#include <QDebug>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QCheckBox>

namespace Ui {
class NoBorderMain;
}

class NoBorderMain : public QDialog
{
    Q_OBJECT

public:
    explicit NoBorderMain(QWidget *parent = 0);
    ~NoBorderMain();

private slots:
    void on_btnMax_clicked();

    void on_btnClose_clicked();

    void on_btnMin_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidgetBottom_itemClicked(QListWidgetItem *item);

private:
    // 鼠标按下
    void mousePressEvent(QMouseEvent* event);

    // 鼠标移动
    void mouseMoveEvent(QMouseEvent* event);

    // 鼠标释放
    void mouseReleaseEvent(QMouseEvent* event);

    // 设置字体图标
    void setFontFamily();

    bool eventFilter(QObject *obj, QEvent *e);


private:
    Ui::NoBorderMain *ui;

    QPoint pStart;          // 拖动起始点
    bool isDrag;            // 是否在拖动

    QRect  preMax;          // 最大化之前的位置
    bool isMax;             // 是否最大化
    QFont font;




};

#endif // NOBORDERMAIN_H
