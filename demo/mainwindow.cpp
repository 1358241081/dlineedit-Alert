#include "mainwindow.h"

#include <DFrame>
#include <DLabel>

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    initUI();
    initConnection();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initUI()
{
    setMinimumSize(500, 300);

    DFrame *frame = new DFrame;
    lineEdit = new DLineEdit;
    DLabel *label = new DLabel("判断输入的字符是否为纯数字：");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(label, 0, Qt::AlignLeft);
    mainLayout->addWidget(lineEdit);
    mainLayout->addStretch();

    frame->setLayout(mainLayout);
    setCentralWidget(frame);
}

void MainWindow::initConnection()
{
    connect(lineEdit, &DLineEdit::textChanged, this, &MainWindow::onTextChanged);
}

void MainWindow::onTextChanged(const QString &text)
{
    int ret = isDigitStr(text);
    if (ret == -1) {

        // 设置为警告模式
        lineEdit->setAlert(true);

        // 显示警告消息
        lineEdit->showAlertMessage("只能输入数字，请重新输入！");

        // 设置警告消息对齐方式
        lineEdit->setAlertMessageAlignment(Qt::AlignLeft);
    } else {

        // 取消警告模式
        lineEdit->setAlert(false);

        // 隐藏警告消息
        lineEdit->hideAlertMessage();
    }
}

int MainWindow::isDigitStr(QString src)
{
    QByteArray ba = src.toLatin1();//QString 转换为 char*
     const char *s = ba.data();

    while(*s && *s >= '0' && *s <= '9') s++;

    if (*s) { //不是纯数字
        return -1;
    } else { //纯数字
        return 0;
    }
}
