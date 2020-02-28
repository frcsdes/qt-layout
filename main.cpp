#include "layout.h"

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>

#include <memory>


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


int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    MainWindow main_window;
    return QApplication::exec();
}
