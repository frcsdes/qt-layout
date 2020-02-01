#ifndef QTL_MAIN_WINDOW_H
#define QTL_MAIN_WINDOW_H

#include "layout.h"

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>


class MainWindow : public QMainWindow {
public:
    MainWindow() {
        auto [parent, children] = qtl::vertical<QLineEdit, QLineEdit, QPushButton>();
        auto push_button = std::get<2>(children);
        push_button->setText("Confirm");
        setCentralWidget(parent.release());
        show();
    }
};


#endif // QTL_MAIN_WINDOW_H
