#ifndef QTL_MAIN_WINDOW_H
#define QTL_MAIN_WINDOW_H

#include "layout.h"

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>


class MainWindow : public QMainWindow {
public:
    MainWindow() {
        using Input = qtl::HBox<QLabel, QLineEdit>;
        using Form  = qtl::VBox<Input, Input, QPushButton>;

        auto form = std::make_unique<Form>();
        form->child<0, 0>()->setText("First name:");
        form->child<1, 0>()->setText("Last name:");
        form->child<2>()->setText("Confirm");

        setCentralWidget(form.release());
        show();
    }
};


#endif // QTL_MAIN_WINDOW_H
