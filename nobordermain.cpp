#include "nobordermain.h"
#include "ui_nobordermain.h"

#include <QMouseEvent>
#include <QFontDatabase>
#include <QIcon>
#include <QDesktopWidget>
#include <QGraphicsDropShadowEffect>
#include <QDebug>


NoBorderMain::NoBorderMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoBorderMain)
{
    ui->setupUi(this);

    // 隐藏边框
    setWindowFlags(Qt::FramelessWindowHint);
    // 放大前的位置
    preMax = this->geometry();

    isDrag = false;
    isMax = false;

    //    ui->btnMin->setFont(font);
    //    ui->btnMin->setText(QChar(0xf00d));
    //    ui->btnMin->setStyleSheet("color:#fff;");
    //    ui->btnMin->setIcon(QIcon(":/images/reduce.png"));



    // 圆角与阴影
    //    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    //    effect->setOffset(4,4);
    //    effect->setColor(QColor(0,0,0,50));
    //    effect->setBlurRadius(10);


    //    ui->widget->setGraphicsEffect(effect);


    // listwidget 左侧
    QListWidgetItem *add_item_1 = new QListWidgetItem(ui->listWidget);
    add_item_1->setIcon(QIcon(":/images/phone.png"));
    add_item_1->setText(QStringLiteral("最近使用"));

    QListWidgetItem *add_item_2 = new QListWidgetItem(ui->listWidget);
    add_item_2->setIcon(QIcon(":/images/phone.png"));
    add_item_2->setText(QStringLiteral("全部文件"));

    QListWidgetItem *add_item_3 = new QListWidgetItem(ui->listWidget);
    add_item_3->setIcon(QIcon(":/images/ToastBkg.png"));
    add_item_3->setText(QStringLiteral("图片"));


    QListWidgetItem *add_item_4 = new QListWidgetItem(ui->listWidget);
    add_item_4->setIcon(QIcon(":/images/ToastBkg.png"));
    add_item_4->setText(QStringLiteral("视频"));


    QListWidgetItem *add_item_5 = new QListWidgetItem(ui->listWidget);
    add_item_5->setIcon(QIcon(":/images/ToastBkg.png"));
    add_item_5->setText(QStringLiteral("文档"));

    QListWidgetItem *add_item_6 = new QListWidgetItem(ui->listWidget);
    add_item_6->setIcon(QIcon(":/images/ToastBkg.png"));
    add_item_6->setText(QStringLiteral("音乐"));

    QListWidgetItem *add_item_7 = new QListWidgetItem(ui->listWidget);
    add_item_7->setIcon(QIcon(":/images/ToastBkg.png"));
    add_item_7->setText(QStringLiteral("种子"));

    QListWidgetItem *add_item_8 = new QListWidgetItem(ui->listWidget);
    add_item_8->setIcon(QIcon(":/images/ToastBkg.png"));
    add_item_8->setText(QStringLiteral("其他"));

    // 第二个list

    QListWidgetItem *add_item_9 = new QListWidgetItem(ui->listWidgetBottom);
    add_item_9->setIcon(QIcon(":/images/c.png"));
    add_item_9->setText(QStringLiteral("隐藏空间"));

    QListWidgetItem *add_item_10 = new QListWidgetItem(ui->listWidgetBottom);
    add_item_10->setIcon(QIcon(":/images/c.png"));
    add_item_10->setText(QStringLiteral("我的分享"));

    QListWidgetItem *add_item_11 = new QListWidgetItem(ui->listWidgetBottom);
    add_item_11->setIcon(QIcon(":/images/c.png"));
    add_item_11->setText(QStringLiteral("回收站"));

    // 右侧table



    /*ui->tableWidget->setRowCount(50);
    ui->tableWidget->setColumnCount(4);
    QStringList header;

    header<< ""<<QStringLiteral("名称")<<QStringLiteral("来源时间")<<QStringLiteral("大小");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    ui->tableWidget->setItem(1,1,new QTableWidgetItem(QStringLiteral("画江湖之画江湖之不良人不良人")));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(QStringLiteral("画江湖之不良人")));

    ui->tableWidget->show();

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  //可选择多个


//    QCheckBox *comBox = new QCheckBox();

//    ui->tableWidget->setCellWidget(0,2,comBox);

    QTableWidgetItem *check = new QTableWidgetItem;
    check->setCheckState(Qt::Checked);
    ui->tableWidget->setItem(0,0,check);

    // 设置表头
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);*/

}

NoBorderMain::~NoBorderMain()
{
    delete ui;
}

void NoBorderMain::mousePressEvent(QMouseEvent *event)
{
    //    this->setFocus();
    //    if(Qt::LeftButton == event->button() && 0 == (Qt::WindowMaximized & this->windowState()))
    //    {
    //        QPoint temp=event->globalPos();
    //        pLast=temp;    //记录鼠标按下的位置
    //                event->ignore();
    //    }
    //    m_bPressed = true; //标记鼠标为按下状态


    if(event->button() == Qt::LeftButton)
    {
        isDrag = true;
        pStart = event->globalPos() - pos();

        event->accept();
    }

}

void NoBorderMain::mouseMoveEvent(QMouseEvent *event)
{
    //    if(this->isMaximized()) //如果当前是最大化，则不允许移动
    //        return;

    //    if((event->buttons() & Qt::LeftButton) && m_bPressed)//是否左击
    //    {
    //        QPoint ptemp=event->globalPos();          //当前鼠标全局位置
    //                ptemp=ptemp-pLast;                        //计算移动变量
    //                ptemp=ptemp+pos();                        //窗口原始位置（pos()） + 鼠标移动变量（ptemp） = 最终窗口位置
    //                move(ptemp);                              //移动窗口到新的位置
    //    }


    if(isDrag && (event->buttons() && Qt::LeftButton))
    {

        move(event->globalPos() - pStart);
        event->accept();

    }




}

void NoBorderMain::mouseReleaseEvent(QMouseEvent *event)
{
    //    QApplication::restoreOverrideCursor();//恢复鼠标指针性状
    //    event->ignore();

    //    m_bPressed = false;

    isDrag = false;
}

void NoBorderMain::setFontFamily()
{
    int fontID = QFontDatabase::addApplicationFont(":/Font/fontawesome-webfont.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontID);
    qDebug()<< fontFamilies.size();
    font.setFamily(fontFamilies.at(0));
    font.setPointSize(20);
}

bool NoBorderMain::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == ui->widgetTitle)
    {
        if(e->type() == QEvent::MouseButtonDblClick)
        {
            on_btnMax_clicked();
            return true;
        }
    }
    return QObject::eventFilter(obj, e);


}

void NoBorderMain::on_btnMax_clicked()
{
    if (isMax)
    {
        setGeometry(preMax);
        ui->btnMax->setIcon(QIcon(":/images/10.png"));
        ui->btnMax->setToolTip(QStringLiteral("最大化"));
    }
    else
    {
        preMax = geometry();

        setGeometry(qApp->desktop()->availableGeometry());
        ui->btnMax->setIcon(QIcon(":/images/9.png"));
        ui->btnMax->setToolTip(QStringLiteral("还原"));
    }
    isMax = !isMax;


}

void NoBorderMain::on_btnClose_clicked()
{
    qApp->exit();

}

void NoBorderMain::on_btnMin_clicked()
{
    showMinimized();


}

void NoBorderMain::on_listWidget_itemClicked(QListWidgetItem *item)
{
    qDebug()<< item->text();
    //    ui->listWidget->clearSelection();
    ui->listWidgetBottom->clearSelection();
}

void NoBorderMain::on_listWidgetBottom_itemClicked(QListWidgetItem *item)
{
    qDebug()<< item->text();
    ui->listWidget->clearSelection();
    //    ui->listWidgetBottom->clearSelection();
}
