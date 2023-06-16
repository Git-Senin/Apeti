#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <windows.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);


#ifdef Q_OS_WIN
    HWND hWnd = reinterpret_cast<HWND>(winId());
    DWORD dwExStyle = GetWindowLongPtr(hWnd, GWL_EXSTYLE);
    dwExStyle |= WS_EX_TRANSPARENT | WS_EX_LAYERED;
    SetWindowLongPtr(hWnd, GWL_EXSTYLE, dwExStyle);

    BYTE currentAlpha;
    DWORD currentFlags;
    GetLayeredWindowAttributes(hWnd, nullptr, &currentAlpha, &currentFlags);

    SetLayeredWindowAttributes(hWnd, 0, 255, currentAlpha);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

