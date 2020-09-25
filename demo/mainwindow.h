#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DLineEdit>

#include <DMainWindow>

DWIDGET_USE_NAMESPACE


class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int isDigitStr(QString src);

private:
    void initUI();
    void initConnection();

private slots:
    void onTextChanged(const QString &text);

private:
    DLineEdit *lineEdit;
};

#endif // MAINWINDOW_H
