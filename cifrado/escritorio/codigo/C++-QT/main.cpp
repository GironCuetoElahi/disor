//
//  main.cpp
//  CifradoC++
//
//  Created by ITO on 12/15/18.
//  Copyright © 2018 Elahi Giron Cueto. All rights reserved.
//


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
